#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include "CalculateModule.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

#define DEBUG

// TODO: -добавить считывание из .txt для автоматического заполнения спинбоксов (взять нарабоки из CSVReader)
//       -переименовать структуры данных оригинального алгоритма

//======================================================================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

    Summary summary;

    Ui::MainWindow* ui;

    QVector<QLabel*> listCompLabels;
    QVector<QDoubleSpinBox*> getColumnOfCompSpinboxes(uint32_t column) const;
    QVector<QDoubleSpinBox*> getRowOfSpinboxes(uint32_t row) const;

    void initMainWindow();
    void changeLabelsFor1Comp();
    void changeLabelsForMultComp();
    void setTabOrder();
    QVector<QVector<QDoubleSpinBox*>> getAllSpinBoxes() const;
    void showResults();

#ifdef DEBUG
    void DEBUG_setAllSpinboxes();
#endif

private slots:
    void spinBoxComp_valueChanged(int value);
    void pushButtonCalculate_clicked();

public slots:


public:
    void resetMainWindow();
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();
};
