#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    defaultWindowSize = size();

    connect(ui->spinBoxComp, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinBox_valueChanged(int))
            );

    on_spinBox_valueChanged(1); // исусственно убираем пока не нужные ряды

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBox_valueChanged(int value)
{
    // to hide columns in order to value

    switch (value)
    {
    case 1:


        /*if (value > 1)
        {
            resize(defaultWindowSize.width()-150, defaultWindowSize.height());
        }*/

        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    }

    // TODO: (Опционально) При удалении/добавлении менять ширину окна
}
