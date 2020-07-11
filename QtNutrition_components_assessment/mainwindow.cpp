#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    defaultWindowSize = size();

    connect(ui->spinBoxComp, SIGNAL(valueChanged(int)),
            this, SLOT(on_spinBoxCalculate_valueChanged(int))
            );

    //on_spinBoxCalculate_valueChanged(1); // исусственно убираем пока не нужные ряды

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBoxCalculate_valueChanged(int value)
{

    // ВЕРНУТЬ УЖЕ СКРЫТЫЕ КОЛОННЫ ПРИ УВЕЛИЧЕНИИ value!

    switch (value)
    {
    case 1:
        for (int i = 2; i <= 5; ++i)
        {
            for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
            {
                currentSpinBox->hide();
            }
        }
        break;

    case 2:
        for (int i = 3; i <= 5; ++i)
        {
            for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
            {
                currentSpinBox->hide();
            }
        }
        break;

    case 3:
        for (int i = 4; i <= 5; ++i)
        {
            for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(i))
            {
                currentSpinBox->hide();
            }
        }
        break;

    case 4:
        for (QDoubleSpinBox* currentSpinBox : getColumnOfCompSpinboxes(5))
        {
            currentSpinBox->hide();
        }
        break;

    case 5:


        break;
    }

    static int earlyer_value = value;

    // TODO: (Опционально) При удалении/добавлении менять ширину окна
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
