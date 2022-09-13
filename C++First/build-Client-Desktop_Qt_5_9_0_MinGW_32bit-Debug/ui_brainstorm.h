/********************************************************************************
** Form generated from reading UI file 'brainstorm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRAINSTORM_H
#define UI_BRAINSTORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrainStorm
{
public:
    QStackedWidget *stackedWidget;
    QWidget *MainMenu;
    QPushButton *RankButton;
    QPushButton *SingleButton;
    QWidget *SingleMenu;
    QPushButton *SingleStart;
    QPushButton *SingleBack;
    QLabel *label;
    QLabel *label_2;
    QWidget *SingleRuning;
    QLabel *SingleQuestion;
    QLCDNumber *lcdNumber;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *SingleButtonA;
    QPushButton *SingleButtonB;
    QPushButton *SingleButtonC;
    QPushButton *SingleButtonD;
    QWidget *SingleScore;
    QLabel *Singleresult;
    QPushButton *OverBack;
    QLabel *Singlescore;
    QWidget *RankWait;
    QLabel *label_3;
    QWidget *RankRunning;
    QLabel *RankQuestion;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *RankButtonA;
    QPushButton *RankButtonB;
    QPushButton *RankButtonC;
    QPushButton *RankButtonD;
    QLCDNumber *lcdNumber_2;
    QLabel *enemyStatus;
    QLabel *selfStatus;
    QWidget *RankResult;
    QLabel *rankResult;
    QPushButton *overButton;
    QLabel *newRank;

    void setupUi(QDialog *BrainStorm)
    {
        if (BrainStorm->objectName().isEmpty())
            BrainStorm->setObjectName(QStringLiteral("BrainStorm"));
        BrainStorm->resize(450, 639);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\347\262\227\351\273\221\345\256\213\347\256\200\344\275\223"));
        BrainStorm->setFont(font);
        stackedWidget = new QStackedWidget(BrainStorm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 431, 621));
        MainMenu = new QWidget();
        MainMenu->setObjectName(QStringLiteral("MainMenu"));
        RankButton = new QPushButton(MainMenu);
        RankButton->setObjectName(QStringLiteral("RankButton"));
        RankButton->setGeometry(QRect(140, 70, 151, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        RankButton->setFont(font1);
        SingleButton = new QPushButton(MainMenu);
        SingleButton->setObjectName(QStringLiteral("SingleButton"));
        SingleButton->setGeometry(QRect(140, 130, 151, 41));
        SingleButton->setFont(font1);
        stackedWidget->addWidget(MainMenu);
        SingleMenu = new QWidget();
        SingleMenu->setObjectName(QStringLiteral("SingleMenu"));
        SingleStart = new QPushButton(SingleMenu);
        SingleStart->setObjectName(QStringLiteral("SingleStart"));
        SingleStart->setGeometry(QRect(150, 490, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(12);
        SingleStart->setFont(font2);
        SingleBack = new QPushButton(SingleMenu);
        SingleBack->setObjectName(QStringLiteral("SingleBack"));
        SingleBack->setGeometry(QRect(150, 550, 121, 31));
        SingleBack->setFont(font2);
        label = new QLabel(SingleMenu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 170, 411, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(36);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(SingleMenu);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 240, 151, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(11);
        label_2->setFont(font4);
        label_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(SingleMenu);
        SingleRuning = new QWidget();
        SingleRuning->setObjectName(QStringLiteral("SingleRuning"));
        SingleQuestion = new QLabel(SingleRuning);
        SingleQuestion->setObjectName(QStringLiteral("SingleQuestion"));
        SingleQuestion->setGeometry(QRect(10, 110, 411, 161));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font5.setPointSize(14);
        SingleQuestion->setFont(font5);
        SingleQuestion->setAlignment(Qt::AlignCenter);
        SingleQuestion->setWordWrap(true);
        lcdNumber = new QLCDNumber(SingleRuning);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(180, 10, 71, 61));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font6.setPointSize(14);
        lcdNumber->setFont(font6);
        layoutWidget = new QWidget(SingleRuning);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 400, 411, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SingleButtonA = new QPushButton(layoutWidget);
        SingleButtonA->setObjectName(QStringLiteral("SingleButtonA"));

        verticalLayout->addWidget(SingleButtonA);

        SingleButtonB = new QPushButton(layoutWidget);
        SingleButtonB->setObjectName(QStringLiteral("SingleButtonB"));

        verticalLayout->addWidget(SingleButtonB);

        SingleButtonC = new QPushButton(layoutWidget);
        SingleButtonC->setObjectName(QStringLiteral("SingleButtonC"));

        verticalLayout->addWidget(SingleButtonC);

        SingleButtonD = new QPushButton(layoutWidget);
        SingleButtonD->setObjectName(QStringLiteral("SingleButtonD"));

        verticalLayout->addWidget(SingleButtonD);

        stackedWidget->addWidget(SingleRuning);
        SingleScore = new QWidget();
        SingleScore->setObjectName(QStringLiteral("SingleScore"));
        Singleresult = new QLabel(SingleScore);
        Singleresult->setObjectName(QStringLiteral("Singleresult"));
        Singleresult->setGeometry(QRect(10, 70, 411, 121));
        QFont font7;
        font7.setPointSize(36);
        Singleresult->setFont(font7);
        Singleresult->setAlignment(Qt::AlignCenter);
        OverBack = new QPushButton(SingleScore);
        OverBack->setObjectName(QStringLiteral("OverBack"));
        OverBack->setGeometry(QRect(10, 560, 411, 31));
        QFont font8;
        font8.setPointSize(12);
        OverBack->setFont(font8);
        Singlescore = new QLabel(SingleScore);
        Singlescore->setObjectName(QStringLiteral("Singlescore"));
        Singlescore->setGeometry(QRect(10, 230, 411, 121));
        QFont font9;
        font9.setPointSize(18);
        Singlescore->setFont(font9);
        Singlescore->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(SingleScore);
        RankWait = new QWidget();
        RankWait->setObjectName(QStringLiteral("RankWait"));
        label_3 = new QLabel(RankWait);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 170, 411, 81));
        QFont font10;
        font10.setPointSize(22);
        label_3->setFont(font10);
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(RankWait);
        RankRunning = new QWidget();
        RankRunning->setObjectName(QStringLiteral("RankRunning"));
        RankQuestion = new QLabel(RankRunning);
        RankQuestion->setObjectName(QStringLiteral("RankQuestion"));
        RankQuestion->setGeometry(QRect(10, 180, 411, 161));
        RankQuestion->setFont(font5);
        RankQuestion->setAlignment(Qt::AlignCenter);
        RankQuestion->setWordWrap(true);
        layoutWidget_2 = new QWidget(RankRunning);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 400, 411, 211));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        RankButtonA = new QPushButton(layoutWidget_2);
        RankButtonA->setObjectName(QStringLiteral("RankButtonA"));

        verticalLayout_2->addWidget(RankButtonA);

        RankButtonB = new QPushButton(layoutWidget_2);
        RankButtonB->setObjectName(QStringLiteral("RankButtonB"));

        verticalLayout_2->addWidget(RankButtonB);

        RankButtonC = new QPushButton(layoutWidget_2);
        RankButtonC->setObjectName(QStringLiteral("RankButtonC"));

        verticalLayout_2->addWidget(RankButtonC);

        RankButtonD = new QPushButton(layoutWidget_2);
        RankButtonD->setObjectName(QStringLiteral("RankButtonD"));

        verticalLayout_2->addWidget(RankButtonD);

        lcdNumber_2 = new QLCDNumber(RankRunning);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(230, 40, 141, 91));
        enemyStatus = new QLabel(RankRunning);
        enemyStatus->setObjectName(QStringLiteral("enemyStatus"));
        enemyStatus->setGeometry(QRect(30, 40, 211, 31));
        enemyStatus->setFont(font8);
        enemyStatus->setAlignment(Qt::AlignCenter);
        selfStatus = new QLabel(RankRunning);
        selfStatus->setObjectName(QStringLiteral("selfStatus"));
        selfStatus->setGeometry(QRect(30, 100, 211, 31));
        selfStatus->setFont(font8);
        selfStatus->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(RankRunning);
        RankResult = new QWidget();
        RankResult->setObjectName(QStringLiteral("RankResult"));
        rankResult = new QLabel(RankResult);
        rankResult->setObjectName(QStringLiteral("rankResult"));
        rankResult->setGeometry(QRect(10, 100, 411, 91));
        QFont font11;
        font11.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font11.setPointSize(48);
        rankResult->setFont(font11);
        rankResult->setAlignment(Qt::AlignCenter);
        overButton = new QPushButton(RankResult);
        overButton->setObjectName(QStringLiteral("overButton"));
        overButton->setGeometry(QRect(10, 570, 411, 41));
        QFont font12;
        font12.setPointSize(14);
        overButton->setFont(font12);
        newRank = new QLabel(RankResult);
        newRank->setObjectName(QStringLiteral("newRank"));
        newRank->setGeometry(QRect(10, 270, 401, 201));
        QFont font13;
        font13.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\273\206\351\273\221"));
        font13.setPointSize(20);
        newRank->setFont(font13);
        newRank->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(RankResult);

        retranslateUi(BrainStorm);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BrainStorm);
    } // setupUi

    void retranslateUi(QDialog *BrainStorm)
    {
        BrainStorm->setWindowTitle(QApplication::translate("BrainStorm", "Dialog", Q_NULLPTR));
        RankButton->setText(QApplication::translate("BrainStorm", "\346\216\222\344\275\215\350\265\233", Q_NULLPTR));
        SingleButton->setText(QApplication::translate("BrainStorm", "\344\270\252\344\272\272\350\256\255\347\273\203\350\265\233", Q_NULLPTR));
        SingleStart->setText(QApplication::translate("BrainStorm", "\345\274\200\345\247\213\347\255\224\351\242\230", Q_NULLPTR));
        SingleBack->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("BrainStorm", "\350\277\236\347\273\255\347\255\224\345\257\271\344\272\224\351\201\223\351\242\230", Q_NULLPTR));
        label_2->setText(QApplication::translate("BrainStorm", "\347\255\224\351\224\231\347\246\273\345\234\272\357\274\214\347\255\224\345\257\271\347\273\247\347\273\255", Q_NULLPTR));
        SingleQuestion->setText(QApplication::translate("BrainStorm", "QUESTION", Q_NULLPTR));
        SingleButtonA->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        SingleButtonB->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        SingleButtonC->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        SingleButtonD->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        Singleresult->setText(QApplication::translate("BrainStorm", "TextLabel", Q_NULLPTR));
        OverBack->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        Singlescore->setText(QApplication::translate("BrainStorm", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("BrainStorm", "\346\255\243\345\234\250\345\214\271\351\205\215\345\257\271\346\211\213......", Q_NULLPTR));
        RankQuestion->setText(QString());
        RankButtonA->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        RankButtonB->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        RankButtonC->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        RankButtonD->setText(QApplication::translate("BrainStorm", "PushButton", Q_NULLPTR));
        enemyStatus->setText(QApplication::translate("BrainStorm", "xch \351\273\204\351\207\2211 1\351\242\227\346\230\237\357\274\232120\345\210\206", Q_NULLPTR));
        selfStatus->setText(QApplication::translate("BrainStorm", "xaf \351\273\204\351\207\2211 1\351\242\227\346\230\237\357\274\232140\345\210\206", Q_NULLPTR));
        rankResult->setText(QApplication::translate("BrainStorm", "\350\203\234\345\210\251", Q_NULLPTR));
        overButton->setText(QApplication::translate("BrainStorm", "\350\277\224\345\233\236", Q_NULLPTR));
        newRank->setText(QApplication::translate("BrainStorm", "\351\273\204\351\207\2211 1\351\242\227\346\230\237 ---> \351\273\204\351\207\2211 3\351\242\227\346\230\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrainStorm: public Ui_BrainStorm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRAINSTORM_H
