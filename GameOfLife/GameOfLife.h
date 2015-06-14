#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <AnimUT/AnimUT.h>

#include "Cells.h"

class GameOfLife : public AnimUT
{

    Q_OBJECT

private:
    Cells *cells;
    int cellSize;
    int nbCells;
    int frameRate;
    QLabel *iter;
    QLabel *frameRateLabel;
    QSlider *frameRateSlider;
    QPushButton *controlButton;

protected:
    void setRpentomino();

public:
    GameOfLife();
    ~GameOfLife();

public slots:
    void updateIterLabel(int iteration);
    void resetGame();
    void drawGrid(bool activate);
    void setFrameRate(int nbFrame);
    void animationControl();
};

#endif // GAMEOFLIFE_H
