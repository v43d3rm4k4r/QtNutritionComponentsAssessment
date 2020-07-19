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
    CalculateModule* cModule;

    Ui::MainWindow* ui;

    QList<QDoubleSpinBox*> getColumnOfCompSpinboxes(int column) const;
    QList<QLabel*> listCompLabels;

    void initMainWindow();
    void changeLabelsFor1Comp();
    void changeLabelsForMultComp();
    QVector<QList<QDoubleSpinBox*>> getAllSpinBoxes() const;
    void setTabOrder();

private slots:
    void spinBoxComp_valueChanged(int value);
    void pushButtonCalculate_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
};
