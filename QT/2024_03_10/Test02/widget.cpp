#include "widget.h"
#include "ui_widget.h"
#include "barchart.h"
#include "ruler.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    BarChart *chartWidget = new BarChart(this);
    // 将 ChartWidget 添加到布局或窗口中
//    Ruler* r = new Ruler(this);
//    ui->verticalLayout->addWidget(r);
}

Widget::~Widget()
{
    delete ui;
}

