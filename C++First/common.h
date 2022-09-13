#ifndef COMMON_H
#define COMMON_H



//5xxx 用户操作指令
#define OK                   5000  
#define REGISTER             5001  //注册
#define LOGIN                5002  //登录
#define SINGLE_QUESTION      5003  //个人训练获取题目
#define RANK                 5004  //进行排位
#define ANSWER               5005  //排位回答一个问题
#define RANKRESULT           5006  //rank结束,发送对决结果



//8xxx 错误
#define ERROR          8001  //未知错误
#define USEREXIST      8002  //用户已经存在
#define NAMEORPASSWD   8003  //用户名或者密码错误
#define USERLOGIN      8004  //用户已经连接



//其他
#define QUESTION_NUM 5 



#endif // COMMON_H
