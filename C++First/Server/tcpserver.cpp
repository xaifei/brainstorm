#include "tcpserver.h"

TcpServer::TcpServer(int threadNum):m_nextThread(0)//下标初始化为0
{
    if(threadNum<=0)
    {
        printf("threadNum<=0");
        exit(-1);
    }
    m_threadNum=threadNum;
    m_threadPool=new Thread[threadNum];
    if(m_threadPool==NULL)
    {
        printf("create threadPool error\n");
        exit(-1);
    }
    m_base=event_base_new();
    if(!m_base)
    {
        printf("Could not initialize libevent!\n");
        exit(-1);
    }
}

//evutil_socket_t fd:   与客户端通信的文件描述符
//struct sockaddr *clientAdd:  客户端的IP地址，地址信息。
void TcpServer::listenCb(struct evconnlistener *,evutil_socket_t fd,struct sockaddr *clientAdd,int ,void *data)
{
    TcpServer *p=(TcpServer*)data;
    p->listenEvent(fd,(struct sockaddr_in *)clientAdd);
}

void TcpServer::listenEvent(evutil_socket_t fd,struct sockaddr_in *clientAdd)
{
    char *ip     =inet_ntoa(clientAdd->sin_addr);//客户端的IP地址
    uint16_t port=ntohs(clientAdd->sin_port);//客户端的使用的端口

    //从线程池中选择一个线程去处理客户端的请求
    //以论寻的方式选择线程
    struct event_base *base=m_threadPool[m_nextThread].getBase();
    m_nextThread=(m_nextThread+1) % m_threadNum;

    //base监测fd
    struct bufferevent *bev=bufferevent_socket_new(base,fd,BEV_OPT_CLOSE_ON_FREE);
    if(!bev)
    {
        fprintf(stderr,"Error constructing bufferevent!");
        event_base_loopbreak(base);
        return;
    }

    //创建一个对象
    TcpSocket *s=new TcpSocket(this,bev,ip,port);

    //单独封装一个类负责和客户端的通信

    bufferevent_setcb(bev,s->readEventCb,s->writeEventCb,s->closeEventCb,s);
    bufferevent_enable(bev,EV_WRITE);//打开是否可写
    bufferevent_enable(bev,EV_READ);//打开是否可读
    bufferevent_enable(bev,EV_SIGNAL);

    //调用客户端连接函数
    connectEvent(s);
}

int TcpServer::listen(int port,const char *ip)
{
    struct sockaddr_in sin;
    memset(&sin,0,sizeof(sin));
    sin.sin_family=AF_INET;
    sin.sin_port=htons(port);
    if(ip!=NULL)
        inet_aton(ip,&sin.sin_addr);

    m_listener=evconnlistener_new_bind(m_base,listenCb,this,LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,-1,(struct sockaddr*)&sin,sizeof(sin));
    if(!m_listener)
    {
        printf("Could not create a listener!\n");
        return -1;
    }

    //开启线程池
    for(int i=0;i<m_threadNum;i++)
    {
        m_threadPool[i].start();
        printf("线程 %d 启动\n",i+1);
    }
    return 0;
}

void TcpServer::start()
{
    event_base_dispatch(m_base);
    evconnlistener_free(m_listener);
    event_base_free(m_base);
    printf("done\n");
}




















