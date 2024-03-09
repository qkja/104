#ifndef MYTIME_H
#define MYTIME_H

#include <QWidget>

namespace Ui {
class MyTime;
}

class MyTime : public QWidget
{
    Q_OBJECT

public:
    explicit MyTime(QWidget *parent = nullptr);
    ~MyTime();

private:
    Ui::MyTime *ui;
};

#endif // MYTIME_H
