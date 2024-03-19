//#include "widget.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}
// 包含头文件
#include <qtimer.h>
#include <QApplication>
#include <QChartView>
#include "qdebug.h"
#include <QLineSeries>
// 引用命名空间
QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QLineSeries *series = new QLineSeries();

    series->append(0,2);
    series->append(QPointF(2,6));
    series->append(3,8);
    series->append(7,9);
    series->append(11,3);

    *series << QPointF(11,2) << QPointF(15,5) << QPointF(18,4) << QPointF(19,2);
    QChart *chart = new QChart();
    // 将图例隐藏
    chart->legend()->hide();
    // 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
    chart->addSeries(series);
    // 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
    series->setUseOpenGL(true);
    // 创建默认的坐标系（笛卡尔坐标）
    chart->createDefaultAxes();
    // 设置图表标题
    chart->setTitle(QStringLiteral("Qt line chart example"));

    QChartView *view = new QChartView(chart);
    // 开启抗锯齿，让显示效果更好
    view->setRenderHint(QPainter::Antialiasing);
    view->resize(400,300);

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&series]() {
        qDebug()<<"q";
    });
    timer.start(100); // 每100毫秒更新一次数据

    // 显示图表
    view->show();

    return a.exec();
}


#include <QCoreApplication>
#include <QThread>
#include <QDebug>

// 自定义的线程类
class MyThread : public QThread {
public:
    void run() override {
        qDebug() << "Thread started";
        // 在这里编写线程的逻辑
        for(int i = 0; i < 5; ++i) {
            qDebug() << "Thread running:" << i;
            sleep(1); // 模拟一些耗时操作
        }
        qDebug() << "Thread finished";
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    qDebug() << "Main thread started";

    // 创建并启动新线程
//    MyThread thread;
//    thread.start();
//    thread.wait();

    qDebug() << "Main thread continues";

    return a.exec();
}
