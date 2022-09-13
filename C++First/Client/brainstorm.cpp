#include "brainstorm.h"
#include "ui_brainstorm.h"

BrainStorm::BrainStorm(Communicate *com, QJsonObject &json, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrainStorm)
{
    ui->setupUi(this);
    _com=com;

    _userName=json["userName"].toString();
    _userRank=json["rank"].toString();

    connect(&_singleTimer,SIGNAL(timeout()),this,SLOT(SingleTimerOut()));
    connect(&_rankTimer,SIGNAL(timeout()),this,SLOT(RankTimerOut()));

    connect(_com,SIGNAL(receiveSingleQuestion(QJsonObject)),this,SLOT(receiveSingleQuestion(QJsonObject)));
    connect(_com,SIGNAL(Rank(QJsonObject)),this,SLOT(Rank(QJsonObject)));

}

BrainStorm::~BrainStorm()
{
    delete ui;
}

//进入个人训练赛
void BrainStorm::on_SingleButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->SingleMenu);
}

//个人训练计时器
void BrainStorm::SingleTimerOut()
{
    --_singleSec;
    if(_singleSec==0)
    {
        ui->Singleresult->setText("回答错误");
        QString str=QString("本次得分：%1").arg(_singleScore);
        ui->Singlescore->setText(str);
        _singleTimer.stop();
        ui->stackedWidget->setCurrentWidget(ui->SingleScore);
    }
    ui->lcdNumber->display(_singleSec);

}

//单人训练，从服务器获取题目
void BrainStorm::getSingleQuestion()
{
    QJsonObject json;
    json["cmd"]=SINGLE_QUESTION;

    _com->writeData(json);

}

//单人训练设置问题
void BrainStorm::SingleSetQuestion()
{
    //题目结束
    if(_currentSingleQuestion==QUESTION_NUM)
    {
        ui->Singleresult->setText("恭喜全部答对");
        QString str=QString("本次得分：%1").arg(_singleScore);
        ui->Singlescore->setText(str);
        ui->stackedWidget->setCurrentWidget(ui->SingleScore);
        _singleTimer.stop();
        return;
    }
    ui->SingleQuestion->setText(_singleQuestion["question"].toArray().at(_currentSingleQuestion).toString());
    ui->SingleButtonA->setText(_singleQuestion["selectionA"].toArray().at(_currentSingleQuestion).toString());
    ui->SingleButtonB->setText(_singleQuestion["selectionB"].toArray().at(_currentSingleQuestion).toString());
    ui->SingleButtonC->setText(_singleQuestion["selectionC"].toArray().at(_currentSingleQuestion).toString());
    ui->SingleButtonD->setText(_singleQuestion["selectionD"].toArray().at(_currentSingleQuestion).toString());
}

//单人训练答题
void BrainStorm::SingleAnswerQuestion(int select)
{
    //回答正确
    if(select==_singleQuestion["answer"].toArray().at(_currentSingleQuestion).toString().toInt())
    {
        _singleScore +=20*_singleSec;
        _currentSingleQuestion++;
        SingleSetQuestion();  //设置下一题
        _singleSec=10;
        _singleTimer.stop();
        ui->lcdNumber->display(_singleSec);
        _singleTimer.start(1000);
    }
    else//回答错误
    {
        ui->Singleresult->setText("回答错误");
        QString str=QString("本次得分：%1").arg(_singleScore);
        ui->Singlescore->setText(str);
        ui->stackedWidget->setCurrentWidget(ui->SingleScore);
        _singleTimer.stop();
    }
}

//单人训练从服务器接收到题目
void BrainStorm::receiveSingleQuestion(QJsonObject json)
{
    _singleQuestion=json;
    _singleSec=10;
    _currentSingleQuestion=0;
    _singleScore=0;

    ui->lcdNumber->display(_singleSec);
    SingleSetQuestion();

    //开启定时器
    _singleTimer.start(1000);

    ui->stackedWidget->setCurrentWidget(ui->SingleRuning);
}

//从个人训练返回
void BrainStorm::on_SingleBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->MainMenu);
}

//个人训练赛开始答题
void BrainStorm::on_SingleStart_clicked()
{
    getSingleQuestion();
}

void BrainStorm::on_OverBack_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->MainMenu);
}

void BrainStorm::on_SingleButtonA_clicked()
{
    SingleAnswerQuestion(1);
}

void BrainStorm::on_SingleButtonB_clicked()
{
    SingleAnswerQuestion(2);
}

void BrainStorm::on_SingleButtonC_clicked()
{
    SingleAnswerQuestion(3);
}

void BrainStorm::on_SingleButtonD_clicked()
{
    SingleAnswerQuestion(4);
}

//--------------------------------------rank------------------------------------------

//排位赛
void BrainStorm::on_RankButton_clicked()
{
    QJsonObject json;
    json["cmd"]=RANK;

    _com->writeData(json);

    //跳到等待页面
    ui->stackedWidget->setCurrentWidget(ui->RankWait);
}

void BrainStorm::RankTimerOut()
{
    _rankSec--;
    if(_rankSec==0)
    {
        if(ui->RankButtonA->isEnabled())//判断随便一个按钮状态
        {
            _currentRankQuestion++;
        }
        rankSetQuestion();
        _rankSec=10;
    }
    ui->lcdNumber_2->display(_rankSec);
}

void BrainStorm::setEnemyScore()
{
    QString str=QString("%1(%2):%3").arg(_enemyName,-5).arg(_enemyRank).arg(_enemyScore);
    ui->enemyStatus->setText(str);
}

void BrainStorm::setSelfScore()
{
    QString str=QString("%1(%2):%3").arg(_userName,-5).arg(_userRank).arg(_myScore);
    ui->selfStatus->setText(str);
}

