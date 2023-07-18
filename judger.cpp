#include "judger.h"
#include<QDebug>
int getSurfaceRed(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][0];
    }
    else
    {
        return 0;
    }
}
int getSurfaceYellow(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][1];
    }
    else
    {
        return 0;
    }
}
int getSurfacePurple(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][2];
    }
    else
    {
        return 0;
    }
}
int getSurfaceGreen(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return Stack.stack[Stack.pTop][3];
    }
    else
    {
        return 0;
    }
}
int getSurfaceWolf(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 55)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfaceSheep(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 54)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfacePig(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 53)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfaceMonkey(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 52)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getSurfaceElephant(stack Stack)
{
    if(Stack.pTop == -1){return 0;}
    if(Stack.stack[Stack.pTop][4] < 51)
    {
        return 0;
    }
    else if(Stack.stack[Stack.pTop][4] == 51)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
judger::judger()
{
    this->nSurfaceCountStrawberry = 0;
    this->nSurfaceCountBanana = 0;
    this->nSurfaceCountOrange = 0;
    this->nSurfaceCountPurple = 0;
    this->nElephant = 0;
    this->nMonkey = 0;
    this->nPig = 0;
    this->nSheep = 0;
    this->nWolf = 0;
    this->player1Turn = 1;
    this->player2Turn = 0;
    this->player3Turn = 0;
    this->easy = 0;
    this->complex = 0;
    this->difficult = 0;
    this->isOutOfGamePlayer1 = 0;
    this->isOutOfGamePlayer2 = 0;
    this->isOutOfGamePlayer3 = 0;
    this->nOut = 0;
}
bool judger::isComplexRegulation(stack player1Stack,stack player2Stack,stack player3Stack)
{
    this->nSurfaceCountStrawberry = getSurfaceRed(player1Stack) + getSurfaceRed(player2Stack)+getSurfaceRed(player3Stack);
    this->nSurfaceCountBanana = getSurfaceYellow(player1Stack) + getSurfaceYellow(player2Stack)+getSurfaceYellow(player3Stack);
    this->nSurfaceCountPurple = getSurfacePurple(player1Stack) + getSurfacePurple(player2Stack)+getSurfacePurple(player3Stack);
    this->nSurfaceCountOrange = getSurfaceGreen(player1Stack) + getSurfaceGreen(player2Stack)+getSurfaceGreen(player3Stack);
    this->nWolf = getSurfaceWolf(player1Stack) + getSurfaceWolf(player2Stack)+getSurfaceWolf(player3Stack);
    this->nPig = getSurfacePig(player1Stack) + getSurfacePig(player2Stack)+getSurfacePig(player3Stack);
    this->nMonkey = getSurfaceMonkey(player1Stack) + getSurfaceMonkey(player2Stack)+getSurfaceMonkey(player3Stack);
    this->nSheep = getSurfaceSheep(player1Stack) + getSurfaceSheep(player2Stack)+getSurfaceSheep(player3Stack);
    if(this->nSurfaceCountOrange % 5==0&&this->nSurfaceCountOrange!=0)
    {
        return true;
    }
    else if(this->nSurfaceCountBanana % 5==0&&this->nSurfaceCountBanana!=0)
    {
        return true;
    }
    else if(this->nSurfaceCountPurple % 5==0&&this->nSurfaceCountPurple!=0)
    {
        return true;
    }
    else if(this->nSurfaceCountStrawberry % 5==0&&this->nSurfaceCountStrawberry!=0)
    {
        return true;
    }
    else if(this->nWolf >= 1&&(this->nMonkey >= 1||this->nElephant >= 1||this->nPig >= 1||this->nSheep >= 1))
    {
        return true;
    }
    else if(this->nElephant >= 1 && this->nSurfaceCountStrawberry>=1)
    {
        return true;
    }
    else if(this->nMonkey >= 1&&this->nSurfaceCountBanana>=1)
    {
        return true;
    }
    else if(this->nPig >= 1&&this->nSurfaceCountPurple>=1)
    {
        return true;
    }
    else if(this->nSheep >= 1&&this->nSurfaceCountOrange>=1)
    {
        return true;
    }
    else {return false;}
}
bool judger::isEasyRegulation(stack player1Stack,stack player2Stack,stack player3Stack)
{
    this->nSurfaceCountOrange = getSurfaceGreen(player1Stack) + getSurfaceGreen(player2Stack)+getSurfaceGreen(player3Stack);
    this->nWolf = getSurfaceWolf(player1Stack) + getSurfaceWolf(player2Stack)+getSurfaceWolf(player3Stack);
    this->nPig = getSurfacePig(player1Stack) + getSurfacePig(player2Stack)+getSurfacePig(player3Stack);
    this->nMonkey = getSurfaceMonkey(player1Stack) + getSurfaceMonkey(player2Stack)+getSurfaceMonkey(player3Stack);
    this->nSheep = getSurfaceSheep(player1Stack) + getSurfaceSheep(player2Stack)+getSurfaceSheep(player3Stack);
    //水果牌判断
    if((getSurfaceGreen(player1Stack)==getSurfaceGreen(player2Stack)&&getSurfaceGreen(player1Stack)!=0)||(getSurfaceGreen(player1Stack)==getSurfaceGreen(player3Stack)&&getSurfaceGreen(player1Stack)!=0)||(getSurfaceGreen(player3Stack)==getSurfaceGreen(player2Stack)&&getSurfaceGreen(player2Stack)!=0))
    {
        return true;
    }
    else if((getSurfaceRed(player1Stack)==getSurfaceRed(player2Stack)&&getSurfaceRed(player1Stack)!=0)||(getSurfaceRed(player1Stack)==getSurfaceRed(player3Stack)&&getSurfaceRed(player1Stack)!=0)||(getSurfaceRed(player3Stack)==getSurfaceRed(player2Stack)&&getSurfaceRed(player2Stack)!=0))
    {
        return true;
    }
    else if((getSurfaceYellow(player1Stack)==getSurfaceYellow(player2Stack)&&getSurfaceYellow(player1Stack)!=0)||(getSurfaceYellow(player1Stack)==getSurfaceYellow(player3Stack)&&getSurfaceYellow(player1Stack)!=0)||(getSurfaceYellow(player3Stack)==getSurfaceYellow(player2Stack)&&getSurfaceYellow(player2Stack)!=0))
    {
        return true;
    }
    else if((getSurfacePurple(player1Stack)==getSurfacePurple(player2Stack)&&getSurfacePurple(player1Stack)!=0)||(getSurfacePurple(player1Stack)==getSurfacePurple(player3Stack)&&getSurfacePurple(player1Stack)!=0)||(getSurfacePurple(player3Stack)==getSurfacePurple(player2Stack)&&getSurfacePurple(player3Stack)!=0))
    {
        return true;
    }

    //动物牌判断
    if(this->nWolf >= 1&&(this->nMonkey >= 1||this->nElephant >= 1||this->nPig >= 1||this->nSheep >= 1))
    {
        return true;
    }
    else if(this->nElephant >= 1 && this->nSurfaceCountStrawberry>=1)
    {
        return true;
    }
    else if(this->nMonkey >= 1&&this->nSurfaceCountBanana>=1)
    {
        return true;
    }
    else if(this->nPig >= 1&&this->nSurfaceCountPurple>=1)
    {
        return true;
    }
    else if(this->nSheep >= 1&&this->nSurfaceCountOrange>=1)
    {
        return true;
    }
    else
    {
        return false;
    }


}
 bool judger::isDifficultRegulation(stack player1Stack,stack player2Stack,stack player3Stack,int &nKind)
 {
     this->nSurfaceCountStrawberry = getSurfaceRed(player1Stack) + getSurfaceRed(player2Stack)+getSurfaceRed(player3Stack);
     this->nSurfaceCountBanana = getSurfaceYellow(player1Stack) + getSurfaceYellow(player2Stack)+getSurfaceYellow(player3Stack);
     this->nSurfaceCountPurple = getSurfacePurple(player1Stack) + getSurfacePurple(player2Stack)+getSurfacePurple(player3Stack);
     this->nSurfaceCountOrange = getSurfaceGreen(player1Stack) + getSurfaceGreen(player2Stack)+getSurfaceGreen(player3Stack);
     this->nWolf = getSurfaceWolf(player1Stack) + getSurfaceWolf(player2Stack)+getSurfaceWolf(player3Stack);
     this->nPig = getSurfacePig(player1Stack) + getSurfacePig(player2Stack)+getSurfacePig(player3Stack);
     this->nMonkey = getSurfaceMonkey(player1Stack) + getSurfaceMonkey(player2Stack)+getSurfaceMonkey(player3Stack);
     this->nSheep = getSurfaceSheep(player1Stack) + getSurfaceSheep(player2Stack)+getSurfaceSheep(player3Stack);
     if(this->nSurfaceCountOrange % 5==0&&this->nSurfaceCountOrange!=0)
     {
         nKind = 3;
         return true;
     }
     else if(this->nSurfaceCountBanana % 5==0&&this->nSurfaceCountBanana!=0)
     {
         nKind = 1;
         return true;
     }
     else if(this->nSurfaceCountPurple % 5==0&&this->nSurfaceCountPurple!=0)
     {
          nKind = 2;
         return true;
     }
     else if(this->nSurfaceCountStrawberry % 5==0&&this->nSurfaceCountStrawberry!=0)
     {
          nKind = 0;
         return true;
     }
     else if(this->nWolf >= 1&&(this->nMonkey >= 1||this->nElephant >= 1||this->nPig >= 1||this->nSheep >= 1))
     {
         nKind = 8;
         return true;
     }
     else if(this->nElephant >= 1 && this->nSurfaceCountStrawberry>=1)
     {
          nKind = 4;
         return true;
     }
     else if(this->nMonkey >= 1&&this->nSurfaceCountBanana>=1)
     {
         nKind = 5;
         return true;
     }
     else if(this->nPig >= 1&&this->nSurfaceCountPurple>=1)
     {
         nKind = 6;
         return true;
     }
     else if(this->nSheep >= 1&&this->nSurfaceCountOrange>=1)
     {
         nKind = 7;
         return true;
     }
     else {return false;}
 }
 bool judger::isOutOfGame(Player *p)
 {
     if(p->nBrand<=0)
     {
         return true;
     }


     {
         return false;
     }
 }
