#include "alarmvalue.h"
#include "ui_alarmvalue.h"
#include <iostream>
#include <QDebug>
AlarmValue::AlarmValue(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmValue)
{
    ui->setupUi(this);

    connect( ui->verticalSlider, &QSlider::valueChanged, [=](int value) {

        if(ui->label->text().toStdString() == "double"
                || ui->label->text().toStdString().find('.') != std::string::npos)
        {
//            qDebug()<<"=========================";
            std::string val = std::to_string(value/10.0);
            val = val.substr(val.find('.'));
            ui->label->setText( val.c_str());
        }
        else
        {
             qDebug()<<"111111";
            ui->label->setText( std::to_string(value).c_str());
        }
    });

    connect( ui->verticalSlider_2, &QSlider::valueChanged, [=](int value) {
        if(ui->label_6->text().toStdString() == "double"
                || ui->label_6->text().toStdString().find('.') != std::string::npos)
        {
            std::string val = std::to_string(value/10.0);
            val = val.substr(val.find('.'));
            ui->label_6->setText(val.c_str());
        }
        else
        {
            ui->label_6->setText( std::to_string(value).c_str());
        }

    });

}




void AlarmValue::setMyRange(const int minVal, const int maxVal)
{

    ui->verticalSlider->setRange(minVal, maxVal);
    ui->verticalSlider_2->setRange(minVal, maxVal);
}

void AlarmValue::setMyVal(const std::string &minVal, const std::string &maxVal,int multiple)
{
    if(minVal.find('.') != std::string::npos
            && maxVal.find('.') != std::string::npos)
    {
        qDebug() << minVal.c_str();
        qDebug() << maxVal.c_str();
//        ui->verticalSlider->setValue((int)(QString(maxVal.c_str()).toDouble()*multiple));
//        ui->verticalSlider_2->setValue((int)(QString(minVal.c_str()).toDouble()*multiple));

        ui->verticalSlider->setValue(8);
        ui->verticalSlider_2->setValue(3);
    }
    else
    {
        ui->verticalSlider->setValue(std::stoi(maxVal)*multiple);
        ui->verticalSlider_2->setValue(std::stoi(minVal)*multiple);
    }

}

// 设置值
void AlarmValue::setLableText()
{
    int maxVal = ui->verticalSlider->maximum();
    int minVal = ui->verticalSlider->minimum();

    if(ui->label_6->text().toStdString() == "double"
            || ui->label_6->text().toStdString().find('.') != std::string::npos)
    {
//        qDebug()<<"-----------------------";
        ui->label_2->setText(QString::number(maxVal/10.0,'d',1));
        ui->label_4->setText(QString::number(maxVal/10.0,'d',1));
        ui->label_3->setText(QString::number(minVal/10.0,'d',1));
        ui->label_5->setText(QString::number(minVal/10.0,'d',1));
    }
    else
    {
        ui->label_2->setText(std::to_string(maxVal).c_str());
        ui->label_4->setText(std::to_string(maxVal).c_str());
        ui->label_3->setText(std::to_string(minVal).c_str());
        ui->label_5->setText(std::to_string(minVal).c_str());
    }

}

void AlarmValue::setLableIntOrDouble(const std::string val)
{
    ui->label->setText(val.c_str());
    ui->label_6->setText(val.c_str());
}


AlarmValue::~AlarmValue()
{
    delete ui;
}

void AlarmValue::setMyTitle(const std::string &text)
{
    ui->groupBox->setTitle(text.c_str());
}
