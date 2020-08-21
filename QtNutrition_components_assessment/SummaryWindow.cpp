#include "SummaryWindow.h"
#include <QtWidgets/QApplication>
//#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtCharts/QChartView>
#include "donutbreakdownchart.h"

SummaryWindow::SummaryWindow(Summary& summary, QWidget* parent)
    : QFrame{parent}, ui{new Ui_Frame}, sum{summary}
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

    //setMinimumSize(QSize(1183, 773))
    //
}
//======================================================================================================
void SummaryWindow::pushButtonSave_clicked()
{

}
//======================================================================================================
void SummaryWindow::pushButtonShowChart_clicked()
{


    QPieSeries *series1 = new QPieSeries();
    series1->setName("Fossil fuels");
    series1->append("Oil", 353295);
    series1->append("Coal", 188500);
    series1->append("Natural gas", 148680);
    series1->append("Peat", 94545);

    QPieSeries *series2 = new QPieSeries();
    series2->setName("Renewables");
    series2->append("Wood fuels", 319663);
    series2->append("Hydro power", 45875);
    series2->append("Wind power", 1060);

    /*QPieSeries *series3 = new QPieSeries();
    series3->setName("Others");
    series3->append("Nuclear energy", 238789);
    series3->append("Import energy", 37802);
    series3->append("Other", 32441);*/

    DonutBreakdownChart *donutBreakdown = new DonutBreakdownChart();
    donutBreakdown->setAnimationOptions(QChart::AllAnimations);
    donutBreakdown->setTitle("Ue or not ue?????????????");
    donutBreakdown->legend()->setAlignment(Qt::AlignRight);
    donutBreakdown->addBreakdownSeries(series1, Qt::red);
    donutBreakdown->addBreakdownSeries(series2, Qt::blue);
    //donutBreakdown->addBreakdownSeries(series3, Qt::darkBlue);


    //QMainWindow window;
    QChartView *chartView = new QChartView(donutBreakdown);
    chartView->setRenderHint(QPainter::Antialiasing);
    //window.setCentralWidget(chartView);

    QPixmap bkgnd("../Backgrounds/Background3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    //palette.setBrush(QPalette::Background, bkgnd);
    chartView->setBackgroundBrush(bkgnd);

    chartView->setWindowTitle("График");
    chartView->resize(800, 500);
    chartView->show();
}
//======================================================================================================
SummaryWindow::~SummaryWindow()
{
    delete ui;
}
