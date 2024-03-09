#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H
#include "changepassword.h"
#include "alarm.h"
#include "backtotube.h"
#include <QMainWindow>
#include "password.h"
#include "setspout.h"
#include "revisiontime.h"

#include "sticktypegouachediagram.h"
#include "awindcutcirclechart.h"
#include "trendcharts.h"

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();
signals:
    void back();
private:
    Ui::MyMainWindow *ui;
    Alarm* alarm; // 这是报警界面的地址
    BackToTube* tube;// 修改背靠管的系数
    ChangePassword* myPass;// 这是修改口令的界面
    MyPassword* pass; // 这是我们的密码

    SetSpout* pout;     // 设定喷口面积
    password* pass_view; // 检测密码界面
    RevisionTime* time_set; // 设定时间


    StickTypeGouacheDiagram* s;// 第一张图
    AWindcutCircleChart* a; // 第二张图
    TrendCharts* t; // 第三张图





};

#endif // MYMAINWINDOW_H
