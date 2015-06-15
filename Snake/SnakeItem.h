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
