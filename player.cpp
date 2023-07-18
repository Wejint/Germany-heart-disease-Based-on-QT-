#include "player.h"

Player::Player(int _key,int _bellKey,int (*_Brands)[5],int _nBrand)
{
    this->outPutKey = _key;
    this->BellKey = _bellKey;
    this->nBrand = _nBrand;
    this->isOutputBrand = 0;
    for(int i = 0;i<56;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            myBrand[i][j] = _Brands[i][j];
        }
    }

};
