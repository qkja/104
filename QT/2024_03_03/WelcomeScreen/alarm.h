#ifndef ALARM_H
#define ALARM_H

#include <QWidget>

class Alarm : public QWidget
{
    Q_OBJECT
public:
    explicit Alarm(QWidget *parent = nullptr);
void func();
signals:
private:
double primary_wind_speed_min = 0.0; // 一次风速

double primary_pulverized_coal_concentration_min= 0.0;// 浓度
double primary_temperature_min= 0.0;// 浓度

double primary_wind_speed_max = 0.0; // 一次风速

double primary_pulverized_coal_concentration_max= 0.0;// 浓度
double primary_temperature_max= 0.0;// 浓度

};

#endif // ALARM_H
