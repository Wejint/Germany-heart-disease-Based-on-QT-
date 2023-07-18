#ifndef JUDGER_H
#define JUDGER_H
#include<player.h>
typedef struct stack
{
    int stack[56][5];//最后一位记录牌在玩家的位置
    int pTop;

}stack;
class judger
{
public:
    judger();
    void addNSurfaceCountStrawberry(int n){nSurfaceCountStrawberry+=n;}
    void addNSurfaceCountBanana(int n){nSurfaceCountBanana+=n;}

    void addNSurfaceCountPurple(int n){nSurfaceCountPurple+=n;}
    void addNSurfaceCountOrange(int n){nSurfaceCountOrange+=n;}

    short int getNSurfaceCountStrawberry(){return nSurfaceCountStrawberry;}
    short int getNSurfaceCountBanana(){return nSurfaceCountBanana;}
    short int getNSurfaceCountPurple(){return nSurfaceCountPurple;}
    short int getNSurfaceCountOrange(){return nSurfaceCountOrange;}
    bool isComplexRegulation(stack player1Stack,stack player2Stack,stack player3Stack);
    bool isEasyRegulation(stack player1Stack,stack player2Stack,stack player3Stack);
    bool isDifficultRegulation(stack player1Stack,stack player2Stack,stack player3Stack,int &nKind);
    bool isOutOfGame(Player *p);
    void Punish(Player* p1,Player* p2,Player* p3);
    short int nOut;
    short int player1Turn;
    short int player2Turn;
    short int player3Turn;

    //记录游戏模式
    bool easy;
    bool complex;
    bool difficult;
    //记录牌堆第一张牌的情况
    short int firstStack1Brand;
    short int firstStack2Brand;
    short int firstStack3Brand;
    //记录玩家出局情况
     short int isOutOfGamePlayer1;
     short int isOutOfGamePlayer2;
     short int isOutOfGamePlayer3;
     int nElephant;
     int nMonkey;
     int nSheep;
     int nPig;
     int nWolf;
private:
    int nSurfaceCountStrawberry;
    int nSurfaceCountBanana;
    int nSurfaceCountPurple;
    int nSurfaceCountOrange;


};

#endif // JUDGER_H
