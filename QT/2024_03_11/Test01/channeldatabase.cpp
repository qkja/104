#include "channeldatabase.h"
#include "ui_channeldatabase.h"

ChannelDatabase::ChannelDatabase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChannelDatabase)
{
    ui->setupUi(this);
}

ChannelDatabase::~ChannelDatabase()
{
    delete ui;
}
