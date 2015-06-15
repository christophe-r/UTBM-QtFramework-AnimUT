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

#ifndef MARIO_H
#define MARIO_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <AnimUT/GraphicsItem.h>

class Mario : public GraphicsItem
{

    Q_OBJECT

public:
    Mario(int posX = 100, int posY = 100);
    ~Mario();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem */* unused */, QWidget */* unused */);

    void setPosition(int myX, int myY);
protected:
    void advance(int phase);
    void doCollision();

public slots:
    void setUp();
    void setRight();
    void setLeft();
    void setDown();

private:
    int x;
    int y;

};

#endif // MYRECT_H
