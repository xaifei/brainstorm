#include "myserver.h"

MyServer::MyServer()
{
    //日志
#ifdef DEBUG//向控制台写
    _log=spdlog::stdout_color_mt("console");
#else
    _log=spdlog::rotating_logger_mt("BrainStorm","BrainStorm",1024*1024*5,3);
    _log->flush_on(spdlog::level::info);
#endif
    //_log->info("11111111111");//写在控制台

    _db=new DB(NULL,"xiaowang","xiaowang","BrainStorm");
    initRankMap();
}

void MyServer::connectEvent(TcpSocket *s)
{
    _log->info("有一个新的连接[{}:{}]\n",s->getIp(),s->getPort());
    //printf("客户端连接%s","端口连接%s",s->getIp(),s->getPort());
}

void MyServer::readEvent(TcpSocket *s)
{
    char buf[1024]={0};
    while(1)
    {
        int len=0;
        s->readDate(&len,sizeof(len));
        if(len<=0)
            break;
        s->readDate(buf,len);
        //数据解析
        Json::Value root;
        Json::Reader reader;//json解析器
        if(!reader.parse(buf,root))
        {
            _log->error("json数据解析失败");
            return;
        }

        int cmd=root["cmd"].asInt();
        switch (cmd)
        {
        case REGISTER:
            Register(s,root);
            break;
        case LOGIN:
            Login(s,root);
            break;
        case SINGLE_QUESTION:
            get_SingleQuestion(s);
            break;
        case RANK:
            Rank(s);
            break;
        case ANSWER:
            rankAnswerOneQuestion(s,root);
            break;
        case RANKRESULT:
            rankResult(s,root);
            break;
        default:
            break;
        }

    }
}

void MyServer::writeEvent(TcpSocket *)
{

}

void MyServer::closeEvent(TcpSocket *s,short)
{
    //将用户从 等待 rank 的列表中删除
    {
        std::unique_lock<std::mutex> _lock(_rankLock);
        int rank=_users[s->getUserName()]->getRank();
        auto it=_rankQueue.find(rank);//然后从队列里面去找他
        if(it != _rankQueue.end())
            _rankQueue.erase(it);
    }

    //printf("客户端退出,ip：%s,端口：%d\n",s->getIp(),s->getPort());
    //_log->error("用户{}[{}:{}] logout",userName,s->getIp(),s->getPort());
    std::unique_lock<std::mutex> _lock(_userLock);
    std::map<std::string,User*>::iterator it=_users.begin();
    while(it!=_users.end())
    {
        if(it->second->getSocket()==s)
        {
            _users.erase(it);
            _log->info("用户{}[{}:{}] logout",it->second->getName(),s->getIp(),s->getPort());
            break;

            //移除完之后释放User
            delete it->second;
            return;
        }

        it++;
    }
    _log->info("用户{}[{}:{}] logout",s->getIp(),s->getPort());

}

void MyServer::writeData(TcpSocket *s,const Json::Value &inJson)
{
    std::string data=inJson.toStyledString();
    s->writeDate(data.c_str(),data.length());
}

void MyServer::Register(TcpSocket *s,const Json::Value &inJson)
{
    std::string userName=inJson["userName"].asString();
    std::string passwd=inJson["passwd"].asString();

    //检测用户是否已经存在
    char sql[100]={0};
    sprintf(sql,"select *from user where name='%s' and passwd='%s'",userName.c_str(),passwd.c_str());

    int result=OK;
    Json::Value outJson;
    bool ret=_db->db_select(sql,outJson);
    if(!ret)
    {
        result=ERROR;
        _log->error("Register select user error");
    }

    if(outJson.isMember("name"))    //用户存在，表明已经做过了
        result=USEREXIST;
    else
    {
        sprintf(sql,"insert into user(name,passwd,rank) values('%s','%s',0)",userName.c_str(),passwd.c_str());
        bool ret=_db->db_exec(sql);
        if(!ret)
        {
            result=ERROR;
            _log->error("Register insert user error");
        }
        else
            _log->info("Register user={} succeed",userName);

    }

    //最后整合数据
    Json::Value json;
    json ["cmd"]=REGISTER;
    json ["result"]=result;

    writeData(s,json);

}

void MyServer::Login(TcpSocket *s,const Json::Value &inJson)
{
    std::string userName=inJson["userName"].asString();
    std::string passwd=inJson["passwd"].asString();
    int rank=0;

    //检测用户是否已经登录

    char sql[100]={0};
    sprintf(sql,"select *from user where name='%s' and passwd='%s'",userName.c_str(),passwd.c_str());

    int result=OK;
    Json::Value outJson;
    bool ret=_db->db_select(sql,outJson);
    if(!ret)
    {
        result=ERROR;
        _log->error("Login select user error");
    }

    if(outJson.isMember("name"))    //用户存在，表明已经注册了
    {
        std::unique_lock<std::mutex> _lock(_userLock);//先上一把锁
        if(_users.find(userName)!=_users.end())//用户已经登录
            result=USERLOGIN;
        else
        {
            int i=0;
            rank=atoi(outJson["rank"][i].asString().c_str());
            User* user=new User(userName,passwd,rank,s);
            _users.insert(make_pair(userName,user));//用户创建完，把他放进列表里,user为指针
            _log->info("用户{}[{}:{}] login",userName,s->getIp(),s->getPort());
            s->setUserName(userName);
        }
    }
    else
        result=NAMEORPASSWD;

    //最后整合数据
    Json::Value json;
    json ["cmd"]     =LOGIN;
    json ["result"]  =result;
    json ["userName"]=userName;
    json ["rank"]    =_rankMap[rank];

    writeData(s,json);
}

