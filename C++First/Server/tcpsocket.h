#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include"tcpserver.h"
#include<string>

class TcpServer;

//通信类，负责与客户端进行通信
class TcpSocket
{

public:
    TcpSocket(TcpServer *tcpServer, struct bufferevent *bev, char *ip, u_int16_t port);

    //可读事件的回调函数
    static void readEventCb(struct bufferevent *bev,void *etc);
    //可写事件的回调函数
    static void writeEventCb(struct bufferevent *bev,void *etc);
    //异常事件的回调函数
    static void closeEventCb(struct bufferevent *bev,short what,void *etc);

    char *getIp();//获取IP地址
    u_int16_t getPort();//获取端口

    //从客户端读数据
    int readDate(void *data, int size);
    //向客户端写数据
    int writeDate(const void *data, int size);

    void setUserName(std::string name);
    std::string getUserName();

private:
    static TcpServer *m_tcpServer;//服务器类对象。需要初始化
    struct bufferevent *m_bev;//通信用的句柄,用来与客户端通信
    char *m_ip;              //客户端的IP地址
    u_int16_t m_port;       //客户端的端口

    std::string _userName;//当前使用他这个用户
};

#endif // TCPSOCKET_H
