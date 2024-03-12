#include "alarmdatabase.h"
#include "ui_alarmdatabase.h"
#include "QDebug"
AlarmDatabase::AlarmDatabase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmDatabase)
{
    qDebug()<<"AlarmDatabase()";
    ui->setupUi(this);
}

AlarmDatabase::~AlarmDatabase()
{
     qDebug()<<"~AlarmDatabase()";
    delete ui;
}
