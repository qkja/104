#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H

#include <QWidget>
#include "backrestcanal.h"
#include "spout.h"
#include "giveanalarm.h"
#include "wordofcommand.h"
#include "mytime.h"
#include "util.hpp"
class SystemSetting : public QWidget
{
    Q_OBJECT
public:
    friend class MainScreen; // 声明MainScreen是我们的友元类
    explicit SystemSetting(QWidget *parent = nullptr,std::unordered_map<std::string, std::string>* info_map = nullptr);
    ~SystemSetting();

private:
    BackrestCanal* backrest_canal; // 靠背管系数修正
    Spout* spout;                   //   设定喷口面积
    GiveAnAlarm* give_an_alarm;      //   设定报警限
    WordOfCommand* word_of_command; //   修改口令
    MyTime* mytime ;                //修定时间
    std::unordered_map<std::string, std::string>* info;
};

#endif // SYSTEMSETTING_H
