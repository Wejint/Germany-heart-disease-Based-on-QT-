#include "mainsecene.h"
#include "ui_mainsecene.h"
#include<QPainter>
#include"mypushbotton.h"
#include<QDebug>
#include<QTimer>
#include<QSound>

MainSecene::MainSecene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSecene)
{
    ui->setupUi(this);
    //配置主场景
    //设置固定大小

    setFixedSize(1000,800);
    //设置图标
    setWindowIcon(QIcon(":/res/Title_Picture.jpg"));
    //设置标题
    setWindowTitle("德国心脏病");
    //退出按钮的实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });
    //开始音效
    QSound * backgroundSound = new QSound("://res/阿特的奇幻之旅-滑稽的旋律_20230611_115322.wav",this);
    backgroundSound->play();



    //开始按钮
    MyPushBotton * startBtn = new MyPushBotton(":/res/Start_Button.jpg");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width()*0.5,this->height() * 0.7);
     //选择关卡场景
     chooseScene = new ChooseLevelScene;
     //解释游戏规则的场景
     explainScene  = new easyExplainationScene;

    connect(startBtn,&MyPushBotton::clicked,[=](){
        qDebug()<<"点击了开始";
        //做弹起特效
        startBtn->Up();
        //延时
        QTimer::singleShot(500,this,[=]{
            //自身隐藏
            this->hide();
            //显示选择关卡场景
            chooseScene->show();
        });

    });
    //监听选择关卡的返回按钮信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        QTimer::singleShot(500,this,[=]{
            //自身隐藏
            chooseScene->hide();
            this->show();
            //


        });
    });
    //监听选择关卡选择信号
    connect(chooseScene,&ChooseLevelScene::chooseEasyScene,explainScene,[=](){
        QTimer::singleShot(500,this,[=]{
            //隐藏
            qDebug()<<"选择了简单关卡"<<endl;
            chooseScene->hide();
            explainScene->show();
            explainScene->jud->easy = 1;

            emit explainScene->easySignal();
        });
    });
    //监听选择关卡选择信号
    connect(chooseScene,&ChooseLevelScene::chooseComplexScene,explainScene,[=](){
        QTimer::singleShot(500,this,[=]{
            //隐藏
            qDebug()<<"选择了复杂关卡"<<endl;
            chooseScene->hide();
            explainScene->show();
            explainScene->jud->complex = 1;
            emit explainScene->complexSignal();
        });
    });
    //监听选择关卡选择信号
    connect(chooseScene,&ChooseLevelScene::chooseDifficultScene,explainScene,[=](){
        QTimer::singleShot(500,this,[=]{
            //隐藏
            qDebug()<<"选择了困难关卡"<<endl;
            chooseScene->hide();
            explainScene->show();
            explainScene->jud->difficult = 1;
            emit explainScene->difficultSignal();
        });
    });
    //监听解释说明界面的返回信号
    connect(explainScene,&easyExplainationScene::chooseSceneBack,chooseScene,[=](){
        QTimer::singleShot(500,chooseScene,[=]{
           explainScene -> hide();

           chooseScene->show();
           explainScene->jud->easy = 0;
           explainScene->jud->complex = 0;
           explainScene->jud->difficult = 0;
        });
    });



}


void MainSecene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/bell.jpg");
    painter.drawPixmap(400,300,pix);
    //pix = pix.scaled(pix.width())

}
void MainSecene::keyPressEvent(QKeyEvent*event)
{
    event->ignore();
    if(event->key() ==Qt::Key_Z)
    {
        emit explainScene->z_PressSignal();
        qDebug()<<"按下了z键"<<endl;
    }
}
MainSecene::~MainSecene()
{
    delete ui;
}
