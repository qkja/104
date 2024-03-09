#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit QPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImg, QString pressImg="");
    void zoom1();
    void zoom2();
signals:
private:
    QString normalImgPath;
    QString pressImgPath;

};

#endif // MYPUSHBUTTON_H
