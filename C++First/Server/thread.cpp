#include "thread.h"

Thread::Thread()
{
    m_base=event_base_new();
    if(!m_base)
    {
        printf("Couldn't creat an event_base:exiting\n");
        exit(-1);
    }
    //在构造函数里创建管道
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("fork");
        exit(-1);
    }
    //管道的读写端
    m_pipeReadFd=fd[0];
    m_pipeWriteFd=fd[1];

    //让管道事件监听管道的读端
    //如果监听到，管道的读端有数据可读
    //EV_READ:监听管道是否有可读事件
    //EV_PERSIST:让事件永久有效，不然读完一次下次就不监听了
    //pipeRead：管道事件来了之后自动调用这个函数，类似于槽函数
    event_set(&m_pipeEvent,m_pipeReadFd,EV_READ | EV_PERSIST,pipeRead,this);

    //将事件添加到m_base集合中
    event_base_set(m_base,&m_pipeEvent);

    //开始事件的监听
    event_add(&m_pipeEvent,0);

}

void Thread::pipeRead(int, short, void *)
{

}

void Thread::start()
{
    //创建线程
    pthread_create(&m_threadId,NULL,worker,this);
    //线程分离
    pthread_detach(m_threadId);
}

void* Thread::worker(void* arg)
{
    Thread* p=(Thread*)arg;
    p->run();       //
    return NULL;
}

void Thread::run()
{
/*测试用的
    while(1)
    {
        printf("thread:%d\n",m_threadId);
        sleep(2);
    }
*/
    //printf("%d:start\n",m_threadId);
    //监听base事件集合
    //dispatch是一个死循环,一直监听。用来处理事件，类似于qt的exec（）
    //如果m_base集合是空的，则event_base_dispatch不运行会立马返回
    //初始化的时候需要给m_base添加一个事件，让它不空
    event_base_dispatch(m_base);
    event_base_free(m_base);

    //printf("%d:done\n",m_threadId);
}

struct event_base *Thread::getBase()
{
    return m_base;
}












