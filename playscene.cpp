#include "playscene.h"
#include<QMenu>
#include<QMenuBar>
#include<QPainter>
#include<QImage>
#include<QRgb>
#include"mypushbotton.h"
#include<QLabel>
#include<QDebug>
#include<chooselevelscene.h>
#include<fruitbrand.h>
#include<player.h>
#include<QString>
#include<time.h>
#include<QTimer>
#include<QPropertyAnimation>
#include<QPalette>
#include<QFont>
#include<QSound>
int getSurfaceRed1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][0];
    }
    else
    {
        return 0;
    }
}
int getSurfaceYellow1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][1];
    }
    else
    {
        return 0;
    }
}
int getSurfacePurple1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][2];
    }
    else
    {
        return 0;
    }
}
int getSurfaceGreen1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][3];
    }
    else
    {
        return 0;
    }
}
int getSurfaceWolf1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 55)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfaceSheep1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 54)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfacePig1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 53)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfaceMonkey1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 52)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfaceElephant1(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 51)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//栈的操作
//初始化
void initStack(stack &sta)
{
    sta.pTop = -1;
}
//入栈
void push(stack &sta,int brand[],int location)
{
    sta.pTop++;
    for(int i = 0;i<4;i++)
    {
        sta.stack[sta.pTop][i] = brand[i];
    }
    sta.stack[sta.pTop][4] = location;

}
//出栈
int pop(stack &sta)
{
    if(sta.pTop == -1)
    {
        qDebug()<<"栈满"<<endl;
        return 0;

    }
    else
    {

        int tmp = sta.stack[sta.pTop][4];
        sta.pTop--;
        return tmp;


    }
}
easyExplainationScene::easyExplainationScene(QWidget *parent) : QMainWindow(parent)
{
    //牌堆初始化
    initStack( this->brandStackPlayer1);
    initStack( this->brandStackPlayer2);
    initStack( this->brandStackPlayer3);
    //将卡牌绘图事件和键盘事件连接

    QSound* bellSound = new QSound("://res/铃铛声音.wav",this);
    fruitBrand *fruitBrandsPlayer1 = new fruitBrand(":/res/底牌.jpg",200,300,0,0,0,1);
    fruitBrand *fruitBrandsPlayer2 = new fruitBrand(":/res/底牌.jpg",200,300,0,0,0,1);
    fruitBrand *fruitBrandsPlayer3 = new fruitBrand(":/res/底牌.jpg",200,300,0,0,0,1);
    fruitBrandsPlayer1->hide();
    fruitBrandsPlayer2->hide();
    fruitBrandsPlayer3->hide();

    fruitBrandsPlayer1->move(200,250);
    fruitBrandsPlayer2->move(400,400);
    fruitBrandsPlayer3->move(600,250);
    fruitBrandsPlayer1->setText("牌堆一");
    fruitBrandsPlayer2->setText("牌堆二");
    fruitBrandsPlayer3->setText("牌堆三");
    fruitBrandsPlayer1->setParent(this);
    fruitBrandsPlayer2->setParent(this);
    fruitBrandsPlayer3->setParent(this);
    //创建显示玩家剩余牌数的label
    QLabel *nBrandPlayer1 = new QLabel;
    QLabel *nBrandPlayer2 = new QLabel;
    QLabel *nBrandPlayer3 = new QLabel;
    nBrandPlayer1->setParent(this);
    nBrandPlayer2->setParent(this);
    nBrandPlayer3->setParent(this);
    QString *str1 = new QString("玩家一剩余19张牌");
    QString *str2 = new QString("玩家二剩余19张牌");
    QString *str3 = new QString("玩家三剩余19张牌");
    nBrandPlayer3->move(0,-200);
    nBrandPlayer2->move(0,-150);
    nBrandPlayer1->move(0,-100);
    QFont font("微软雅黑",20,QFont::Bold,true);
    nBrandPlayer1->setFont(font);
    nBrandPlayer1->setStyleSheet("color:black");
    nBrandPlayer2->setFont(font);
    nBrandPlayer2->setStyleSheet("color:black");
    nBrandPlayer3->setFont(font);
    nBrandPlayer3->setStyleSheet("color:black");
    nBrandPlayer1->setText(*str1);
    nBrandPlayer2->setText(*str2);
    nBrandPlayer3->setText(*str3);
    //bell设置
    QLabel *bell = new QLabel;
    QPixmap tmpPixmap;
     tmpPixmap.load("://res/bell.jpg");

     bell->setGeometry(0,0,tmpPixmap.width(),tmpPixmap.height());
     bell->setPixmap(tmpPixmap);
     bell->setParent(this);
     bell->move(800,600);
     bell->hide();

    //字幕显示
     QLabel *explainationLabel = new QLabel;
     explainationLabel->setParent(this);
     explainationLabel->setFixedSize(500,500);
     explainationLabel->move(300,200);
     QFont f("微软雅黑",10,QFont::Bold,true);
     explainationLabel->setFont(f);
     //不同模式显示不同规则
     connect(this,&easyExplainationScene::easySignal,[=]{
         explainationLabel->show();
         QString strExpalin("亲爱的玩家，你好：\n"
                            "在这个模式中，每名玩家将拿到19张牌，每-------\n"
                            "张牌上有四种不同的水果，当桌面上出现【“某一，两三张牌\n"
                            "某种水果数量相同时”】请按铃！如果判断成功，则获\n"
                            "得奖励(获得牌堆中所有牌)若判断失败则接受惩罚\"\n"
                            "(给另外两名玩家各发一张牌)\n"
                            "\n"
                            "请留意特殊情况，大象爱吃草莓，猴子爱---------\n"
                            "吃香蕉，绵羊爱吃柠檬，猪爱吃梅子，当动物-----\n"
                            "狼爱吃动物，0.0.当动物和它们喜欢的东西同时出-\n"
                            "现时记得按铃哦！祝你们好运^.^--------------\n"
                            "\n"
                            "玩家一操作:“Z”发牌，“Q”按铃---------------\n "
                            "玩家二操作:“M”发牌，“P”按铃---------------\n "
                            "玩家三操作：“0”发牌，“9”按铃--------------\n"
                            "按k键继续");


         explainationLabel -> setText(strExpalin);
         qDebug()<<this->jud->easy;
         qDebug()<<this->jud->complex;
         qDebug()<<this->jud->difficult;

     });
     connect(this,&easyExplainationScene::complexSignal,[=]{
         explainationLabel->show();
         QString strExpalin("亲爱的玩家，你好：\n"
                            "在这个模式中，每名玩家将拿到19张牌，每-------\n"
                            "张牌上有四种不同的水果，当桌面上出现【“某种水果\n"
                            "的数量是5的倍数”】请按铃！如果判断成功，则获--\n"
                            "得奖励(获得牌堆中所有牌)若判断失败则接受惩罚\"\n"
                            "(给另外两名玩家各发一张牌)\n"
                            "\n"
                            "请留意特殊情况，大象爱吃草莓，猴子爱---------\n"
                            "吃香蕉，绵羊爱吃柠檬，猪爱吃梅子，当动物-----\n"
                            "狼爱吃动物，0.0.当动物和它们喜欢的东西同时出-\n"
                            "现时记得按铃哦！祝你们好运^.^--------------\n"
                            "\n"
                            "玩家一操作:“Z”发牌，“Q”按铃---------------\n "
                            "玩家二操作:“M”发牌，“P”按铃---------------\n "
                            "玩家三操作：“0”发牌，“9”按铃--------------\n"
                            "按k键继续");


         explainationLabel -> setText(strExpalin);

         qDebug()<<this->jud->easy;
         qDebug()<<this->jud->complex;
         qDebug()<<this->jud->difficult;

     });

     connect(this,&easyExplainationScene::difficultSignal,[=]{
         explainationLabel->show();
         QString strExpalin("亲爱的玩家，你好：\n"
                            "在这个模式中，每名玩家将拿到19张牌，每--------\n"
                            "张牌上有四种不同的水果，当桌面上出现【“某种水果\n"
                            "的数量是5的倍数“】请按铃！如果判断成功，则获--\n"
                            "得奖励(获得牌堆中组成五的倍数的水果的牌)若判断\n"
                            "失败则接受惩罚\"(给另外两名玩家各发一张牌)\n"
                            "\n"
                            "请留意特殊情况，大象爱吃草莓，猴子爱---------\n"
                            "吃香蕉，绵羊爱吃柠檬，猪爱吃梅子，当动物-----\n"
                            "狼爱吃动物，0.0.当动物和它们喜欢的东西同时出-\n"
                            "现时记得按铃哦！祝你们好运^.^--------------\n"
                            "\n"
                            "玩家一操作:“Z”发牌，“Q”按铃---------------\n "
                            "玩家二操作:“M”发牌，“P”按铃---------------\n "
                            "玩家三操作：“0”发牌，“9”按铃--------------\n"
                            "按k键继续");


         explainationLabel -> setText(strExpalin);
         qDebug()<<this->jud->easy;
         qDebug()<<this->jud->complex;
         qDebug()<<this->jud->difficult;



     });
     connect(this,&easyExplainationScene::K_PressSignal,[=](){
         explainationLabel->hide();
         fruitBrandsPlayer1->show();
         fruitBrandsPlayer2->show();
         fruitBrandsPlayer3->show();
         bell->show();

     });
     setFixedSize(1000,800);
     //设置图标
     setWindowIcon(QIcon(":/res/Title_Picture.jpg"));
     //设置标题
     setWindowTitle("德国心脏病");
     //创建菜单栏
     QMenuBar *bar = menuBar();
     setMenuBar(bar);
     //创建开始菜单
     QMenu * startMenu = bar->addMenu("开始");
     //创建退出菜单项
     QAction * quitAction = startMenu->addAction("退出");
     connect(quitAction,&QAction::triggered,[=](){
         this->close();

     });
     //返回按钮
     MyPushBotton * backbtn = new MyPushBotton("://res/button.jpg");
     backbtn->setFixedSize(150,50);
     backbtn ->setParent(this);
     backbtn->move(this->width() - backbtn->width(),this->height() - backbtn->height());
     QLabel * labelBack = new QLabel;
     labelBack->setParent(this);
     labelBack->setFixedSize(backbtn->width(),backbtn->height());
     labelBack->setText("返回");
     labelBack->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
     labelBack->move(this->width() - backbtn->width(),this->height() - backbtn->height() );
     //设置让鼠标穿透
     labelBack->setAttribute(Qt::WA_TransparentForMouseEvents);

     //点击返回
     connect(backbtn,&MyPushBotton::clicked,[=]()
     {
        qDebug()<<"点击了返回按钮";
        backbtn->Up();

        emit chooseSceneBack();
     });



    //裁判初始化
    jud = new judger;





    //裁判随时监控是否有玩家被淘汰
    QLabel *outLabel = new QLabel;
    outLabel->setParent(this);
    outLabel->setFixedSize(550,50);
    outLabel->move(300,200);
    QFont f4("微软雅黑",20,QFont::Bold,true);
    outLabel->setStyleSheet("color:red");
    outLabel->setFont(f4);

    QPropertyAnimation * animationOut = new QPropertyAnimation (outLabel,"geometry");
    animationOut->setDuration(3000);
    animationOut->setStartValue(QRect(0,300,outLabel->width(),outLabel->height()));
    animationOut->setEndValue(QRect(1000,300,outLabel->width(),outLabel->height()));

    QTimer*timer = new QTimer(this);
    //启动定时器
    timer->start(500);//发送信号
    int *isOut1 = new int(0);
    int *isOut2 = new int(0);
    int *isOut3 = new int(0);
    connect(timer,&QTimer::timeout,[=](){
        if(*isOut1==0)
        {
            if(this->jud->isOutOfGame(player1))
            {
                jud->isOutOfGamePlayer1 = 1;
                QString out = QString("玩家一被淘汰");
                outLabel->setText(out);
                animationOut->start();
                *isOut1 = 1;
            }
        }
        if(*isOut2==0)
        {
            if(this->jud->isOutOfGame(player2))
            {
                jud->isOutOfGamePlayer2 = 1;
                QString out = QString("玩家二被淘汰");
                outLabel->setText(out);
                animationOut->start();
                *isOut2 = 1;
            }
        }
        if(*isOut3==0)
        {
            if(this->jud->isOutOfGame(player3))
            {
                jud->isOutOfGamePlayer3 = 1;
                QString out = QString("玩家三被淘汰");
                outLabel->setText(out);
                animationOut->start();
                *isOut3 = 1;
            }
        }

    });

    //初始化牌堆

    int Brands[56][5] = {{0,0,0,1,0},{0,0,0,2,0},{0,0,0,3,0},{0,0,0,4,0},{0,0,1,0,0},{0,0,1,1,0},{0,0,1,2,0},{0,0,1,3,0},{0,0,2,0,0},{0,0,2,1,0},{0,0,3,0,0},{0,0,3,1,0}
                          ,{0,0,4,0,0},{0,1,0,0,0},{0,1,0,1,0},{0,1,0,2,0},{0,1,0,3,0},{0,1,1,0,0},{0,1,2,0,0},{0,1,3,0,0},{0,2,0,0,0},{0,2,0,1,0},{0,2,1,0,0},{0,3,0,0,0},{0,3,0,1,0},{0,3,1,0,0},
 {0,4,0,0,0},{0,5,0,0,0},{1,0,0,0,0},{1,0,0,1,0},{1,0,0,2,0},{1,0,0,3,0},{1,0,1,0,0},{1,0,1,1,0},{1,0,2,0,0},
                          {1,0,3,0,0},{1,1,0,0,0},{1,1,0,1,0},{1,1,1,1,0},{1,3,0,0,0},{2,0,0,0,0},{2,0,0,1,0},{2,0,1,0,0},{2,1,0,0,0},{3,0,0,0,0},{3,0,0,1,0},{3,0,1,0,0},{3,1,0,0,0},{4,0,0,0,0},{5,0,0,0,0},{0,0,5,0,0}
                        , {0,0,0,0,0},{2,2,2,2,0},{3,3,3,3,0},{4,4,4,4,0},{5,5,5,5,0}};
    int (*pBrand)[5] = new int[56][5];
    for(int i = 0 ;i<56;i++)
    {
        for(int j = 0; j < 5;j++)
        {
            pBrand[i][j] = Brands[i][j];
        }
    }
    player1 = new Player(Qt::Key_Z,Qt::Key_Q,Brands,19);

    player2 = new Player(Qt::Key_M,Qt::Key_P,Brands,19);

    player3 = new Player(Qt::Key_0,Qt::Key_9,Brands,19);


//    给玩家发牌
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 19;i++)
    {
        int tmp = rand()%((55 - 0 + 1) + 0);
        qDebug()<<tmp<<endl;
        player1->myBrand[tmp][4] += 1;
    }
    for(int i = 19; i < 38;i++)
    {
        int tmp = rand()%((55 - 0 + 1) + 0);
        qDebug()<<tmp<<endl;
        player2->myBrand[tmp][4] += 1;
    }
    for(int i = 38; i < 57;i++)
    {
        int tmp = rand()%((55 - 0 + 1) + 0);
        qDebug()<<tmp<<endl;
        player3->myBrand[tmp][4] += 1;
    }













