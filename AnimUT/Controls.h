#ifndef CONTROLS_H
#define CONTROLS_H

#include <QCheckBox>
#include <QFormLayout>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QWidget>

#include "Animate.h"
#include "ui_AnimUT.h"

class Controls : protected QWidget
{
    Q_OBJECT

public:
    Controls(Ui::AnimUT* ui);
    ~Controls();
    QPushButton *addButton(QString buttonName);
    QFrame *addDivider();
    QSlider *addSlider();
    QSlider *addSlider(QString name){ addLabel(name); return addSlider();}
    QLineEdit *addLineEdit();
    QLineEdit *addLineEdit(QString name){ addLabel(name); return addLineEdit();}
    QProgressBar *addProgressBar();
    QProgressBar *addProgressBar(QString name){ addLabel(name); return addProgressBar();}
    QLabel *addLabel(QString name);
    QRadioButton *addRadioButton(QString name);
    QCheckBox *addCheckBox(QString name);
    void addItem(QWidget *widget);
    void addAnimationControl(Animate *amimate, int myFrameRate = 50);

protected:
    QVBoxLayout *layout;
    Ui::AnimUT *ui;
    int frameRate;
    QPushButton *controlButton;
    Animate *controlAnimate;

signals:

public slots:
    void animationControl();
};

#endif // CONTROLS_H
