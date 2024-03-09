#include "password.h"
#include "ui_password.h"
#include <QDebug>
password::password(MyPassword *pass_,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::password)
{
    ui->setupUi(this);
     pass = pass_;
}



password::~password()
{
    delete ui;
}

void password::on_pushButton_clicked()
{
  if(ui->lineEdit_2->text().toStdString() == pass->get())
  {
      qDebug() <<"验证成功";
      emit back_true();
  }
  else
  {
      emit back_false();
  }
}

void password::on_pushButton_2_clicked()
{
     emit back_false();
}
