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
    void resetAnimation();
    void drawGrid(bool activate);
    void setFrameRate(int nbFrame);
    void animationControl();
};

#endif // GAMEOFLIFE_H
