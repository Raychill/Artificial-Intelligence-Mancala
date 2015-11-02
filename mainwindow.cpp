#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mBoard.h"
#include "cells.h"
#include "singleagent.h"
#include <QButtonGroup>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <QDebug>

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

    srand (time(NULL));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDualPlayers_triggered()
{
    mode = DUALPLAYER;

    // Reset the board.
    board.setNewGame();
    updateButtons();

    (rand() % 2) ? enableA() : enableB();

} // End of on_actionDualPlayers_triggered().

void MainWindow::on_actionSinglePlayer_triggered()
{
    mode = SINGLE;

    // Reset the board.
    board.setNewGame();
    updateButtons();

    enableB();

} // End of on_actionSinglePlayer_triggered().

void MainWindow::on_actionDualAgents_triggered()
{
    mode = DUALAGENT;

    // Disable all botton.
    disableAll();

    // Reset the board.
    board.setNewGame();
    updateButtons();

    // Start the game with two AI.
    dualAgent_updateGameState();

} // End of on_actionDualAgents_triggered().


void MainWindow::setEnabledButtonSetA(const bool b)
{
    foreach(QAbstractButton *button, ui->buttonGroup_2->buttons())
        button->setEnabled(b);

} // End of setEnabledButtonSetA().

void MainWindow::setEnabledButtonSetB(const bool b)
{
    foreach(QAbstractButton *button, ui->buttonGroup->buttons())
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
        board[index].button->repaint();
        usleep(10000);

    }

} // End of updateButtons().

void MainWindow::updateButtons(const int start)
{
    int i;

    for(i = (start+1) % board.size(); i != start; i = (i +1) % board.size())
    {
        board[i].button->setText(QString::number(board[i].marbelNum));
        board[i].button->repaint();
        usleep(10000);
    }
} // End of updateButtons().


void MainWindow::updateGameState(const unsigned int key, const unsigned int bankKey)
{
    disableAll();

    if(mode == DUALPLAYER)
    {
        dualPlayer_updateGameState(key, bankKey);
    }
    else if(mode == SINGLE)
    {
        Single_updateGameState(key);
    }
} // End of updateGameState().


void MainWindow::dualPlayer_updateGameState(const unsigned int key, const unsigned int bankKey)
{
    // Test to go again.
    if(board.updateBoard(key,bankKey) == true )
    {
        if(key < board.size()/2)
        {
            enableB();
        }
        else
        {
            enableA();
        }
    }
    else // It's the other player's turn.
    {
        if(key < board.size()/2)
        {
            enableA();
        }
        else
        {
            enableB();
        }
    }
    updateButtons(key);
} // End of dualPlayer_updateGameState().



int MainWindow::myAi()
{
    unsigned int max = 0;
    unsigned int maxIndex = 0;
    int  nonZeroIndex1st = -1;
    std::vector<cells> cList = board.getAr();

    for(size_t i = 0; i < cList.size()-1; ++i)
    {
        if(cList[i].marbelNum == (i +1))
            return cList[i].cellNum;

        // Find the cell with the more marbles.
        if(cList[i].marbelNum > max)
        {
            max = cList[i].marbelNum;
            maxIndex = cList[i].cellNum;
        }

        // Find the first non zero cell.
        if(nonZeroIndex1st == -1 && cList[i].marbelNum > 0)
            nonZeroIndex1st = cList[i].cellNum;
    }

    // 50:50 of max or first non zero.
    return (rand() % 2) ? maxIndex : nonZeroIndex1st;

} // End of myAi().

int MainWindow::myAiB()
{
    unsigned int max = 0;
    unsigned int maxIndex = 0;
    int  nonZeroIndex1st = -1;
    std::vector<cells> cList = board.getBr();

    for(size_t i = 0; i < cList.size()-1; ++i)
    {
        if(cList[i].marbelNum == (i +1))
            return cList[i].cellNum;

        // Find the cell with the more marbles.
        if(cList[i].marbelNum > max)
        {
            max = cList[i].marbelNum;
            maxIndex = cList[i].cellNum;
        }

        // Find the first non zero cell.
        if(nonZeroIndex1st == -1 && cList[i].marbelNum > 0)
            nonZeroIndex1st = cList[i].cellNum;
    }

    // 50:50 of max or first non zero.
    return (rand() % 2) ? maxIndex : nonZeroIndex1st;

} // End of myAiB().



void MainWindow::Single_updateGameState(const unsigned int key)
{
    // Player moves.
    if(board.updateBoard(key, 7) == true)
    {
        updateButtons(key);
    }
    else
    {
        // AI action!
        bool aiGoAgain = false;

        do
        {
            int aiMove = myAi();
            aiGoAgain = board.updateBoard(aiMove, 0);
            updateButtons(aiMove);


        } while(aiGoAgain && !board.isGameOver());
    }

    if(board.isGameOver())
    {
        board.flush();
        updateButtons();
    } else
        enableB();

} // End of Single_updateGameState().

void MainWindow::dualAgent_updateGameState()
{
    bool again = false;

    while(!board.isGameOver())
    {
        do
        {
            int aiMove = myAi();
            again = board.updateBoard(aiMove, 0);
            updateButtons(aiMove);


        } while(again && !board.isGameOver());

        do
        {
            int aiMove = myAiB();
            again = board.updateBoard(aiMove, 7);
            updateButtons(aiMove);


        } while(again && !board.isGameOver());
    }

    board.flush();
    updateButtons();

} // End of dualAgent_updateGameState().

void MainWindow::enableA()
{
    setEnabledButtonSetA(true);
    disableZero();
} // End of enableA().

void MainWindow::enableB()
{
    setEnabledButtonSetB(true);
    disableZero();
} // End of enableB().

void MainWindow::disableAll()
{
    setEnabledButtonSetA(false);
    setEnabledButtonSetB(false);
} // End of disableAll().

void MainWindow::disableZero()
{
    // Update the text of each GUI button.
    for(size_t index = 0; index < board.size(); ++index)
    {
        // Disable cell that are banks or have no marbles.
        if(board[index].marbelNum == 0 || board[index].isBank)
        {
            board[index].button->setEnabled(false);
            board[index].button->repaint();
        }
    }
} // End of disableZero().


