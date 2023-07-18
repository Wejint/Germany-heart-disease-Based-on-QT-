#include "chooselevelscene.h"
#include<QMenu>
#include<QMenuBar>
#include<QPainter>
#include<QImage>
#include<QRgb>
#include"mypushbotton.h"
#include<QLabel>
#include<QDebug>


ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
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
    //创建选择关卡的按钮
        //简单
        MyPushBotton * menuBtn = new MyPushBotton(":/res/button.jpg");
        menuBtn->setFixedSize(240,80);

        menuBtn->setParent(this);
        menuBtn->move(this->width()/2 - menuBtn->width()/2,this->height() / 2 - menuBtn->height() - 120);
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setText("简单");
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label->move(this->width()/2 - menuBtn->width()/2,this->height() / 2 - menuBtn->height() - 120);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        connect(menuBtn,&MyPushBotton::clicked,this,[=](){
            qDebug()<<"点击了选择关卡按钮";
            menuBtn->Up();

            emit chooseEasyScene();
        });
        //复杂
        MyPushBotton * menuBtn1 = new MyPushBotton(":/res/button.jpg");
        menuBtn1->setFixedSize(240,80);

        menuBtn1->setParent(this);
        menuBtn1->move(this->width()/2 - menuBtn->width()/2,this->height() / 2 - menuBtn->height() );
        QLabel * label1 = new QLabel;
        label1->setParent(this);
        label1->setFixedSize(menuBtn->width(),menuBtn->height());
        label1->setText("复杂");
//        label1->setFixedSize(20,20);
        label1->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label1->move(this->width()/2 - menuBtn->width()/2,this->height() / 2 - menuBtn->height() );
        label1->setAttribute(Qt::WA_TransparentForMouseEvents);
        connect(menuBtn1,&MyPushBotton::clicked,this,[=](){
            qDebug()<<"点击了选择关卡按钮";
            menuBtn1->Up();

            emit chooseComplexScene();
        });
        //困难
        MyPushBotton * menuBtn2 = new MyPushBotton(":/res/button.jpg");
        menuBtn2->setFixedSize(240,80);

        menuBtn2->setParent(this);
        menuBtn2->move(this->width()/2 - menuBtn->width()/2,this->height() / 2 - menuBtn->height() + 120);
        QLabel * label2 = new QLabel;
        label2->setParent(this);
        label2->setFixedSize(menuBtn->width(),menuBtn->height());
        label2->setText("困难");
        label2->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label2->move(this->width()/2 - menuBtn->width()/2,this->height() / 2 - menuBtn->height() + 120);
        label2->setAttribute(Qt::WA_TransparentForMouseEvents);
        connect(menuBtn2,&MyPushBotton::clicked,this,[=](){
            qDebug()<<"点击了选择关卡按钮";
            menuBtn2->Up();

            emit chooseDifficultScene();
        });
}
 void ChooseLevelScene::paintEvent(QPaintEvent *)
 {
     //背景图设置
     QPainter painter(this);
     QPixmap pix;
     pix.load("://res/OIP-C.jpg");
     painter.drawPixmap(0,0,this->width(),this->height(),pix);

     //bell设置
//     QPixmap tmpPixmap = QPixmap::fromImage(processImage("://res/bell.jpg"));
//     pix.load("://res/bell.jpg");
//     painter.drawPixmap(400,300,pix);

 }
