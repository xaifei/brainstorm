/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *RegNButton;
    QLineEdit *UserlineEdit;
    QLineEdit *PasswdlineEdit;
    QPushButton *BackButton;
    QLabel *Userlabel;
    QLabel *Passwdlabel;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(489, 382);
        RegNButton = new QPushButton(Register);
        RegNButton->setObjectName(QStringLiteral("RegNButton"));
        RegNButton->setGeometry(QRect(90, 210, 291, 31));
        UserlineEdit = new QLineEdit(Register);
        UserlineEdit->setObjectName(QStringLiteral("UserlineEdit"));
        UserlineEdit->setGeometry(QRect(171, 91, 211, 31));
        PasswdlineEdit = new QLineEdit(Register);
        PasswdlineEdit->setObjectName(QStringLiteral("PasswdlineEdit"));
        PasswdlineEdit->setGeometry(QRect(170, 150, 211, 31));
        BackButton = new QPushButton(Register);
        BackButton->setObjectName(QStringLiteral("BackButton"));
        BackButton->setGeometry(QRect(90, 260, 291, 31));
        Userlabel = new QLabel(Register);
        Userlabel->setObjectName(QStringLiteral("Userlabel"));
        Userlabel->setGeometry(QRect(80, 90, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        Userlabel->setFont(font);
        Userlabel->setAlignment(Qt::AlignCenter);
        Passwdlabel = new QLabel(Register);
        Passwdlabel->setObjectName(QStringLiteral("Passwdlabel"));
        Passwdlabel->setGeometry(QRect(80, 150, 91, 31));
        Passwdlabel->setFont(font);
        Passwdlabel->setAlignment(Qt::AlignCenter);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        RegNButton->setText(QApplication::translate("Register", "\347\253\213\345\215\263\346\263\250\345\206\214", Q_NULLPTR));
        BackButton->setText(QApplication::translate("Register", "\350\277\224\345\233\236", Q_NULLPTR));
        Userlabel->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        Passwdlabel->setText(QApplication::translate("Register", "\345\257\206  \347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