void MyServer::get_SingleQuestion(TcpSocket *s)
{
    char sql[100]={0};
    sprintf(sql,"select * from question order by rand() limit %d",QUESTION_NUM);

    int result=OK;
    Json::Value outJson;
    bool ret=_db->db_select(sql,outJson);
    if(!ret || outJson["question"].size()!=QUESTION_NUM)
    {
        result=ERROR;
        _log->error("get_SingleQuestion select question error");
    }

    Json::Value json;
    json ["cmd"]     =SINGLE_QUESTION;
    json ["result"]  =result;
    json ["question"]=outJson;

    _log->info("用户{}[{}:{}] 获取题目: {}\n",s->getUserName(),s->getIp(),s->getPort(),json.toStyledString());

    //服务器把数据发送给客户端
    writeData(s,json);
}

void MyServer::startRank(TcpSocket *first,TcpSocket *second)
{
    char sql[100]={0};
    sprintf(sql,"select * from question order by rand() limit %d",QUESTION_NUM);

    int result=OK;
    Json::Value outJson;
    bool ret=_db->db_select(sql,outJson);
    if(!ret || outJson["question"].size()!=QUESTION_NUM)
    {
        result=ERROR;
        _log->error("startRank select question error");
    }

    Json::Value json;
    json ["cmd"]     =RANK;
    json ["result"]  =result;
    json ["question"]=outJson;

    //first user
    json ["enemyName"] =second->getUserName();
    json ["enemyRank"] =_rankMap[_users[second->getUserName()]->getRank()];
    json ["enemyScore"]=0;
    writeData(first,json);

    //second user
    json ["enemyName"] =first->getUserName();
    json ["enemyRank"] =_rankMap[_users[first->getUserName()]->getRank()];
    writeData(second,json);

    _log->info(" 获取 rank 题目: {}\n",json.toStyledString());
}

void MyServer::Rank(TcpSocket *s)
{
    TcpSocket *other=NULL;//对手
    int rank=_users[s->getUserName()]->getRank();//当前用户 rank 积分

    std::unique_lock<std::mutex> lock(_rankLock);
    //查找同一段位的对手
    std::map<int,TcpSocket*>::iterator it=_rankQueue.find(rank);
    if(it!=_rankQueue.end())//找到了
    {
        other=it->second;
        _rankQueue.erase(it);
    }
    else
    {
        //查找其他段位的选手 积分差值的绝对值小于5的都可以进行对决
        for(int i=0;i<=5;i++)
        {
            it=_rankQueue.find(rank+i);
            if(it!=_rankQueue.end())
            {
                other=it->second;
                _rankQueue.erase(it);
                break;
            }
            it=_rankQueue.find(rank-i);
            if(it!=_rankQueue.end())
            {
                other=it->second;
                _rankQueue.erase(it);
                break;
            }
        }
    }
    _log->info("rank 分数：{}",rank);
    if(other==NULL)//没有匹配到用户
    {
        _rankQueue.insert(std::make_pair(rank,s));
        _log->info("当前等候 rank 人数：{}",_rankQueue.size());

    }
    else//找到
    {
        //开始对决
        startRank(s,other);
    }
}

void MyServer::rankAnswerOneQuestion(TcpSocket *s,const Json::Value &inJson)
{
    std::string enemyName=inJson["enemyName"].asString();
    User *user=_users[enemyName];

    Json::Value json;
    json ["cmd"]            =ANSWER;
    json ["enemyscore"]     =inJson["score"].asInt();
    json ["enemyQuestionId"]=inJson["questionId"].asInt();

    writeData(user->getSocket(),json);
}

void MyServer::rankResult(TcpSocket *s,const Json::Value &inJson)
{
    std::unique_lock<std::mutex> lock(_userLock);
    User *user=_users[s->getUserName()];

    int score     =inJson["score"].asInt();
    int enemyscore=inJson["enemyscore"].asInt();

    if(score<enemyscore)
        user->setRank(user->getRank()-1);
    else if(score>enemyscore)
        user->setRank(user->getRank()+1);

    Json::Value json;
    json ["cmd"]     =RANKRESULT;
    json ["newRank"] =_rankMap[user->getRank()];

    writeData(s,json);//发送给客户端
}

void MyServer::initRankMap()
{
    char buf[100]={0};
    int rank=0;
    int num=0;
    for(int i=0;i<100;i++)
    {
        if(i<9)
        {
            rank=i/3;
            num=i%3;
            sprintf(buf,"青铜%d %d颗星",3-rank,num+1);
        }
        else if(9<=i && i<18)
        {
            rank=(i-9)/3;
            num=(i-9)%3;
            sprintf(buf,"白银%d %d颗星",3-rank,num+1);
        }
        else if(9<=i && i<18)
        {
            rank=(i-9)/4;
            num=(i-9)%4;
            sprintf(buf,"黄金%d %d颗星",4-rank,num+1);
        }
        else if(18<=i && i<34)
        {
            rank=(i-18)/4;
            num=(i-18)%4;
            sprintf(buf,"铂金%d %d颗星",4-rank,num+1);
        }
        else if(34<=i && i<50)
        {
            rank=(i-34)/5;
            num=(i-34)%5;
            sprintf(buf,"钻石%d %d颗星",5-rank,num+1);
        }
        else if(50<=i && i<75)
        {
            rank=(i-50)/5;
            num=(i-50)%5;
            sprintf(buf,"星曜%d %d颗星",5-rank,num+1);
        }
        _rankMap.insert(std::make_pair(i,buf));
    }

    /*
    for(int i=0;i<100;i++)
    {
        std::cout<<i<<":"<<_rankMap[i]<<std::endl;
    }
    */

}





























