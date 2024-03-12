#include "giveanalarm.h"
#include "ui_giveanalarm.h"
#include "qdebug.h"
#include "alarmvalue.h"


GiveAnAlarm::GiveAnAlarm(QWidget *parent, std::unordered_map<std::string, std::string>* info_map) :
    QWidget(parent),
    ui(new Ui::GiveAnAlarm)
{
    info = info_map;
    qDebug()<<"GiveAnAlarm";
    ui->setupUi(this);
    this->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    this->setWindowTitle("设定报警限");
    // 这里需要加一个资源的图片
    ui->widget_2->setMyTitle("风速");
    ui->widget_2->setLableIntOrDouble("int");
    ui->widget_2->setMyRange(0,40);
    ui->widget_2->setLableText();

    ui->widget_2->setMyVal(info->find("lower_wind_speed_limit")->second,info->find("upper_wind_speed_limit")->second,1);




    ui->widget_3->setMyTitle("煤粉浓度");
    ui->widget_3->setLableIntOrDouble("double");

    ui->widget_3->setMyRange(0,16);
    ui->widget_3->setLableText();

    ui->widget_2->setMyVal(info->find("lower_limit_of_pulverized_coal_concentration")->second,info->find("upper_limit_of_pulverized_coal_concentration")->second,10);

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
