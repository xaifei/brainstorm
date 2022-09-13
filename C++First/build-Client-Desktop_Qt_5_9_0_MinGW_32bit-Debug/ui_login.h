/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *LogButton;
    QPushButton *RegButton;
    QLabel *Userlabel;
    QLineEdit *UserlineEdit;
    QLineEdit *PasswdlineEdit;
    QLabel *Passwdlabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(517, 379);
        LogButton = new QPushButton(Widget);
        LogButton->setObjectName(QStringLiteral("LogButton"));
        LogButton->setGeometry(QRect(109, 229, 131, 31));
        RegButton = new QPushButton(Widget);
        RegButton->setObjectName(QStringLiteral("RegButton"));
        RegButton->setGeometry(QRect(283, 229, 121, 31));
        Userlabel = new QLabel(Widget);
        Userlabel->setObjectName(QStringLiteral("Userlabel"));
        Userlabel->setGeometry(QRect(99, 109, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        Userlabel->setFont(font);
        Userlabel->setAlignment(Qt::AlignCenter);
        UserlineEdit = new QLineEdit(Widget);
        UserlineEdit->setObjectName(QStringLiteral("UserlineEdit"));
        UserlineEdit->setGeometry(QRect(210, 110, 191, 31));
        PasswdlineEdit = new QLineEdit(Widget);
        PasswdlineEdit->setObjectName(QStringLiteral("PasswdlineEdit"));
        PasswdlineEdit->setGeometry(QRect(209, 169, 191, 31));
        Passwdlabel = new QLabel(Widget);
        Passwdlabel->setObjectName(QStringLiteral("Passwdlabel"));
        Passwdlabel->setGeometry(QRect(99, 169, 91, 31));
        Passwdlabel->setFont(font);
        Passwdlabel->setAlignment(Qt::AlignCenter);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        LogButton->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", Q_NULLPTR));
        RegButton->setText(QApplication::translate("Widget", "\346\263\250\345\206\214", Q_NULLPTR));
        Userlabel->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        Passwdlabel->setText(QApplication::translate("Widget", "\345\257\206  \347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
