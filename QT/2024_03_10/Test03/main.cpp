#include "widget.h"
#include <QLineSeries>
#include <QApplication>
#include <QMainWindow>
//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}



///////////////////////////////////////////////////////////
#include <QtWidgets/QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    // 创建数据集
//    QBarSet *set = new QBarSet("Category");
//    *set << 1 << 2 << 3 << 4 << 5;

//    // 创建数据系列
//    QBarSeries *series = new QBarSeries();
////    series->append(set);

//    // 创建图表
//    QChart *chart = new QChart();
//    chart->addSeries(series);
//    chart->setTitle("Bar Chart");

//    // 创建X轴
////    QValueAxis *axisX = new QValueAxis();
////    chart->addAxis(axisX, Qt::AlignBottom);
////    series->attachAxis(axisX);
//    QValueAxis *axisY = new QValueAxis();
//       chart->addAxis(axisY, Qt::AlignLeft);
//       series->attachAxis(axisY);
//    // 创建图表视图
//    QChartView *chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);

//    // 显示窗口
//    QMainWindow window;
//    window.setCentralWidget(chartView);
//    window.resize(400, 300);
//    window.show();

//    return a.exec();

    // 创建数据系列
//       QLineSeries *series = new QLineSeries();
//       series->append(0, 100);
//       series->append(1, 3);
////       series->append(2, 2);
////       series->append(3, 4);
////       series->append(4, 5);

//       // 创建图表
//       QChart *chart = new QChart();
//       chart->addSeries(series);
//       chart->setTitle("Line Chart");

//       // 创建Y轴
//       QValueAxis *axisY = new QValueAxis();
//       chart->addAxis(axisY, Qt::AlignLeft);
//       series->attachAxis(axisY);

//       // 创建图表视图
//       QChartView *chartView = new QChartView(chart);
//       chartView->setRenderHint(QPainter::Antialiasing);

//       // 显示窗口
//       QMainWindow window;
//       window.setCentralWidget(chartView);
//       window.resize(400, 300);
//       window.show();

//       return a.exec();


    // 创建数据集
//       QBarSet *set = new QBarSet("Category");
////       *set << 1 << 2 << 3 << 4 << 5;

       // 创建数据系列
       QBarSeries *series = new QBarSeries();
//       series->append(set);

       // 创建图表
       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Bar Chart");

       // 创建Y轴（竖直尺子）
       QValueAxis *axisY = new QValueAxis();
       axisY->setRange(0, 60);  // 设置刻度尺的范围
       axisY->setTickCount(6); // 设置刻度尺的数量
       axisY->setTickInterval(1); // 设置刻度尺的间隔
       axisY->setLabelsVisible(true); // 设置刻度尺的标签可见

       chart->addAxis(axisY, Qt::AlignLeft);
       series->attachAxis(axisY);

       QPen pen = axisY->gridLinePen();
        pen.setWidth(20);  // 设置线条宽度
       axisY->setGridLinePen(pen);

          chart->addAxis(axisY, Qt::AlignLeft);
          series->attachAxis(axisY);

       // 创建图表视图
       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       // 显示窗口
       QMainWindow window;
       window.setCentralWidget(chartView);
       window.resize(400, 300);
       window.show();

       return a.exec();
}

