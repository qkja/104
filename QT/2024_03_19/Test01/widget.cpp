#include "widget.h"
#include "ui_widget.h"
#include "myqlineseries.h"
#include <qtimer.h>
#include <qdebug.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
//    QLineSeries *series = new QLineSeries(this);

//    series->append(0,2);
//    series->append(QPointF(2,6));
//    series->append(3,8);
//    series->append(7,9);
//    series->append(11,3);

//    *series << QPointF(11,2) << QPointF(15,5) << QPointF(18,4) << QPointF(19,2);
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

//    QTimer timer;
//    QObject::connect(&timer, &QTimer::timeout, [&series]() {
//        qDebug()<<"q";
//    });
//    timer.start(100); // 每100毫秒更新一次数据

//    // 显示图表
//    view->show();
    qDebug() <<"------------------------------------";
}

Widget::~Widget()
{
    delete ui;
}
