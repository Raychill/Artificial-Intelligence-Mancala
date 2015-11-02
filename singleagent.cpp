#include "cells.h"
#include "singleagent.h"
#include "mBoard.h"

agent::agent(mBoard &game)
{
    this->game = &game;
    agentScore = 0;
    opponentScore = 0;

}

agent::~agent()
{

}


int agent::getNextMove(void )
{

   // getMaxMove();// or getMaxMove;
    return getMaxMove();
}

int agent::getMinMove(void)
{

    vector<cells> moves;
    //if statement to toggle who plays
    moves = getMinMax();
    int min = moves[0].marbelNum;

    for(int i = 0; i < moves.size();i++){
        if(min > moves[i].marbelNum)
            min = moves[i].marbelNum;
        if(min == moves[i].marbelNum)
            min == moves[i].marbelNum;


    }
    return min;
}

int agent::getMaxMove(void)
{

   vector<cells> moves = getMinMax();
   int max = moves[0].marbelNum;
   int index = 0;
    for(int i = 0; i < moves.size();i++){
       // max = moves[i].marbelNum;
        if(moves[i].marbelNum == 0)
            i++;//prune any 0s
        if(max < moves[i].marbelNum)
            index = moves[i].cellNum;//max = moves[i].marbelNum;
        else if(max == moves[i].marbelNum)
             index = moves[i].cellNum;//max = moves[i].marbelNum;

        }
   return index;

}
vector<cells> agent::getMinMax()
{
vector<cells> A = game-> getA();
//vector<cells> B = game -> getB();
int lengthA = game->getA().size();
int heuristics;
//vector<cells> Stack;
for(int i = 0; i < A.size();i++)
{
    heuristics = lengthA + A[i].marbelNum;
    A[i].marbelNum = heuristics;
}

return A;
}



