#include "backrestcanal.h"
#include "ui_backrestcanal.h"

BackrestCanal::BackrestCanal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackrestCanal)
{
    ui->setupUi(this);
}

BackrestCanal::~BackrestCanal()
{
    delete ui;
}

void BackrestCanal::on_pushButton_clicked()
{
    emit fromBackrestCanalToMainScreenSignals();
}

void BackrestCanal::on_pushButton_2_clicked()
{
    emit fromBackrestCanalToMainScreenSignals();
}
