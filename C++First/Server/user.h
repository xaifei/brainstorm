#ifndef USER_H
#define USER_H
#include<string>
#include"tcpsocket.h"

class User
{
public:
    User(std::string n,std::string p,int rank,TcpSocket *s);

    TcpSocket *getSocket();
    const char *getName();

    int getRank();

    void setRank(int rank);

private:
    std::string _userName;  //用户名
    std::string _passwd;    //用户密码
    int _rank;             //rank分数


    TcpSocket *_s;          //通信类套接字
};

#endif // USER_H
