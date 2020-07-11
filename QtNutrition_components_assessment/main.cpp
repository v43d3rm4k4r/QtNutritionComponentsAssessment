#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.setWindowTitle("NUTRITION COMPONENTS ASSESSMENT");

    w.resize(w.minimumSize());

    w.show();


    return app.exec();
}
