#ifndef ANIMUT_H
#define ANIMUT_H

#include <QMainWindow>

#include "Animate.h"
#include "Controls.h"
#include "Viewer.h"
#include "AboutWindow.h"
#include "Worker.h"


namespace Ui {
class AnimUT;
}

class AnimUT : public QMainWindow
{
    Q_OBJECT

    AboutWindow *aboutWindow;

public:
    explicit AnimUT(QWidget *parent = 0);
    ~AnimUT();
    QThread *launchWorker(Worker *worker);

protected:
    Controls *controls;
    Viewer *viewer;
    Animate *animate;
    QGraphicsScene *scene;
    Ui::AnimUT *ui;

private slots:
    void on_actionQuit_triggered();
    void on_actionAbout_triggered();

};

#endif // ANIMUT_H
