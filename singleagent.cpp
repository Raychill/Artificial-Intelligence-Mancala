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

    getMinMove();// or getMaxMove;
    return 0;
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
    int index;
    for(int i = 0; i < moves.size();i++){
        if(moves[i].marbelNum == 0)
            i++;
        if(max < moves[i].marbelNum)
            index = i;//max = moves[i].marbelNum;
        if(max == moves[i].marbelNum)
             index = i+8;//max = moves[i].marbelNum;


    }
   return index;

}
vector<cells> agent::getMinMax()
{
vector<cells> A = game-> getA();
//vector<cells> B = game -> getB();
int lengthA = game->getA().size();
int heuristics;
//vector<int> minMax;
for(int i = 0; i < A.size();i++)
{
    heuristics = lengthA - A[i].marbelNum;
    A[i].marbelNum = heuristics;
}

return A;
}



