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
    mBoard(const mBoard & other);
    ~mBoard();

    cells & operator[](const int i) const;
    mBoard & operator= (const mBoard &);
    cells & at(const int i) const ;
    size_t size(void);

    void setNewGame();

    void flush(void) const;
    bool updateBoard(const unsigned int key,
                     const unsigned int bankkey);

    bool isGameOver() const;
    bool hasMovesA() const;
    bool hasMovesB() const;

    std::vector<cells> getA() const;
    std::vector<cells> getB() const;

    std::vector<cells> getAr() const;
    std::vector<cells> getBr() const;

}; // End of mBoard class.


#endif // MBOARD_H

