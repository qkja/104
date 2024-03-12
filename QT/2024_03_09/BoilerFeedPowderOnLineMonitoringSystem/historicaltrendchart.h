#ifndef HISTORICALTRENDCHART_H
#define HISTORICALTRENDCHART_H

#include <QWidget>
#include "util.hpp"
namespace Ui
{
    class HistoricalTrendChart;
}

class HistoricalTrendChart : public QWidget
{
    Q_OBJECT

public:
    explicit HistoricalTrendChart(QWidget *parent = nullptr);
    ~HistoricalTrendChart();

private:
    Ui::HistoricalTrendChart *ui;
};

#endif // HISTORICALTRENDCHART_H
