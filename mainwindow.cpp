#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mBoard.h"
#include "cells.h"

#include <QButtonGroup>

mBoard board(8, 0, 4);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable all the buttons on start
    setEnabledButtonSetA(false);
    setEnabledButtonSetB(false);

    // Map the buttons to the cells.
    board[0].button = ui->pushButton;
    board[1].button = ui->pushButton_2;
    board[2].button = ui->pushButton_3;
    board[3].button = ui->pushButton_4;
    board[4].button = ui->pushButton_5;
    board[5].button = ui->pushButton_6;
    board[6].button = ui->pushButton_7;
    board[7].button = ui->pushButton_8;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDualPlayers_triggered()
{
    board.setNewGame();
    updateButtons();
    setEnabledButtonSetA(true);
    setEnabledButtonSetB(false);
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
    board.updateBoard(1, 4);
    updateButtons();
    setEnabledButtonSetA(false);
    setEnabledButtonSetB(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    board.updateBoard(2, 4);
    updateButtons();
    setEnabledButtonSetA(false);
    setEnabledButtonSetB(true);
}

void MainWindow::on_pushButton_4_clicked()
{
    board.updateBoard(3, 4);
    updateButtons();
    setEnabledButtonSetA(false);
    setEnabledButtonSetB(true);
}

void MainWindow::on_pushButton_5_clicked()
{
    // this is a bank.
    updateButtons();
}

void MainWindow::on_pushButton_6_clicked()
{
    board.updateBoard(5, 0);
    updateButtons();
    setEnabledButtonSetA(true);
    setEnabledButtonSetB(false);
}

void MainWindow::on_pushButton_7_clicked()
{
    board.updateBoard(6, 0);
    updateButtons();
    setEnabledButtonSetA(true);
    setEnabledButtonSetB(false);
}

void MainWindow::on_pushButton_8_clicked()
{
    board.updateBoard(7, 0);
    updateButtons();
    setEnabledButtonSetA(true);
    setEnabledButtonSetB(false);
}

void MainWindow::updateButtons()
{
    // Update the text of each GUI button.
    for(size_t index = 0; index < board.size(); ++index)
    {
        int i = board[index].marbelNum;
        QString s = QString::number(i);
        board[index].button->setText(s);
    }

} // End of updateButtons().
