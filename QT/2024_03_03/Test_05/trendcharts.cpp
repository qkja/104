#include "trendcharts.h"
#include "ui_trendcharts.h"

TrendCharts::TrendCharts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrendCharts)
{
    ui->setupUi(this);
}

TrendCharts::~TrendCharts()
{
    delete ui;
}
