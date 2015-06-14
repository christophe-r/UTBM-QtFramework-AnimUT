#include <QApplication>

#include "StartMenu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    StartMenu startMenu;
    startMenu.show();

    return app.exec();
}
