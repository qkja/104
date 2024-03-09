#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H
#include <QTabWidget>

class MyTabWidget : public QTabWidget
{
public:
    MyTabWidget(QWidget* parent = nullptr);
    void mouseDoubleClickEvent(QMouseEvent* e);


};

#endif // MYTABWIDGET_H
