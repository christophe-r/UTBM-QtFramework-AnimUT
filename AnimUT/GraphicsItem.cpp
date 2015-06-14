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
