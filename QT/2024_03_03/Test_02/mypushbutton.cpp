#include "mypushbutton.h"
#include "QDebug"
#include <QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg, QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret =  pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"图片失败";
        return;
    }

    this->setFixedSize(pix.width(), pix.height());
    // 不规则图片设置
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置秃瓢

    this->setIcon(pix);

    this->setIconSize (QSize( pix.width(), pix.height()));

}

void MyPushButton::zoom1()
{
    // 创建动态对象
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    // 设置时间间隔
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(), this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(), this->height()));

    animation->setEasingCurve(QEasingCurve::OutBounce); // 设置弹跳曲线
    // 执行动画
    animation->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * animation1 =  new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
