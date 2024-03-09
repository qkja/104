#include "mainsence.h"
#include "ui_mainsence.h"

MainSence::MainSence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSence)
{
    ui->setupUi(this);

    // 固定界面大小
    this->setFixedSize(1000,800);
}

MainSence::~MainSence()
{
    delete ui;
}

