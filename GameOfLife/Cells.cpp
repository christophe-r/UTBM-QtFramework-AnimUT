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

#include <QGraphicsSceneMouseEvent>

#include "Cells.h"

Cells::Cells(int myCellSize, int myNbCells): cellSize(myCellSize), iteration(0), nbCells(myNbCells)
{
    // initialise grid
    currentState =  std::vector< std::vector<bool> >(nbCells, std::vector<bool>(nbCells, false));
    nextState =  std::vector< std::vector<bool> >(nbCells, std::vector<bool>(nbCells, false));
}

Cells::~Cells() {}

/**
 * @brief Cells::checkRules Check rules for a single cell
 * @param x - int - X coordinate of the cell
 * @param y - int - Y coordinate of the cell
 */
void Cells::checkRules(int x, int y)
{

    int aliveCell = 0;
    for (int i = -1; i < 2; ++i) { // Count active cell neighbour
        for (int j = -1; j < 2; ++j) {
            if (x+i<nbCells && y+j<nbCells && x+i>0 && y+j>0) {
                if (!(i==0&& j==0 && j==i) && currentState[x+i][y+j]) {
                    aliveCell++;
                }
            }
        }
    }

    if(currentState[x][y] && (aliveCell == 2 || aliveCell == 3)){ // rule 1
        nextState[x][y] = true;
    } else {
        nextState[x][y] = false;
    }
    if(!currentState[x][y] && aliveCell == 3){ // rule 2
        nextState[x][y] = true;
    }

}

/**
 * @brief Cells::addAliveCell set a cell alive
 * @param x - int - X coordinate of the cell
 * @param y - int - Y coordinate of the cell
 */
void Cells::addAliveCell(int x, int y)
{
    currentState[x][y] = true;
}

/**
 * @brief Cells::resetBoard Reset the board
 */
void Cells::resetBoard()
{
    iteration = 0;
    currentState =  std::vector< std::vector<bool> >(nbCells, std::vector<bool>(nbCells, false)); // reset board state
    nextState =  std::vector< std::vector<bool> >(nbCells, std::vector<bool>(nbCells, false));
    update(0, 0, cellSize*nbCells, cellSize*nbCells); // redraw the board
}

/**
 * @brief Cells::paint Lethod call each time the cell board is called (inherit from QT)
 * @param painter - QPainter - Object use to paint
 * @param option  - QStyleOptionGraphicsItem
 * @param widget  - QWidget
 */
void Cells::paint(QPainter *painter, const QStyleOptionGraphicsItem */* unused */, QWidget */* unused */)
{
    painter->setBrush(Qt::black); // background of cells
    painter->setPen(Qt::gray); // outline of cells
    for (int i = 0; i < nbCells; ++i) {
        for (int j = 0; j < nbCells; ++j) {
            if (currentState[i][j]) {
                painter->drawRect(i*cellSize, j*cellSize, cellSize, cellSize); // paint a rect for each cell alive
            }
        }
    }
}

/**
 * @brief Cells::boundingRect Method call from QT to now the size a the cells board(inherit from QT)
 * @return QRectF
 */
QRectF Cells::boundingRect() const
{
    return QRect(0, 0, cellSize*nbCells, cellSize*nbCells); // return the size of the board
}

/**
 * @brief Cells::advance Method call twice from QT at each step of an animation(inherit from QT)
 * @param phase - bool
 */
void Cells::advance(int phase)
{
    if(!phase) return; // no computation in the first step of the animation (notification)

    for (int i = 0; i < nbCells; ++i) {
        for (int j = 0; j < nbCells; ++j) {
            checkRules(i, j); // check rules for each cells
        }
    }
    currentState = nextState;
    iteration++;
    emit newIteration(iteration); // emit event for the control
    update(0, 0, cellSize*nbCells, cellSize*nbCells); // redraw the board
}

/**
 * @brief Cells::mousePressEvent Call a each mouse click on the board
 * @param event - QGraphicsSceneMouseEvent
 */
void Cells::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    int x = static_cast<int>(event->pos().x()/cellSize);
    int y = static_cast<int>(event->pos().y()/cellSize);
    if (currentState[x][y]) { // toogle the clicked cell
        currentState[x][y] = false;
    } else {
        currentState[x][y] = true;
    }
    update(0, 0, cellSize*nbCells, cellSize*nbCells); // redraw the board
}

