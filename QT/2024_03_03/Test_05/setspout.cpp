#include "setspout.h"
#include "ui_setspout.h"

SetSpout::SetSpout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetSpout)
{
    ui->setupUi(this);
}

SetSpout::~SetSpout()
{
    delete ui;
}

void SetSpout::on_pushButton_clicked()
{
    emit back();
}

void SetSpout::on_pushButton_2_clicked()
{
    emit back();
}

void SetSpout::on_pushButton_3_clicked()
{
    emit back();
}
