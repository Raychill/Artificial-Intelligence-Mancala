#ifndef MBOARD_H
#define MBOARD_H

#include <vector>

#include "cells.h"



class mBoard
{

private:

    // The list of all the cells on the board.
    cells *boardState;

    // The number of cells.
    const unsigned int cellCount;
    // The index of bank A.
    const unsigned int bankkeyA;
    // The index of bank B.
    const unsigned int bankkeyB;


public:

    mBoard(const unsigned int cellCount,
           const unsigned int bankkeyA,
           const unsigned int bankkeyB);
    ~mBoard();

    cells & operator[](const int i);
    cells & at(const int i);
    size_t size(void);

    void setNewGame();

    bool updateBoard(const unsigned int key,
                     const unsigned int bankkey);

    bool isGameOver();

    std::vector<cells> getA();
    std::vector<cells> getB();


}; // End of mBoard class.


#endif // MBOARD_H

