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

#include "GraphicsItem.h"

GraphicsItem::GraphicsItem()
{
    setPos(mapToParent(0, 0));
}

GraphicsItem::~GraphicsItem() {}

/**
 * @brief GraphicsItem::paint Method call at each repaint of the object
 * @param painter - QPainter - Used to paint on the view
 * @param option
 * @param widget
 */
void GraphicsItem::paint(QPainter */* unused */, const QStyleOptionGraphicsItem */* unused */, QWidget */* unused */){}

/*
  // function called at each step of the animation (you need to implement it)
  void GraphicsItem::advance(int phase){}
*/
