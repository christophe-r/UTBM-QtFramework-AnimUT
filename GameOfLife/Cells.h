#ifndef CELLS_H
#define CELLS_H

#include <vector>

#include "AnimUT/GraphicsItem.h"

class Cells : public GraphicsItem
{

    Q_OBJECT

private:
    int cellSize;
    int iteration;
    int nbCells;
    std::vector< std::vector<bool> > currentState;
    std::vector< std::vector<bool> > nextState;

protected:
    void advance(int phase);
    void checkRules(int x, int y);

public:
    Cells(int myCellSize, int myNbCells);
    ~Cells();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void addAliveCell(int x, int y);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void resetBoard();

signals:
    void newIteration(int i);
};

#endif // CELLS_H
