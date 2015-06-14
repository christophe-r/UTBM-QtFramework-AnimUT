#ifndef ANIMATE_H
#define ANIMATE_H

#include <QGraphicsScene>
#include <QTimer>


class Animate: public QObject
{
public:
    Animate(QGraphicsScene *myScene);
    ~Animate();

    void start(int frameRate = 50);
    void stop();
    bool isRunning();

protected:
    QTimer *timer;
    QGraphicsScene *scene;
};

#endif // ANIMATE_H
