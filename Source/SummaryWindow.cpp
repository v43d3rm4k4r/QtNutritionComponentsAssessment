#include "SummaryWindow.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "DonutBreakdownChart.h"
#include "SummarySaveWindow.h"

SummaryWindow::SummaryWindow(Summary& summary, QWidget* parent)
    : QFrame{parent}, ui{new Ui_Frame}, summary{summary}
{
    ui->setupUi(this);

    connect(ui->pushButtonSave, SIGNAL(clicked()),
            this, SLOT(pushButtonSave_clicked())
            );
    connect(ui->pushButtonShowChart, SIGNAL(clicked()),
            this, SLOT(pushButtonShowChart_clicked())
            );

    QPixmap bkgnd("../Backgrounds/Background2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->showResults();
    this->setEnabled(true);
    this->setMinimumWidth(650);
}
//======================================================================================================
void SummaryWindow::showResults()
{
    const uint8_t precision = 2u;

    for (uint32_t i = 0; i < AMI; ++i)
    {
        if (i == 0)
            ui->textEdit->append("Валин:");
        if (i == 1)
            ui->textEdit->append("Гистидин:");
        if (i == 2)
            ui->textEdit->append("Изолейцин:");
        if (i == 3)
            ui->textEdit->append("Лейцин:");
        if (i == 4)
            ui->textEdit->append("Лизин:");
        if (i == 5)
            ui->textEdit->append("Метионин+Цистеин:");
        if (i == 6)
            ui->textEdit->append("Треонин:");
        if (i == 7)
            ui->textEdit->append("Триптофан:");
        if (i == 8)
            ui->textEdit->append("Фенилаланин+Тирозин:");

        if (summary.comp_num == 1)
            ui->textEdit->append(QString("Аминокислота на 100г белка = %1")
                                 .arg(summary.recount[i][0], 0, 'f', precision));
        if (summary.comp_num == 2)
        {
            ui->textEdit->append(QString("Аминокислота на 100г белка в 1 компоненте = %1")
                                 .arg(summary.recount[i][0], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 2 компоненте = %1")
                                 .arg(summary.recount[i][1], 0, 'f', precision));
        }
        if (summary.comp_num == 3)
        {
            ui->textEdit->append(QString("Аминокислота на 100г белка в 1 компоненте = %1")
                                 .arg(summary.recount[i][0], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 2 компоненте = %1")
                                 .arg(summary.recount[i][1], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 3 компоненте = %1")
                                 .arg(summary.recount[i][2], 0, 'f', precision));
        }
        if (summary.comp_num == 4)
        {
            ui->textEdit->append(QString("Аминокислота на 100г белка в 1 компоненте = %1")
                                 .arg(summary.recount[i][0], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 2 компоненте = %1")
                                 .arg(summary.recount[i][1], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 3 компоненте = %1")
                                 .arg(summary.recount[i][2], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 4 компоненте = %1")
                                 .arg(summary.recount[i][3], 0, 'f', precision));
        }
        if (summary.comp_num == 5)
        {
            ui->textEdit->append(QString("Аминокислота на 100г белка в 1 компоненте = %1")
                                 .arg(summary.recount[i][0], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 2 компоненте = %1")
                                 .arg(summary.recount[i][1], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 3 компоненте = %1")
                                 .arg(summary.recount[i][2], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 4 компоненте = %1")
                                 .arg(summary.recount[i][3], 0, 'f', precision));
            ui->textEdit->append(QString("Аминокислота на 100г белка в 5 компоненте = %1")
                                 .arg(summary.recount[i][4], 0, 'f', precision));
        }

        ui->textEdit->append(QString("Аминокислота в продукте = %1\n")
                             .arg(summary.akp[i], 0, 'f', precision) +
                QString("Аминокислотный скор = %1\n")
                             .arg(summary.aminoacidskor[i], 0, 'f', precision) +
                QString("Коэффициент рациональности = %1")
                             .arg(summary.koef_ration[i], 0, 'f', precision)
                             );

        ui->textEdit->append(QString("Коэффициент сбалансированности = %1")
                             .arg(summary.fatty_acid_per_100g[i], 0, 'f', precision));
        ui->textEdit->append("=================================================");

    } // for

    ui->textEdit->append("============ОЦЕНКА БЕЛКОВОЙ СОСТАВЛЯЮЩЕЙ:============");
    ui->textEdit->append(QString("Коэффициент разбалансированности = %1")
                         .arg(summary.kras, 0, 'f', precision));
    ui->textEdit->append(QString("Биологическая ценность = %1")
                         .arg(summary.biological_value, 0, 'f', precision));
    ui->textEdit->append(QString("Коэффициент рациональности аминокислотного состава = %1")
                         .arg(summary.amino_acid_comp_ratio_coef, 0, 'f', precision));
    ui->textEdit->append(QString("Показатель сопоставимой избыточности = %1")
                         .arg(summary.comparable_redundancy_ratio, 0, 'f', precision));
    ui->textEdit->append(QString("Индекс сбалансированности = %1")
                         .arg(summary.balance_index, 0, 'f', precision));
    ui->textEdit->append(QString("Коэффициент сбалансированности белковой составляющей = %1")
                         .arg(summary.k_general, 0, 'f', precision));

    if (summary.k_general >= 0.0 && summary.k_general <= 0.2)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkRed));
        printf("Шкала желательности Харрингтона - очень низкая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.k_general > 0.2 && summary.k_general <= 0.37)
    {
        ui->textEdit->setTextColor(QColor(Qt::red));
        ui->textEdit->append("Шкала желательности Харрингтона - низкая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.k_general > 0.37 && summary.k_general <= 0.64)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkYellow));
        ui->textEdit->append("Шкала желательности Харрингтона - средняя");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }


    if (summary.k_general > 0.64 && summary.k_general <= 0.8)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkGreen));
        ui->textEdit->append("Шкала желательности Харрингтона - высокая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.k_general > 0.8 && summary.k_general <= 1.0)
    {
        ui->textEdit->setTextColor(QColor(Qt::green));
        ui->textEdit->append("Шкала желательности Харрингтона - очень высокая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    ui->textEdit->append("=================================================");

    /*ВЫВОД ЛИПИДОВ*/
    for (uint32_t i = 0; i < LIP_PROP; ++i)
    {
        if (summary.comp_num == 1 && i == 0)
            ui->textEdit->append(QString("Насыщенных жирных кислот = %1")
                                 .arg(summary.recount_lip[i][0], 0, 'f', precision));
        if (summary.comp_num == 1 && i == 1)
            ui->textEdit->append(QString("Мононенасыщенных жирных кислот = %1")
                                 .arg(summary.recount_lip[i][0], 0, 'f', precision));
        if (summary.comp_num == 1 && i == 2)
            ui->textEdit->append(QString("Полиненасыщенных жирных кислот = %1")
                                 .arg(summary.recount_lip[i][0], 0, 'f', precision));
        if (summary.comp_num == 1 && i == 3)
            ui->textEdit->append(QString("Омега-6 = %1")
                                 .arg(summary.recount_lip[i][0], 0, 'f', precision));
        if (summary.comp_num == 1 && i == 4)
            ui->textEdit->append(QString("Омега-3 = %1")
                                 .arg(summary.recount_lip[i][0], 0, 'f', precision));

        if (summary.comp_num == 2)
        {
            if (i == 0)
                ui->textEdit->append(QString("Насыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 2 компоненте = %1")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision));
            if (i == 1)
                ui->textEdit->append(QString("Мононенасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 2 компоненте = %1")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision));
            if (i == 2)
                ui->textEdit->append(QString("Полиненасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 2 компоненте = %1")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision));
            if (i == 3)
                ui->textEdit->append(QString("Омега-6 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-6 в 2 компоненте = %1")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision));
            if (i == 4)
                ui->textEdit->append(QString("Омега-3 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-3 в 2 компоненте = %1")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision));
        }
        if (summary.comp_num == 3)
        {
            if (i == 0)
                ui->textEdit->append(QString("Насыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 3 компоненте = %1")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision));
            if (i == 1)
                ui->textEdit->append(QString("Мононенасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 3 компоненте = %1")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision));
            if (i == 2)
                ui->textEdit->append(QString("Полиненасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 3 компоненте = %1")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision));
            if (i == 3)
                ui->textEdit->append(QString("Омега-6 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-6 в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Омега-6 в 3 компоненте = %1")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision));
            if (i == 4)
                ui->textEdit->append(QString("Омега-3 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-3 в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Омега-3 в 3 компоненте = %1")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision));
        }
        if (summary.comp_num == 4)
        {
            if (i == 0)
                ui->textEdit->append(QString("Насыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 4 компоненте = %1")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision));
            if (i == 1)
                ui->textEdit->append(QString("Мононенасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 4 компоненте = %1")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision));
            if (i == 2)
                ui->textEdit->append(QString("Полиненасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 4 компоненте = %1")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision));
            if (i == 3)
                ui->textEdit->append(QString("Омега-6 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-6 в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Омега-6 в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Омега-6 в 4 компоненте = %1")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision));
            if (i == 4)
                ui->textEdit->append(QString("Омега-3 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-3 в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Омега-3 в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Омега-3 в 4 компоненте = %1")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision));
        }
        if (summary.comp_num == 5)
        {
            if (i == 0)
                ui->textEdit->append(QString("Насыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 4 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision) +
                        QString("Насыщенных жирных кислот в 5 компоненте = %1")
                                     .arg(summary.recount_lip[i][4], 0, 'f', precision));
            if (i == 1)
                ui->textEdit->append(QString("Мононенасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 4 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision) +
                        QString("Мононенасыщенных жирных кислот в 5 компоненте = %1")
                                     .arg(summary.recount_lip[i][4], 0, 'f', precision));
            if (i == 2)
                ui->textEdit->append(QString("Полиненасыщенных жирных кислот в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 4 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision) +
                        QString("Полиненасыщенных жирных кислот в 4 компоненте = %1")
                                     .arg(summary.recount_lip[i][4], 0, 'f', precision));
            if (i == 3)
                ui->textEdit->append(QString("Омега-6 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-6 в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Омега-6 в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Омега-6 в 4 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision) +
                        QString("Омега-6 в 5 компоненте = %1")
                                     .arg(summary.recount_lip[i][4], 0, 'f', precision));
            if (i == 4)
                ui->textEdit->append(QString("Омега-3 в 1 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][0], 0, 'f', precision) +
                        QString("Омега-3 в 2 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][1], 0, 'f', precision) +
                        QString("Омега-3 в 3 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][2], 0, 'f', precision) +
                        QString("Омега-3 в 4 компоненте = %1\n")
                                     .arg(summary.recount_lip[i][3], 0, 'f', precision) +
                        QString("Омега-3 в 5 компоненте = %1")
                                     .arg(summary.recount_lip[i][4], 0, 'f', precision));
        }
        ui->textEdit->append(QString("Жирных кислот в 100г продукта = %1").arg(summary.ratio_calc[i], 0, 'f', precision));
        ui->textEdit->append("=================================================");
    } // for

    ui->textEdit->append("============ОЦЕНКА ЛИПИДНОЙ СОСТАВЛЯЮЩЕЙ:============");
    ui->textEdit->append(QString("Коэффициент жирнокислотного соответствия (при i=3) = %1").arg(summary.fattyAcidComplianceResult1));
    ui->textEdit->append(QString("Коэффициент жирнокислотного соответствия (при i=5) = %1").arg(summary.fattyAcidComplianceResult2));

    if (summary.fattyAcidComplianceResult1 >= 0.0 && summary.fattyAcidComplianceResult1 <= 0.2)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkRed));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - очень низкая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.fattyAcidComplianceResult1 > 0.2 && summary.fattyAcidComplianceResult1 <= 0.37)
    {
        ui->textEdit->setTextColor(QColor(Qt::red));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - низкая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.fattyAcidComplianceResult1 > 0.37 && summary.fattyAcidComplianceResult1 <= 0.64)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkYellow));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - средняя");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }


    if (summary.fattyAcidComplianceResult1 > 0.64 && summary.fattyAcidComplianceResult1 <= 0.8)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkGreen));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - высокая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.fattyAcidComplianceResult1 > 0.8 && summary.fattyAcidComplianceResult1 <= 1.0)
    {
        ui->textEdit->setTextColor(QColor(Qt::green));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - очень высокая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }
    //-------------------------------------------------------------------------------------------------
    if (summary.fattyAcidComplianceResult2 >= 0.0 && summary.fattyAcidComplianceResult2 <= 0.2)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkRed));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - очень низкая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.fattyAcidComplianceResult2 > 0.2 && summary.fattyAcidComplianceResult2 <= 0.37)
    {
        ui->textEdit->setTextColor(QColor(Qt::red));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - низкая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.fattyAcidComplianceResult2 > 0.37 && summary.fattyAcidComplianceResult2<= 0.64)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkYellow));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - средняя");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }


    if (summary.fattyAcidComplianceResult2 > 0.64 && summary.fattyAcidComplianceResult2 <= 0.8)
    {
        ui->textEdit->setTextColor(QColor(Qt::darkGreen));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - высокая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    if (summary.fattyAcidComplianceResult2 > 0.8 && summary.fattyAcidComplianceResult2 <= 1.0)
    {
        ui->textEdit->setTextColor(QColor(Qt::green));
        ui->textEdit->append("Шкала желательности Харрингтона (при i=3) - очень высокая");
        ui->textEdit->setTextColor(QColor(Qt::black));
    }

    ui->textEdit->append("=================================================");
}
//======================================================================================================
/*void SummaryWindow::sendResultToSaveWindow()
{
    emit sendResultToSaveWindowSignal(ui->textEdit->toPlainText());
}*/
//======================================================================================================
/*void SummaryWindow::closeEvent(QCloseEvent* event)
{
    Q_UNUSED(event);



}*/

