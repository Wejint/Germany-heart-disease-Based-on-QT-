#ifndef MYPUSHBOTTON_H
#define MYPUSHBOTTON_H

#include <QMainWindow>
#include <QWidget>
#include<QPushButton>
class MyPushBotton:public QPushButton
{
public:
    MyPushBotton(QString normalImg,QString pressImg = "");
    //正常显示图片路径
    QString normalImgPath;
    //按下后显示的图片路径
    QString pressImgPath;
    //弹跳特效
    void Up();
    void Down();
};

#endif // MYPUSHBOTTON_H
