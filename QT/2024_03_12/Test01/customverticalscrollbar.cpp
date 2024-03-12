#include "customverticalscrollbar.h"

CustomVerticalScrollBar::CustomVerticalScrollBar(QWidget *parent)
    : QSlider(Qt::Vertical, parent)
{
    // 设置滑块的范围和初始值
    setRange(0, 99);
    setValue(50);

    // 设置刻度线的显示位置
    setTickPosition(QSlider::TicksBothSides);

    // 设置刻度线的间隔
    setTickInterval(10);
}


void CustomVerticalScrollBar::paintEvent(QPaintEvent *event)
{
    QSlider::paintEvent(event);

    // 在这里添加你的自定义绘制代码，例如绘制刻度线
    QPainter painter(this);
    drawCustomTicks(&painter);
}

void CustomVerticalScrollBar::drawCustomTicks(QPainter *painter)
{
    // 在这里添加刻度线的绘制逻辑
    // 可以使用 painter->drawLine() 绘制线条
    // 可以使用 painter->drawText() 绘制刻度值
}
