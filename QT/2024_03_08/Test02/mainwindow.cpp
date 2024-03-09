#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLineSeries *lineSeries = new QLineSeries();        //创建折线系列


    QChartView *chartView = new QChartView(this);


    /*为系列里添加100个数据*/

    for(quint8 i=0; i<100; i++)

    {

        lineSeries->append(i,qrand()%300);

    }


    lineSeries->setName("系列一");                  //设置系列名称


    mChart = new QChart();                          //创建图标对象


    mChart->addSeries(lineSeries);                  //向图表中添加系列


    mChart->createDefaultAxes();                       //创建默认的坐标，必须在addSeries之后调用

    mChart->setTheme(QChart::ChartThemeDark);           //设置图标主题


    mChart->setTitle("图标实例");                       //设置图标名称


    mChart->legend()->hide();                          //隐藏图例，也就是不显示系列名称了


    chartView->setChart(mChart);                    //向chartView中添加图标


    chartView->resize(QSize(500,300));              //重新设置chartView的大小


    chartView->setRenderHints(QPainter::Antialiasing);//消除边缘，看起来平滑一些

//    ui->horizontalLayout->addWidget(chartView);     //把chartView放到水平布局中（在ui中拖一个水平布局）

}

MainWindow::~MainWindow()
{
    delete ui;
}

