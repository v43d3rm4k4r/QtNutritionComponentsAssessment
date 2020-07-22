#pragma once

#include <QMainWindow>
#include <QLabel>
#include "CalculateModule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE


// TODO: -добавить считывание из .txt для автоматического заполнения спинбоксов (взять нарабоки из CSVReader)
//       -переименовать структуры данных оригинального алгоритма

//======================================================================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    CalculateModule* cModule;

    Ui::MainWindow* ui;

    QList<QLabel*> listCompLabels;
    QList<QDoubleSpinBox*> getColumnOfCompSpinboxes(int column) const;


    void initMainWindow();
    void changeLabelsFor1Comp();
    void changeLabelsForMultComp();
    void setTabOrder();
    QVector<QList<QDoubleSpinBox*>> getAllSpinBoxes() const;


private slots:
    void spinBoxComp_valueChanged(int value);
    void pushButtonCalculate_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
};
