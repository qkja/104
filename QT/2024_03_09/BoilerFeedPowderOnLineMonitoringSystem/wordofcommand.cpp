#include "wordofcommand.h"
#include "ui_wordofcommand.h"

WordOfCommand::WordOfCommand(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordOfCommand)
{
    ui->setupUi(this);
}

WordOfCommand::~WordOfCommand()
{
    delete ui;
}
