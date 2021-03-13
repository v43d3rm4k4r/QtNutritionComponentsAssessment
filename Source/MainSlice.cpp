/*
 * MainSlice.cpp
 *
 *  Created on: 2020
 *      Author: Daniil Kuprianov
 */

#include "MainSlice.h"

QT_CHARTS_USE_NAMESPACE

MainSlice::MainSlice(QPieSeries *breakdownSeries, QObject *parent)
    : QPieSlice(parent),
      _breakdownSeries(breakdownSeries)
{
    connect(this, &MainSlice::percentageChanged, this, &MainSlice::updateLabel);
}
//======================================================================================================
QPieSeries* MainSlice::breakdownSeries() const
{
    return _breakdownSeries;
}
//======================================================================================================
void MainSlice::setName(QString name)
{
    _name = name;
}
//======================================================================================================
QString MainSlice::name() const
{
    return _name;
}
//======================================================================================================
void MainSlice::updateLabel()
{
    this->setLabel(QString("%1 %2%").arg(_name).arg(percentage() * 100, 0, 'f', 2));
}

//#include "moc_mainslice.cpp"
