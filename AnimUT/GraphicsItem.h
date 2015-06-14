#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPainter>

class GraphicsItem : public QObject, public QGraphicsItem
{

    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    GraphicsItem();
    ~GraphicsItem();

    virtual void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    virtual QRectF boundingRect() const = 0;
};

#endif // GRAPHICSITEM_H
