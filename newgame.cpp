
#include <iostream>
#include <string>
#include <map>
#include <QString>
#include <sstream>
#include "newgame.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cells.h"

using namespace std;


//----------------------------------------------------
newGame::newGame()
{
    //Game = new map<string,int>;
}
//----------------------------------------------------
newGame::~newGame()
{

    //Game.clear();
}
//------------------------------------------------------
vector<cells> newGame :: setNewGame()
{

    cells board;
    board.cellNum = 8, board.marbelNum = 4;//cellNumber will be changed soon
    int length = 8;
    for(int i = 0; i < length; i++){
        Game.push_back(board);
        Game[i].cellNum = i;
        }//end loop
    Game[0].marbelNum = 0;
    Game[4].marbelNum = 0;

    return Game;


}
//--------------------------------------------------------
int newGame::getMarbelNumber(int key)//
{
    for(size_t i = 0; i <= Game.size();i++)
    {
        if(Game[i].cellNum == key)
            return Game[i].marbelNum;

    }
    return -1;//error

}
//-------------------------------------------------------
void newGame::selectCell(size_t key)
{

    int marbels = Game[key].marbelNum;
    Game[key].marbelNum = 0;
    //int top = 0;// so you can get to top of the vector;
    int a = 0;
    key++;
    for(int i = 0; i < marbels; i++)
        {

        if(key >= Game.size()||i+key >= Game.size())
            Game[a++].marbelNum +=1;
        else
            Game[i+key].marbelNum += 1;

        }
}


