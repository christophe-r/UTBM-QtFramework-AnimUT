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

#ifndef CELLS_H
#define CELLS_H

#include <vector>

#include "AnimUT/GraphicsItem.h"

class Cells : public GraphicsItem
{

    Q_OBJECT

private:
    int cellSize;
    int iteration;
    int nbCells;
    std::vector< std::vector<bool> > currentState;
    std::vector< std::vector<bool> > nextState;

protected:
    void advance(int phase);
    void checkRules(int x, int y);

public:
    Cells(int myCellSize, int myNbCells);
    ~Cells();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void addAliveCell(int x, int y);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

public slots:
    void resetBoard();

signals:
    void newIteration(int i);
};

#endif // CELLS_H
