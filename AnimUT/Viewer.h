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
