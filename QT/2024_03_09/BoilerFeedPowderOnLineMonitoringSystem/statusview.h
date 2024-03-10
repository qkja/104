#ifndef STATUSVIEW_H
#define STATUSVIEW_H
#include "rodtypewindpowderdiagram.h"
#include <QWidget>

class StatusView : public QWidget
{
    Q_OBJECT
public:
    friend class MainScreen;
    explicit StatusView(QWidget *parent = nullptr);
    ~StatusView();
signals:
private:
    RodTypeWindPowderDiagram* rod_type_wind_powder_diagram; //棒型风粉图
};

#endif // STATUSVIEW_H
