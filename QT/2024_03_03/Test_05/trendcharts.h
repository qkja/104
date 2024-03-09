#ifndef TRENDCHARTS_H
#define TRENDCHARTS_H

#include <QMainWindow>

namespace Ui {
class TrendCharts;
}

class TrendCharts : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrendCharts(QWidget *parent = nullptr);
    ~TrendCharts();
signals:
    void back();
private:
    Ui::TrendCharts *ui;
};

#endif // TRENDCHARTS_H
