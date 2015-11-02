#ifndef SINGLEAGENT
#define SINGLEAGENT
#include "mBoard.h"



class agent
{

    mBoard *game;

public:

    int agentScore;
    int opponentScore;

    agent(mBoard &game);
    ~agent();

    int getNextMove(void);
    int getMinMove(void);
    int getMaxMove(void);
    int getMinMax(void);


    /*
    void selectCell(int key);
    int randomBestMove(Game currentGame);
    */

};

#endif // SINGLEAGENT

