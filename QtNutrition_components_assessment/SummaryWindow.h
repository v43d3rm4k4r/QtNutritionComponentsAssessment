#pragma once

#include <QtWidgets>

#include "CalculateModule.h"
#include "ui_SummaryWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SummaryWindow; }
QT_END_NAMESPACE


class SummaryWindow : public QFrame
{
    Q_OBJECT

    Ui_Frame* ui;

public:
    SummaryWindow(QWidget* parent = nullptr, const Summary& summary = {0});
    virtual ~SummaryWindow();
};
