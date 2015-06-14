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
