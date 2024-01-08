#include "Widget.h"
#include <QtWidgets/QApplication>

// 信号与槽
// 这里我们需要注意的重载,qt5有点麻烦, 不过可以使用qt4
// 槽函数的参数要和信号匹配,允许槽函数少于信号的,但是 有一定的规则
// 可以一对一,一对多,这些都是扩展的
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
