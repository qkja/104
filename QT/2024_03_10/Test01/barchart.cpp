#include "barchart.h"
#include "ui_barchart.h"


BarChart::BarChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BarChart)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Category 1");
//    QBarSet *set1 = new QBarSet("Category 2");
//    QBarSet *set2 = new QBarSet("Category 3");

    *set0 << 1 << 2 << 3 << 4;
//    *set1 << 5 << 4 << 3 << 2 << 1;
//    *set2 << 1 << 3 << 0 << 2 << 4;

       // 创建数据系列
       QBarSeries *series = new QBarSeries();
       series->append(set0);
//       series->append(set1);
//       series->append(set2);

       // 创建图表
       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Simple Bar Chart");

       // 创建坐标轴
       QBarCategoryAxis *axisX = new QBarCategoryAxis();
       chart->addAxis(axisX, Qt::AlignBottom);
       series->attachAxis(axisX);

       QValueAxis *axisY = new QValueAxis();
       chart->addAxis(axisY, Qt::AlignLeft);
       series->attachAxis(axisY);

       // 创建图表视图
       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       // 将图表视图添加到UI中
     ui->verticalLayout->addWidget(chartView);  // 假设在UI文件中有一个垂直布局（verticalLayout）
}

BarChart::~BarChart()
{
    delete ui;
}
