#include "channeldatabase.h"
#include "ui_channeldatabase.h"
#include "QDebug"
ChannelDatabase::ChannelDatabase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelDatabase)
{
    qDebug()<<"ChannelDatabase";
    ui->setupUi(this);
}

ChannelDatabase::~ChannelDatabase()
{
    qDebug()<<"~ChannelDatabase";
    delete ui;
}
