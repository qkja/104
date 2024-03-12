#include "statusview.h"
#include <QDebug>
StatusView::StatusView(QWidget *parent) :
    QWidget(parent)
  ,rod_type_wind_powder_diagram(new RodTypeWindPowderDiagram(this))
  ,tangential_circle_diagram_of_primary_wind(new TangentialCircleDiagramOfPrimaryWind(this))
  ,trend_chart(new TrendChart(this))
  ,historical_trend_chart(new HistoricalTrendChart(this))
{
    qDebug() << "StatusView()";
    rod_type_wind_powder_diagram->setParent(nullptr);
    tangential_circle_diagram_of_primary_wind->setParent(nullptr);
    trend_chart->setParent(nullptr);
    historical_trend_chart->setParent(nullptr);
}

StatusView::~StatusView()
{
    // 需要手动析构
    delete  rod_type_wind_powder_diagram;
    delete  tangential_circle_diagram_of_primary_wind;
    delete  trend_chart;
    delete  historical_trend_chart;
    qDebug() << "~StatusView()";
}
