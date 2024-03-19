#include "mainwindow.h"
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QApplication>
#include "BlockqQueue.hpp"
#include "controller.h"
#include "producerthread.h"
#include "workerthread.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    BlockqQueue<int> bq;

//    // 创建控制器对象
//    Controller controller;
//    ProducerThread producer(&bq);
//    // 创建工作线程
//    WorkerThread workerThread(&bq);
//    // 连接信号和槽
//    QObject::connect(&workerThread, &WorkerThread::workFinished,
//                     &controller, &Controller::handleResult);

//    // 线程启动了
//    producer.start();
//    workerThread.start();
//    QLineSeries *series = new QLineSeries();
//    series->append(0,2);
//    //    series->append(QPointF(2,6));
//    //    series->append(3,8);
//    //    series->append(7,9);
//    //    series->append(11,3);
//    //    *series << QPointF(11,2) << QPointF(15,5) << QPointF(18,4) << QPointF(19,2);
//    QChart *chart = new QChart();
//    // 将图例隐藏
//    chart->legend()->hide();
//    // 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
//    chart->addSeries(series);
//    // 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
//    series->setUseOpenGL(true);
//    // 创建默认的坐标系（笛卡尔坐标）
//    chart->createDefaultAxes();
//    // 设置图表标题
//    chart->setTitle(QStringLiteral("Qt line chart example"));

//    QChartView *view = new QChartView(chart);
//    // 开启抗锯齿，让显示效果更好
//    view->setRenderHint(QPainter::Antialiasing);
//    view->resize(400,300);

//        QObject::connect(&controller, &Controller::mySignals, [&series,&view](std::pair<int,int>& p)
//        {
//            std::string str;
//            str += std::to_string(p.first);
//            str += " : ";
//            str += std::to_string(p.second);
//             str += "更新";
//            qDebug()<< str.c_str();

//            series->append(QPointF(p.first/10.0,p.second/10.0));
//            view->update();
//        });


    //    QTimer timer;
    //    QObject::connect(&timer, &QTimer::timeout,[&series,&view]() {
    //        static int x = 0;
    //        int y = x + x ;
    //        series->append(x,y);
    //        x += 0.1;
    //        // 强制刷新图表视图
    //        view->repaint(); // 或者 chartView->update();
    //    });
    //    timer.start(100); // 每100毫秒更新一次数据

    // 显示图表
//    view->show();
    qDebug() << "Main thread continues";
    return a.exec();
}



