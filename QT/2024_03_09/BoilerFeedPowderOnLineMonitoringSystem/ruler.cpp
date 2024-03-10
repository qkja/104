#include "ruler.h"
#include <QVBoxLayout>
Ruler::Ruler(QWidget *parent) : QWidget(parent)
{
    QBarSeries *series = new QBarSeries();

    // 创建图表
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("尺子");

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
    chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
}
