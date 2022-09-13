#include <iostream>
#include"thread.h"
#include"tcpserver.h"
#include"myserver.h"

using namespace std;

int main1()
{
    Thread *pt1=new Thread;
    Thread *pt2=new Thread;

    pt1->start();
    pt2->start();

    while(1)
    {
        printf("1111\n");
        sleep(1);
    }
    return 0;
}

int main2()
{
    TcpServer s;
    s.listen(9999);
    s.start();
    return 0;
}

int main()
{
    MyServer s;
    s.listen(9999);
    s.start();
    return 0;
}
















