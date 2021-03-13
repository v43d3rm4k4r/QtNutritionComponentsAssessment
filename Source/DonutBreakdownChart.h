/*
 * DonutBreakdownChart.h
 *
 *  Created on: 2020
 *      Author: Daniil Kuprianov
 */

#pragma once

#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>

QT_CHARTS_USE_NAMESPACE

class DonutBreakdownChart : public QChart
{
    QPieSeries* _mainSeries;
public:
    DonutBreakdownChart(QGraphicsItem* parent = nullptr,
                        Qt::WindowFlags wFlags = {});
    void addBreakdownSeries(QPieSeries* series, QColor color);

private:
    void recalculateAngles();
    void updateLegendMarkers();
};


