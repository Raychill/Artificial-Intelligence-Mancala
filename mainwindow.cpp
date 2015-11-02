#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mBoard.h"
#include "cells.h"
#include "singleagent.h"
#include <QButtonGroup>

mBoard board(14, 0, 7);
//Board agentGame = board;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable all the buttons on start
    setEnabledButtonSetA(false);
    setEnabledButtonSetB(false);

    // Map the buttons to the cells.

    // Button set B
    board[7].button = ui->pushButton_8;
    board[1].button = ui->pushButton_2;
    board[2].button = ui->pushButton_3;
    board[3].button = ui->pushButton_4;
    board[4].button = ui->pushButton_5;
    board[5].button = ui->pushButton_6;
    board[6].button = ui->pushButton_7;

    // Button set A
    board[0].button = ui->pushButton;
    board[8].button = ui->pushButton_9;
    board[9].button = ui->pushButton_10;
    board[10].button = ui->pushButton_11;
    board[11].button = ui->pushButton_12;
    board[12].button = ui->pushButton_13;
    board[13].button = ui->pushButton_14;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDualPlayers_triggered()
{
    mode = DUALPLAYER;
    board.setNewGame();
    updateButtons();
    setEnabledButtonSetA(true);
    setEnabledButtonSetB(false);

    board.debug();
}

void MainWindow::on_actionSinglePlayer_triggered()
{
    mode = SINGLE;

    board.setNewGame();
    updateButtons();
   // agent mAgent(board);
   // setAgentGame(-1,-1);
    setEnabledButtonSetA(true);
    setEnabledButtonSetB(false);
}

void MainWindow::on_actionDualAgents_triggered()
{
    mode = DUALAGENT;


}


void MainWindow::setEnabledButtonSetA(const bool b)
{
    foreach(QAbstractButton *button, ui->buttonGroup->buttons())
        button->setEnabled(b);

} // End of setEnabledButtonSetA().

void MainWindow::setEnabledButtonSetB(const bool b)
{
    foreach(QAbstractButton *button, ui->buttonGroup_2->buttons())
        button->setEnabled(b);

} // End setEnabledButtonSetB().



void MainWindow::on_pushButton_2_clicked()
{
    updateGameState(1,7);
}
void MainWindow::on_pushButton_3_clicked()
{
    updateGameState(2,7);
}
void MainWindow::on_pushButton_4_clicked()
{
    updateGameState(3,7);
}
void MainWindow::on_pushButton_5_clicked()
{
    updateGameState(4,7);
}
void MainWindow::on_pushButton_6_clicked()
{
    updateGameState(5,7);
}
void MainWindow::on_pushButton_7_clicked()
{
   updateGameState(6,7);
}
void MainWindow::on_pushButton_8_clicked()
{
    updateGameState(7,0);
}
void MainWindow::on_pushButton_9_clicked()
{
    updateGameState(8,0);
}
void MainWindow::on_pushButton_10_clicked()
{
    updateGameState(9,0);
}
void MainWindow::on_pushButton_11_clicked()
{
    updateGameState(10,0);
}

void MainWindow::on_pushButton_12_clicked()
{
    updateGameState(11,0);
}

void MainWindow::on_pushButton_13_clicked()
{
    updateGameState(12,0);
}

void MainWindow::on_pushButton_14_clicked()
{
    updateGameState(13,0);
}

void MainWindow::updateButtons()
{
    // Update the text of each GUI button.
    for(size_t index = 0; index < board.size(); ++index)
    {
        int i = board[index].marbelNum;
        QString s = QString::number(i);
        board[index].button->setText(s);

        // Disable cell that are banks or have no marbles.
        if(board[index].marbelNum == 0 || board[index].isBank)
        {
            board[index].button->setEnabled(false);
        }
    }


} // End of updateButtons().

void MainWindow::updateGameState(const unsigned int key, const unsigned int bankKey)
{

    if(mode == DUALPLAYER)
    {
        dualPlayer_updateGameState(key, bankKey);
    }
    else if(mode == SINGLE)
    {
        Single_updateGameState(key);
    }
    updateButtons();
}


void MainWindow::dualPlayer_updateGameState(const unsigned int key, const unsigned int bankKey)
{
    if(board.updateBoard(key,bankKey) == true )
    {
        if(key < board.size()/2)
        {
            setEnabledButtonSetB(false);
            setEnabledButtonSetA(true);
        }
        else /*if(key > board.size()/2)*/
        {
            setEnabledButtonSetA(false);
            setEnabledButtonSetB(true);
        }
    }
    else
    {
        if(key < board.size()/2)
        {
            setEnabledButtonSetB(true);
            setEnabledButtonSetA(false);
        }
        else /*if(key > board.size()/2)*/
        {
            setEnabledButtonSetA(true);
            setEnabledButtonSetB(false);
        }
    }
}



int MainWindow::myAi()
{
    unsigned int max = 0;
    unsigned int maxIndex = 0;
    std::vector<cells> cList = board.getAr();

    for(size_t i = 0; i < cList.size()-1; ++i)
    {
        if(cList[i].marbelNum == (i +1))
            return cList[i].cellNum;

        if(cList[i].marbelNum > max)
        {
            max = cList[i].marbelNum;
            maxIndex = cList[i].cellNum;
        }
    }

    return maxIndex;
}

void MainWindow::Single_updateGameState(const unsigned int key)
{
    //agent AI(board);

    if(board.updateBoard(key, 7) == true)
    {
        setEnabledButtonSetA(true);
        setEnabledButtonSetB(false);
    }
    else
    {
       agent A(board);
       //bool aiGoAgain = false;
         bool aiGoAgain = false;

        do
        {

            aiGoAgain = board.updateBoard(myAi(), 0);

             updateButtons();
        } while(aiGoAgain);
        setEnabledButtonSetA(true);
        setEnabledButtonSetB(false);
    }


}
