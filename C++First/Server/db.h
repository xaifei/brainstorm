#ifndef DB_H
#define DB_H
#include"mysql/mysql.h"
#include<mutex>
#include<spdlog/spdlog.h>
#include<json/json.h>

class DB
{
public:
    DB(const char *host,const char *userName,const char *passwd,const char *dbName);
    //执行数据库语句
    bool db_exec(const char *sql);

    //数据库查询
    //[in] sql        查询语句
    //[out] outJson   查询结果到json变量中
    bool db_select(const char *sql,Json::Value &outJson);



private:
    std::mutex _mutex;//数据库句柄互斥锁
    MYSQL *_mysql;//数据库
};

#endif // DB_H
