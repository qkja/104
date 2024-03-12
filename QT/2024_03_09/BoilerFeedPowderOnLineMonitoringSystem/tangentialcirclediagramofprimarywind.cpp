#include "tangentialcirclediagramofprimarywind.h"
#include "ui_tangentialcirclediagramofprimarywind.h"
#include <QDebug>
TangentialCircleDiagramOfPrimaryWind::TangentialCircleDiagramOfPrimaryWind(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TangentialCircleDiagramOfPrimaryWind)
{
    ui->setupUi(this);
    qDebug() <<"TangentialCircleDiagramOfPrimaryWind";
}

TangentialCircleDiagramOfPrimaryWind::~TangentialCircleDiagramOfPrimaryWind()
{
      qDebug() <<"~TangentialCircleDiagramOfPrimaryWind";
    delete ui;
}
