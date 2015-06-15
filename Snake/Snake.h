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
