#include <QVector>
#include <QKeyEvent>

#include "SampleApp.h"

SampleApp::SampleApp():AnimUT()
{
#ifdef DEBUG
    qDebug("SampleApp launched");
#endif
    controls->addLabel("Animation");
    controls->addAnimationControl(animate, 1000/100);
    controls->addDivider();

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
