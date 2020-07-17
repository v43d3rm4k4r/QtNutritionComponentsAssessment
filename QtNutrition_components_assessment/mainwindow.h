#pragma once

#include <QMainWindow>
#include <QDoubleSpinBox>
#include <QLabel>
#include "CalculateModule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE


//======================================================================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Summary input;

    Ui::MainWindow* ui;

    QList<QDoubleSpinBox*> getColumnOfCompSpinboxes(int column);
    QList<QLabel*> listCompLabels;

    void initMainWindow();
    void changeLabelsFor1Comp();
    void changeLabelsForMultComp();
    void setTabOrder();

private slots:
    void spinBoxComp_valueChanged(int value);
    void pushButtonCalculate_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const Summary& setNgetSummaryInput() noexcept;
};
