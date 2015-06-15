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

#include <QDebug>
#include <QMessageBox>

#include "SnakeItem.h"

SnakeItem::SnakeItem(int myCellSize, int myNbCells)
{
    cellSize = myCellSize;
    nbCells = myNbCells;
    notLost = true;
    score = 0;

    initializeGame();
}

SnakeItem::~SnakeItem() {}

void SnakeItem::initializeGame()
{
    // initialize grid
    gridState =  std::vector< std::vector<short int> >(nbCells, std::vector<short int>(nbCells, 0));
    for (int i = 0; i < nbCells; ++i) {
        for (int j = 0; j < nbCells; ++j) {
            gridState[i][j] = 0;
        }
    }

    x = 1;
    y = 0;
    cellLifeTime = 3;
    currentPos[0] = 3;
    currentPos[1] = 3;
    gridState[1][3] = cellLifeTime-2;
    gridState[2][3] = cellLifeTime-1;
    gridState[3][3] = cellLifeTime;

    placeFruit();
}

QRectF SnakeItem::boundingRect() const
{
    return QRect(0, 0, cellSize*nbCells, cellSize*nbCells);
}

void SnakeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem */* unused */, QWidget */* unused */)
{
    for (int i = 0; i < nbCells; ++i) {
        for (int j = 0; j < nbCells; ++j) {
            if (gridState[i][j] > 0 ) {
                painter->setBrush(Qt::black);
                painter->drawRect(i*cellSize, j*cellSize, cellSize, cellSize);
            }
            if (gridState[i][j] == -5 ) {
                painter->setBrush(Qt::red);
                painter->drawEllipse(i*cellSize, j*cellSize, cellSize, cellSize);
            }
        }
    }
}

void SnakeItem::setUp()
{
    if(!notLost) return;
    if( x==0 && y==1 ) return; // Ignore down
    x = 0;
    y = -1;
}

void SnakeItem::setRight()
{
    if(!notLost) return;
    if( x==-1 && y==0 ) return; // Ignore left
    x = 1;
    y = 0;
}

void SnakeItem::setLeft()
{
    if(!notLost) return;
    if( x==1 && y==0 ) return; // Ignore right
    x = -1;
    y = 0;
}

void SnakeItem::setDown()
{
    if(!notLost) return;
    if( x==0 && y==-1 ) return; // Ignore up
    x = 0;
    y = 1;
}

void SnakeItem::advance(int phase)
{
    if(!phase) return;

    if (notLost) {
        for (int i = 0; i < nbCells; ++i) {
            for (int j = 0; j < nbCells; ++j) {
                if (gridState[i][j] > 0 ) {
                    gridState[i][j]--;
                }
            }
        }
    }
    if (x==1 && y==0) {
        currentPos[0]++;
    }
    if (x==-1 && y==0) {
        currentPos[0]--;
    }
    if (x==0 && y==1) {
        currentPos[1]++;
    }
    if (x==0 && y==-1) {
        currentPos[1]--;
    }
    checkCollision();
    gridState[currentPos[0]][currentPos[1]] = cellLifeTime;
    update(0,0,cellSize*nbCells,cellSize*nbCells);
}

void SnakeItem::checkCollision()
{
    if (currentPos[0] > nbCells-1 ) {
        currentPos[0] = 0;
    }
    if (currentPos[1] > nbCells-1 ) {
        currentPos[1] = 0;
    }
    if (currentPos[0] < 0 ) {
        currentPos[0] = nbCells-1;
    }
    if (currentPos[1] < 0 ) {
        currentPos[1] = nbCells-1;
    }

    if ( gridState[currentPos[0]][currentPos[1]] > 0 && notLost) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game Over");
        msgBox.setText("You lose!");
        msgBox.setInformativeText("Maybe you can have better luck next time?");
        msgBox.setStandardButtons(QMessageBox::Retry);
        msgBox.setDefaultButton(QMessageBox::Retry);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Retry:
            score = 0;
            emit updateScore(0);
            initializeGame();
            update(0, 0, cellSize*nbCells, cellSize*nbCells);
            break;
        default:
            break;
        }
    }

    // when we eat a fruit
    if ( gridState[currentPos[0]][currentPos[1]] == -5 ) {
        addPoints(50);
        placeFruit();
        for (int i = 0; i < nbCells; ++i) {
            for (int j = 0; j < nbCells; ++j) {
                if (gridState[i][j] > 0 ) {
                    gridState[i][j] += 2;
                }
            }
        }
        cellLifeTime = cellLifeTime + 2;
    }
    addPoints(1);
}

void SnakeItem::placeFruit()
{
    bool fruitNotPlaced = true;
    while (fruitNotPlaced) {
        int placex = qrand() % nbCells;
        int placey = qrand() % nbCells;
        if (gridState[placex][placey] == 0) {
            gridState[placex][placey] = -5;
            fruitNotPlaced = false;
        }
    }
}

void SnakeItem::addPoints(int nbPoints)
{
    if (notLost) {
        score += nbPoints;
        emit updateScore(score);
    }
}


