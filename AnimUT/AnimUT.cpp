#include <QThread>

#include "AnimUT.h"
#include "ui_AnimUT.h"

AnimUT::AnimUT(QWidget *parent): QMainWindow(parent), ui(new Ui::AnimUT)
{
    ui->setupUi(this);
    controls = new Controls(ui); // start control managment
    ui->ControlsLayout->setAlignment(Qt::AlignTop);
    viewer = ui->MainGraphicsView;
    scene =  viewer->getScene();// start graphic view managment
    animate = new Animate(scene); // start animation management
    aboutWindow = NULL;
}

AnimUT::~AnimUT()
{
    delete aboutWindow;
    delete controls;
    delete viewer;
    delete animate;
    delete ui;
}

/**
 * @brief AnimUT::on_actionQuit_triggered Bind action from toolBar
 */
void AnimUT::on_actionQuit_triggered()
{
    this->close();
}

/**
 * @brief AnimUT::on_actionAbout_triggered Bind action from toolBar
 */
void AnimUT::on_actionAbout_triggered()
{
    aboutWindow = new AboutWindow();
    aboutWindow->show();
}

/**
 * @brief AnimUT::launchWorker Launch and connect a worker into a thread (This does not start the thread)
 * @param worker - Worker - An herited object from Worker with an overloaded work() method
 * @return QThread - QThread object, for more connection and control
 */
QThread *AnimUT::launchWorker(Worker* worker)
{
    QThread* thread = new QThread;

    worker->moveToThread(thread); // move object into a thread

    connect(worker, SIGNAL(workRequested()), thread, SLOT(start())); // execute the worker
    connect(thread, SIGNAL(started()), worker, SLOT(work())); // when the thread is ok, do the work() method
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection); // finish the thread

    return thread;
}
