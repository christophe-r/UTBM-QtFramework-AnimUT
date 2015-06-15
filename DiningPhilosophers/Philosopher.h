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

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include <QString>
#include <QMutex>
#include <AnimUT/Worker.h>

#define NB_PHILOSOPHERS 5
#define MAX_MS_WAIT 3000

class Philosopher: public Worker
{
    Q_OBJECT

public:
    Philosopher(int id, QMutex *forks[]);
    int getId();

private:
    int id;
    bool stopped;
    QMutex **forks;

public slots:
    virtual void work();
    virtual void stop();

signals:
    void stateChanged(int i, bool bold, const QString &value);
};

#endif // PHILOSOPHER_H
