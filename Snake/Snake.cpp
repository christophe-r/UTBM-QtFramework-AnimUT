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
#include <QKeyEvent>
#include <QMessageBox>
#include <QPen>

#include "Snake.h"

Snake::Snake():AnimUT()
{
#ifdef debug
    qDebug("Snake launched");
#endif

    controls->addAnimationControl(animate, 200);

    cellSize = 15;
    nbCells = 20;

    // controls
    snakeItem = new SnakeItem(cellSize, nbCells);

    controls->addLabel("Movements");
    QPushButton *upBtn = controls->addButton("Up");
    connect(upBtn, SIGNAL(released()), snakeItem, SLOT(setUp()));
    QPushButton *downBtn = controls->addButton("Down");
    connect(downBtn, SIGNAL(released()), snakeItem, SLOT(setDown()));
    QPushButton *leftBtn = controls->addButton("Left");
    connect(leftBtn, SIGNAL(released()), snakeItem, SLOT(setLeft()));
    QPushButton *rightBtn = controls->addButton("Right");
    connect(rightBtn, SIGNAL(released()), snakeItem, SLOT(setRight()));

    controls->addDivider();

    score = controls->addLabel("Score : 0");
    connect(snakeItem, SIGNAL(updateScore(int)), this, SLOT(updateScore(int)));

    // viewer
    drawBorders();
    viewer->addItem(snakeItem);
}

Snake::~Snake() {}

void Snake::drawBorders()
{
    QPen myPen = QPen(Qt::black);
    QLineF topLine(0, 0, cellSize*nbCells, 0);
    QLineF leftLine(0, 0, 0, cellSize*nbCells);
    QLineF rightLine(cellSize*nbCells, 0, cellSize*nbCells, cellSize*nbCells);
    QLineF bottomLine(0, cellSize*nbCells, cellSize*nbCells, cellSize*nbCells);
    scene->addLine(topLine, myPen);
    scene->addLine(leftLine, myPen);
    scene->addLine(rightLine, myPen);
    scene-> addLine(bottomLine, myPen);
}

void Snake::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        snakeItem->setLeft();
        break;
    case Qt::Key_Right:
        snakeItem->setRight();
        break;
    case Qt::Key_Up:
        snakeItem->setUp();
        break;
    case Qt::Key_Down:
        snakeItem->setDown();
        break;
    default:
        break;
    }
}

void Snake::updateScore(int nbPoint)
{
    score->setText(QString("Score: %1").arg(nbPoint));
}
