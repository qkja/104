#include "widget.h"
#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();
//    return a.exec();
//}


#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDebug>
#include <QPushButton>
using namespace std;
class QMyLabel:public QLabel{
    Q_OBJECT
public slots:
    void rsetText(QTableWidgetItem * item);
};

void QMyLabel::rsetText(QTableWidgetItem * item){
    this->setText(item->text());
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建一个窗口，作为输入框和列表框的父窗口
    QWidget widget;
    //设置窗口的标题
    widget.setWindowTitle("QTableWidget控件");
    //自定义窗口的大小
    widget.resize(900,500);
    //在 widget 窗口中添加一个 4 行 3 列的表格
    QTableWidget TableWidget(4,3,&widget);
    //自定义表格的尺寸和字体大小
    TableWidget.resize(900,350);
    TableWidget.setFont(QFont("宋体",20));
    //设置表格中每一行的表头
    TableWidget.setHorizontalHeaderLabels(QStringList() << "教程" << "网址" << "状态");
    //设置表格数据区内的所有单元格都不允许编辑
    TableWidget.setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置表格中每一行的内容
    TableWidget.setItem(0,0,new QTableWidgetItem("C语言"));
    TableWidget.setItem(0,1,new QTableWidgetItem("http://c.tian.net/c/"));
    TableWidget.setItem(0,2,new QTableWidgetItem("已更新"));
    TableWidget.setItem(1,0,new QTableWidgetItem("Qt教程"));
    TableWidget.setItem(1,1,new QTableWidgetItem("http://c..net/qt/"));
    TableWidget.setItem(1,2,new QTableWidgetItem("更新"));
    TableWidget.setItem(2,0,new QTableWidgetItem("C教程"));
    TableWidget.setItem(2,1,new QTableWidgetItem("http://c.tian.net/cplus/"));
    TableWidget.setItem(2,2,new QTableWidgetItem("已更新完毕"));
    //向 widget 窗口中添加一个文本框
    QMyLabel lab;
    lab.setText("选中单元格");
    lab.setParent(&widget);
    //自定义文本框的尺寸和位置
    lab.resize(900,150);
    lab.move(0,350);
    lab.setAlignment(Qt::AlignCenter);
    lab.setFont(QFont("宋体",16));
    widget.show();
    //为表格和文本框之间建立关联，当用户点击表格中某个单元格时，
    //文本框显示单元格内的文本内容。
    QObject::connect(&TableWidget,&QTableWidget::itemClicked,&lab,&QMyLabel::rsetText);
    return a.exec();
}





//0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

//原文链接：https://blog.csdn.net/ccc369639963/article/details/122683773
//#include <QApplication>
//#include <QtCharts/QChartView>
//#include <QtCharts/QLineSeries>
//#include <QtCharts/QDateTimeAxis>
//#include <QtCharts/QValueAxis>
//#include <QDateTime>
//#include <QDate>
//QT_CHARTS_USE_NAMESPACE

//int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);

//    // 创建一个趋势图系列
//    QLineSeries *series = new QLineSeries();
//    series->setName("Trend Data");

//    // 向系列添加数据（这里用时间戳作为X轴）
//    QDateTime timestamp;
//    timestamp.setDate(QDate(2022, 1, 1));

//    for (int i = 0; i < 100; ++i) {
//        series->append(timestamp.toMSecsSinceEpoch(), qrand() % 100);
//        timestamp = timestamp.addDays(1);  // 假设数据每天增加一条
//    }

//    // 创建一个趋势图
//    QChart *chart = new QChart();
//    chart->addSeries(series);

//    // 创建X轴（时间轴）
//    QDateTimeAxis *axisX = new QDateTimeAxis;
//    axisX->setTickCount(5);
//    axisX->setFormat("MM-dd");
//    axisX->setTitleText("Date");
//    chart->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

//    // 创建Y轴
//    QValueAxis *axisY = new QValueAxis;
//    axisY->setLabelFormat("%i");
//    axisY->setTitleText("Value");
//    chart->addAxis(axisY, Qt::AlignRight);
//    series->attachAxis(axisY);

