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

