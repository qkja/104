#include "backtotube.h"
#include "ui_backtotube.h"

BackToTube::BackToTube(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackToTube)
{
    ui->setupUi(this);
}

BackToTube::~BackToTube()
{
    delete ui;
}
// 退出
void BackToTube::on_pushButton_2_clicked()
{
    emit back();
}
// 修改
void BackToTube::on_pushButton_clicked()
{
emit back();
}