//    // 创建图表视图并显示
//    QChartView chartView(chart);
//    chartView.setRenderHint(QPainter::Antialiasing);
//    chartView.show();

//    return a.exec();
//}

//class MyWidget : public QWidget {
//public:
//    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {}

//protected:
//    void paintEvent(QPaintEvent *event) override {
//        Q_UNUSED(event);

//        QPainter painter(this);

//        // 设置画笔颜色和宽度
//        painter.setPen(QPen(Qt::black, 2));

//        // 绘制正方形的两个对角线
//        int side = 100;  // 正方形的边长
//        int x = (width() - side) / 2;
//        int y = (height() - side) / 2;
//painter.drawRect(x, y, side, side);
//        // 左上到右下的对角线
//        painter.drawLine(x, y, x + side/3, y + side/3);

//        // 右上到左下的对角线
//        //painter.drawLine(x + side, y, x, y + side/2);
//    }
//};

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    MyWidget widget;
//    widget.setGeometry(100, 100, 300, 300);
//    widget.show();

//    return app.exec();
//}

//class MyWidget : public QWidget {
//public:
//    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {}

//protected:
//    void paintEvent(QPaintEvent *event) override {
//        Q_UNUSED(event);

//        QPainter painter(this);

//        // 设置画笔颜色和宽度
//        painter.setPen(QPen(Qt::black, 2));

//        // 绘制正方形
//        int side = 100;  // 正方形的边长
//        int x = (width() - side) / 2;
//        int y = (height() - side) / 2;
//        painter.drawRect(x, y, side, side);

//        // 在正方形的对角线上绘制柱状图（立方体）
//        int barWidth = 1;
//        int barHeight = 3;

//        // 左上到右下的对角线
//        painter.drawRect(x, y, barWidth, barHeight);

//        // 右上到左下的对角线
//        painter.drawRect(x + side - barWidth, y + barHeight, barWidth, barHeight);

//        // 左下到右上的对角线
//        painter.drawRect(x, y + side - 2 * barHeight, barWidth, barHeight);

//        // 右下到左上的对角线
//        painter.drawRect(x + side - barWidth, y + side - barHeight, barWidth, barHeight);
//    }
//};

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    MyWidget widget;
//    widget.setGeometry(100, 100, 300, 300);
//    widget.show();

//    return app.exec();
//}




////////#include <QApplication>
////////#include <QWidget>
////////#include <QPainter>

////////class MyWidget : public QWidget {
////////public:
////////    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {}

////////protected:
////////    void paintEvent(QPaintEvent *event) override {
////////        Q_UNUSED(event);

////////        QPainter painter(this);

////////        // 设置画笔颜色和宽度
////////        painter.setPen(QPen(Qt::black, 15));

////////        // 绘制正方形
////////        int side = 1000;  // 正方形的边长
////////        int x = (width() - side) / 2;
////////        int y = (height() - side) / 2;
////////        painter.drawRect(x, y, side, side);
////////    }
////////};

////////int main(int argc, char *argv[]) {
////////    QApplication app(argc, argv);

////////    MyWidget widget;
////////    widget.setGeometry(100, 100, 300, 300);
////////    widget.show();

////////    return app.exec();
////////}
//////#include <QApplication>
//////#include <QWidget>
//////#include <QPainter>

//////class MyWidget : public QWidget {
//////public:
//////    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {}

//////protected:
//////    void paintEvent(QPaintEvent *event) override {
//////        Q_UNUSED(event);

//////        QPainter painter(this);

//////        // 设置画笔颜色和宽度
//////        painter.setPen(QPen(Qt::black, 2));

//////        // 绘制正方形
//////        int side = 100;  // 正方形的边长
//////        int x = (width() - side) / 2;
//////        int y = (height() - side) / 2;
//////        painter.drawRect(x, y, side, side);

