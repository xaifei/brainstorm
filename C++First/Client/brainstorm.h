#ifndef BRAINSTORM_H
#define BRAINSTORM_H

#include <QDialog>
#include"communicate.h"
#include<QJsonObject>
#include<QTimer>

namespace Ui {
class BrainStorm;
}

class BrainStorm : public QDialog
{
    Q_OBJECT

public:
    explicit BrainStorm(Communicate *_com,QJsonObject &json,QWidget *parent = 0);
    ~BrainStorm();

private:
    //单人训练，从服务器获取题目
    void getSingleQuestion();

    //单人训练设置问题
    void SingleSetQuestion();

    //单人训练答题
    void SingleAnswerQuestion(int select);

    //设置得分
    void setEnemyScore();
    void setSelfScore();
	
	//--------------------------------------------------------

    //rank设置问题
    void rankSetQuestion();

    //rank结果
    void rankSetResult(QJsonObject &json);

    //rank答题
    void RankAnswerQuestion(int select);

private slots:
    void on_RankButton_clicked();

    void on_SingleButton_clicked();

    void on_SingleBack_clicked();

    void on_SingleStart_clicked();

    //单人训练从服务器接收到题目
    void receiveSingleQuestion(QJsonObject json);
    //个人训练计时器
    void SingleTimerOut();

    void on_OverBack_clicked();

    void on_SingleButtonA_clicked();

    void on_SingleButtonB_clicked();

    void on_SingleButtonC_clicked();

    void on_SingleButtonD_clicked();
	
//----------------------------------------------------------------------

    //接受排位
    void Rank(QJsonObject json);

    //排位计时器
    void RankTimerOut();

    void on_RankButtonA_clicked();

    void on_RankButtonB_clicked();

    void on_RankButtonC_clicked();

    void on_RankButtonD_clicked();

    void on_overButton_clicked();

private:
    Ui::BrainStorm *ui;
    Communicate    *_com;    //通信类指针，负责和服务器通信

    QJsonObject    _singleQuestion;
    int            _currentSingleQuestion;//当前回答哪一个问题的下标
    QTimer         _singleTimer;     //个人训练定时器
    int            _singleSec;           //个人训练答题时间
    int            _singleScore;         //个人训练得分

    //----------------------Rank---------------------
    QJsonObject _rankQuestion;   //rank的题
    QString     _enemyName;//对手的名字
    QString     _enemyRank;//对手的段位
    int         _enemyScore;   //对手的得分

    int _rankSec;     //rank 答题计时
    int _myScore;     //自己的得分

    QString _userName;//自己的名字
    QString _userRank;//自己的段位

    int _currentRankQuestion;//当前回答哪一个问题的下标

    int _enemyRankQuestion;//对手当前回答问题的下标

    QTimer _rankTimer;     //排位定时器

};

#endif // BRAINSTORM_H
