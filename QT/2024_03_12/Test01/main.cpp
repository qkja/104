#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
//#include <QApplication>
//#include <QWidget>
//#include <QSlider>
//#include <QVBoxLayout>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    // 创建一个窗口
//    QWidget window;

//    // 创建一个垂直滑块（QSlider）
//    QSlider slider(Qt::Vertical, &window);

//    // 设置滑块的范围和初始值
//    slider.setRange(0, 100);
//    slider.setValue(50);

//    // 设置刻度线的显示位置
//    slider.setTickPosition(QSlider::TicksBothSides);

//    // 设置刻度线的间隔
//    slider.setTickInterval(10);

//    // 创建一个垂直布局管理器
//    QVBoxLayout layout(&window);

//    // 在布局中添加滑块
//    layout.addWidget(&slider);

//    // 显示窗口
//    window.show();

//    return a.exec();
//}
