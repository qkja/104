#include "spout.h"
#include "ui_spout.h"

Spout::Spout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Spout)
{
    ui->setupUi(this);
}

Spout::~Spout()
{
    delete ui;
}
