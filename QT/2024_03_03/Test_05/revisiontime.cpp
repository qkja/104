#include "revisiontime.h"
#include "ui_revisiontime.h"

RevisionTime::RevisionTime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RevisionTime)
{
    ui->setupUi(this);
}

RevisionTime::~RevisionTime()
{
    delete ui;
}

void RevisionTime::on_pushButton_clicked()
{
    emit back();
}

void RevisionTime::on_pushButton_2_clicked()
{
      emit back();
}