//出牌特效
    fruitBrand *moveEffect1 = new fruitBrand(":/res/底牌.jpg",200,300,0,0,0,1);
    moveEffect1->setParent(this);
    moveEffect1->hide();
    //玩家一出牌操作
    connect(this,&easyExplainationScene::z_PressSignal,[=](){
        if(jud->isOutOfGamePlayer1 == 0)
        {

            qDebug()<<"接收到了信号"<<endl;
            //找出玩家Z的第一张牌
            int i = 0;
            int tmpBrand[4];
            while(1)
            {
                if(this->player1->myBrand[i][4]>=1)
                {
                    for(int j = 0;j<4;j++)
                    {
                        tmpBrand[j] =  this->player1->myBrand[i][j];
                        qDebug()<<tmpBrand[j];
                    }
                    player1->myBrand[i][4] -= 1;
                    break;
                }
                if(i == 55)
                {
                    i++;
                    break;
                }
                i++;

            }
            //出牌特效
            moveEffect1->show();
            QString str = QString(":/res/%1%2%3%4.jpg").arg(tmpBrand[0]).arg(tmpBrand[1]).arg(tmpBrand[2]).arg(tmpBrand[3]);
            QPixmap PixMove1;
             PixMove1.load(str);

             moveEffect1->setGeometry(0,0,PixMove1.width(),PixMove1.height());
             moveEffect1->setIcon(PixMove1);
             //model
             QPropertyAnimation * animation1 = new QPropertyAnimation (moveEffect1,"geometry");
             animation1->setDuration(1000);
             animation1->setStartValue(QRect(fruitBrandsPlayer1->x(),fruitBrandsPlayer1->y()+300,100,150));
             animation1->setEndValue(QRect(fruitBrandsPlayer1->x() - 25,fruitBrandsPlayer1->y() ,100,150));
             animation1->start();

            //更新玩家剩余牌数
            //在下方显示玩家一剩余的牌数
            this->player1->nBrand--;
            qDebug()<<"玩家一剩余"<< this->player1->nBrand<<"张牌"<<endl;
            *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
            nBrandPlayer1->setText(*str1);
            //防止牌堆显示空牌

            if(i!=56)
            {
                QTimer::singleShot(1000,this,[=]{
                QString str = QString(":/res/%1%2%3%4.jpg").arg(tmpBrand[0]).arg(tmpBrand[1]).arg(tmpBrand[2]).arg(tmpBrand[3]);
                qDebug()<<str;
                QPixmap pixmap;
                pixmap.load(str);
                fruitBrandsPlayer1->setIcon(pixmap);
                }
                );
            }


            //提示玩家二出牌
            qDebug()<<"该玩家二出牌了！"<<endl;
            //将卡牌放到牌堆里

            push(this->brandStackPlayer1,pBrand[i],i);










            this->player1->isOutputBrand = 1;
            //告诉裁判第一张牌是啥
            this->jud->firstStack1Brand = i;

        }
        else
        {
            qDebug()<<"玩家一已经出局"<<endl;
        }
    });
    fruitBrand *moveEffect2 = new fruitBrand(":/res/底牌.jpg",200,300,0,0,0,1);
    moveEffect2->setParent(this);
    moveEffect2->hide();
    //玩家二出牌操作
    connect(this,&easyExplainationScene::m_PressSignal,[=](){
        if(jud->isOutOfGamePlayer2 != 1)
        {

            qDebug()<<"接收到了信号"<<endl;
            //找出玩家m的第一张牌
            int i = 0;
            int tmpBrand[4];
            while(1)
            {
                if(this->player2->myBrand[i][4]>=1)
                {
                    for(int j = 0;j<4;j++)
                    {
                        tmpBrand[j] =  this->player2->myBrand[i][j];
                        qDebug()<<tmpBrand[j];
                    }
                    player2->myBrand[i][4] -= 1;
                    break;
                }
                if(i == 55){ i++; break;}
                i++;


            }
            //出牌特效
            moveEffect2->show();
            QString str = QString(":/res/%1%2%3%4.jpg").arg(tmpBrand[0]).arg(tmpBrand[1]).arg(tmpBrand[2]).arg(tmpBrand[3]);
            QPixmap PixMove2;
             PixMove2.load(str);

             moveEffect2->setGeometry(0,0,PixMove2.width(),PixMove2.height());
             moveEffect2->setIcon(PixMove2);

             QPropertyAnimation * animation2 = new QPropertyAnimation (moveEffect2,"geometry");
             animation2->setDuration(1000);
             animation2->setStartValue(QRect(fruitBrandsPlayer2->x(),fruitBrandsPlayer2->y()+300,100,150));
             animation2->setEndValue(QRect(fruitBrandsPlayer2->x() - 25,fruitBrandsPlayer2->y() ,100,150));
             animation2->start();


            //更新玩家剩余牌数
            //玩家二牌数减1
            this->player2->nBrand--;
            *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
            nBrandPlayer2->setText(*str2);
            //将打出的牌显示
            if(i!= 56)//防止产生空牌
            {
                QTimer::singleShot(1000,this,[=]{
                QString str = QString(":/res/%1%2%3%4.jpg").arg(tmpBrand[0]).arg(tmpBrand[1]).arg(tmpBrand[2]).arg(tmpBrand[3]);
                qDebug()<<str;
                QPixmap pixmap1;
                pixmap1.load(str);
                fruitBrandsPlayer2->setIcon(pixmap1);
                });
            }


            //在下方显示玩家二剩余的牌数
            qDebug()<<"玩家二剩余"<< this->player2->nBrand<<"张牌"<<endl;
            //提示玩家三出牌
            qDebug()<<"该玩家三出牌了！"<<endl;
            //将卡牌放到牌堆里

            push(this->brandStackPlayer2,pBrand[i],i);





            this->player2->isOutputBrand = 1;
            //告诉裁判第一张牌是啥
            this->jud->firstStack2Brand = i;



        }
        else
        {
            qDebug()<<"玩家二已经出局"<<endl;
        }


    });
    fruitBrand *moveEffect3 = new fruitBrand(":/res/底牌.jpg",200,300,0,0,0,1);
    moveEffect3->setParent(this);
    moveEffect3->hide();
    //玩家三出牌操作
    connect(this,&easyExplainationScene::_0PressSignal,[=](){
        if(jud->isOutOfGamePlayer3 != 1)
        {

            qDebug()<<"接收到了信号"<<endl;
            //找出玩家Z的第一张牌
            int i = 0;
            int tmpBrand[4];
            while(1)
            {
                if(this->player3->myBrand[i][4]>=1)
                {
                    for(int j = 0;j<4;j++)
                    {
                        tmpBrand[j] =  this->player3->myBrand[i][j];
                        qDebug()<<tmpBrand[j];
                    }
                    player3->myBrand[i][4] -= 1;
                    break;
                }
                if(i == 55){i++; break;}
                i++;

            }
            //出牌特效
            moveEffect3->show();
            QString str = QString(":/res/%1%2%3%4.jpg").arg(tmpBrand[0]).arg(tmpBrand[1]).arg(tmpBrand[2]).arg(tmpBrand[3]);
            QPixmap PixMove3;
             PixMove3.load(str);

             moveEffect3->setGeometry(0,0,PixMove3.width(),PixMove3.height());
             moveEffect3->setIcon(PixMove3);

             QPropertyAnimation * animation3 = new QPropertyAnimation (moveEffect3,"geometry");
             animation3->setDuration(1000);
             animation3->setStartValue(QRect(fruitBrandsPlayer3->x(),fruitBrandsPlayer3->y()+300,100,150));
             animation3->setEndValue(QRect(fruitBrandsPlayer3->x() - 25,fruitBrandsPlayer3->y() ,100,150));
             animation3->start();


            //更新玩家剩余牌数
            //扣除玩家三1张牌数
            this->player3->nBrand--;
            *str1 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
            nBrandPlayer3->setText(*str1);
            if(i!=56)
            {
                QTimer::singleShot(1000,this,[=]{
                    QString str = QString(":/res/%1%2%3%4.jpg").arg(tmpBrand[0]).arg(tmpBrand[1]).arg(tmpBrand[2]).arg(tmpBrand[3]);
                    qDebug()<<str;
                    QPixmap pixmap2;
                    pixmap2.load(str);
                    fruitBrandsPlayer3->setIcon(pixmap2);});

            }


            //在下方显示玩家三剩余的牌数
            qDebug()<<"玩家三剩余"<< this->player3->nBrand<<"张牌"<<endl;
            //提示玩家一出牌
            qDebug()<<"该玩家一出牌了！"<<endl;


            push(this->brandStackPlayer3,pBrand[i],i);
//            //裁判统计现在场上的水果数
//            if(i<51)
//            {
//                this->jud->addNSurfaceCountBanana(Brands[i][2]);
//                this->jud->addNSurfaceCountStrawberry(Brands[i][0]);
//                this->jud->addNSurfaceCountPurple(Brands[i][1]);
//                this->jud->addNSurfaceCountOrange(Brands[i][3]);
//            }
//            else if(i>=51&&i<56)
//            {
//                if(i==51)
//                {
//                    this->jud->nElephant += 1;
//                }
//                if(i==52)
//                {
//                    this->jud->nMonkey += 1;
//                }
//                if(i==53)
//                {
//                    this->jud->nPig += 1;
//                }
//                if(i == 54)
//                {
//                    this->jud->nSheep += 1;
//                }
//                if(i==55)
//                {
//                    this->jud->nWolf += 1;
//                }

//            }
//            //处理之前记录的数据
//            if(this->player3->isOutputBrand != 0)
//            {
//                if(this->jud->firstStack3Brand<51)
//                {
//                    this->jud->addNSurfaceCountBanana(-Brands[this->jud->firstStack3Brand][2]);
//                    this->jud->addNSurfaceCountStrawberry(-Brands[this->jud->firstStack3Brand][0]);
//                    this->jud->addNSurfaceCountPurple(-Brands[this->jud->firstStack3Brand][1]);
//                    this->jud->addNSurfaceCountOrange(-Brands[this->jud->firstStack3Brand][3]);

//                }
//                else if(this->jud->firstStack3Brand>=51&&this->jud->firstStack3Brand<56)
//                {
//                    if(this->jud->firstStack3Brand == 51)
//                    {
//                        this->jud->nElephant--;
//                    }
//                    else if(this->jud->firstStack3Brand == 52)
//                    {
//                        this->jud->nMonkey--;
//                    }
//                    else if(this->jud->firstStack3Brand == 53)
//                    {
//                        this->jud->nPig--;
//                    }
//                    else if(this->jud->firstStack3Brand == 54)
//                    {
//                        this->jud->nSheep--;
//                    }
//                    else if(this->jud->firstStack3Brand == 55)
//                    {
//                        this->jud->nWolf--;
//                    }
//                }

//            }


            this->player3->isOutputBrand = 1;
            //告诉裁判第一张牌是啥
            this->jud->firstStack3Brand = i;

        }
        else
        {
            qDebug()<<"玩家三已经出局"<<endl;
        }


    });
    //字幕显示
     QLabel *player1Label = new QLabel;
     player1Label->setParent(this);
     player1Label->setFixedSize(550,50);
     player1Label->move(300,200);
     QFont f2("微软雅黑",20,QFont::Bold,true);
     player1Label->setStyleSheet("color:blue");
     player1Label->setFont(f2);

     QPropertyAnimation * animationPlayer1 = new QPropertyAnimation (player1Label,"geometry");
     animationPlayer1->setDuration(3000);
     animationPlayer1->setStartValue(QRect(0,300,player1Label->width(),player1Label->height()));
     animationPlayer1->setEndValue(QRect(1000,300,player1Label->width(),player1Label->height()));
