

#include "mBoard.h"
#include "cells.h"



//----------------------------------------------------
mBoard::mBoard(const unsigned int cellCount,
               const unsigned int bankkeyA,
               const unsigned int bankkeyB)
    :cellCount(cellCount),
      bankkeyA(bankkeyA),
      bankkeyB(bankkeyB)

{
    boardState = new cells[cellCount];

    // Set the bank cell flags.
    boardState[bankkeyA].isBank = true;
    boardState[bankkeyB].isBank = true;


}

mBoard::mBoard(const mBoard & other):cellCount(other.cellCount),bankkeyA(other.bankkeyA),bankkeyB(other.bankkeyB)
{

    boardState = new cells[other.cellCount];

    for(size_t i = 0; i < cellCount; ++i)
    {
        boardState[i] = other.at(i);
    }


    // Set the bank cell flags.
    boardState[bankkeyA].isBank = true;
    boardState[bankkeyB].isBank = true;
}


//----------------------------------------------------
mBoard::~mBoard()
{
    delete[] boardState;
}


cells & mBoard::operator[](const int i) const
{
    return boardState[i];
}

// TDDO: I don't know if this is good. Please Test!!
mBoard & mBoard::operator= (const mBoard & other)
{
    delete[] boardState;

    boardState = new cells[other.cellCount];

    /*
    cellCount = other.cellCount;
    bankkeyA = other.bankkeyA;
    bankkeyB = other.bankkeyB;
    */

    for(size_t i = 0; i < cellCount; ++i)
    {
        boardState[i] = other[i];
    }


    // Set the bank cell flags.
    boardState[bankkeyA].isBank = true;
    boardState[bankkeyB].isBank = true;

    return *this;
}

cells & mBoard::at(const int i) const
{
    return boardState[i];
}

size_t mBoard::size(void)
{
    return cellCount;
}

//------------------------------------------------------
void mBoard :: setNewGame()
{

    for(unsigned int i = 0; i < cellCount; ++i)
    {
        boardState[i].cellNum = i;
        boardState[i].marbelNum = 4;

    }  //end loop

    // Clear banks A and B.
    boardState[bankkeyA].marbelNum = 0;
    boardState[bankkeyB].marbelNum = 0;

}


void mBoard::flush(void) const
{

    for(size_t i = 0; i < cellCount; ++i)
    {
        // Skip banks cells.
        if(i == bankkeyA || i == bankkeyB)
            continue;

        if(i > bankkeyB)
        {
            // Adding to bank A.
            boardState[bankkeyA].marbelNum += boardState[i].marbelNum;

        } else
        {
            // Adding to bank B.
            boardState[bankkeyB].marbelNum += boardState[i].marbelNum;
        }

        // Clear the cell.
        boardState[i].marbelNum = 0;
    }

} // End of flush().


bool mBoard::updateBoard(const unsigned int key, const unsigned int bankkey)
{
    bool goAgain = false;

    cells *cell = &(boardState[key]);
    unsigned int marbles = cell->marbelNum;

    // Clear the cell.
    cell->marbelNum = 0;

    for(unsigned int index = (key + 1) % cellCount;
        marbles != 0;
        index = (index +1) % cellCount)
    {
        cells *cell = &(boardState[index]);

        // Test of the cell is a bank.
        if(!(cell->isBank) || cell->cellNum == bankkey)
        {
            --marbles;
            ++(cell->marbelNum);

            // If it ends on a bank, set goAgain.
            if(marbles == 0 && cell->cellNum == bankkey)
                goAgain = true;

        }

    } // End of for().

    return goAgain;

} // End of updateBoard().


bool mBoard::isGameOver() const
{
    return !hasMovesA() || !hasMovesB();

} // End of isGameOver().

bool mBoard::hasMovesA() const
{
    const std::vector<cells> cellsA = getA();
    const size_t len = cellsA.size();

    // Skip the bank cell at the end of the list.
    for(size_t i = 0; i < (len -1); ++i)
    {
        if(cellsA[i].marbelNum != 0)
            return true;
    }

    return false;
} // End of hasMovesA().

bool mBoard::hasMovesB() const
{
    const std::vector<cells> cellsB = getA();
    const size_t len = cellsB.size();

    // Skip the bank cell at the end of the list.
    for(size_t i = 0; i < (len -1); ++i)
    {
        if(cellsB[i].marbelNum != 0)
            return true;
    }

    return false;

} // End of hasMovesB().


std::vector<cells> mBoard::getA() const
{
    std::vector<cells> listCells;

    int i = 1;
    for(; !boardState[i].isBank; i = (i + 1) % cellCount)
        listCells.push_back(boardState[i]);

    // Add the bank to the list.
    listCells.push_back(boardState[bankkeyA]);

    return listCells;
}

std::vector<cells> mBoard::getB() const
{
    std::vector<cells> listCells;

    int i = 8;
    for(; !boardState[i].isBank; i = (i + 1) % cellCount)
        listCells.push_back(boardState[i]);

    // Add the bank to the list.
    listCells.push_back(boardState[bankkeyB]);

    return listCells;
}
