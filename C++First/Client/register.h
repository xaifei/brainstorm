#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include<QJsonObject>
#include"communicate.h"
#include"../common.h"

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(Communicate *com,QWidget *parent = 0);
    ~Register();

private slots:
    void on_RegNButton_clicked();

    void on_BackButton_clicked();

    void rstResult(int);

private:
    Ui::Register *ui;
    Communicate *_com;
};

#endif // REGISTER_H
