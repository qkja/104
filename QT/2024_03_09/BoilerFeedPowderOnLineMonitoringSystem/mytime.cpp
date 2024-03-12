#include "mytime.h"
#include "ui_mytime.h"
#include "qdebug.h"

MyTime::MyTime(QWidget *parent) : QWidget(parent),
                                  ui(new Ui::MyTime)
{
    qDebug() << "MyTime()";
    ui->setupUi(this);
}

MyTime::~MyTime()
{
    qDebug() << "~MyTime()";
    delete ui;
}

void MyTime::on_pushButton_clicked()
{
    emit fromMyTimeToMianScreenSignals();
}

void MyTime::on_pushButton_2_clicked()
{
    emit fromMyTimeToMianScreenSignals();
}
