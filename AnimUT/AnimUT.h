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

#ifndef ANIMUT_H
#define ANIMUT_H

#include <QMainWindow>

#include "Animate.h"
#include "Controls.h"
#include "Viewer.h"
#include "AboutWindow.h"
#include "Worker.h"


namespace Ui {
class AnimUT;
}

class AnimUT : public QMainWindow
{
    Q_OBJECT

    AboutWindow *aboutWindow;

public:
    explicit AnimUT(QWidget *parent = 0);
    ~AnimUT();
    QThread *launchWorker(Worker *worker);

protected:
    Controls *controls;
    Viewer *viewer;
    Animate *animate;
    QGraphicsScene *scene;
    Ui::AnimUT *ui;

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();

};

#endif // ANIMUT_H
