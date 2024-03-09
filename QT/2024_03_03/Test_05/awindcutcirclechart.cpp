#include "awindcutcirclechart.h"
#include "ui_awindcutcirclechart.h"

AWindcutCircleChart::AWindcutCircleChart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AWindcutCircleChart)
{
    ui->setupUi(this);
}

AWindcutCircleChart::~AWindcutCircleChart()
{
    delete ui;
}
