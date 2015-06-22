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

#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QToolBar>

#include "ui_AnimUT.h"
#include "Controls.h"

Controls::Controls(Ui::AnimUT* ui, QToolBar *toolBar)
{
    this->ui = ui;
    layout = ui->ControlsLayout;
    this->toolBar = toolBar;
}

Controls::~Controls() {}

/**
 * @brief Controls::addButton Easily add a button in the control list
 * @param name - QString - The text of the button
 * @return QPushButton - A pointer of the button
 */
QPushButton *Controls::addButton(QString name)
{
    QPushButton *pushButton;

    pushButton = new QPushButton(this);
    pushButton->setText(name);
    layout->addWidget(pushButton);

    return pushButton;
}

/**
 * @brief Controls::addDivider Easily add a divider in the control list
 * @return QFrame - A pointer of the divider
 */
QFrame *Controls::addDivider()
{
    QFrame *divider;
    divider = new QFrame(this);
    divider->setFrameShape(QFrame::HLine);
    divider->setFrameShadow(QFrame::Sunken);
    layout->addWidget(divider);

    return divider;
}

/**
 * @brief Controls::addSlider Easily add a slider in the control list
 * @return QSlider - A pointer of the slider
 */
QSlider *Controls::addSlider()
{
    QSlider *slider;
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
    slider->setSizePolicy(sizePolicy);
    layout->addWidget(slider);

    return slider;
}

/**
 * @brief Controls::addLabel Easily add a label in the control list
 * @param name - QString - The text of the label
 * @return QLabel - A pointer of the label
 */
QLabel *Controls::addLabel(QString name)
{
    QLabel *label;
    label = new QLabel(this);
    label->setText(name);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
    label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
    label->setSizePolicy(sizePolicy);
    layout->addWidget(label);

    return label;
}

/**
 * @brief Controls::addRadioButton Easily add a radioButton in the control list
 * @param name - QString - The text of the radioButton
 * @return QRadioButton - A pointer of the radioButton
 */
QRadioButton *Controls::addRadioButton(QString name)
{
    QRadioButton *radioButton;
    radioButton = new QRadioButton(this);
    radioButton->setText(name);
    layout->addWidget(radioButton);

    return radioButton;
}

/**
 * @brief Controls::addCheckBox Easily add a checkBox in the control list
 * @param name - QString - The text of the checkBox
 * @return QCheckBox - A pointer of the checkBox
 */
QCheckBox *Controls::addCheckBox(QString name)
{
    QCheckBox *checkBox;
    checkBox = new QCheckBox(this);
    checkBox->setText(name);
    layout->addWidget(checkBox);

    return checkBox;
}

/**
 * @brief Controls::addLineEdit Easily add a lineEdit in the control list
 * @param name - QString - The text of the lineEdit
 * @return QLineEdit - A pointer of the lineEdit
 */
QLineEdit *Controls::addLineEdit()
{
    QLineEdit *lineEdit;
    lineEdit = new QLineEdit(this);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
    lineEdit->setSizePolicy(sizePolicy);
    layout->addWidget(lineEdit);
    return lineEdit;
}

/**
 * @brief Controls::addProgressBar Easily add a progressBar in the control list
 * @param name - QString - The text of the progressBar
 * @return QProgressBar - A pointer of the progressBar
 */
QProgressBar *Controls::addProgressBar()
{
    QProgressBar *progressBar;
    progressBar = new QProgressBar(this);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
    progressBar->setSizePolicy(sizePolicy);
    layout->addWidget(progressBar);
    return progressBar;
}

/**
 * @brief Controls::addItem Add a widget in the control list
 * @param name - QWidget - The widget you want to add to the scene
 */
void Controls::addItem(QWidget *widget)
{
    layout->addWidget(widget);
}

/**
 * @brief Controls::addAnimationControl Easily add a full connected action to control animation
 * @param amimate     - Animate - The animation object you want to connect
 * @param myFrameRate -   int   - The number of frames per second in the animation, default: 20 frames/second
 */
void Controls::addAnimationControl(Animate *amimate, int myFrameRate)
{
    controlAnimate = amimate;
    frameRate = myFrameRate;
    connect(ui->actionStartStop, SIGNAL(triggered()), this, SLOT(animationControl()));

    toolBar->addAction(ui->actionStartStop);
}

/**
 * @brief Controls::addResetControl Easily add a full connected action to reset animation
 * @param app     - AnimUT - The app where the resetAnimation() method should be called
 */
void Controls::addResetControl(AnimUT *app)
{
    // Adding action to menu and connects it to the app's reset slot
    QAction *actionReset = new QAction((QObject*)app);
    actionReset->setText("Reset");
    actionReset->setShortcut(QKeySequence(tr("Ctrl+R")));
    actionReset->setIcon(QIcon(":/icons/images/reset.png"));
    ui->menuAnimation->addAction(actionReset);
    connect(actionReset, SIGNAL(triggered()), (QObject*)app, SLOT(resetAnimation()));

    toolBar->addAction(actionReset);
}


/**
 * @brief Controls::animationControl Method used to control the animation
 */
void Controls::animationControl(){
    if (controlAnimate->isRunning()) {
        ui->actionStartStop->setText("Start");
        ui->actionStartStop->setIcon(QIcon(":/icons/images/play.png"));
        controlAnimate->stop();
    } else {
        ui->actionStartStop->setText("Stop");
        ui->actionStartStop->setIcon(QIcon(":/icons/images/stop.png"));
        controlAnimate->start(frameRate);
    }
}

