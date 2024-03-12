#include "linechart.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QDateTime>
#include <QDateTimeAxis>
#include <QVBoxLayout>

QT_CHARTS_USE_NAMESPACE

LineChart::LineChart(QWidget *parent) : QWidget(parent)
{


    QLineSeries *series = new QLineSeries();
    series->setName("Trend Data");

    // 向系列添加数据（这里用时间戳作为X轴）
    QDateTime timestamp;
    timestamp.setDate(QDate(2022, 1, 1));

    for (int i = 0; i < 100; ++i) {
        series->append(timestamp.toMSecsSinceEpoch(), qrand() % 100);
        timestamp = timestamp.addDays(1);  // 假设数据每天增加一条
    }

    // 创建一个趋势图
    QChart *chart = new QChart();
    chart->addSeries(series);

    // 创建X轴（时间轴）
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTickCount(5);
    axisX->setFormat("MM-dd");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 创建Y轴
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Value");
    chart->addAxis(axisY, Qt::AlignRight);
    series->attachAxis(axisY);

    // 创建图表视图并显示
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    // 将QChartView设置为自定义控件的中央部件
    setLayout(new QVBoxLayout());
    layout()->addWidget(chartView);
}
