#pragma once

#include <QtWidgets>

#include "CalculateModule.h"
#include "ui_SummaryWindow.h"

/*QT_BEGIN_NAMESPACE
namespace Ui { class SummaryWindow; }
QT_END_NAMESPACE*/

class SummaryWindow : public QFrame
{
    Q_OBJECT

    Ui_Frame* ui;
    Summary& summary;

    void showResults();

private slots:
    void pushButtonSave_clicked();
    void pushButtonShowChart_clicked();

public:
    SummaryWindow(Summary& summary, QWidget* parent);
    virtual ~SummaryWindow();
};
