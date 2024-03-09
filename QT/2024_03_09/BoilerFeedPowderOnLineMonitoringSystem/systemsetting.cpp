#include "systemsetting.h"
#include <qdebug.h>
SystemSetting::SystemSetting(QWidget *parent):
    QWidget(parent),
    backrest_canal(new BackrestCanal(this)),
    spout(new Spout(this)),
    give_an_alarm(new GiveAnAlarm(this)),
    word_of_command(new WordOfCommand(this)),
    mytime(new MyTime(this))
{
    qDebug()<<"SystemSetting";
    give_an_alarm->setParent(nullptr);
    backrest_canal->setParent(nullptr);
    spout->setParent(nullptr);
    word_of_command->setParent(nullptr);
    mytime->setParent(nullptr);
}

SystemSetting::~SystemSetting()
{
    // 需要手动析构
    delete give_an_alarm;
    delete backrest_canal;
    delete spout;
    delete word_of_command;
    delete mytime;
    qDebug()<<"~SystemSetting";
}
