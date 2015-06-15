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
