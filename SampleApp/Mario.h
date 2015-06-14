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
