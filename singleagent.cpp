
#include "singleagent.h"
#include "mBoard.h"

agent::agent(mBoard &game)
{
    this->game = &game;
    agentScore = 0;
    opponentScore = 0;

}


int agent::getNextMove(void )
{

    getMinMove();// or getMaxMove;
    return 0;
}

int agent::getMinMove(void)
{

    vector<cells> moves;
    //if statement to toggle who plays
    moves = getMinMax(A);
    int min = moves[0].marbelNum;
    for(; !moves[i].isBank; i = (i + 1) % cellCount){
        if(min > moves[i].marbelNum)
            min = moves[i].marbelNum;
        if(min == moves[i].marbelNum)
            min == moves[i].marbelNum;


    }
    return min;
}

int agent::getMaxMove(void)
{

    vector<cells> moves;
    //if statement to toggle who plays
    moves = getMinMax(A);
    int max = moves[0].marbelNum;
    for(; !moves[i].isBank; i = (i + 1) % cellCount){
        if(max < moves[i].marbelNum)
            max = moves[i].marbelNum;
        if(max == moves[i].mmarbelNum)
            max = moves[i].marbelNum;


    }
   return max;

}
vector<cells> agent::getMinMax(char player)
{
vector<cells> A = game-> getA();
vector<cells> B = game -> getB();
int lengthA = game->getA().size();
int lengthB = game->getB().size();

//int i = 0;
if(player == 'A')
//for(; !A[i].isBank; i = (i + 1) % game->cellCount)
for(int i = 0; i < A.size();i++)
{
    A[i].marbelNum = A[i].marbelNum - lengthA + A[lengthA].marbelNum;

}

//i = 0;
else//(player == 'B')
//for(; !B[i].isBank; i = (i + 1) % game->cellCount)
for(int i = 0; i < B.size();i++)
{
    B[i].marbelNum = B[i].marbelNum - lengthB + B[lengthB].marbelNum;

}


}



