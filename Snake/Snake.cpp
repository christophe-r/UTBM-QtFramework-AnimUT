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

    controls->addLabel("Animation");
    controls->addAnimationControl(animate, 200);
    controls->addDivider();

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
