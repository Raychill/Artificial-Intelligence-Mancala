#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void updateButtons();
    void updateGameState(const unsigned int key, const unsigned int bankKey);
    void setEnabledButtonSetA(const bool b);
    void setEnabledButtonSetB(const bool b);
    void setAgentGame(mBoard &board,const int key, const int bankKey);

    void on_actionDualPlayers_triggered();


    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();

    void on_actionSinglePlayer_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
