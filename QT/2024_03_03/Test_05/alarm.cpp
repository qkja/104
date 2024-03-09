#include "alarm.h"
#include "ui_alarm.h"
#include <QPushButton>
#include <QDebug>
#include <fstream>
Alarm::Alarm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Alarm)
{
    ui->setupUi(this);

    init();
}

Alarm::~Alarm()
{
    delete ui;
}
// 这里是读文件
//void Alarm::readVal(std::string path,  std::vector<Value>& v)
//{
//    std::ofstream reader(path.c_str());

//    // 这里应该有一个文件,作为我们上一次程序结束后遗留的文件

//    _val.push_back(ui->widget_1->getValse());
//    _val.push_back(ui->widget_2->getValse());
//    _val.push_back(ui->widget_3->getValse());
//}

void Alarm::on_pushButton_clicked()
{
    qDebug() << "按下了";


    // 设置初始值

    // 写文件
    emit this->back();
}

void Alarm::on_pushButton_2_clicked()
{
    qDebug() << "按下了";
    emit this->back();
}

void Alarm::init()
{
//    readVal("path", _val);
    //    设置初始值
//    ui->widget_1->setValse(_val[0]);
//    ui->widget_2->setValse(_val[1]);
//    ui->widget_3->setValse(_val[2]);
}
