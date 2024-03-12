#ifndef CUSTOMVERTICALSCROLLBAR_H
#define CUSTOMVERTICALSCROLLBAR_H

#include <QSlider>
#include <QPaintEvent>
#include <QPainter>

class CustomVerticalScrollBar : public QSlider
{
    Q_OBJECT
public:
    CustomVerticalScrollBar(QWidget *parent = nullptr);
protected:
    // 重新实现绘制事件，以添加额外的绘制内容
    void paintEvent(QPaintEvent *event) override;

    // 自定义绘制刻度线的方法
    void drawCustomTicks(QPainter *painter);
};



#endif // CUSTOMVERTICALSCROLLBAR_H
