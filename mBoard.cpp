

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
//----------------------------------------------------
mBoard::~mBoard()
{
    delete[] boardState;
}


cells & mBoard::operator[](const int i)
{
    return boardState[i];
}

cells & mBoard::at(const int i)
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
    std::vector<cells> cellsA = getA();
    std::vector<cells> cellsB = getB();

    const size_t len = cellsA.size();

    // For All the cells A or B without the banks cells.
    for(size_t i = 0; i < len -1; ++i)
    {
        // Add all the marbels to bank A.
        cellsA.back().marbelNum += cellsA[i].marbelNum;
        cellsA[i].marbelNum = 0;

        // Add all the marbels to bank B.
        cellsB.back().marbelNum += cellsB[i].marbelNum;
        cellsB[i].marbelNum = 0;
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


bool mBoard::isGameOver()
{
    for(unsigned int i = 0; i < cellCount; ++i)
    {
        // Don't count the banks.
        if(i == bankkeyA || i == bankkeyB)
            continue;
        // If any cells have any marbles, then the game is not over.
        else if(boardState[i].marbelNum != 0)
            return false;
    }

    return true;

} // End of isGameOver().



std::vector<cells> mBoard::getA() const
{
    std::vector<cells> listCells;

    int i = 1;
    for(; !boardState[i].isBank; i = (i + 1) % cellCount)
        listCells.push_back(boardState[i]);

    // Add the bank to the list.
    listCells.push_back(boardState[i]);

    return listCells;
}

std::vector<cells> mBoard::getB() const
{
    std::vector<cells> listCells;

    int i = 8;
    for(; !boardState[i].isBank; i = (i + 1) % cellCount)
        listCells.push_back(boardState[i]);

    // Add the bank to the list.
    listCells.push_back(boardState[i]);

    return listCells;
}
