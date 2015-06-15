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

#include "Mario.h"

Mario::Mario(int posX, int posY)
{
    // set draggable
    setFlag(QGraphicsItem::ItemIsMovable);

    x = 1;
    y = 0;
    setPos(mapToParent(posX, posY));
}

Mario::~Mario(){}

void Mario::paint(QPainter *painter, const QStyleOptionGraphicsItem */* unused */, QWidget */* unused */)
{
    // collision detection
    if(!scene()->collidingItems(this).isEmpty()){
        doCollision();
    }

    QPixmap pixmap;
    if ( pixmap.load(":/graphics/images/mario.gif") ){
        painter->drawPixmap( QPoint(0,0), pixmap );
    } else {
        painter->drawRect(QRect(0, 0, 35, 35));
    }
}

QRectF Mario::boundingRect() const
{
    return QRect(0,0,35,35);
}

void Mario::advance(int phase)
{
    if(!phase) return;
    setPos(mapToParent(x, y));
}

void Mario::doCollision()
{
    if( x==0 && y==-1 ){ // up => down
        x = 0;
        y = 1;
    } else if( x==1 && y==0 ){ // right => left
        x = -1;
        y = 0;
    } else if( x==-1 && y==0 ){ // left => right
        x = 1;
        y = 0;
    } else if( x==0 && y==1 ){ // down => up
        x = 0;
        y = -1;
    }
}

void Mario::setUp()
{
    x = 0;
    y = -1;
}

void Mario::setRight()
{
    x = 1;
    y = 0;
}

void Mario::setLeft()
{
    x = -1;
    y = 0;
}

void Mario::setDown()
{
    x = 0;
    y = 1;
}

void Mario::setPosition(int myX, int myY)
{
    x = myX;
    y = myY;
}
