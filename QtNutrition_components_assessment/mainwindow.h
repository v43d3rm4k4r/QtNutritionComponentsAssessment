#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPainter>
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

    Summary summary;

    Ui::MainWindow* ui;

    QVector<QLabel*> listCompLabels;
    QVector<QDoubleSpinBox*> getColumnOfCompSpinboxes(int column) const;
    QVector<QDoubleSpinBox*> getRowOfSpinboxes(int row) const;

    void initMainWindow();
    void changeLabelsFor1Comp();
    void changeLabelsForMultComp();
    void setTabOrder();
    QVector<QVector<QDoubleSpinBox*>> getAllSpinBoxes() const;
    void showResults();

private slots:
    void spinBoxComp_valueChanged(int value);
    void pushButtonCalculate_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
};
//======================================================================================================
class ResultWindow : public QFrame
{
public:
    ResultWindow(QWidget *parent = nullptr)
        : QFrame(parent)
    {

    }

protected:
    void paintEvent(QPaintEvent* event) override
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setBrush(QBrush(Qt::black, Qt::BDiagPattern));
        painter.setPen(QPen(Qt::blue, 1));
        painter.drawPie(QRect(10, 10,  110, 70), 90 * 16, 270 * 16);
    }
};
