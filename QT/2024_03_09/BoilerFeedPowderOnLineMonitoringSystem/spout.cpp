#include "spout.h"
#include "ui_spout.h"
#include "qdebug.h"
Spout::Spout(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Spout)
{
    qDebug() << "Spout()";
    ui->setupUi(this);
}

Spout::~Spout()
{
    qDebug() << "~Spout()";
    delete ui;
}

void Spout::on_pushButton_clicked()
{
    emit fromSpoutToMianScreenSignals();
}

void Spout::on_pushButton_2_clicked()
{
    emit fromSpoutToMianScreenSignals();
}

void Spout::on_pushButton_3_clicked()
{
    emit fromSpoutToMianScreenSignals();
}
