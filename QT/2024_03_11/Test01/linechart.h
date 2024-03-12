#ifndef LINECHART_H
#define LINECHART_H
#include <QtCharts/QChartView>
#include <QWidget>

class LineChart : public QWidget
{
    Q_OBJECT
public:
    explicit LineChart(QWidget *parent = nullptr);

signals:
public:
    QtCharts::QChartView *chartView;
};

#endif // LINECHART_H
