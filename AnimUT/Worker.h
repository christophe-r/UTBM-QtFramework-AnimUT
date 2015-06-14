#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QMutex>

class Worker : public QObject
{
    Q_OBJECT

public:
    explicit Worker(QObject *parent = 0);

    void startWork();
    void stop();

protected:
    QMutex mutex;

signals:
    void workRequested();
    void finished();

public slots:
    virtual void work();
};

#endif // WORKER_H