void BrainStorm::rankSetQuestion()
{
    ui->RankQuestion->setText(_rankQuestion["question"].toArray().at(_currentRankQuestion).toString());
    ui->RankButtonA->setText(_rankQuestion["selectionA"].toArray().at(_currentRankQuestion).toString());
    ui->RankButtonB->setText(_rankQuestion["selectionB"].toArray().at(_currentRankQuestion).toString());
    ui->RankButtonC->setText(_rankQuestion["selectionC"].toArray().at(_currentRankQuestion).toString());
    ui->RankButtonD->setText(_rankQuestion["selectionD"].toArray().at(_currentRankQuestion).toString());

    ui->RankButtonA->setEnabled(true);
    ui->RankButtonB->setEnabled(true);
    ui->RankButtonC->setEnabled(true);
    ui->RankButtonD->setEnabled(true);

    ui->RankButtonA->setStyleSheet("");
    ui->RankButtonB->setStyleSheet("");
    ui->RankButtonC->setStyleSheet("");
    ui->RankButtonD->setStyleSheet("");

    if(_currentRankQuestion==QUESTION_NUM)
    {
        _rankTimer.stop();
        //将结果发给服务器
        QJsonObject json;
        json["cmd"]       =RANKRESULT;
        json["score"]     =_myScore;
        json["enemyName"] =_enemyName;
        json["enemyScore"]=_enemyScore;

        _com->writeData(json);
    }
}

void BrainStorm::rankSetResult(QJsonObject &json)
{
    QString newRank=json["newRank"].toString();
    if(_myScore==_enemyScore)
        ui->rankResult->setText("平局");
    else if(_myScore<_enemyScore)
        ui->rankResult->setText("失败");
    else if(_myScore>_enemyScore)
        ui->rankResult->setText("成功");

    QString str=QString("%1 ---> %2").arg(_userRank).arg(newRank);
    ui->newRank->setText(str);
    _userRank=newRank;

    ui->stackedWidget->setCurrentWidget(ui->RankResult);
}

void BrainStorm::Rank(QJsonObject json)
{
    int cmd=json["cmd"].toInt();
    if(cmd==RANK)
    {
        _rankQuestion=json["question"].toObject();
        _enemyName   =json["enemyName"].toString();
        _enemyRank   =json["enemyRank"].toString();
        _enemyScore  =json["enemyScore"].toInt();

        _rankSec=10;
        _myScore=0;
        ui->lcdNumber_2->display(_rankSec);

        _currentRankQuestion=0;
        _enemyRankQuestion  =0;

        setEnemyScore();
        setSelfScore();
        rankSetQuestion();

        _rankTimer.start(1000);

        ui->stackedWidget->setCurrentWidget(ui->RankRunning);
    }
    else if(cmd==ANSWER)//同步答题
    {
        _enemyScore       =json["enemyscore"].toInt();
        _enemyRankQuestion=json["enemyQuestionId"].toInt();
        setEnemyScore();

        if(_currentRankQuestion==_enemyRankQuestion)
        {
            _rankSec=10;
            _rankTimer.stop();
            ui->lcdNumber_2->display(_rankSec);
            _rankTimer.start(1000);
            rankSetQuestion();
        }
    }
    else if(cmd==RANKRESULT)
    {
        rankSetResult(json);
    }
}

void BrainStorm::RankAnswerQuestion(int select)
{
    //计算得分
    if(select==_rankQuestion["answer"].toArray().at(_currentRankQuestion).toString().toInt())
        _myScore +=20*_rankSec;
    setSelfScore();
    _currentRankQuestion++;
    //判断是否跳到下一题
    if(_currentRankQuestion==_enemyRankQuestion)
    {
        _rankSec=10;
        _rankTimer.stop();
        ui->lcdNumber_2->display(_rankSec);
        _rankTimer.start(1000);
        rankSetQuestion();
    }

    QJsonObject json;
    json["cmd"]      =ANSWER;
    json["enemyName"]=_enemyName;
    json["score"]    =_myScore;
    json["questionId"] =_currentRankQuestion;

    _com->writeData(json);//发送给服务器
}

void BrainStorm::on_RankButtonA_clicked()
{
    ui->RankButtonA->setStyleSheet("background-color:rgb(255, 0, 0)");
    ui->RankButtonA->setEnabled(false);
    ui->RankButtonB->setEnabled(false);
    ui->RankButtonC->setEnabled(false);
    ui->RankButtonD->setEnabled(false);
    RankAnswerQuestion(1);
}

void BrainStorm::on_RankButtonB_clicked()
{
    ui->RankButtonB->setStyleSheet("background-color:rgb(255, 0, 0)");
    ui->RankButtonA->setEnabled(false);
    ui->RankButtonB->setEnabled(false);
    ui->RankButtonC->setEnabled(false);
    ui->RankButtonD->setEnabled(false);
    RankAnswerQuestion(2);
}

void BrainStorm::on_RankButtonC_clicked()
{
    ui->RankButtonC->setStyleSheet("background-color:rgb(255, 0, 0)");
    ui->RankButtonA->setEnabled(false);
    ui->RankButtonB->setEnabled(false);
    ui->RankButtonC->setEnabled(false);
    ui->RankButtonD->setEnabled(false);
    RankAnswerQuestion(3);
}

void BrainStorm::on_RankButtonD_clicked()
{
    ui->RankButtonD->setStyleSheet("background-color:rgb(255, 0, 0)");
    ui->RankButtonA->setEnabled(false);
    ui->RankButtonB->setEnabled(false);
    ui->RankButtonC->setEnabled(false);
    ui->RankButtonD->setEnabled(false);
    RankAnswerQuestion(4);
}

void BrainStorm::on_overButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->MainMenu);
}
