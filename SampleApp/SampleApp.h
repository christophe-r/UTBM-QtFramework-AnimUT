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

};

#endif // SAMPLEAPP_H
