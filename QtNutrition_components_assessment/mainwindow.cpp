#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QResizeEvent>
#include "CalculateModule.h"

#include "SummaryWindow.h" // !!!

//======================================================================================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}, ui{new Ui::MainWindow}
{
    ui->setupUi(this);

    listCompLabels << ui->labelComp1
                   << ui->labelComp2
                   << ui->labelComp3
                   << ui->labelComp4
                   << ui->labelComp5;

    connect(ui->spinBoxComp, SIGNAL(valueChanged(int)),
            this, SLOT(spinBoxComp_valueChanged(int))
            );
    connect(ui->pushButtonCalculate, SIGNAL(clicked()),
            this, SLOT(pushButtonCalculate_clicked())
            );

    setTabOrder();
    spinBoxComp_valueChanged(1);

    QPixmap bkgnd("../Backgrounds/Background1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    setMinimumSize(QSize(1183, 773));
}
//======================================================================================================
void MainWindow::spinBoxComp_valueChanged(int value)
{
    static int32_t earlyer_value = 1;

    if (value < earlyer_value)
    {
        ui->doubleSpinBoxPropComp1->setValue(0.0);
        ui->doubleSpinBoxPropComp2->setValue(0.0);
        ui->doubleSpinBoxPropComp3->setValue(0.0);
        ui->doubleSpinBoxPropComp4->setValue(0.0);
        ui->doubleSpinBoxPropComp5->setValue(0.0);
    }

    switch (value)
    {
    case 1:
        for (int32_t i = value; i <= 5; ++i)
        {
            for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
            {
                if (i != 1)
                    currentSpinBox->hide();
            }
            if (i != 1)
                listCompLabels[i-1]->hide();
        }

        ui->doubleSpinBoxPropComp1->setValue(1.00);
        ui->doubleSpinBoxPropComp1->setEnabled(false);

        changeLabelsFor1Comp();
        break;

    case 2:
        if (value < earlyer_value)
        {
            for (int32_t i = 3; i <= 5; ++i)
            {
                for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
                {
                    if (currentSpinBox->isVisible())
                        currentSpinBox->hide();
                }
                if (listCompLabels[i-1]->isVisible())
                    listCompLabels[i-1]->hide();
            }
        }
        else
        {
            for (int32_t i = earlyer_value; i <= value; ++i)
            {
                for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
                {
                    if (!currentSpinBox->isVisible())
                        currentSpinBox->show();
                }
                if (!listCompLabels[i-1]->isVisible())
                    listCompLabels[i-1]->show();
            }
        }

        break;

    case 3:
        if (value < earlyer_value)
        {
            for (int32_t i = 4; i <= 5; ++i)
            {
                for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
                {
                    currentSpinBox->hide();
                }
                if (listCompLabels[i-1]->isVisible())
                    listCompLabels[i-1]->hide();
            }
        }
        else
        {
            for (int32_t i = earlyer_value; i <= value; ++i)
            {
                for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
                {
                    if (!currentSpinBox->isVisible())
                        currentSpinBox->show();
                }
                if (!listCompLabels[i-1]->isVisible())
                    listCompLabels[i-1]->show();
            }
        }

        break;

    case 4:
        if (value < earlyer_value)
        {
            for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(5))
            {
                currentSpinBox->hide();
            }
            if (listCompLabels[4]->isVisible())
                listCompLabels[4]->hide();
        }
        else
        {
            for (int32_t i = earlyer_value; i <= value; ++i)
            {
                for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
                {
                    if (!currentSpinBox->isVisible())
                        currentSpinBox->show();
                }
                if (!listCompLabels[i-1]->isVisible())
                    listCompLabels[i-1]->show();
            }
        }

        break;

    case 5:
        // тут только увеличение
        for (int32_t i = earlyer_value; i <= value; ++i)
        {
            for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
            {
                if (!currentSpinBox->isVisible())
                    currentSpinBox->show();
            }
            if (!listCompLabels[i-1]->isVisible())
                listCompLabels[i-1]->show();
        }

        break;
    }

    if (value != 1)
    {
        changeLabelsForMultComp();
        ui->doubleSpinBoxPropComp1->setValue(0.0);
        ui->doubleSpinBoxPropComp1->setEnabled(true);
    }


    //resize(minimumSize());
    qDebug() << size().width();
    qDebug() << size().height();

    earlyer_value = value;
}
//======================================================================================================
QVector<QDoubleSpinBox*> MainWindow::getColumnOfCompSpinboxes(uint32_t column) const
{
    switch (column)
    {
    // only for MainWindow::setTabOrder()
    case 1:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp1
                                         << ui->doubleSpinBoxProteinsComp1
                                         << ui->doubleSpinBoxValin1
                                         << ui->doubleSpinBoxGistidin1
                                         << ui->doubleSpinBoxIzoleycin1
                                         << ui->doubleSpinBoxLeycin1
                                         << ui->doubleSpinBoxLizin1
                                         << ui->doubleSpinBoxMetioninCistein1
                                         << ui->doubleSpinBoxTreonin1
                                         << ui->doubleSpinBoxTriptofan1
                                         << ui->doubleSpinBoxFenilalaninTirozin1
                                         << ui->doubleSpinBoxLypidsComp1
                                         << ui->doubleSpinBoxSaturatedFattyAcids1
                                         << ui->doubleSpinBoxMonounsaturatedFattyAcids1
                                         << ui->doubleSpinBoxPolyunsaturatedFattyAcids1
                                         << ui->doubleSpinBoxOmega6_1
                                         << ui->doubleSpinBoxOmega3_1;
        break;

    case 2:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp2
                                         << ui->doubleSpinBoxProteinsComp2
                                         << ui->doubleSpinBoxValin2
                                         << ui->doubleSpinBoxGistidin2
                                         << ui->doubleSpinBoxIzoleycin2
                                         << ui->doubleSpinBoxLeycin2
                                         << ui->doubleSpinBoxLizin2
                                         << ui->doubleSpinBoxMetioninCistein2
                                         << ui->doubleSpinBoxTreonin2
                                         << ui->doubleSpinBoxTriptofan2
                                         << ui->doubleSpinBoxFenilalaninTirozin2
                                         << ui->doubleSpinBoxLypidsComp2
                                         << ui->doubleSpinBoxSaturatedFattyAcids2
                                         << ui->doubleSpinBoxMonounsaturatedFattyAcids2
                                         << ui->doubleSpinBoxPolyunsaturatedFattyAcids2
                                         << ui->doubleSpinBoxOmega6_2
                                         << ui->doubleSpinBoxOmega3_2;
        break;

    case 3:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp3
                                         << ui->doubleSpinBoxProteinsComp3
                                         << ui->doubleSpinBoxValin3
                                         << ui->doubleSpinBoxGistidin3
                                         << ui->doubleSpinBoxIzoleycin3
                                         << ui->doubleSpinBoxLeycin3
                                         << ui->doubleSpinBoxLizin3
                                         << ui->doubleSpinBoxMetioninCistein3
                                         << ui->doubleSpinBoxTreonin3
                                         << ui->doubleSpinBoxTriptofan3
                                         << ui->doubleSpinBoxFenilalaninTirozin3
                                         << ui->doubleSpinBoxLypidsComp3
                                         << ui->doubleSpinBoxSaturatedFattyAcids3
                                         << ui->doubleSpinBoxMonounsaturatedFattyAcids3
                                         << ui->doubleSpinBoxPolyunsaturatedFattyAcids3
                                         << ui->doubleSpinBoxOmega6_3
                                         << ui->doubleSpinBoxOmega3_3;
        break;

    case 4:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp4
                                         << ui->doubleSpinBoxProteinsComp4
                                         << ui->doubleSpinBoxValin4
                                         << ui->doubleSpinBoxGistidin4
                                         << ui->doubleSpinBoxIzoleycin4
                                         << ui->doubleSpinBoxLeycin4
                                         << ui->doubleSpinBoxLizin4
                                         << ui->doubleSpinBoxMetioninCistein4
                                         << ui->doubleSpinBoxTreonin4
                                         << ui->doubleSpinBoxTriptofan4
                                         << ui->doubleSpinBoxFenilalaninTirozin4
                                         << ui->doubleSpinBoxLypidsComp4
                                         << ui->doubleSpinBoxSaturatedFattyAcids4
                                         << ui->doubleSpinBoxMonounsaturatedFattyAcids4
                                         << ui->doubleSpinBoxPolyunsaturatedFattyAcids4
                                         << ui->doubleSpinBoxOmega6_4
                                         << ui->doubleSpinBoxOmega3_4;
        break;

    case 5:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp5
                                         << ui->doubleSpinBoxProteinsComp5
                                         << ui->doubleSpinBoxValin5
                                         << ui->doubleSpinBoxGistidin5
                                         << ui->doubleSpinBoxIzoleycin5
                                         << ui->doubleSpinBoxLeycin5
                                         << ui->doubleSpinBoxLizin5
                                         << ui->doubleSpinBoxMetioninCistein5
                                         << ui->doubleSpinBoxTreonin5
                                         << ui->doubleSpinBoxTriptofan5
                                         << ui->doubleSpinBoxFenilalaninTirozin5
                                         << ui->doubleSpinBoxLypidsComp5
                                         << ui->doubleSpinBoxSaturatedFattyAcids5
                                         << ui->doubleSpinBoxMonounsaturatedFattyAcids5
                                         << ui->doubleSpinBoxPolyunsaturatedFattyAcids5
                                         << ui->doubleSpinBoxOmega6_5
                                         << ui->doubleSpinBoxOmega3_5;
        break;
    }
    return QVector<QDoubleSpinBox*>();
}
//======================================================================================================
QVector<QDoubleSpinBox*> MainWindow::getRowOfSpinboxes(uint32_t row) const
{
    switch (row)
    {
    case 1:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp1
                                           << ui->doubleSpinBoxPropComp2
                                           << ui->doubleSpinBoxPropComp3
                                           << ui->doubleSpinBoxPropComp4
                                           << ui->doubleSpinBoxPropComp5;
        break;
    case 2:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxProteinsComp1
                                           << ui->doubleSpinBoxProteinsComp2
                                           << ui->doubleSpinBoxProteinsComp3
                                           << ui->doubleSpinBoxProteinsComp4
                                           << ui->doubleSpinBoxProteinsComp5;
        break;
    case 3:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxValin1
                                           << ui->doubleSpinBoxValin2
                                           << ui->doubleSpinBoxValin3
                                           << ui->doubleSpinBoxValin4
                                           << ui->doubleSpinBoxValin5;
        break;
    case 4:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxGistidin1
                                           << ui->doubleSpinBoxGistidin2
                                           << ui->doubleSpinBoxGistidin3
                                           << ui->doubleSpinBoxGistidin4
                                           << ui->doubleSpinBoxGistidin5;
        break;
    case 5:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxIzoleycin1
                                           << ui->doubleSpinBoxIzoleycin2
                                           << ui->doubleSpinBoxIzoleycin3
                                           << ui->doubleSpinBoxIzoleycin4
                                           << ui->doubleSpinBoxIzoleycin5;
        break;
    case 6:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxLeycin1
                                           << ui->doubleSpinBoxLeycin2
                                           << ui->doubleSpinBoxLeycin3
                                           << ui->doubleSpinBoxLeycin4
                                           << ui->doubleSpinBoxLeycin5;
        break;
    case 7:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxLizin1
                                           << ui->doubleSpinBoxLizin2
                                           << ui->doubleSpinBoxLizin3
                                           << ui->doubleSpinBoxLizin4
                                           << ui->doubleSpinBoxLizin5;
        break;
    case 8:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxMetioninCistein1
                                           << ui->doubleSpinBoxMetioninCistein2
                                           << ui->doubleSpinBoxMetioninCistein3
                                           << ui->doubleSpinBoxMetioninCistein4
                                           << ui->doubleSpinBoxMetioninCistein5;
        break;
    case 9:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxTreonin1
                                           << ui->doubleSpinBoxTreonin2
                                           << ui->doubleSpinBoxTreonin3
                                           << ui->doubleSpinBoxTreonin4
                                           << ui->doubleSpinBoxTreonin5;
        break;
    case 10:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxTriptofan1
                                           << ui->doubleSpinBoxTriptofan2
                                           << ui->doubleSpinBoxTriptofan3
                                           << ui->doubleSpinBoxTriptofan4
                                           << ui->doubleSpinBoxTriptofan5;
        break;
    case 11:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxFenilalaninTirozin1
                                           << ui->doubleSpinBoxFenilalaninTirozin2
                                           << ui->doubleSpinBoxFenilalaninTirozin3
                                           << ui->doubleSpinBoxFenilalaninTirozin4
                                           << ui->doubleSpinBoxFenilalaninTirozin5;
    case 12:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxLypidsComp1
                                           << ui->doubleSpinBoxLypidsComp2
                                           << ui->doubleSpinBoxLypidsComp3
                                           << ui->doubleSpinBoxLypidsComp4
                                           << ui->doubleSpinBoxLypidsComp5;
    case 13:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxSaturatedFattyAcids1
                                           << ui->doubleSpinBoxSaturatedFattyAcids2
                                           << ui->doubleSpinBoxSaturatedFattyAcids3
                                           << ui->doubleSpinBoxSaturatedFattyAcids4
                                           << ui->doubleSpinBoxSaturatedFattyAcids5;
    case 14:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxMonounsaturatedFattyAcids1
                                           << ui->doubleSpinBoxMonounsaturatedFattyAcids2
                                           << ui->doubleSpinBoxMonounsaturatedFattyAcids3
                                           << ui->doubleSpinBoxMonounsaturatedFattyAcids4
                                           << ui->doubleSpinBoxMonounsaturatedFattyAcids5;
    case 15:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxPolyunsaturatedFattyAcids1
                                           << ui->doubleSpinBoxPolyunsaturatedFattyAcids2
                                           << ui->doubleSpinBoxPolyunsaturatedFattyAcids3
                                           << ui->doubleSpinBoxPolyunsaturatedFattyAcids4
                                           << ui->doubleSpinBoxPolyunsaturatedFattyAcids5;
    case 16:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxOmega6_1
                                           << ui->doubleSpinBoxOmega6_2
                                           << ui->doubleSpinBoxOmega6_3
                                           << ui->doubleSpinBoxOmega6_4
                                           << ui->doubleSpinBoxOmega6_5;
    case 17:
        return QVector<QDoubleSpinBox*>()  << ui->doubleSpinBoxOmega6_1
                                           << ui->doubleSpinBoxOmega6_2
                                           << ui->doubleSpinBoxOmega6_3
                                           << ui->doubleSpinBoxOmega6_4
                                           << ui->doubleSpinBoxOmega6_1;
        break;

    }

    return QVector<QDoubleSpinBox*>();
}

