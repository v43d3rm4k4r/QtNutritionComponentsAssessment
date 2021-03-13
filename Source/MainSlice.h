/*
 * MainSlice.h
 *
 *  Created on: 2020
 *      Author: Daniil Kuprianov
 */

#pragma once

#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class MainSlice : public QPieSlice
{
    Q_OBJECT

    QPieSeries* _breakdownSeries;
    QString _name;

public:
    MainSlice(QPieSeries* breakdownSeries, QObject* parent = nullptr);

    QPieSeries* breakdownSeries() const;

    void setName(QString name);
    QString name() const;

public slots:
    void updateLabel();
};
