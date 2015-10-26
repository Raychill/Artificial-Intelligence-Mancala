
#ifndef CELLS_H
#define CELLS_H

#include <QAbstractButton>


class cells
{

protected:

public:

    unsigned int cellNum;
    unsigned int marbelNum;
    QAbstractButton *button;
    bool isBank;


    cells();
    ~cells();


}; // End of cells class.

#endif // CELLS_H
