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
#include <QToolBar>

#include "DiningPhilosophers.h"
#include "Philosopher.h"

DiningPhilosophers::DiningPhilosophers():AnimUT()
{
#ifdef DEBUG
    qDebug("Dining Philosophers launched");
#endif


    connect(ui->actionStartStop, SIGNAL(triggered()), this, SLOT(animationStartStop()));
    toolBar->addAction(ui->actionStartStop);


    started = false;

    for(int i=0; i < NB_PHILOSOPHERS; i++){ // initialize forks mutex locks and graphics
        forks[i] = new QMutex();

        philosophersGraphic[i] = new QGraphicsTextItem;
        philosophersGraphic[i]->setHtml(QString("Philosopher %1").arg(i));
        scene->addItem(philosophersGraphic[i]);
    }

    // Texts position
    philosophersGraphic[0]->setPos(0, -170);
    philosophersGraphic[1]->setPos(150, -60);
    philosophersGraphic[2]->setPos(100, 60);
    philosophersGraphic[3]->setPos(-100, 60);
    philosophersGraphic[4]->setPos(-155, -60);

    // Drawing table
    QPen pen(Qt::black, 2);
    scene->addEllipse(-60, -130, 200, 200, pen);
}

DiningPhilosophers::~DiningPhilosophers()
{
    if( started ) stopThreads();
    delete *philosophersGraphic;
}

void DiningPhilosophers::stopThreads(){
    for(int i=0; i < NB_PHILOSOPHERS; i++){ // send stop signal to all threads
        philosophers[i]->stop();
    }

    for (int i=0; i < NB_PHILOSOPHERS; i++){ // wait and delete threads
        philosophersThread[i]->wait();
    }

    delete *philosophersThread;
    delete *philosophers;
}

void DiningPhilosophers::updateState(int i, bool bold, const QString &value){
    if( bold ){
        philosophersGraphic[i]->setHtml("<span style=\"font-weight:bold;color:#F00;\">"+value+"</span>");
    } else {
        philosophersGraphic[i]->setHtml(value);
    }
}

void DiningPhilosophers::animationStartStop()
{
    if( !started ){
        started = true;
        //startResetBtn->setText("Reset");
        ui->actionStartStop->setText("Stop");
        ui->actionStartStop->setIcon(QIcon(":/icons/images/stop.png"));

        for( int i=0; i<NB_PHILOSOPHERS; i++ ){ // initialize and run philosopher threads
            philosophers[i] = new Philosopher(i, forks);
            philosophersThread[i] = launchWorker(philosophers[i]);
            philosophers[i]->startWork();
            connect(philosophers[i], SIGNAL(stateChanged(int, bool, QString)), this, SLOT(updateState(int, bool, QString)));
        }

    } else {
        started = false;
        //startResetBtn->setText("Start");
        ui->actionStartStop->setText("Start");
        ui->actionStartStop->setIcon(QIcon(":/icons/images/play.png"));
        stopThreads();
    }
}
