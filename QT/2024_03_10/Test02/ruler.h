#ifndef RULER_H
#define RULER_H
#include <QtWidgets/QApplication>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE
#include <QWidget>

class Ruler : public QWidget
{
    Q_OBJECT
public:
    explicit Ruler(QWidget *parent = nullptr);

signals:
public:
      QChartView *chartView;

};

#endif // RULER_H
