#include "login.h"
#include "ui_widget.h"
#include"register.h"
#include<QMessageBox>
#include"brainstorm.h"
#include"../common.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    _com=new Communicate();

    connect(_com,SIGNAL(login(QJsonObject)),this,SLOT(login(QJsonObject)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_LogButton_clicked()
{
    QString userName=ui->UserlineEdit->text();
    QString passwd=ui->PasswdlineEdit->text();

    //将登录信息发送给服务器
    QJsonObject json;
    json["cmd"]=LOGIN;
    json["userName"]=userName;
    json["passwd"]=passwd;

    //给服务器发送数据
    _com->writeData(json);


}

void Widget::login(QJsonObject json)
{
    int result=json["result"].toInt();
    switch (result)
    {
    case OK:
    {
        this->hide();
        BrainStorm *dlg=new BrainStorm(_com,json);
        dlg->show();
        dlg->setAttribute(Qt::WA_DeleteOnClose);//属性，把new出来的自己销毁
        break;
    }
    case ERROR:
        QMessageBox::critical(this,"登录","登录失败,未知错误");
        break;
    case USERLOGIN:
        QMessageBox::critical(this,"登录","登录失败,不允许重复登录");
        break;
    case NAMEORPASSWD:
        QMessageBox::critical(this,"登录","用户名或密码错误");
        break;
    default:
        break;
    }
}

void Widget::on_RegButton_clicked()
{
    this->hide();
    Register reg(_com);
    reg.exec();
    this->show();
}
