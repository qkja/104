#include "dataprocessing.h"
#include "QDebug"
DataProcessing::DataProcessing(QWidget *parent)
    : QWidget(parent)
    ,alarm_database(new AlarmDatabase(this))
    ,channel_database(new ChannelDatabase(this))

{
    alarm_database->setParent(nullptr);
    channel_database->setParent(nullptr);
    qDebug() << "DataProcessing()";
}

DataProcessing::~DataProcessing()
{
    delete  alarm_database;
    delete  channel_database;
    qDebug() << "~DataProcessing()";
}
