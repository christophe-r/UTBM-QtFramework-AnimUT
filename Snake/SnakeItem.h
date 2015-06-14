#ifndef SNAKEITEM_H
#define SNAKEITEM_H

#include <AnimUT/GraphicsItem.h>

class SnakeItem : public GraphicsItem
{

    Q_OBJECT

private:
    int x, y;
    int score;
    bool notLost;
    int cellSize;
    int cellLifeTime;
    int nbCells;
    std::vector< std::vector<short int> > gridState;
    void advance(int phase);
    int currentPos[2];

public:
    SnakeItem(int myCellSize, int myNbCells);
    ~SnakeItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem */* unused */, QWidget */* unused */);
    void checkCollision();
    void initializeGame();
    void placeFruit();
    void addPoints(int nbPoints);

public slots:
    void setUp();
    void setRight();
    void setLeft();
    void setDown();

signals:
    void updateScore(int);

};

#endif // SNAKEITEM_H
