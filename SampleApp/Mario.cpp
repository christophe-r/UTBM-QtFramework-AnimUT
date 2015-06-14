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
