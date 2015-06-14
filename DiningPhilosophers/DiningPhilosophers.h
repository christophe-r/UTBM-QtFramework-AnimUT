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
