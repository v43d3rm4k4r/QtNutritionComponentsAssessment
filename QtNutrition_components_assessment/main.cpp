#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;

    window.setWindowTitle("NUTRITION COMPONENTS ASSESSMENT");

    window.resize(924, 663);

    window.show();

    return app.exec();
}
