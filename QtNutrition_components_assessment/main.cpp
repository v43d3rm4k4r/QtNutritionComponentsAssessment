#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("NUTRITION COMPONENTS ASSESSMENT");
    window.resize(940, 663);
    window.show();
    return app.exec();
}
