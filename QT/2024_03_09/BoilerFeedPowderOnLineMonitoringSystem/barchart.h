#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QValueAxis>


QT_CHARTS_USE_NAMESPACE
class BarChart : public QWidget
{
    Q_OBJECT
public:
    explicit BarChart(QWidget *parent = nullptr);

    template <class T>
    void addData(const T&);

    void doOther();
signals:
public:
    QBarSet *qBarSet;
    QChartView *chartView;
};

#endif // BARCHART_H
