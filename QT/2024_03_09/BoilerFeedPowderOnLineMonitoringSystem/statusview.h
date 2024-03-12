#ifndef STATUSVIEW_H
#define STATUSVIEW_H
#include "rodtypewindpowderdiagram.h"
#include "tangentialcirclediagramofprimarywind.h"
#include "trendchart.h"
#include "historicaltrendchart.h"
#include <QWidget>
#include "util.hpp"
class StatusView : public QWidget
{
    Q_OBJECT
public:
    friend class MainScreen;
    explicit StatusView(QWidget *parent = nullptr);
    ~StatusView();
signals:
private:
    RodTypeWindPowderDiagram *rod_type_wind_powder_diagram; // 棒型风粉图
    TangentialCircleDiagramOfPrimaryWind *
        tangential_circle_diagram_of_primary_wind; // 一次风切圆图
    TrendChart *trend_chart;
    HistoricalTrendChart *historical_trend_chart;
};

#endif // STATUSVIEW_H
