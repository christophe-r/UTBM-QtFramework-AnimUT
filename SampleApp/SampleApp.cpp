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

#include <QVector>
#include <QKeyEvent>

#include "SampleApp.h"

SampleApp::SampleApp():AnimUT()
{
#ifdef DEBUG
    qDebug("SampleApp launched");
#endif
    controls->addAnimationControl(animate, 1000/100);
    controls->addResetControl(this);

    // controls
    controls->addLabel("Movements");
    QPushButton *upBtn = controls->addButton("Up");
    QPushButton *downBtn = controls->addButton("Down");
    QPushButton *leftBtn = controls->addButton("Left");
    QPushButton *rightBtn = controls->addButton("Right");

    // items
    objects.append(new Mario(10, 10));
    objects.append(new Mario());
    objects.append(new Mario(200, 100));
    objects.append(new Mario(200, 200));

    // viewer
    viewer->setSceneRect(0, 0, 350, 350, QPen(Qt::red));

    foreach(Mario *item, objects){
        connect(upBtn, SIGNAL(released()), item, SLOT(setUp()));
        connect(downBtn, SIGNAL(released()), item, SLOT(setDown()));
        connect(leftBtn, SIGNAL(released()), item, SLOT(setLeft()));
        connect(rightBtn, SIGNAL(released()), item, SLOT(setRight()));
        viewer->addItem(item);
        item->setRight(); // Goes right on start
    }

    QPen pen(Qt::black, 1);
    scene->addEllipse(160, 160, 30, 30, pen, QBrush(Qt::SolidPattern));

}

SampleApp::~SampleApp() {}

void SampleApp::resetAnimation()
{
    if( animate->isRunning() ) controls->animationControl();

    objects[0]->setPos(10, 10);
    objects[1]->setPos(100, 100);
    objects[2]->setPos(200, 100);
    objects[3]->setPos(200, 200);
}

void SampleApp::keyReleaseEvent(QKeyEvent * event)
{
    switch (event->key()){
    case Qt::Key_Left:
        foreach(Mario *item, objects)
            item->setLeft();
        break;
    case Qt::Key_Right:
        foreach(Mario *item, objects)
            item->setRight();
        break;
    case Qt::Key_Up:
        foreach(Mario *item, objects)
            item->setUp();
        break;
    case Qt::Key_Down:
        foreach(Mario *item, objects)
            item->setDown();
        break;
    default:
        break;
    }

}
