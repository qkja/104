#include "sticktypegouachediagram.h"
#include "ui_sticktypegouachediagram.h"

StickTypeGouacheDiagram::StickTypeGouacheDiagram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StickTypeGouacheDiagram)
{
    ui->setupUi(this);
}

StickTypeGouacheDiagram::~StickTypeGouacheDiagram()
{
    delete ui;
}
