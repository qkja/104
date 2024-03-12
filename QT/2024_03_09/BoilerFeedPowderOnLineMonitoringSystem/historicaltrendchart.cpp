#include "historicaltrendchart.h"
#include "ui_historicaltrendchart.h"
#include <QDebug>
HistoricalTrendChart::HistoricalTrendChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoricalTrendChart)
{
    ui->setupUi(this);
    qDebug()<<"HistoricalTrendChart";
}

HistoricalTrendChart::~HistoricalTrendChart()
{
       qDebug()<<"~HistoricalTrendChart";
    delete ui;
}
