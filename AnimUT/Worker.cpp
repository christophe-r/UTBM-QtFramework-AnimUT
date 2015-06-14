#include <QDebug>
#include <QThread>

#include "Worker.h"

Worker::Worker(QObject *parent) : QObject(parent) {}

/**
 * @brief Request the thread to execute the work() method
 */
void Worker::startWork()
{
#ifdef DEBUG
    qDebug() << "Requesting worker started in Thread " << thread()->currentThreadId();
#endif
    emit workRequested();
}

/**
 * @brief Request the thread to stop
 */
void Worker::stop()
{
#ifdef DEBUG
    qDebug() << "Stopping worker started in Thread " << thread()->currentThreadId();
#endif
    emit finished();
}

/**
 * @brief Place here the code you want to execute in the thread
 */
void Worker::work()
{
    stop();
}
