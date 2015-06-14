#include <QObject>

#include "Animate.h"

Animate::Animate(QGraphicsScene *myScene)
{
    timer = new QTimer();
    scene = myScene;
    connect(timer, SIGNAL(timeout()),scene, SLOT(advance()));
}

Animate::~Animate()
{
    timer->stop();
    delete timer;
}

/**
 * @brief Animate::start Start the animation in the graphic scene
 * @param frameRate - int - number of frames per second during the animation
 */
void Animate::start(int frameRate)
{
    timer->start(frameRate);
}

/**
 * @brief Animate::stop Stops the animation in the graphic scene
 */
void Animate::stop()
{
    timer->stop();
}

/**
 * @brief Animate::isRunning Check if an animation is running
 * @return bool - true if an animation is running
 */
bool Animate::isRunning()
{
    return timer->isActive();
}

