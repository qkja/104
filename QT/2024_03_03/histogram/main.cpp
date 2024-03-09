#include "mainwindow.h"

#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();
//}

#include <QApplication>
#include <QtCharts>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // 创建一个柱状图系列
    QBarSeries *barSeries = new QBarSeries();

    // 直接向系列中添加值，不使用QBarSet
    barSeries->append(new QBarSet("Category 1", barSeries));
    barSeries->setSet(0, new QBarSet("Bar 1", barSeries));
    barSeries->setSet(1, new QBarSet("Bar 2", barSeries));
    barSeries->setSet(2, new QBarSet("Bar 3", barSeries));

    // 向每个数据集中添加值
    barSeries->setSet(0)->append(1);
    barSeries->setSet(0)->append(2);
    barSeries->setSet(0)->append(3);

    barSeries->setSet(1)->append(4);
    barSeries->setSet(1)->append(5);
    barSeries->setSet(1)->append(6);

    barSeries->setSet(2)->append(7);
    barSeries->setSet(2)->append(8);
    barSeries->setSet(2)->append(9);

    // 创建一个图表视图
    QChartView *chartView = new QChartView();
    QChart *chart = new QChart();

    // 将柱状图系列添加到图表中
    chart->addSeries(barSeries);

    // 设置图表标题
    chart->setTitle("Bar Chart Example");

    // 将图表设置为视图的图表
    chartView->setChart(chart);

    // 显示图表视图
    chartView->show();

    return a.exec();
}

