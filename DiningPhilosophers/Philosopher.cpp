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

#include <QDebug>
#include <QThread>
#include <QMutex>
#include <QEventLoop>
#include <QTimer>

#include "Philosopher.h"

Philosopher::Philosopher(int id, QMutex *forks[]) : id(id), forks(forks)
{
    stopped = false;
}

void Philosopher::work()
{
#ifdef DEBUG
    qDebug("[Philosopher %d] Launched!", id);
#endif

    QEventLoop loop;

    do {
        // Thinking a random time
        QTimer::singleShot(qrand() % MAX_MS_WAIT, &loop, SLOT(quit()));
        loop.exec();

        forks[id]->lock(); // gets left fork
        forks[(id+1) % NB_PHILOSOPHERS]->lock(); // gets right fork

#ifdef DEBUG
        qDebug("[Philosopher %d] I'm eating", id);
#endif

        emit stateChanged(id, true, "I'm eating");

        while( stopped ){ break; } // avoids to enter in the wait loop if the thread has been exited

        // Eating a random time
        QTimer::singleShot(qrand() % MAX_MS_WAIT, &loop, SLOT(quit()));
        loop.exec();

#ifdef DEBUG
        qDebug("[Philosopher %d] I'm thinking", id);
#endif

        emit stateChanged(id, false, "I'm thinking");

        forks[id]->unlock(); // releases left fork
        forks[(id+1) % NB_PHILOSOPHERS]->unlock(); // releases right fork

    } while(!stopped);

#ifdef DEBUG
    qDebug("[Philosopher %d] Quit!", id);
#endif

    emit stateChanged(id, false, QString("Philosopher %1").arg(id));

    stop();
}

void Philosopher::stop()
{
    stopped = true;
    Worker::stop();
}

int Philosopher::getId()
{
    return id;
}
