#ifndef MYQLINESERIES_H
#define MYQLINESERIES_H
#include <QChartView>
#include <QLineSeries>

#include <QWidget>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE
class MyQLineSeries : public QtCharts::QLineSeries
{
    Q_OBJECT
public:
    explicit MyQLineSeries(QWidget *parent = nullptr):QtCharts::QLineSeries(parent)
    {
        //在构造函数中进行额外的初始化操作
        // 例如设置线条样式、数据点标记等
        setPen(QPen(Qt::red, 2)); // 设置线条颜色和宽度
        setPointLabelsVisible(true); // 显示数据点标签
    }
    // 自定义函数，用于添加一组数据点
    void addDataPoints(const QVector<QPointF> &points)
    {
        for (const QPointF &point : points)
            append(point);
    }
signals:

};

#endif // MYQLINESERIES_H
