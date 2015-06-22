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

#ifndef SAMPLEAPP_H
#define SAMPLEAPP_H

#include <QObject>
#include <QVector>

#include <AnimUT/AnimUT.h>

#include "Mario.h"

class SampleApp : public AnimUT
{
    Q_OBJECT

private:
    QVector<Mario*> objects;

public:
    SampleApp();
    virtual void keyReleaseEvent(QKeyEvent * event);
    ~SampleApp();

public slots:
    void resetAnimation();

};

#endif // SAMPLEAPP_H
