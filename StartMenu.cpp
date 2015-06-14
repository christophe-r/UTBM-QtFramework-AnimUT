#include "StartMenu.h"
#include "ui_StartMenuWindow.h"

#include "GameOfLife/GameOfLife.h"
#include "Snake/Snake.h"
#include "SampleApp/SampleApp.h"
#include "DiningPhilosophers/DiningPhilosophers.h"

StartMenu::StartMenu(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::StartMenuWindow)
{
    ui->setupUi(this);
    setFixedSize(size());
}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::on_SampleAppBtn_released()
{
    SampleApp *mySampleApp = new SampleApp();
    mySampleApp->setAttribute(Qt::WA_DeleteOnClose);
    mySampleApp->show();
}

void StartMenu::on_GameOfLifeBtn_released()
{
    GameOfLife *myGameOfLife = new GameOfLife();
    myGameOfLife->setAttribute(Qt::WA_DeleteOnClose);
    myGameOfLife->show();
}

void StartMenu::on_SnakeBtn_released()
{
    Snake *mySnake = new Snake();
    mySnake->setAttribute(Qt::WA_DeleteOnClose);
    mySnake->show();
}

void StartMenu::on_DiningPhilosophersBtn_released()
{
    DiningPhilosophers *myDiningPhilosophers = new DiningPhilosophers();
    myDiningPhilosophers->setAttribute(Qt::WA_DeleteOnClose);
    myDiningPhilosophers->show();
}

void StartMenu::on_ExitBtn_released()
{
    qApp->quit();
}

void StartMenu::on_AboutBtn_released()
{
    AboutWindow *aboutWindow = new AboutWindow();
    aboutWindow->setAttribute(Qt::WA_DeleteOnClose);
    aboutWindow->show();
}
