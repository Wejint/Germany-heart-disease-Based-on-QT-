#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player(){}
    Player(int _key,int _bellKey,int (*_Brands)[5],int _nBrand);

    int myBrand[56][5];
    int getKey(){return outPutKey;}
    int outPutKey;
    int BellKey;
    int nBrand;
    bool isOutputBrand;
private:
    //控制的案件

    //卡牌
    //行数代表不同的牌
    //前四行分别代表红，黄，紫，绿的牌数最后用0，1代表是否拥有这张牌。


};

#endif // PLAYER_H