//     animationPlayer1->setEasingCurve(QEasingCurve::OutBounce);
     //animationPlayer1->start();
    //玩家按铃后的处理方法
    connect(this,&easyExplainationScene::Q_PressSignal,[=](){

        if(jud->isOutOfGamePlayer1 !=1)
        {
            bellSound->play();
            if((this->jud->complex==1&&this->jud->isComplexRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==true)||(this->jud->easy==1&&this->jud->isEasyRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==true))
            {

                     QString strPlayer1("恭喜玩家一按铃成功!");
                     player1Label->setText(strPlayer1);
                     animationPlayer1->start();
                    //显示
                    qDebug()<<"恭喜玩家一按铃成功!"<<endl;


                    //将牌堆中的牌全部给一玩家

                            while(brandStackPlayer1.pTop>-1)
                            {

                                this->player1->myBrand[pop(brandStackPlayer1)][4] += 1;
                                this->player1->nBrand++;


                            }



                            while(this->brandStackPlayer2.pTop > -1)
                            {
                                this->player1->myBrand[pop(brandStackPlayer2)][4] += 1;
                                this->player1->nBrand++;

                            }



                            while(this->brandStackPlayer3.pTop > -1)
                            {
                                this->player1->myBrand[pop(brandStackPlayer3)][4] += 1;
                                this->player1->nBrand++;
                                qDebug()<<"0"<<endl;
                            }



                    *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                    nBrandPlayer1->setText(*str1);
                    //显示空牌堆
                    QPixmap pix;
                    pix.load(":/res/底牌.jpg");
                    moveEffect3->hide();
                    moveEffect2->hide();
                    moveEffect1->hide();
                    fruitBrandsPlayer1->setIcon(pix);
                    fruitBrandsPlayer2->setIcon(pix);
                    fruitBrandsPlayer3->setIcon(pix);
                    //显示
                    qDebug()<<"恭喜玩家一按铃成功!"<<endl;
                }


                //按错铃的惩罚机制
                else if((this->jud->complex==1&&jud->isComplexRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==false)||(this->jud->easy==1&&jud->isEasyRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==false))
                {
                    QString strPlayer1("玩家一被惩罚!给每位玩家发一张牌");
                    player1Label->setText(strPlayer1);
                    animationPlayer1->start();
                    qDebug()<<"玩家一被惩罚!给每位玩家发一张牌"<<endl;
                    int nPunish = 0;
                    int nCountPunish = 0;
                    while(1)
                    {
                        if(player1->myBrand[nPunish][4] >= 1&&nCountPunish == 0)
                        {
                            //将玩家一的一张牌发给玩家二
                            player2->myBrand[nPunish][4] += 1;
                            player2->nBrand++;
                            //记录下惩罚次数
                            nCountPunish++;
                            //将玩家一的该张牌去除
                            player1->myBrand[nPunish][4] -= 1;
                            player1->nBrand--;
                        }
                        else if
                                (player1->myBrand[nPunish][4] != 0&&nCountPunish == 1)
                        {
                            player3->myBrand[nPunish][4] += 1;
                            player3->nBrand++;
                            nCountPunish++;
                            //将玩家一的该张牌去除
                            player1->myBrand[nPunish][4] -= 1;
                            player1->nBrand--;
                            //结束惩罚循环
                            break;
                        }
                        nPunish++;
                    }
                    *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
                    nBrandPlayer2->setText(*str2);
                    *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                    nBrandPlayer1->setText(*str1);
                    *str3 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
                    nBrandPlayer3->setText(*str3);
                }
            //困难模式处理方法
                if(this->jud->difficult == 1)
                {
                    QString strPlayer1("恭喜玩家一按铃成功!");
                    player1Label->setText(strPlayer1);
                    animationPlayer1->start();
                   //显示
                   qDebug()<<"恭喜玩家一按铃成功!"<<endl;
                    int nKind;
                    if(this->jud->isDifficultRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3,nKind)==1)
                    {
                        if(nKind == 0)//草莓为5
                        {
                            if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer2) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer2)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                               this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                               this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                               this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                               this->player1->nBrand+=3;
                            }
                            else if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer2))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceRed1(this->brandStackPlayer2) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer2)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer1)%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer2)%5==0&&getSurfaceRed1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer3)%5==0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }



                        }
                        else if(nKind == 1)//香蕉为5
                        {
                            if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer2) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer2)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer2))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer2) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer2)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer1)%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer2)%5==0&&getSurfaceYellow1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer3)%5==0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }

                        }
                        else if(nKind == 2)//紫色为5
                        {
                            if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer2) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer2)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer2))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfacePurple1(this->brandStackPlayer2) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer2)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer1)%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer2)%5==0&&getSurfacePurple1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer3)%5==0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                        }
                        else if(nKind == 3)//橘子为5
                        {
                            if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer2) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer2)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer2))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer2) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer2)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand+=2;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer1)%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer2)%5==0&&getSurfaceGreen1(this->brandStackPlayer2)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer3)%5==0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player1->nBrand++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }

                        }
                        else if(nKind == 4)//大象吃草莓
                        {
                            if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0&&getSurfaceRed1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0&&getSurfaceRed1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0&&getSurfaceRed1(this->brandStackPlayer2)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->nBrand+=2;
                            }

                        }
                        else if(nKind == 5)//猴子吃香蕉
                        {
                            if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0&&getSurfaceYellow1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0&&getSurfaceYellow1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0&&getSurfaceYellow1(this->brandStackPlayer2)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->nBrand+=2;
                            }

                        }
                        else if(nKind == 6)//猪吃梅子
                        {
                            if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0&&getSurfacePurple1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0&&getSurfacePurple1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0&&getSurfacePurple1(this->brandStackPlayer2)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }

                        }
                        else if(nKind == 7)//绵羊吃柠檬
                        {
                            if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0&&getSurfaceGreen1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0&&getSurfaceGreen1(this->brandStackPlayer3)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0&&getSurfaceGreen1(this->brandStackPlayer2)>0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer3) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player1->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0)
                            {
                                this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player1->nBrand+=2;
                            }
                        }
                        else if(nKind == 8)
                        {

                        }    //狼吃其它动物
                        if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0)&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {//玩家一是狼其余全是动物
                            this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player1->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0)&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家二是狼其余全是动物
                            this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player1->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0)&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家三是狼，其余全是动物
                            this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player1->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家一是狼，玩家二是动物
                            this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player1->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家一是狼，玩家三是动物
                            this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;

                            this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player1->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0))
                        {
                            //玩家二是狼，玩家一是动物
                            this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player1->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家二是狼，玩家三是动物
                            this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player1->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0))
                        {
                            //玩家三是狼，玩家一是动物
                            this->player1->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            this->player1->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家三是狼，玩家二是动物
                            this->player1->myBrand[pop(this->brandStackPlayer3)][4]++;

                            this->player1->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player1->nBrand+=2;
                        }
                        else
                        {
                            qDebug()<<"error"<<endl;
                        }

                        //更新卡牌显示
                        QPixmap pix1;
                        QPixmap pix2;
                        QPixmap pix3;

                        QString str1 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][0]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][1]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][2]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][3]);
                        QString str2 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][0]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][1]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][2]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][3]);
                        QString str3 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][0]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][1]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][2]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][3]);

                        pix1.load(str1);
                        pix2.load(str2);
                        pix3.load(str3);
                        moveEffect3->hide();
                        moveEffect2->hide();
                        moveEffect1->hide();
                        fruitBrandsPlayer1->setIcon(pix1);
                        fruitBrandsPlayer2->setIcon(pix2);
                        fruitBrandsPlayer3->setIcon(pix3);
                        //显示
                        qDebug()<<"恭喜玩家一按铃成功!"<<endl;


                    }
                    else if(this->jud->isDifficultRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3,nKind)==0)
                    {
                        //惩罚
                        QString strPlayer1("玩家一被惩罚!给每位玩家发一张牌");
                        player1Label->setText(strPlayer1);
                        animationPlayer1->start();
                        qDebug()<<"玩家一被惩罚!给每位玩家发一张牌"<<endl;
                        int nPunish = 0;
                        int nCountPunish = 0;
                        while(1)
                        {
                            if(player1->myBrand[nPunish][4] >= 1&&nCountPunish == 0)
                            {
                                //将玩家一的一张牌发给玩家二
                                player2->myBrand[nPunish][4] += 1;
                                player2->nBrand++;
                                //记录下惩罚次数
                                nCountPunish++;
                                //将玩家一的该张牌去除
                                player1->myBrand[nPunish][4] -= 1;
                                player1->nBrand--;
                            }
                            else if
                                    (player1->myBrand[nPunish][4] != 0&&nCountPunish == 1)
                            {
                                player3->myBrand[nPunish][4] += 1;
                                player3->nBrand++;
                                nCountPunish++;
                                //将玩家一的该张牌去除
                                player1->myBrand[nPunish][4] -= 1;
                                player1->nBrand--;
                                //结束惩罚循环
                                break;
                            }
                            nPunish++;
                        }
                        *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
                        nBrandPlayer2->setText(*str2);
                        *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                        nBrandPlayer1->setText(*str1);
                        *str3 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
                        nBrandPlayer3->setText(*str3);
                    }
                    //更新牌数
                    QString str = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                    nBrandPlayer1->setText(str);
                }//difficult==1的反括号

            }

        else
        {
            qDebug()<<"玩家一已经出局!"<<endl;
        }
        //更新图片


    });
    //玩家二按铃之后的处理
    //字幕显示
     QLabel *player2Label = new QLabel;
     player2Label->setParent(this);
     player2Label->setFixedSize(550,50);
     player2Label->move(300,200);
     QFont f_("微软雅黑",20,QFont::Bold,true);
     player2Label->setStyleSheet("color:yellow");
     player2Label->setFont(f_);

     QPropertyAnimation * animationPlayer2 = new QPropertyAnimation (player2Label,"geometry");
     animationPlayer2->setDuration(3000);
     animationPlayer2->setStartValue(QRect(0,250,player2Label->width(),player2Label->height()));
     animationPlayer2->setEndValue(QRect(1000,250,player2Label->width(),player2Label->height()));
    connect(this,&easyExplainationScene::p_PressSignal,[=](){
        if(jud->isOutOfGamePlayer2 != 1)
        {
            bellSound->play();
            if((this->jud-> complex==1&&this->jud->isComplexRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==true)||(this->jud->easy==1&&this->jud->isEasyRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==true))
            {
                    QString strPlayer2("恭喜玩家二按铃成功!");
                    player2Label->setText(strPlayer2);
                    animationPlayer2->start();

                    while(brandStackPlayer1.pTop>-1)
                    {
                        this->player2->myBrand[pop(brandStackPlayer1)][4] += 1;
                        this->player2->nBrand++;

                    }



                    while(this->brandStackPlayer2.pTop > -1)
                    {
                        this->player2->myBrand[pop(brandStackPlayer2)][4] += 1;
                        this->player2->nBrand++;

                    }



                    while(this->brandStackPlayer3.pTop > -1)
                    {
                        this->player2->myBrand[pop(brandStackPlayer3)][4] += 1;
                        this->player2->nBrand++;

                    }
                    *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
                    nBrandPlayer2->setText(*str1);
                    //显示空牌堆
                    QPixmap pix2;
                    pix2.load(":/res/底牌.jpg");
                    moveEffect3->hide();
                    moveEffect2->hide();
                    moveEffect1->hide();
                    fruitBrandsPlayer1->setIcon(pix2);
                    fruitBrandsPlayer2->setIcon(pix2);
                    fruitBrandsPlayer3->setIcon(pix2);
                    //显示
                    qDebug()<<"恭喜玩家二按铃成功!"<<endl;
               }


                //按错铃的惩罚机制
                else if((this->jud->complex==1&&jud->isComplexRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==false)||(this->jud->easy==1&&jud->isEasyRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==false))
                {
                    QString strPlayer2("玩家二被惩罚!给每位玩家发一张牌");
                    player2Label->setText(strPlayer2);
                    animationPlayer2->start();
                    qDebug()<<"玩家二被惩罚!给每位玩家发一张牌"<<endl;
                    int nPunish = 0;
                    int nCountPunish = 0;
                    while(1)
                    {
                        if(player2->myBrand[nPunish][4] >= 1&&nCountPunish == 0)
                        {
                            //将玩家二的一张牌发给玩家一
                            player1->myBrand[nPunish][4] += 1;
                            player1->nBrand++;
                            //记录下惩罚次数
                            nCountPunish++;
                            //将玩家二的该张牌去除
                            player2->myBrand[nPunish][4] -= 1;

                            player2->nBrand--;
                        }
                        else if
                                (player2->myBrand[nPunish][4] != 0&&nCountPunish == 1)
                        {
                            player3->nBrand++;
                            player3->myBrand[nPunish][4] += 1;
                            nCountPunish++;
                            //将玩家二的该张牌去除
                            player2->myBrand[nPunish][4] -= 1;
                            player2->nBrand--;
                            //结束惩罚循环
                            break;
                        }
                        nPunish++;
                    }
                    *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
                    nBrandPlayer2->setText(*str2);
                    *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                    nBrandPlayer1->setText(*str1);
                    *str3 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
                    nBrandPlayer3->setText(*str3);
                }

            //困难模式处理方法
                if(this->jud->difficult == 1)
                {
                    QString strPlayer2("恭喜玩家二按铃成功!");
                    player2Label->setText(strPlayer2);
                    animationPlayer2->start();
                   //显示
                   qDebug()<<"恭喜玩家一按铃成功!"<<endl;
                    int nKind;
                    if(this->jud->isDifficultRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3,nKind)==1)
                    {
                        if(nKind == 0)//草莓为5
                        {
                            if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer2) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer2)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                               this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                               this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                               this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                               this->player2->nBrand+=3;
                            }
                            else if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer2))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceRed1(this->brandStackPlayer2) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer2)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer1)%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer2)%5==0&&getSurfaceRed1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer3)%5==0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }



                        }
                        else if(nKind == 1)//香蕉为5
                        {
                            if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer2) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer2)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer2))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer2) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer2)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer1)%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer2)%5==0&&getSurfaceYellow1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer3)%5==0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }

                        }
                        else if(nKind == 2)//紫色为5
                        {
                            if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer2) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer2)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer2))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfacePurple1(this->brandStackPlayer2) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer2)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer1)%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer2)%5==0&&getSurfacePurple1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer3)%5==0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                        }
                        else if(nKind == 3)//橘子为5
                        {
                            if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer2) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer2)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer2))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer2) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer2)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand+=2;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer1)%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer2)%5==0&&getSurfaceGreen1(this->brandStackPlayer2)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer3)%5==0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player2->nBrand++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }

                        }
                        else if(nKind == 4)//大象吃草莓
                        {
                            if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0&&getSurfaceRed1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0&&getSurfaceRed1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0&&getSurfaceRed1(this->brandStackPlayer2)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->nBrand+=2;
                            }

                        }
                        else if(nKind == 5)//猴子吃香蕉
                        {
                            if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0&&getSurfaceYellow1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0&&getSurfaceYellow1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0&&getSurfaceYellow1(this->brandStackPlayer2)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->nBrand+=2;
                            }

                        }
                        else if(nKind == 6)//猪吃梅子
                        {
                            if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0&&getSurfacePurple1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0&&getSurfacePurple1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0&&getSurfacePurple1(this->brandStackPlayer2)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }

                        }
                        else if(nKind == 7)//绵羊吃柠檬
                        {
                            if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0&&getSurfaceGreen1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0&&getSurfaceGreen1(this->brandStackPlayer3)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0&&getSurfaceGreen1(this->brandStackPlayer2)>0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer3) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player2->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0)
                            {
                                this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player2->nBrand+=2;
                            }
                        }
                        else if(nKind == 8)
                        {

                        }    //狼吃其它动物
                        if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0)&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {//玩家一是狼其余全是动物
                            this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player2->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0)&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家二是狼其余全是动物
                            this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player2->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0)&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家三是狼，其余全是动物
                            this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player2->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家一是狼，玩家二是动物
                            this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player2->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家一是狼，玩家三是动物
                            this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;

                            this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player2->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0))
                        {
                            //玩家二是狼，玩家一是动物
                            this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player2->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家二是狼，玩家三是动物
                            this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player2->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0))
                        {
                            //玩家三是狼，玩家一是动物
                            this->player2->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player2->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家三是狼，玩家二是动物
                            this->player2->myBrand[pop(this->brandStackPlayer3)][4]++;

                            this->player2->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player2->nBrand+=2;
                        }
                        else
                        {
                            qDebug()<<"error"<<endl;
                        }

                        //更新卡牌显示
                        QPixmap pix1;
                        QPixmap pix2;
                        QPixmap pix3;

                        QString str1 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][0]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][1]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][2]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][3]);
                        QString str2 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][0]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][1]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][2]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][3]);
                        QString str3 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][0]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][1]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][2]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][3]);

                        pix1.load(str1);
                        pix2.load(str2);
                        pix3.load(str3);
                        moveEffect3->hide();
                        moveEffect2->hide();
                        moveEffect1->hide();
                        fruitBrandsPlayer1->setIcon(pix1);
                        fruitBrandsPlayer2->setIcon(pix2);
                        fruitBrandsPlayer3->setIcon(pix3);
                        //显示
                        qDebug()<<"恭喜玩家二按铃成功!"<<endl;


                    }
                    else if(this->jud->isDifficultRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3,nKind)==0)
                    {
                        //惩罚
                        QString strPlayer2("玩家二被惩罚!给每位玩家发一张牌");
                        player2Label->setText(strPlayer2);
                        animationPlayer2->start();
                        qDebug()<<"玩家二被惩罚!给每位玩家发一张牌"<<endl;
                        int nPunish = 0;
                        int nCountPunish = 0;
                        while(1)
                        {
                            if(player2->myBrand[nPunish][4] >= 1&&nCountPunish == 0)
                            {
                                //将玩家二的一张牌发给玩家一
                                player1->myBrand[nPunish][4] += 1;
                                player1->nBrand++;
                                //记录下惩罚次数
                                nCountPunish++;
                                //将玩家二的该张牌去除
                                player2->myBrand[nPunish][4] -= 1;
                                player2->nBrand--;
                            }
                            else if
                                    (player2->myBrand[nPunish][4] != 0&&nCountPunish == 1)
                            {
                                player3->myBrand[nPunish][4] += 1;
                                player3->nBrand++;
                                nCountPunish++;
                                //将玩家一的该张牌去除
                                player2->myBrand[nPunish][4] -= 1;
                                player2->nBrand--;
                                //结束惩罚循环
                                break;
                            }
                            nPunish++;
                        }
                        *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
                        nBrandPlayer2->setText(*str2);
                        *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                        nBrandPlayer1->setText(*str1);
                        *str3 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
                        nBrandPlayer3->setText(*str3);
                    }
                    //更新牌数
                    QString str = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                    nBrandPlayer1->setText(str);
                }//difficult==1的反括号

            }


        else
        {
            qDebug()<<"玩家二已经出局"<<endl;
        }

    });
    //字幕显示
     QLabel *player3Label = new QLabel;
     player3Label->setParent(this);
     player3Label->setFixedSize(550,50);
     player3Label->move(300,200);
     QFont f3("微软雅黑",20,QFont::Bold,true);
     player3Label->setStyleSheet("color:green");
     player3Label->setFont(f3);

     QPropertyAnimation * animationPlayer3 = new QPropertyAnimation (player3Label,"geometry");
     animationPlayer3->setDuration(3000);
     animationPlayer3->setStartValue(QRect(0,200,player3Label->width(),player3Label->height()));
     animationPlayer3->setEndValue(QRect(1000,200,player3Label->width(),player3Label->height()));

    connect(this,&easyExplainationScene::_9PressSignal,[=](){
        if(jud->isOutOfGamePlayer3 != 1)
        {
            bellSound->play();
            if((this->jud-> complex==1&&this->jud->isComplexRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==true)||(this->jud->easy==1&&this->jud->isEasyRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==true))
            {

                QString strPlayer3("恭喜玩家三按铃成功!");
                player3Label->setText(strPlayer3);
                animationPlayer3->start();
                    //将牌堆中的牌全部给三玩家
                while(brandStackPlayer1.pTop>-1)
                {
                    this->player3->myBrand[pop(brandStackPlayer1)][4] += 1;
                    this->player3->nBrand++;

                }



                while(this->brandStackPlayer2.pTop > -1)
                {
                    this->player3->myBrand[pop(brandStackPlayer2)][4] += 1;
                    this->player3->nBrand++;

                }



                while(this->brandStackPlayer3.pTop > -1)
                {
                    this->player3->myBrand[pop(brandStackPlayer3)][4] += 1;
                    this->player3->nBrand++;

                }
                        *str3 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
                        nBrandPlayer3->setText(*str3);
                    //显示空牌堆
                    QPixmap pix;
                    pix.load(":/res/底牌.jpg");
                    moveEffect3->hide();
                    moveEffect2->hide();
                    moveEffect1->hide();
                    fruitBrandsPlayer1->setIcon(pix);
                    fruitBrandsPlayer2->setIcon(pix);
                    fruitBrandsPlayer3->setIcon(pix);
                    //显示
                    qDebug()<<"恭喜玩家三按铃成功!"<<endl;



                }
                //按错铃的惩罚机制
                else if((this->jud->complex==1&&jud->isComplexRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==false)||(this->jud->easy==1&&jud->isEasyRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3)==false))
                {
                QString strPlayer3("玩家三被惩罚!给每位玩家发一张牌");
                player3Label->setText(strPlayer3);
                animationPlayer3->start();
                    qDebug()<<"玩家一被惩罚!给每位玩家发一张牌"<<endl;
                    int nPunish = 0;
                    int nCountPunish = 0;
                    while(1)
                    {
                        if(player3->myBrand[nPunish][4] >= 1&&nCountPunish == 0)
                        {
                            //将玩家三的一张牌发给玩家一
                            player1->myBrand[nPunish][4] += 1;
                            player1->nBrand++;
                            //记录下惩罚次数
                            nCountPunish++;
                            //将玩家三的该张牌去除
                            player3->myBrand[nPunish][4] -= 1;
                            player3->nBrand--;
                        }
                        else if
                                (player3->myBrand[nPunish][4] >= 1&&nCountPunish == 1)
                        {
                            player2->myBrand[nPunish][4] += 1;
                            player2->nBrand++;
                            nCountPunish++;
                            //将玩家三的该张牌去除
                            player3->myBrand[nPunish][4] -= 1;
                            player3->nBrand--;
                            //结束惩罚循环
                            break;
                        }
                        nPunish++;
                    }
                    *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
                    nBrandPlayer2->setText(*str2);
                    *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                    nBrandPlayer1->setText(*str1);
                    *str3 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
                    nBrandPlayer3->setText(*str3);
                }
            //困难模式处理方法
                if(this->jud->difficult == 1)
                {
                    QString strPlayer3("恭喜玩家三按铃成功!");
                    player3Label->setText(strPlayer3);
                    animationPlayer3->start();
                   //显示
                   qDebug()<<"恭喜玩家三按铃成功!"<<endl;
                    int nKind;
                    if(this->jud->isDifficultRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3,nKind)==1)
                    {
                        if(nKind == 0)//草莓为5
                        {
                            if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer2) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer2)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                               this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                               this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                               this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                               this->player3->nBrand+=3;
                            }
                            else if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer2))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceRed1(this->brandStackPlayer1) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceRed1(this->brandStackPlayer2) + getSurfaceRed1(this->brandStackPlayer3))%5==0&&getSurfaceRed1(this->brandStackPlayer2)!=0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer1)%5==0&&getSurfaceRed1(this->brandStackPlayer1)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer2)%5==0&&getSurfaceRed1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceRed1(this->brandStackPlayer3)%5==0&&getSurfaceRed1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }



                        }
                        else if(nKind == 1)//香蕉为5
                        {
                            if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer2) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer2)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer2))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer1) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceYellow1(this->brandStackPlayer2) + getSurfaceYellow1(this->brandStackPlayer3))%5==0&&getSurfaceYellow1(this->brandStackPlayer2)!=0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer1)%5==0&&getSurfaceYellow1(this->brandStackPlayer1)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer2)%5==0&&getSurfaceYellow1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceYellow1(this->brandStackPlayer3)%5==0&&getSurfaceYellow1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }

                        }
                        else if(nKind == 2)//紫色为5
                        {
                            if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer2) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer2)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer2))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfacePurple1(this->brandStackPlayer1) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfacePurple1(this->brandStackPlayer2) + getSurfacePurple1(this->brandStackPlayer3))%5==0&&getSurfacePurple1(this->brandStackPlayer2)!=0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer1)%5==0&&getSurfacePurple1(this->brandStackPlayer1)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer2)%5==0&&getSurfacePurple1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfacePurple1(this->brandStackPlayer3)%5==0&&getSurfacePurple1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                        }
                        else if(nKind == 3)//橘子为5
                        {
                            if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer2) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer2)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer2))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer1) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }
                            else if((getSurfaceGreen1(this->brandStackPlayer2) + getSurfaceGreen1(this->brandStackPlayer3))%5==0&&getSurfaceGreen1(this->brandStackPlayer2)!=0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand+=2;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer1)%5==0&&getSurfaceGreen1(this->brandStackPlayer1)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer2)%5==0&&getSurfaceGreen1(this->brandStackPlayer2)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            }
                            //单个牌是5的倍数
                            else if(getSurfaceGreen1(this->brandStackPlayer3)%5==0&&getSurfaceGreen1(this->brandStackPlayer3)!=0)
                            {
                                this->player3->nBrand++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            }

                        }
                        else if(nKind == 4)//大象吃草莓
                        {
                            if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0&&getSurfaceRed1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0&&getSurfaceRed1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0&&getSurfaceRed1(this->brandStackPlayer2)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer1) == 1&&getSurfaceRed1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer2) == 1&&getSurfaceRed1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceElephant1(this->brandStackPlayer3) == 1&&getSurfaceRed1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->nBrand+=2;
                            }

                        }
                        else if(nKind == 5)//猴子吃香蕉
                        {
                            if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0&&getSurfaceYellow1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0&&getSurfaceYellow1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0&&getSurfaceYellow1(this->brandStackPlayer2)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer1) == 1&&getSurfaceYellow1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer2) == 1&&getSurfaceYellow1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceMonkey1(this->brandStackPlayer3) == 1&&getSurfaceYellow1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->nBrand+=2;
                            }

                        }
                        else if(nKind == 6)//猪吃梅子
                        {
                            if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0&&getSurfacePurple1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0&&getSurfacePurple1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0&&getSurfacePurple1(this->brandStackPlayer2)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer1) == 1&&getSurfacePurple1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer2) == 1&&getSurfacePurple1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfacePig1(this->brandStackPlayer3) == 1&&getSurfacePurple1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }

                        }
                        else if(nKind == 7)//绵羊吃柠檬
                        {
                            if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0&&getSurfaceGreen1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0&&getSurfaceGreen1(this->brandStackPlayer3)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0&&getSurfaceGreen1(this->brandStackPlayer2)>0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=3;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer1) == 1&&getSurfaceGreen1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer2) == 1&&getSurfaceGreen1(this->brandStackPlayer3) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer1) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player3->nBrand+=2;
                            }
                            else if(getSurfaceSheep1(this->brandStackPlayer3) == 1&&getSurfaceGreen1(this->brandStackPlayer2) >0)
                            {
                                this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                                this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                                this->player3->nBrand+=2;
                            }
                        }
                        else if(nKind == 8)
                        {

                        }    //狼吃其它动物
                        if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0)&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {//玩家一是狼其余全是动物
                            this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player3->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0)&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家二是狼其余全是动物
                            this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player3->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0)&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家三是狼，其余全是动物
                            this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player3->nBrand+=3;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家一是狼，玩家二是动物
                            this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player3->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer1) == 1&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家一是狼，玩家三是动物
                            this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;

                            this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player3->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0))
                        {
                            //玩家二是狼，玩家一是动物
                            this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player3->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer2) == 1&&(getSurfaceElephant1(this->brandStackPlayer3) >0||getSurfaceMonkey1(this->brandStackPlayer3) >0||getSurfacePig1(this->brandStackPlayer3) >0||getSurfaceSheep1(this->brandStackPlayer3) >0))
                        {
                            //玩家二是狼，玩家三是动物
                            this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;

                            this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;
                            this->player3->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer1) >0||getSurfaceMonkey1(this->brandStackPlayer1) >0||getSurfacePig1(this->brandStackPlayer1) >0||getSurfaceSheep1(this->brandStackPlayer1) >0))
                        {
                            //玩家三是狼，玩家一是动物
                            this->player3->myBrand[pop(this->brandStackPlayer1)][4]++;
                            this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            this->player3->nBrand+=2;
                        }
                        else if(getSurfaceWolf1(this->brandStackPlayer3) == 1&&(getSurfaceElephant1(this->brandStackPlayer2) >0||getSurfaceMonkey1(this->brandStackPlayer2) >0||getSurfacePig1(this->brandStackPlayer2) >0||getSurfaceSheep1(this->brandStackPlayer2) >0))
                        {
                            //玩家三是狼，玩家二是动物
                            this->player3->myBrand[pop(this->brandStackPlayer3)][4]++;

                            this->player3->myBrand[pop(this->brandStackPlayer2)][4]++;
                            this->player3->nBrand+=2;
                        }
                        else
                        {
                            qDebug()<<"error"<<endl;
                        }

                        //更新卡牌显示
                        QPixmap pix1;
                        QPixmap pix2;
                        QPixmap pix3;

                        QString str1 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][0]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][1]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][2]).arg(this->brandStackPlayer1.stack[this->brandStackPlayer1.pTop][3]);
                        QString str2 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][0]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][1]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][2]).arg(this->brandStackPlayer2.stack[this->brandStackPlayer2.pTop][3]);
                        QString str3 = QString(":/res/%1%2%3%4.jpg").arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][0]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][1]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][2]).arg(this->brandStackPlayer3.stack[this->brandStackPlayer3.pTop][3]);

                        pix1.load(str1);
                        pix2.load(str2);
                        pix3.load(str3);
                        moveEffect3->hide();
                        moveEffect2->hide();
                        moveEffect1->hide();
                        fruitBrandsPlayer1->setIcon(pix1);
                        fruitBrandsPlayer2->setIcon(pix2);
                        fruitBrandsPlayer3->setIcon(pix3);
                        //显示
                        qDebug()<<"恭喜玩家三按铃成功!"<<endl;


                    }
                    else if(this->jud->isDifficultRegulation(this->brandStackPlayer1,this->brandStackPlayer2,this->brandStackPlayer3,nKind)==0)
                    {
                        //惩罚
                        QString strPlayer3("玩家三被惩罚!给每位玩家发一张牌");
                        player3Label->setText(strPlayer3);
                        animationPlayer3->start();
                        qDebug()<<"玩家一被惩罚!给每位玩家发一张牌"<<endl;
                        int nPunish = 0;
                        int nCountPunish = 0;
                        while(1)
                        {
                            if(player3->myBrand[nPunish][4] >= 1&&nCountPunish == 0)
                            {
                                //将玩家一的一张牌发给玩家二
                                player2->myBrand[nPunish][4] += 1;
                                player2->nBrand++;
                                //记录下惩罚次数
                                nCountPunish++;
                                //将玩家一的该张牌去除
                                player3->myBrand[nPunish][4] -= 1;
                                player3->nBrand--;
                            }
                            else if
                                    (player3->myBrand[nPunish][4] != 0&&nCountPunish == 1)
                            {
                                player1->myBrand[nPunish][4] += 1;
                                player1->nBrand++;
                                nCountPunish++;
                                //将玩家一的该张牌去除
                                player3->myBrand[nPunish][4] -= 1;
                                player3->nBrand--;
                                //结束惩罚循环
                                break;
                            }
                            nPunish++;
                        }
                        *str2 = QString("玩家二剩余%1张牌").arg(this->player2->nBrand);
                        nBrandPlayer2->setText(*str2);
                        *str1 = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                        nBrandPlayer1->setText(*str1);
                        *str3 = QString("玩家三剩余%1张牌").arg(this->player3->nBrand);
                        nBrandPlayer3->setText(*str3);
                    }
                    //更新牌数
                    QString str = QString("玩家一剩余%1张牌").arg(this->player1->nBrand);
                    nBrandPlayer1->setText(str);
                }//difficult==1的反括号

            }


        else
        {
            qDebug()<<"玩家三已经出局"<<endl;
        }
    });
    //胜利图片
    QLabel * winLabel = new QLabel;
    QPixmap tmpPix;
    QLabel * winLabelText = new QLabel;
    winLabelText->setText("玩家一");
    winLabelText->setAlignment(Qt::AlignCenter);
    winLabelText->move(0,50);
    QFont font1("微软雅黑",50,QFont::Bold,true);
    winLabelText->setFont(font1);
    winLabelText->setStyleSheet("color:red");
    winLabelText->hide();



    winLabelText->setParent(this);


    tmpPix.load("://res/victory.jpg");
    winLabel->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);

    winLabel->move((this->width() - tmpPix.width()) * 0.5,-tmpPix.height());
    //胜利之后把图片移下来
    QTimer*timer1 = new QTimer(this);
    QTimer*timer2 = new QTimer(this);
    //启动定时器
    timer1->start(1000);//发送信号

    connect(timer1,&QTimer::timeout,[=]{
        if(this->jud->isOutOfGamePlayer3 == 1&&jud->isOutOfGamePlayer2 == 1)
        {
            qDebug()<<"游戏结束"<<endl;
            QPropertyAnimation * animation = new QPropertyAnimation (winLabel,"geometry");
            animation->setDuration(1000);
            animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
            animation->setEndValue(QRect(winLabel->x(),winLabel->y() + 250,winLabel->width(),winLabel->height()));
            animation->setEasingCurve(QEasingCurve::OutBounce);
            animation->start();
            winLabelText->setText("玩家一胜利");
            winLabelText->show();
            timer2->start(50);
            timer1->stop();

        }
        else if(this->jud->isOutOfGamePlayer3 == 1&&jud->isOutOfGamePlayer1 == 1)
    {
        qDebug()<<"游戏结束"<<endl;
        QPropertyAnimation * animation = new QPropertyAnimation (winLabel,"geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
        animation->setEndValue(QRect(winLabel->x(),winLabel->y() + 250,winLabel->width(),winLabel->height()));
        animation->setEasingCurve(QEasingCurve::OutBounce);
        animation->start();
        winLabelText->setText("玩家二胜利");
        winLabelText->show();
        timer2->start(50);
        timer1->stop();
     }
        else if(this->jud->isOutOfGamePlayer2 == 1&&jud->isOutOfGamePlayer1 == 1)
        {
            qDebug()<<"游戏结束"<<endl;
            QPropertyAnimation * animation = new QPropertyAnimation (winLabel,"geometry");
            animation->setDuration(1000);
            animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
            animation->setEndValue(QRect(winLabel->x(),winLabel->y() + 250,winLabel->width(),winLabel->height()));
            animation->setEasingCurve(QEasingCurve::OutBounce);
            animation->start();
            winLabelText->setText("玩家三胜利");
            winLabelText->show();
            timer2->start(50);
            timer1->stop();
        }

    });
    //字幕滑动特效


    connect(timer2,&QTimer::timeout,[=]{

        QPropertyAnimation * animation = new QPropertyAnimation (winLabelText,"geometry");
        animation->setDuration(1000);
        animation->setStartValue(QRect(winLabelText->x(),winLabelText->y(),winLabelText->width(),winLabelText->height()));
        animation->setEndValue(QRect(winLabelText->x() + 100,winLabelText->y() ,winLabelText->width(),winLabelText->height()));
        animation->start();

        qDebug()<<"move"<<endl;

    });

}

