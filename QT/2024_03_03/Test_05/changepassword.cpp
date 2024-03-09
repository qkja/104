#include "changepassword.h"
#include "ui_changepassword.h"
#include <QDebug>
#include <QString>
ChangePassword::ChangePassword(MyPassword *pass,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    _pass = pass;
}

ChangePassword::~ChangePassword()
{
    delete ui;
}


void ChangePassword::on_pushButton_clicked()
{
    while (ui->lineEdit_2->text().toStdString() != _pass->get())
    {
        ui->lineEdit_2->text().clear();
        ui->lineEdit_4->text().clear();
        qDebug()<< "失败";


    }
    if(ui->lineEdit_2->text().toStdString() == _pass->get())
    {
        _pass->set(ui->lineEdit_4->text().toStdString());
        qDebug()<< "成功";

    }
    //这里发出一个指令就可以了
    emit back();
}

void ChangePassword::on_pushButton_2_clicked()
{
    // 这里也是发出一个指令
     emit back();
}
