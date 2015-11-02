
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

    return 0;
}

int agent::getMinMove(void)
{

}

int agent::getMaxMove(void)
{

}
int agent::getMinMax(void)
{//create a vector that is half the size of the game
 // vector will store the values of the min max game
 // you then to take the cell marbel value, subtract its position from the bank
 // then calculate the remaining number of marbels.
    vector<int> localState;
    int localScore = 0;
    int i = 0;



}



