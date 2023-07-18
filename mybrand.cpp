#include "mybrand.h"
#include<mypushbotton.h>
#include<QPushButton>
#include<QDebug>
//MyBrand::MyBrand(QWidget *parent)
//{

//}

MyBrand::MyBrand( QString strFilePath,int _width,int _height)
{
    this->height = _height;
    this->width = _width;
    QPixmap pix;
    bool ret = pix.load(strFilePath);
    if(!ret)
    {
        QString str = QString("图片%1加载失败").arg(strFilePath);
        qDebug()<<"图片加载失败"<<endl;
    }
    this->setFixedSize(this->width,this->height);
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.width()));
}
