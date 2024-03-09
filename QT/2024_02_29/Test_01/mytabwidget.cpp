#include "mytabwidget.h"

#include <QDebug>
MyTabWidget::MyTabWidget(QWidget* parent)
    : QTabWidget(parent)
{ };

void MyTabWidget::mouseDoubleClickEvent(QMouseEvent *e)
{
    qDebug() << "你好";
}
