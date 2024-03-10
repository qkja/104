#include "statusview.h"
#include <QDebug>
StatusView::StatusView(QWidget *parent) :
    QWidget(parent)
    ,rod_type_wind_powder_diagram(new RodTypeWindPowderDiagram(this))
{
    qDebug() << "StatusView()";
    rod_type_wind_powder_diagram->setParent(nullptr);
}

StatusView::~StatusView()
{
     qDebug() << "~StatusView()";
}
