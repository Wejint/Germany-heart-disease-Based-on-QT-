#include "mypushbotton.h"
#include<QDebug>
#include<QPropertyAnimation>
MyPushBotton::MyPushBotton(QString normalImg,QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;
    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPUshButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小；
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void MyPushBotton::Down()
{
    //创建动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}
void MyPushBotton::Up()
{
    //创建动画对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+ 10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //执行动画
    animation->start();

}
