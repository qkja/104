#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //数据
    QBarSet *set0 = new QBarSet("SET0");
    *set0<<0<<10<<8<<12<<7<<19<<14;


    //分组
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    //图表
    QChart *chart=new QChart;
    QChartView *chartview=new QChartView;
    chart->addSeries(series);

    //横、纵坐标轴线
    QValueAxis *axisX=new QValueAxis;
    QValueAxis *axisY=new QValueAxis;
    axisX->setRange(0,10);                //X轴的范围
    axisX->setTickCount(11);              //X轴分成多少格
    axisY->setRange(0,21);                //Y轴的范围
    axisY->setTickCount(11);              //Y分成多少格

    //将图标放入chartview
    chart->createDefaultAxes();
    chart->setAxisX(axisX,series);
    chart->setAxisY(axisY,series);
    chartview->setChart(chart);

    //将表格放入布局中
    QVBoxLayout *boxlayout=new QVBoxLayout;
    boxlayout->addWidget(chartview);
    this->setLayout(boxlayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

