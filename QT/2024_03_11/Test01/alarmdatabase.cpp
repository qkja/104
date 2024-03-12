#include "alarmdatabase.h"
#include "ui_alarmdatabase.h"

AlarmDatabase::AlarmDatabase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmDatabase)
{
    ui->setupUi(this);
}

AlarmDatabase::~AlarmDatabase()
{
    delete ui;
}
