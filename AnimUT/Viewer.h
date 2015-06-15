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

#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QVector>
#include <QGraphicsItem>
#include <QGraphicsView>

class Viewer : public QGraphicsView
{
    Q_OBJECT


public:
    Viewer(QWidget* parent_ = 0);
    Viewer(QGraphicsScene *scene, QWidget *parent = 0): QGraphicsView(scene, parent) {}
    ~Viewer();

    void addItem(QGraphicsItem *item);
    QGraphicsScene *getScene();
    void setSceneRect(qreal x, qreal y, qreal w, qreal h, QPen myPen);

    //weel event
    void wheelEvent(QWheelEvent * event);

protected:
    QGraphicsScene *scene;
private:
    int _numScheduledScalings;

private slots:
    void scalingTime(qreal);
    void animFinished();
};

#endif // VIEWER_H
