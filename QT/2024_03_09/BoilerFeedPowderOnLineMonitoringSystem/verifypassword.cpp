#include "verifypassword.h"
#include "ui_verifypassword.h"
#include "qdebug.h"
VerifyPassword::VerifyPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerifyPassword)
{
    qDebug() <<"VerifyPassword()";
    ui->setupUi(this);
}

VerifyPassword::~VerifyPassword()
{
    qDebug() <<"~VerifyPassword()";
    delete ui;
}

bool VerifyPassword::is_true(const std::string &str)
{
    return password == str;
}

void VerifyPassword::set(const std::string &str)
{
    password = str;
}

std::string VerifyPassword::get()
{
    return  password;
}

void VerifyPassword::on_pushButton_clicked()
{
    emit fromVerifyPasswordSignalsIsTrue();
}

void VerifyPassword::on_pushButton_2_clicked()
{
    emit fromVerifyPasswordSignalsIsFalse();
}
