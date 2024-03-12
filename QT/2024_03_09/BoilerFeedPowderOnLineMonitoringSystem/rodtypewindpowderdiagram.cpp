#include "rodtypewindpowderdiagram.h"
#include "ui_rodtypewindpowderdiagram.h"
#include <QDebug>
RodTypeWindPowderDiagram::RodTypeWindPowderDiagram(QWidget *parent) : QWidget(parent),
                                                                      ui(new Ui::RodTypeWindPowderDiagram)
{
    qDebug() << "RodTypeWindPowderDiagram()";
    ui->setupUi(this);
}

RodTypeWindPowderDiagram::~RodTypeWindPowderDiagram()
{
    qDebug() << "~RodTypeWindPowderDiagram()";
    delete ui;
}
