#ifndef SINGLEAGENT
#define SINGLEAGENT
#include <vector>
#include "mBoard.h"

using namespace std;

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
    vector<cells> getMinMax();


    /*
    void selectCell(int key);
    int randomBestMove(Game currentGame);
    */

};

#endif // SINGLEAGENT

