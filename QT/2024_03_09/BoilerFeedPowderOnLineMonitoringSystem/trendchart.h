#ifndef TRENDCHART_H
#define TRENDCHART_H

#include <QWidget>
#include "util.hpp"
namespace Ui {
class TrendChart;
}

class TrendChart : public QWidget
{
    Q_OBJECT

public:
    explicit TrendChart(QWidget *parent = nullptr);
    ~TrendChart();

private:
    Ui::TrendChart *ui;
};

#endif // TRENDCHART_H
