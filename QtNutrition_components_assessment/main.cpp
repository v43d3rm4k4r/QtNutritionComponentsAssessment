#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LPCSTR title = "NUTRITION COMPONENTS ASSESSMENT";
    SetConsoleTitleA(title);

    MainWindow w;

    //w.resize(w.minimumSize());
    qDebug() << w.size().width();
    qDebug() << w.size().height();

    w.show();


    return a.exec();
}
