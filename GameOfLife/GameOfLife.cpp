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

#include "GameOfLife.h"

/**
 * Game of life is a game where in a world (2D matrix here) cells born and die.
 * There is 2 rules to define who lives and who dies...
 *   - A cell remains alive if 2 or 3 of its direct neighbours is alive, otherwise it dies
 *   - A cell becomes alive if only 3 of its direct neighbours is alive
 *
 * More info at: https://en.wikipedia.org/wiki/Conway's_Game_of_Life
 */
GameOfLife::GameOfLife():AnimUT()
{

#ifdef DEBUG
    qDebug("GameOfLife launched");
#endif

    resize(740, 550); // resize window

    cellSize = 15;
    nbCells = 30;
    frameRate = 200; // Default ms to wait between two frames (here, 2 img/sec)
    bool displayGrid = true;

    // add controls
    controls->addLabel("Animation");
    controls->addAnimationControl(animate, frameRate);
    QPushButton *resetButton = controls->addButton("Reset");
    controls->addDivider();

    QCheckBox *showGridButton = controls->addCheckBox("Show grid");
    connect(showGridButton, SIGNAL(toggled(bool)), this, SLOT( drawGrid(bool)));

    controls->addDivider();
    frameRateLabel = controls->addLabel(QString("Frame rate: <b>%1</b>").arg(1000/frameRate)); // img per sec

    controls->addLabel("Set frame rate:");
    frameRateSlider = controls->addSlider();
    frameRateSlider->setMaximum(100);
    frameRateSlider->setMinimum(1);
    frameRateSlider->setSingleStep(5);
    connect(frameRateSlider, SIGNAL(valueChanged(int)), this, SLOT(setFrameRate(int)));
    frameRateSlider->setSliderPosition(1000/frameRate);

    controls->addDivider();
    controls->addLabel("Generation:");
    iter = controls->addLabel("<span style=\"font-size:16pt; font-weight:bold;\">0</span>");
    iter->setAlignment(Qt::AlignHCenter);

    drawGrid(displayGrid);
    showGridButton->setChecked(displayGrid);

    cells = new Cells(cellSize, nbCells); // create a board of cells
    connect(cells, SIGNAL(newIteration(int)), this, SLOT(updateIterLabel(int)));
    connect(resetButton, SIGNAL(released()), this, SLOT(resetGame()));

    cells->addAliveCell(14,15);
    cells->addAliveCell(15,15);
    cells->addAliveCell(15,14);
    cells->addAliveCell(15,16);
    cells->addAliveCell(16,14);

    setRpentomino(); // draw the initial pattern

    // viewer
    viewer->addItem(cells);
}

GameOfLife::~GameOfLife()
{
    delete cells;
}

/**
 * @brief GameOfLife::resetGame
 */
void GameOfLife::resetGame()
{
    updateIterLabel(0);
    cells->resetBoard();
    setRpentomino();
}

/**
 * @brief GameOfLife::setRpentomino Create a R-pentomino pattern into the board
 */
void GameOfLife::setRpentomino()
{
    cells->addAliveCell(14,15);
    cells->addAliveCell(15,15);
    cells->addAliveCell(15,14);
    cells->addAliveCell(15,16);
    cells->addAliveCell(16,14);
}

/**
 * @brief GameOfLife::drawGrid Paint or not the grid between the cells
 * @param activate - int - True is the grid have to be paint
 */
void GameOfLife::drawGrid(bool activate)
{
    QPen myPen;

    if (activate) { // choose if the grid have to be paint or not
        myPen = QPen(Qt::gray, 1);
    } else {
        myPen = QPen(Qt::white, 2);
    }

    for (int i = 0; i <= nbCells; ++i) { // draw vertical and horizontal lines
        QLineF hLine(i*cellSize, 0, i*cellSize, nbCells*cellSize);
        QLineF vLine(0, i*cellSize, nbCells*cellSize, i*cellSize);
        scene->addLine(hLine, myPen);
        scene->addLine(vLine, myPen);
    }
}

/**
 * @brief GameOfLife::updateIterLabel Update the number of iteration in controls
 * @param iteration - int - The number of iteration
 */
void GameOfLife::updateIterLabel(int iteration)
{
    iter->setText(QString("<span style=\"font-size:16pt; font-weight:bold;\">%1</span>").arg(iteration));
}

/**
 * @brief GameOfLife::setFrameRate Set the number of frame per second during the animation
 * @param nbFrame - int - The number of frame per second
 */
void GameOfLife::setFrameRate(int nbFrame)
{
    frameRateLabel->setText(QString("Frame rate: <b>%1</b>").arg(nbFrame));
    frameRate = nbFrame;
    if (animate->isRunning()) {
        animate->stop();
        animate->start(1000/nbFrame);
    }
}

/**
 * @brief GameOfLife::animationControl Method to start/stop animation and set the framerate
 */
void GameOfLife::animationControl()
{
    if (animate->isRunning()) {
        controlButton->setText("Start");
        animate->stop();
    } else {
        controlButton->setText("Stop");
        animate->start(frameRate);
    }
}
