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

#ifndef DININGPHILOSOPHERS_H
#define DININGPHILOSOPHERS_H

#include <AnimUT/AnimUT.h>
#include <QThread>

#include "Philosopher.h"

class DiningPhilosophers : public AnimUT
{

    Q_OBJECT


public:
    DiningPhilosophers();
    ~DiningPhilosophers();

private:
    void stopThreads();
    bool started;
    QPushButton *startResetBtn;
    QGraphicsTextItem *philosophersGraphic[NB_PHILOSOPHERS];

    QMutex *forks[NB_PHILOSOPHERS];
    Philosopher *philosophers[NB_PHILOSOPHERS];
    QThread *philosophersThread[NB_PHILOSOPHERS];


private slots:
    void updateState(int i, bool bold, const QString &value);
    void on_startResetBtn_clicked();
};

#endif // DININGPHILOSOPHERS_H
