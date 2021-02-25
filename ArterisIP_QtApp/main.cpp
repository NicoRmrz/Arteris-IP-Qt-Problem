// Author: Nico Ramirez
// Arteris IP QT Project

#include "mainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;
    w.show();
    return a.exec();
}
