#include "giveanalarm.h"
#include "ui_giveanalarm.h"
#include "qdebug.h"
GiveAnAlarm::GiveAnAlarm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GiveAnAlarm)
{
    qDebug()<<"GiveAnAlarm";
    ui->setupUi(this);
}

GiveAnAlarm::~GiveAnAlarm()
{
    qDebug()<<"~GiveAnAlarm";
    delete ui;
}

void GiveAnAlarm::on_pushButton_determine_clicked()
{
    emit fromGiveAnAlarmToMainScreenSignals();
}

void GiveAnAlarm::on_pushButton_cancel_clicked()
{
 emit fromGiveAnAlarmToMainScreenSignals();
}
