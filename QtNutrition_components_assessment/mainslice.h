#pragma once

#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class MainSlice : public QPieSlice
{
    Q_OBJECT
public:
    MainSlice(QPieSeries *breakdownSeries, QObject *parent = 0);

    QPieSeries *breakdownSeries() const;

    void setName(QString name);
    QString name() const;

public Q_SLOTS:
    void updateLabel();

private:
    QPieSeries *m_breakdownSeries;
    QString m_name;
};