//======================================================================================================
void SummaryWindow::pushButtonSave_clicked()
{
    SummarySaveWindow* save_window = new SummarySaveWindow(ui->textEdit->toPlainText(), this);
    save_window->setWindowFlags(Qt::Window);
    save_window->setWindowModality(Qt::ApplicationModal);
    save_window->show();
}
//======================================================================================================
void SummaryWindow::pushButtonShowChart_clicked()
{
    double allAKP = 0;
    for (const auto& current : summary.akp)
    {
        allAKP += current;
    }
    QPieSeries* proteins = new QPieSeries(this);
    proteins->setName("Протеины");
    proteins->append("Протеины", allAKP);
    //-------------------------------------------------------------------------------------------------
    double allFatty_acid_per_100g = 0;
    for (const auto& current : summary.fatty_acid_per_100g)
    {
        allFatty_acid_per_100g += current;
    }
    QPieSeries* lipids = new QPieSeries(this);
    lipids->setName("Липиды");
    lipids->append("Липиды", allFatty_acid_per_100g);

    qDebug() << "allAKP = " << allAKP;
    qDebug() << "allFatty_acid_per_100g = " << allFatty_acid_per_100g;

    DonutBreakdownChart* donutBreakdown = new DonutBreakdownChart;
    donutBreakdown->setParent(this);
    donutBreakdown->setAnimationOptions(QChart::AllAnimations);
    donutBreakdown->setTitle("Оценка белковой и липидной составляющих продукта");
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    //donutBreakdown->legend()->setFont(QFont("Arial", 16));

    donutBreakdown->addBreakdownSeries(proteins, Qt::red);
    donutBreakdown->addBreakdownSeries(lipids, Qt::blue);


    QChartView *chartView = new QChartView;
    chartView->setChart(donutBreakdown);
    chartView->setRenderHint(QPainter::Antialiasing);

    QPixmap bkgnd("../Backgrounds/Background3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    //chartViewProteins->setBackgroundBrush(bkgnd);

    chartView->setPalette(palette);
    chartView->setWindowTitle("График");
    chartView->resize(850, 500);
    chartView->move(x()-100, y());
    chartView->setWindowModality(Qt::ApplicationModal);
    chartView->show();

    /*chartViewProteins->setWindowTitle("Протеины");
    chartViewProteins->resize(800, 500);
    chartViewProteins->move(x()-500, y());
    chartViewProteins->show();

    chartViewLipids->setWindowTitle("Липиды");
    chartViewLipids->resize(800, 500);
    chartViewLipids->move(x()+300, y());
    chartViewLipids->show();*/
}
//======================================================================================================
SummaryWindow::~SummaryWindow()
{
    delete ui;
}
