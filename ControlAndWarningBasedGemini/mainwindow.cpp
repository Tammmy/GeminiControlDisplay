#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "configsonar.h"
#include "warninginfoconfigdialog.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

MainWindow::MainWindow(bool transparent, bool frameless, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //![1]
    QLineSeries* series = new QLineSeries();

    //![1]

    //![2]
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2) << QPointF(21, 0);
    //![2]

    //![3]
    QChart* chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("生物通量曲线");
    //![3]


    QValueAxis* xAxis = new QValueAxis();
    QValueAxis* yAxis = new QValueAxis();
    yAxis->setTitleText("生物量(kg)");
    yAxis->setLabelFormat("%d");
    xAxis->setTitleText("时间(10min)");
    xAxis->setLabelFormat("%d");
    chart->setAxisX(xAxis, series);
    chart->setAxisY(yAxis, series);

    //![4]
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //![4]

    ui->warning_vertical_layout->addWidget(chartView);
    //![1]
    QLineSeries* series1 = new QLineSeries();

    //![1]

    //![2]
    series1->append(0, 6);
    series1->append(2, 4);
    series1->append(3, 8);
    series1->append(7, 4);
    series1->append(10, 5);
    *series1 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2) << QPointF(21, 0);
    //![2]

    //![3]
    QChart* chart1 = new QChart();
    chart1->legend()->hide();
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setTitle("生物密度曲线");
    //![3]

    QValueAxis* xAxis1 = new QValueAxis();
    QValueAxis* yAxis1 = new QValueAxis();
    yAxis1->setTitleText("密度(kg/m3)");
    xAxis1->setTitleText("Time(minutes)");
    xAxis1->setLabelFormat("%d");
    chart1->setAxisX(xAxis1, series1);
    chart1->setAxisY(yAxis1, series1);

    //![4]
    QChartView* chartView1 = new QChartView(chart1);
    chartView1->setRenderHint(QPainter::Antialiasing);
    //![4]
    ui->warning_vertical_layout->addWidget(chartView1);

    //![1]
    QLineSeries* series2 = new QLineSeries();

    //![1]

    //![2]
    series2->append(0, 6);
    series2->append(2, 4);
    series2->append(3, 8);
    series2->append(7, 4);
    series2->append(10, 5);
    *series2 << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2) << QPointF(21, 0);
    //![2]

    //![3]
    QChart* chart2 = new QChart();
    chart2->legend()->hide();
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setTitle("生物通量曲线");
    //chart2->setTitleBrush(QColor(255, 255, 255));
    //QPalette p(QColor(43, 43, 43));
    //chart2->setPalette(p);
    //chart2->setBackgroundVisible(false);
    //![3]

    //    //![4]
    //    QChartView* chartView2 = new QChartView(chart2);
    //    chartView2->setRenderHint(QPainter::Antialiasing);
    //    QPalette p(QColor(43, 43, 43));
    //    chartView2->setPalette(p);

    //    //![4]
    //    ui->warning_vertical_layout->addWidget(chartView2);
    QBarSet* barSet = new QBarSet(QString("毛虾"));
    *barSet << 10 << 20 << 30 << 40;
    //    QBarSet* set1 = new QBarSet("水母");
    //    QBarSet* set2 = new QBarSet("鱼类");
    //    QBarSet* set3 = new QBarSet("其它");
    //    *set1 << 20;
    //    *set2 << 30;
    //    *set3 << 40;
    QBarSeries* barseries = new QBarSeries();
    barseries->append(barSet);
    //    barseries->append(set1);
    //    barseries->append(set2);
    //    barseries->append(set3);
    barseries->setLabelsVisible(false);

    QChart* chart3 = new QChart();
    chart3->addSeries(barseries);
    chart3->setTitle("生物种类占比");

    QStringList categories;
    categories << "毛虾" << "水母" << "鱼类" << "其它";

    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart3->addAxis(axisX, Qt::AlignBottom);
    barseries->attachAxis(axisX);
    axisX->setRange(QString("毛虾"), QString("其它"));
    axisX->setTitleText("生物种类");

    QValueAxis* axisY = new QValueAxis();
    chart3->addAxis(axisY, Qt::AlignLeft);
    barseries->attachAxis(axisY);
    axisY->setRange(0, 100);
    axisY->setTitleText("百分比");

    chart3->legend()->setVisible(true);
    chart3->legend()->setAlignment(Qt::AlignBottom);
    chart3->legend()->hide();
    //![5]

    //![6]
    QChartView* chartView3 = new QChartView(chart3);
    chartView3->setRenderHint(QPainter::Antialiasing);

    ui->warning_vertical_layout->addWidget(chartView3);

    //ui->statusBar->showMessage("中国水产科学研究院渔业机械研究所@2022");
    connect(ui->action_config_sonar, SIGNAL(triggered(bool)), this, SLOT(ShowConfigSonarDialog()));
    connect(ui->action_config_warning, SIGNAL(triggered(bool)), this, SLOT(ShowConfigWarningDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowConfigSonarDialog()
{
    ConfigSonar* configSonar = new ConfigSonar();
    configSonar->show();
}

void MainWindow::ShowConfigWarningDialog()
{
    WarningInfoConfigDialog* warningInfoConfig = new WarningInfoConfigDialog();
    warningInfoConfig->show();
}

