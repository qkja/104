#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsView>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建一个QMainWindow窗口
    QMainWindow window;
    window.setWindowTitle("柱状图上添加文字");

    // 创建一个场景
    QGraphicsScene scene;

    // 创建柱状图
    QGraphicsRectItem *bar = scene.addRect(10, 10, 50, 100, QPen(Qt::black), QBrush(Qt::blue));

    // 在柱状图上添加文字
    QGraphicsTextItem *textItem = scene.addText("文本", QFont("Arial", 12));
    textItem->setPos(20, 5); // 调整文本位置

    // 创建一个视图，将场景添加到视图中
    QGraphicsView *view = new QGraphicsView(&scene);

    // 设置视图为中央窗口部件
    window.setCentralWidget(view);

    window.show();
    return app.exec();
}


//#include "mainwindow.h"

//#include <QWidget>
//#include <QtWidgets/QApplication>
//#include <QtCharts/QChartView>
//#include <QtCharts/QBarSeries>
//#include <QtCharts/QBarSet>
//#include <QtCharts/QBarCategoryAxis>
//#include <QApplication>
//#include <QValueAxis>
//#include <vector>
//QT_CHARTS_USE_NAMESPACE
//#include <QApplication>



//#include <QtWidgets/QApplication>
//#include <QtCharts/QChartView>
//#include <QtCharts/QBarSeries>
//#include <QtCharts/QBarSet>
//#include <QtCharts/QBarCategoryAxis>

//QT_CHARTS_USE_NAMESPACE

//int main(int argc, char *argv[]) {
////    QApplication a(argc, argv);

////    // 创建数据集
////    QBarSet *set0 = new QBarSet("Category 1");
//////    QBarSet *set1 = new QBarSet("Category 2");
//////    QBarSet *set2 = new QBarSet("Category 3");

////    *set0 << 1 << 2 << 3 << 4 << 5;
//////    *set1 << 5 << 4 << 3 << 2 << 1;
//////    *set2 << 1 << 3 << 0 << 2 << 4;

////    // 创建数据系列
////    QBarSeries *series = new QBarSeries();
////    series->append(set0);
//////    series->append(set1);
//////    series->append(set2);

////    // 创建图表
////    QChart *chart = new QChart();
////    chart->addSeries(series);
////    chart->setTitle("Simple Bar Chart");

////    // 创建坐标轴
////    QBarCategoryAxis *axisX = new QBarCategoryAxis();
////    chart->addAxis(axisX, Qt::AlignBottom);
////    series->attachAxis(axisX);

//////    QValueAxis *axisY = new QValueAxis();
//////    chart->addAxis(axisY, Qt::AlignLeft);
//////    series->attachAxis(axisY);

////    // 创建图表视图
////    QChartView *chartView = new QChartView(chart);
////    chartView->setRenderHint(QPainter::Antialiasing);

////    // 显示窗口
////    QMainWindow window;
////    window.setCentralWidget(chartView);
////    window.resize(400, 300);
////    window.show();

////    return a.exec();

//    QApplication app(argc, argv);

//      // 创建一个QWidget窗口
//      QWidget window;
//      window.setWindowTitle("柱状图上添加文字");

//      // 创建一个场景
//      QGraphicsScene scene;

//      // 创建柱状图
//      QGraphicsRectItem *bar = scene.addRect(10, 10, 50, 100, QPen(Qt::black), QBrush(Qt::blue));

//      // 在柱状图上添加文字
//      QGraphicsTextItem *textItem = scene.addText("文本", QFont("Arial", 12));
//      textItem->setPos(20, 5); // 调整文本位置

//      // 创建一个视图，将场景添加到视图中
//      QGraphicsView view(&scene);
//      view.setScene(&scene);

//      // 将视图设置为主窗口的中央窗口部件
//      window.setCentralWidget(&view);

//      window.show();
//      return app.exec();
//}


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//       // 创建数据集
//       QBarSet *set0 = new QBarSet("Category 1");
//       QBarSet *set1 = new QBarSet("Category 2");
//       QBarSet *set2 = new QBarSet("Category 3");

//       *set0 << 1 << 2 << 3 << 4 << 5;
//       *set1 << 5 << 4 << 3 << 2 << 1;
//       *set2 << 1 << 3 << 0 << 2 << 4;

//       // 创建数据系列
//       QBarSeries *series = new QBarSeries();
//       series->append(set0);
//       series->append(set1);
//       series->append(set2);

//       // 创建图表
//       QChart *chart = new QChart();
//       chart->addSeries(series);
//       chart->setTitle("Simple Bar Chart");

//       // 创建坐标轴
//       QBarCategoryAxis *axisX = new QBarCategoryAxis();
//       chart->addAxis(axisX, Qt::AlignBottom);
//       series->attachAxis(axisX);

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
//}
