#ifndef SNAKE_H
#define SNAKE_H


#include "SnakeItem.h"

#include <AnimUT/AnimUT.h>


class Snake : public AnimUT
{

   Q_OBJECT

public:
    Snake();
    ~Snake();
    void drawBorders();
    virtual void keyReleaseEvent(QKeyEvent *event);
private:
    SnakeItem *snakeItem;
    int cellSize;
    int nbCells;
    QLabel *score;

public slots:
    void updateScore(int nbPoint);

};

#endif // SNAKE_H
