#-------------------------------------------------
#
# Project created by QtCreator 2015-05-18T17:04:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnimUT
TEMPLATE = app


SOURCES += main.cpp \
    StartMenu.cpp \
    AnimUT/AnimUT.cpp \
    AnimUT/Animate.cpp \
    AnimUT/Controls.cpp \
    AnimUT/GraphicsItem.cpp \
    AnimUT/Viewer.cpp \
    AnimUT/AboutWindow.cpp \
    AnimUT/Worker.cpp \
    SampleApp/SampleApp.cpp \
    SampleApp/Mario.cpp \
    GameOfLife/GameOfLife.cpp \
    GameOfLife/Cells.cpp \
    Snake/Snake.cpp \
    Snake/SnakeItem.cpp \
    DiningPhilosophers/DiningPhilosophers.cpp \
    DiningPhilosophers/Philosopher.cpp


HEADERS  += \
    StartMenu.h \
    AnimUT/AnimUT.h \
    AnimUT/Animate.h \
    AnimUT/Controls.h \
    AnimUT/GraphicsItem.h \
    AnimUT/Viewer.h \
    AnimUT/AboutWindow.h \
    AnimUT/Worker.h \
    SampleApp/SampleApp.h \
    SampleApp/Mario.h \
    GameOfLife/GameOfLife.h \
    GameOfLife/Cells.h \
    Snake/Snake.h \
    Snake/SnakeItem.h \
    DiningPhilosophers/DiningPhilosophers.h \
    DiningPhilosophers/Philosopher.h


FORMS    += \
    AnimUT/AnimUT.ui \
    AnimUT/AboutWindow.ui \
    StartMenuWindow.ui

RESOURCES += images.qrc
RC_FILE = resources.rc


