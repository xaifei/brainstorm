#ifndef MYSERVER_H
#define MYSERVER_H

#include"tcpserver.h"
#include<spdlog/spdlog.h>
#include"db.h"
#include<json/json.h>
#include<json/reader.h>
#include"../common.h"
#include<string>
#include<map>
#include"user.h"
#define DEBUG
//#define QUESTION_NUM 5

class MyServer:public TcpServer//继承
{
public:
    MyServer();

    void connectEvent(TcpSocket *);

    void readEvent(TcpSocket *);

    void writeEvent(TcpSocket *);

    void closeEvent(TcpSocket *s, short);

private:
    //发送数据
    void writeData(TcpSocket *s,const Json::Value &inJson);

    //用户注册
    void Register(TcpSocket *s,const Json::Value &inJson);

    //用户登录
    void Login(TcpSocket *s,const Json::Value &inJson);

    //获取个人训练题目
    void get_SingleQuestion(TcpSocket *s);

    //进行排位
    void Rank(TcpSocket *s);

    //rank 回答一道问题
    void rankAnswerOneQuestion(TcpSocket *s,const Json::Value &inJson);

    //开始对决
    void startRank(TcpSocket *first,TcpSocket *second);

    //rank结果
    void rankResult(TcpSocket *s, const Json::Value &inJson);

    //初始化rank积分对照表
    void initRankMap();

private:
    std::shared_ptr<spdlog::logger> _log;//记录日志的句柄
    DB* _db;//数据库句柄

    //键是用户名，值是用户指针
    std::mutex _userLock;//锁_Users
    std::map<std::string,User*> _users;    //在线用户列表

    //key : rank积分
    //值  : 对应的段位说明
    std::map<int,std::string> _rankMap;    //rank积分比对表

    //key   : rank积分
    //value : 参与rank的用户socket句柄
    std::mutex _rankLock;
    std::map<int,TcpSocket*> _rankQueue;   //等待排位的队列
};

#endif // MYSERVER_H
