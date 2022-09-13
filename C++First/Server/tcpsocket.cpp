#include "tcpsocket.h"

TcpServer *TcpSocket::m_tcpServer=NULL;

TcpSocket::TcpSocket(TcpServer *tcpServer,struct bufferevent *bev,char *ip,u_int16_t port)
{
    m_tcpServer=tcpServer;
    m_bev=bev;
    m_ip=ip;
    m_port=port;
}

//可读事件的回调函数
void TcpSocket::readEventCb(struct bufferevent *,void *etc)
{
    TcpSocket *s=(TcpSocket*)etc;
    m_tcpServer->readEvent(s);
}

//可写事件的回调函数
void TcpSocket::writeEventCb(struct bufferevent *,void *etc)
{
    TcpSocket *s=(TcpSocket*)etc;
    m_tcpServer->writeEvent(s);
}

//异常事件的回调函数
void TcpSocket::closeEventCb(struct bufferevent *,short what,void *etc)
{
    TcpSocket *s=(TcpSocket*)etc;
    m_tcpServer->closeEvent(s,what);
    delete s;
}

char *TcpSocket::getIp()
{
    return m_ip;
}

u_int16_t TcpSocket::getPort()
{
    return m_port;
}

//从客户端读数据
int TcpSocket::readDate(void *data,int size)
{

    return bufferevent_read(m_bev,data,size);
}

//向客户端写数据
int TcpSocket::writeDate(const void *data,int size)
{
    return bufferevent_write(m_bev,data,size);
}

void TcpSocket::setUserName(std::string name)
{
    _userName=name;
}

std::string TcpSocket::getUserName()
{
    return _userName;
}


















