#ifndef MYBRAND_H
#define MYBRAND_H

#include <QPushButton>

class MyBrand : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyBrand(QWidget *parent = nullptr);
    MyBrand( QString strFilePath,int _width,int _height);
    int getWidth(){return width;}
    int getHeight(){return height;}

    QPixmap pix;
private:
    int width;
    int height;
signals:

public slots:
};

#endif // MYBRAND_H
