#include "trendchart.h"
#include "ui_trendchart.h"

TrendChart::TrendChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrendChart)
{
    ui->setupUi(this);
}

TrendChart::~TrendChart()
{
    delete ui;
}
