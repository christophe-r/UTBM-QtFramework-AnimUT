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
