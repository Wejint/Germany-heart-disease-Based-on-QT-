#ifndef EASYEXPLAINATIONSCENE_H
#define EASYEXPLAINATIONSCENE_H

#include <QMainWindow>
#include<QKeyEvent>
#include<player.h>
#include<judger.h>


class easyExplainationScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit easyExplainationScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent*);
    void paintBrand();
    Player *player1;
    Player *player2;
    Player *player3;
    //牌堆
    stack brandStackPlayer1;
    stack brandStackPlayer2;
    stack brandStackPlayer3;
    //裁判
    judger *jud;
    //判断游戏是否开始
    short int isBegin;

signals:
    void chooseSceneBack();
    //玩家一
    void z_PressSignal();
    void Q_PressSignal();
    //玩家二
    void p_PressSignal();
    void m_PressSignal();
    //玩家三
    void _9PressSignal();
    void _0PressSignal();
    //
    void K_PressSignal();
    //选关卡
    void easySignal();
    void complexSignal();
    void difficultSignal();


public slots:
};

#endif // EASYEXPLAINATIONSCENE_H
