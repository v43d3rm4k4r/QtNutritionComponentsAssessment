#include "SummaryWindow.h"

SummaryWindow::SummaryWindow(QWidget* parent, const Summary& summary)
    : QFrame{parent}, ui{new Ui_Frame}
{
    ui->setupUi(this);

    //
}
//======================================================================================================
SummaryWindow::~SummaryWindow()
{
    delete ui;
}
