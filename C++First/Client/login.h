#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"register.h"
#include"communicate.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_LogButton_clicked();

    void on_RegButton_clicked();

    void login(QJsonObject json);

private:
    Ui::Widget *ui;

    Communicate *_com;//通信类指针，负责和服务器通信
};

#endif // WIDGET_H