//////        // 在每个角绘制一个条形图
//////        int barWidth = 20;
//////        int barHeight = 30;
//////        // 左上到右下的对角线
//////              painter.drawRect(x, y, barWidth, barHeight);

//////              // 右上到左下的对角线
//////              painter.drawRect(x + side - barWidth, y, barWidth, barHeight);

//////              // 左下到右上的对角线
//////              painter.drawRect(x, y + side - barHeight, barWidth, barHeight);

//////              // 右下到左上的对角线
//////              painter.drawRect(x + side - barWidth, y + side - barHeight, barWidth, barHeight);
////////        // 左上角
////////        painter.drawRect(x, y, barWidth, barHeight);

////////        // 右上角
////////        painter.drawRect(x + side - barWidth, y, barWidth, barHeight);

////////        // 左下角
////////        painter.drawRect(x, y + side - barHeight, barWidth, barHeight);

////////        // 右下角
////////        painter.drawRect(x + side - barWidth, y + side - barHeight, barWidth, barHeight);
//////    }
//////};

//////int main(int argc, char *argv[]) {
//////    QApplication app(argc, argv);

//////    MyWidget widget;
//////    widget.setGeometry(100, 100, 300, 300);
//////    widget.show();

//////    return app.exec();
//////}
////#include <QApplication>
////#include <QWidget>
////#include <QPainter>

////class MyWidget : public QWidget {
////public:
////    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {}

////protected:
////    void paintEvent(QPaintEvent *event) override {
////        Q_UNUSED(event);

////        QPainter painter(this);

////        // 设置画笔颜色和宽度
////        painter.setPen(QPen(Qt::black, 2));

////        // 绘制正方形
////        int side = 100;  // 正方形的边长
////        int x = (width() - side) / 2;
////        int y = (height() - side) / 2;
////        painter.drawRect(x, y, side, side);

////        // 在正方形的对角线上绘制条形图
////        int barWidth = 20;
////        int barHeight = 30;

////        // 左上到右下的对角线
////        painter.drawRect(x, y, barWidth, barHeight);

////        // 右上到左下的对角线
////        painter.drawRect(x + side - barWidth, y, barWidth, barHeight);

////        // 左下到右上的对角线
////        painter.drawRect(x, y + side - barHeight, barWidth, barHeight);

////        // 右下到左上的对角线
////        painter.drawRect(x + side - barWidth, y + side - barHeight, barWidth, barHeight);
////    }
////};

////int main(int argc, char *argv[]) {
////    QApplication app(argc, argv);

////    MyWidget widget;
////    widget.setGeometry(100, 100, 300, 300);
////    widget.show();

////    return app.exec();
////}
//#include <QApplication>
//#include <QWidget>
//#include <QPainter>

//class MyWidget : public QWidget {
//public:
//    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {}

//protected:
//    void paintEvent(QPaintEvent *event) override {
//        Q_UNUSED(event);

//        QPainter painter(this);

//        // 设置画笔颜色和宽度
//        painter.setPen(QPen(Qt::black, 2));

//        // 绘制正方形
//        int side = 100;  // 正方形的边长
//        int x = (width() - side) / 2;
//        int y = (height() - side) / 2;
//        painter.drawRect(x, y, side, side);

//        // 在正方形的对角线上绘制柱状图（立方体）
//        int barWidth = 20;
//        int barHeight = 30;

//        // 左上到右下的对角线
//        painter.drawRect(x, y, barWidth, barHeight);

//        // 右上到左下的对角线
//        painter.drawRect(x + side - barWidth, y, barWidth, barHeight);

//        // 左下到右上的对角线
//        painter.drawRect(x, y + side - barHeight, barWidth, barHeight);

//        // 右下到左上的对角线
//        painter.drawRect(x + side - barWidth, y + side - barHeight, barWidth, barHeight);
//    }
//};

//int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);

//    MyWidget widget;
//    widget.setGeometry(100, 100, 300, 300);
//    widget.show();

//    return app.exec();
//}