void easyExplainationScene::paintEvent(QPaintEvent *)
{

    //背景图设置
    QPainter painter(this);
    QPixmap pix;
    pix.load("://res/桌面.JPEG");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

//    painter.drawPixmap(0,0,200,300,fruitBrands[0].pix);


}


void easyExplainationScene::keyPressEvent(QKeyEvent*event)
{

    //监听玩家一操作

    //出牌
    if(event->key() ==Qt::Key_Z)
    {
        //判断是否为玩家一的回合
        if(this->jud->player1Turn ==1||this->jud->isOutOfGamePlayer3 == 1)
        {
            emit this->z_PressSignal();
            qDebug()<<"按下了z键"<<endl;
            //禁止该玩家出牌，给予下一个玩家出牌权
            this->jud->player2Turn = 1;
            this->jud->player1Turn = 0;
        }
       else
        {
            qDebug()<<"现在不是你的回合哦！"<<endl;
        }
    }
    //按铃
    if(event->key() == Qt::Key_Q)
    {
        qDebug()<<"玩家一按铃了！"<<endl;
        emit this->Q_PressSignal();
    }
    //监听玩家二操作

    //出牌
    if(event->key() ==Qt::Key_M)
    {
                      //判断是否为玩家二的回合
                      if(this->jud->player2Turn ==1||this->jud->isOutOfGamePlayer1 == 1)
                      {
                          emit this->m_PressSignal();
                          qDebug()<<"按下了m键"<<endl;
                          //禁止该玩家出牌，给予下一个玩家出牌权
                          this->jud->player3Turn = 1;
                          this->jud->player2Turn = 0;
                      }
                     else
                      {
                          qDebug()<<"现在不是你的回合哦！"<<endl;
                      }
    }

    //按铃
    if(event->key() == Qt::Key_P)
    {
        qDebug()<<"玩家二按铃了！"<<endl;
        emit this->p_PressSignal();
    }
    //监听玩家三操作

    //出牌
    if(event->key() ==Qt::Key_0)
    {
        //判断是否为玩家三的回合
        if(this->jud->player3Turn ==1||this->jud->isOutOfGamePlayer2 == 1)
        {
            emit this->_0PressSignal();
            qDebug()<<"按下了0键"<<endl;
            //禁止该玩家出牌，给予下一个玩家出牌权
            this->jud->player1Turn = 1;
            this->jud->player3Turn = 0;
        }
       else
        {
            qDebug()<<"现在不是你的回合哦！"<<endl;
        }
    }
    //按铃
    if(event->key() == Qt::Key_9)
    {
        qDebug()<<"玩家三按铃了！"<<endl;
        emit this->_9PressSignal();
    }
    //开局的效果
    if(event->key() == Qt::Key_K)
    {
        emit this->K_PressSignal();
    }
}
