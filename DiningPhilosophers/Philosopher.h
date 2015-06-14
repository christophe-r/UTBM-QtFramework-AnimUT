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
