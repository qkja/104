#include "barchart.h"
#include <QVBoxLayout>

BarChart::BarChart(QWidget *parent) : QWidget(parent)
{
       qBarSet = new QBarSet("Category 1");
       addData(0);
       doOther();
}

void BarChart::doOther()
{

    // 创建数据系列
    QBarSeries *series = new QBarSeries();
    series->append(qBarSet);
    // 创建图表
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("标题");

    // 创建坐标轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    // 创建图表视图
    chartView = new QChartView(chart);

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
}

template<class T>
void BarChart::addData(const T & val)
{
    qBarSet->append(1);
    qBarSet->append(2);
}
