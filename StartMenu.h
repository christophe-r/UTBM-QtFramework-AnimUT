#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
#include "AnimUT/AboutWindow.h"

#include "SampleApp/SampleApp.h"
#include "GameOfLife/GameOfLife.h"
#include "Snake/Snake.h"
#include "DiningPhilosophers/DiningPhilosophers.h"

namespace Ui {
class StartMenuWindow;
}

class StartMenu : public QMainWindow
{
    Q_OBJECT
public:
    explicit StartMenu(QWidget *parent = 0);
    ~StartMenu();

private slots:
    void on_SampleAppBtn_released();
    void on_GameOfLifeBtn_released();
    void on_SnakeBtn_released();
    void on_DiningPhilosophersBtn_released();
    void on_ExitBtn_released();
    void on_AboutBtn_released();

private:
    Ui::StartMenuWindow *ui;

};

#endif // STARTMENU_H