//======================================================================================================
void MainWindow::changeLabelsFor1Comp()
{
    ui->label_2->setText("Введите пропорции компонента:");
    ui->label_3->setText("Введите кол-во белка на 100г компонента:");
    ui->label_19->setText("Введите кол-во липидов на 100г компонента:");
    ui->label_20->setText("Введите кол-во насыщенных жирных кислот на 100г компонента:");
    ui->label_21->setText("Введите кол-во мононенасыщенных жирных кислот на 100г компонента:");
    ui->label_22->setText("Введите кол-во полиненасыщенных жирных кислот на 100г компонента:");
    ui->label_23->setText("Введите омега-6 на 100г компонента:");
    ui->label_24->setText("Введите омега-3 на 100г компонента:");
}
//======================================================================================================
void MainWindow::changeLabelsForMultComp()
{
    ui->label_2->setText("Введите пропорции компонентов:");
    ui->label_3->setText("Введите кол-во белка на 100г каждого компонента:");
    ui->label_19->setText("Введите кол-во липидов на 100г каждого компонента:");
    ui->label_20->setText("Введите кол-во насыщенных жирных кислот на 100г каждого компонента:");
    ui->label_21->setText("Введите кол-во мононенасыщенных жирных кислот на 100г каждого компонента:");
    ui->label_22->setText("Введите кол-во полиненасыщенных жирных кислот на 100г каждого компонента:");
    ui->label_23->setText("Введите омега-6 на 100г каждого компонента:");
    ui->label_24->setText("Введите омега-3 на 100г каждого компонента:");
}
//======================================================================================================
void MainWindow::setTabOrder()
{
    const uint8_t ROWS = 17;

    QVector<QVector<QDoubleSpinBox*>> vCols;

    for (uint8_t i = 1; i <= 5; i++)
    {
        vCols << getColumnOfCompSpinboxes(i);
    }

    for (uint8_t cols = 1; cols < 5; ++cols)
    {
        for (uint8_t rows = 1; rows < ROWS; ++rows)
            QWidget::setTabOrder(vCols[cols-1][rows-1], vCols[cols-1][rows]);

        if (cols == 4)
        {
            for (uint8_t rows = 1; rows < ROWS; ++rows)
                QWidget::setTabOrder(vCols[4][rows-1], vCols[4][rows]);
        }

        // соединяем с началом следующей колонны
        QWidget::setTabOrder(vCols[cols-1][ROWS-1], vCols[cols][0]);
    }
}
//======================================================================================================
void MainWindow::pushButtonCalculate_clicked()
{
    double sum = ui->doubleSpinBoxPropComp1->value()   + ui->doubleSpinBoxPropComp2->value()
                 + ui->doubleSpinBoxPropComp3->value() + ui->doubleSpinBoxPropComp4->value()
                 + ui->doubleSpinBoxPropComp5->value();

    if (!qFuzzyCompare(sum, 1.0))
    {
        QMessageBox::warning(this, "Ошибка",
                            "Сумма пропорций компонентов должна равняться 1.", QMessageBox::Ok);
        return;
    }

    CalculateModule* cModule = new CalculateModule(getAllSpinBoxes(), ui->spinBoxComp->value());

    summary = cModule->getResult();
    delete cModule;

    showResults();

    //summary = {0};
}
//======================================================================================================
QVector<QVector<QDoubleSpinBox*>> MainWindow::getAllSpinBoxes() const
{
    QVector<QVector<QDoubleSpinBox*>> allSpinBoxes;

    for (uint32_t i = 1; i <= 17; ++i)
    {
        allSpinBoxes << getRowOfSpinboxes(i);
    }
    return allSpinBoxes;
}
//======================================================================================================
void MainWindow::showResults()
{
    //this->setEnabled(false);

    // вместо всего этого понять что такое модальные окна
    SummaryWindow* wgt = new SummaryWindow(summary, *this, this);

    wgt->setWindowFlags(Qt::Window);

    wgt->show();


    // ПРИ ЗАКРЫТИИ ОКНА ТЕКСТОВОГО ВЫВОДА ОБНУЛИТЬ СТРУКТУРУ И ВКЛЮЧИТЬ ГЛАВНОЕ ОКНО!!!
    //wgt->setEnabled(true);

}
//======================================================================================================
void MainWindow::resetMainWindow()
{
    this->setEnabled(true);
    summary = {0};
}
//======================================================================================================
MainWindow::~MainWindow()
{
    delete ui;
}
