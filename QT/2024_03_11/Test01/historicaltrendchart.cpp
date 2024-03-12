#include "historicaltrendchart.h"
#include "ui_historicaltrendchart.h"

HistoricalTrendChart::HistoricalTrendChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoricalTrendChart)
{
    ui->setupUi(this);
}

HistoricalTrendChart::~HistoricalTrendChart()
{
    delete ui;
}
