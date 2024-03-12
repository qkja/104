#ifndef DATAPROCESSING_H
#define DATAPROCESSING_H
#include "channeldatabase.h"
#include "alarmdatabase.h"

#include <QWidget>
#include "util.hpp"
class DataProcessing : public QWidget
{
    Q_OBJECT
public:
    explicit DataProcessing(QWidget *parent = nullptr);
    ~DataProcessing();
signals:
public:
    AlarmDatabase *alarm_database;     // 报警数据库:
    ChannelDatabase *channel_database; // 通道数据库:
};

#endif // DATAPROCESSING_H
