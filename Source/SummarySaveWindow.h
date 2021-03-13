/*
 * SummarySaveWindow.h
 *
 *  Created on: 2020
 *      Author: Daniil Kuprianov
 */

#pragma once

#include <QFileDialog>
#include <QFile>
#include "ui_SummarySaveWindow.h"

class SummarySaveWindow : public QWidget
{
    Q_OBJECT

    Ui_Form* ui;
    QFileDialog* _file_dialog;
    QString _result;

private slots:
    void pushButtonFileDialog_clicked();
    void urlSelected(const QUrl& url);
    void pushButtonConfirm_clicked();

public:
    SummarySaveWindow(const QString& result, QWidget* parent);
    virtual ~SummarySaveWindow();
};
