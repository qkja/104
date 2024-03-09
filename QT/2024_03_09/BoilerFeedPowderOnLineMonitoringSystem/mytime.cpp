#include "mytime.h"
#include "ui_mytime.h"

MyTime::MyTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyTime)
{
    ui->setupUi(this);
}

MyTime::~MyTime()
{
    delete ui;
}
