#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newgame.h"
#include "cells.h"
#include <QButtonGroup>
newGame n;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   setEnabledButtonSetA(false);
   setEnabledButtonSetB(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDualPlayers_triggered()
{
    n.setNewGame();
    setButtons();
    setEnabledButtonSetA(true);
    setEnabledButtonSetB(false);
}


void MainWindow::setEnabledButtonSetA(const bool b)
{
    foreach(QAbstractButton *button, ui->buttonGroup->buttons())
        button->setEnabled(b);
}

void MainWindow::setEnabledButtonSetB(const bool b)
{
    foreach(QAbstractButton *button, ui->buttonGroup_2->buttons())
        button->setEnabled(b);
}


void MainWindow::on_pushButton_2_clicked()
{
n.selectCell(1);
setButtons();
setEnabledButtonSetA(false);
setEnabledButtonSetB(true);
}

void MainWindow::on_pushButton_3_clicked()
{
n.selectCell(2);
setButtons();
setEnabledButtonSetA(false);
setEnabledButtonSetB(true);
}

void MainWindow::on_pushButton_4_clicked()
{
n.selectCell(3);
setButtons();
setEnabledButtonSetA(false);
setEnabledButtonSetB(true);
}

void MainWindow::on_pushButton_5_clicked()
{
setButtons();
}

void MainWindow::on_pushButton_6_clicked()
{
n.selectCell(5);
setButtons();
setEnabledButtonSetA(true);
setEnabledButtonSetB(false);
}

void MainWindow::on_pushButton_7_clicked()
{
n.selectCell(6);
setButtons();
setEnabledButtonSetA(true);
setEnabledButtonSetB(false);
}

void MainWindow::on_pushButton_8_clicked()
{
n.selectCell(7);
setButtons();
setEnabledButtonSetA(true);
setEnabledButtonSetB(false);
}
void MainWindow::setButtons()
{
    /*
    int marbelCount = 0;
    QString str_marbelCount;

    for(size_t index = 0; index < 8; ++index)
    {

    }
    */

    int i = n.Game[0].marbelNum;// returns the cell stack
    QString s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton->setText(s);//outputs to a

    i = n.Game[1].marbelNum;// returns the cell stack
    s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton_2->setText(s);//outputs to a

     i = n.Game[2].marbelNum;// returns the cell stack
     s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton_3->setText(s);//outputs to a

     i = n.Game[3].marbelNum;// returns the cell stack
    s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton_4->setText(s);//outputs to a

     i = n.Game[4].marbelNum;// returns the cell stack
   s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton_5->setText(s);//outputs to a

    i = n.Game[5].marbelNum;// returns the cell stack
    s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton_6->setText(s);//outputs to a

     i = n.Game[6].marbelNum;// returns the cell stack
    s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton_7->setText(s);//outputs to a

    i = n.Game[7].marbelNum;// returns the cell stack
    s = QString::number(i);// converts cell stack val to Qstring
    ui->pushButton_8->setText(s);//outputs to a


}
