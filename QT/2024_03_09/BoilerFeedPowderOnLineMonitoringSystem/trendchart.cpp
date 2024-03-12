#include "trendchart.h"
#include "ui_trendchart.h"
#include <QDebug>
TrendChart::TrendChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrendChart)
{
    ui->setupUi(this);
    qDebug()<<"TrendChart";
}

TrendChart::~TrendChart()
{
        qDebug()<<"~TrendChart";
    delete ui;
}
