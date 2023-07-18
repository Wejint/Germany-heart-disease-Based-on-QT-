#ifndef BRAND_H
#define BRAND_H
#include<QPainter>
#include<string.h>
#include<QDebug>
class Brand
{
public:
    Brand(){}
    Brand( QString strFilePath,int _width,int _height):width(_width),height(_height){
        pix.load(strFilePath);


    }
    int getWidth(){return width;}
    int getHeight(){return height;}
    void move(int x,int y);
    QPixmap pix;
private:
    int width;
    int height;

};

#endif // BRAND_H
