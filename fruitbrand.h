#ifndef FRUITBRAND_H
#define FRUITBRAND_H
#include <brand.h>
#include<mybrand.h>
class fruitBrand:public MyBrand
{
public:

    fruitBrand(const char filepath[],int _width,int _height,int _nRed,int _nYellow,int _nPurple,int _nGreen):MyBrand(filepath,_width,_height),nRed(_nRed),nYellow(_nYellow),nGreen(_nGreen),nPurple(_nPurple){}
    int nRed;
    int nYellow;
    int nPurple;
    int nGreen;


};

#endif // FRUITBRAND_H
