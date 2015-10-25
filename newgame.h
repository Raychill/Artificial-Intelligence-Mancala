#ifndef NEWGAME
#define NEWGAME
#include <map>
#include <string>
#include "mainwindow.h"
//#include "newgame.h"
using namespace std;
class cells;
class newGame
{
public:
    vector<cells> setNewGame();
    void selectCell(size_t key);
    int getMarbelNumber(int key);


    newGame();
    ~newGame();
    vector<cells> Game;

};


#endif // NEWGAME

