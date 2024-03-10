#ifndef BARCHART_H
#define BARCHART_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QApplication>
#include <QValueAxis>
#include <vector>
QT_CHARTS_USE_NAMESPACE


namespace Ui {
class BarChart;
}

class BarChart : public QWidget
{
    Q_OBJECT

public:
    explicit BarChart(QWidget *parent = nullptr);
    ~BarChart();

private:
    Ui::BarChart *ui;
//    std::vector<>
};

#endif // BARCHART_H
