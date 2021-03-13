/*
 * DonutBreakdownChart.cpp
 *
 *  Created on: 2020
 *      Author: Daniil Kuprianov
 */

#include "DonutBreakdownChart.h"
#include "MainSlice.h"
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieLegendMarker>

QT_CHARTS_USE_NAMESPACE

//======================================================================================================
DonutBreakdownChart::DonutBreakdownChart(QGraphicsItem* parent, Qt::WindowFlags wFlags)
    : QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    // create the series for main center pie
    _mainSeries = new QPieSeries(this);
    _mainSeries->setPieSize(0.7);
    QChart::addSeries(_mainSeries);
}
//======================================================================================================
void DonutBreakdownChart::addBreakdownSeries(QPieSeries* breakdownSeries, QColor color)
{
    QFont font("Arial", 16);

    // add breakdown series as a slice to center pie
    MainSlice* mainSlice = new MainSlice(breakdownSeries);
    mainSlice->setName(breakdownSeries->name());
    mainSlice->setValue(breakdownSeries->sum());
    _mainSeries->append(mainSlice);

    // customize the slice
    mainSlice->setBrush(color);
    /*mainSlice->setLabelVisible();
    mainSlice->setLabelColor(Qt::white);
    mainSlice->setLabelPosition(QPieSlice::LabelInsideHorizontal);
    mainSlice->setLabelFont(font);*/

    // position and customize the breakdown series
    breakdownSeries->setPieSize(0.8);
    breakdownSeries->setHoleSize(0.7);
    //breakdownSeries->setLabelsVisible(); // outer labels
    const auto slices = breakdownSeries->slices();
    foreach (QPieSlice* slice, slices)
    {
        color = color.lighter(115);
        slice->setBrush(color);
        slice->setLabelFont(font);
    }

    // add the series to the chart
    QChart::addSeries(breakdownSeries);

    // recalculate breakdown donut segments
    recalculateAngles();

    // update customize legend markers
    updateLegendMarkers();
}
//======================================================================================================
void DonutBreakdownChart::recalculateAngles()
{
    double angle = 0;
    const auto slices = _mainSeries->slices();
    for (QPieSlice* slice : slices) {
        QPieSeries* breakdownSeries = qobject_cast<MainSlice*>(slice)->breakdownSeries();
        breakdownSeries->setPieStartAngle(angle);
        angle += slice->percentage() * 360.0; // full pie is 360.0
        breakdownSeries->setPieEndAngle(angle);
    }
}
//======================================================================================================
void DonutBreakdownChart::updateLegendMarkers()
{
    // go through all markers
    const auto all_series = series();
    foreach (QAbstractSeries* series, all_series)
    {
        const auto markers = legend()->markers(series);
        foreach (QLegendMarker* marker, markers)
        {
            QPieLegendMarker* pieMarker = qobject_cast<QPieLegendMarker*>(marker);
            if (series == _mainSeries)
            {
                // hide markers from main series
                pieMarker->setVisible(false);
            }
            else
            {
                // modify markers from breakdown series
                pieMarker->setLabel(QString("%1 %2%")
                                    .arg(pieMarker->slice()->label())
                                    .arg(pieMarker->slice()->percentage() * 100, 0, 'f', 2));
                pieMarker->setFont(QFont ("Arial", 16));
            }
        }
    }
}
