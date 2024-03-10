#include "wordofcommand.h"
#include "ui_wordofcommand.h"
#include "qdebug.h"
WordOfCommand::WordOfCommand(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordOfCommand)
{
    qDebug() <<"WordOfCommand()";
    ui->setupUi(this);
}

WordOfCommand::~WordOfCommand()
{
      qDebug() <<"~WordOfCommand()";
    delete ui;
}

void WordOfCommand::on_pushButton_clicked()
{
    emit fromWordOfCommandToMainScreenSignals();
}

void WordOfCommand::on_pushButton_2_clicked()
{
     emit fromWordOfCommandToMainScreenSignals();
}
