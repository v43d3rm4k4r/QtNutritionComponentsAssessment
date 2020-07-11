#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    listCompLabels << ui->labelComp1
                   << ui->labelComp2
                   << ui->labelComp3
                   << ui->labelComp4
                   << ui->labelComp5;

    connect(ui->spinBoxComp, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinBoxCalculate_valueChanged(int))
            );

    on_spinBoxCalculate_valueChanged(1); // исусственно убираем пока не нужные ряды

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBoxCalculate_valueChanged(int value)
{
    static int earlyer_value = 1;

    switch (value)
    {
    case 1:
        qDebug() << "case 1 is called";
        for (int i = value; i <= 5; ++i)
        {
            for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
            {
                if (currentSpinBox->isVisible())
                    currentSpinBox->hide();
            }
            if (i != 1 && listCompLabels[i-1]->isVisible())
                listCompLabels[i-1]->hide();
        }

        changeLabelsFor1Comp();
        break;

    case 2:
        if (value < earlyer_value)
        {
            for (int i = 3; i <= 5; ++i)
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
            for (int i = earlyer_value; i <= value; ++i)
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
            for (int i = 4; i <= 5; ++i)
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
            for (int i = earlyer_value; i <= value; ++i)
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
            for (int i = earlyer_value; i <= value; ++i)
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
        for (int i = earlyer_value; i <= value; ++i)
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
        changeLabelsForMultComp();

    resize(minimumSize());
    earlyer_value = value;
}

QList<QDoubleSpinBox*> MainWindow::getColumnOfCompSpinboxes(int column)
{
    switch (column)
    {
    case 2:
        return QList<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp2
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
        return QList<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp3
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
        return QList<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp4
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
        return QList<QDoubleSpinBox*>()  << ui->doubleSpinBoxPropComp5
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
    return QList<QDoubleSpinBox*>();
}

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
