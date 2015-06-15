/* This file is part of AnimUT project.
 * <https://github.com/christophe-r/UTBM-QtFramework-AnimUT>
 *
 * AnimUT project was originally created in spring 2015 by:
 *  - Vincent MARSEGUERRA <http://vincent.marseguerra.fr/>
 *  - Christophe RIBOT <http://www.christophe-ribot.fr/>
 *
 * AnimUT project is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * AnimUT project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with AnimUT project. If not, see <http://www.gnu.org/licenses/>.
 */

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
