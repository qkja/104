#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include "util.hpp"
#include "mainscreen.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
class WelcomeScreen;
}
QT_END_NAMESPACE

class WelcomeScreen : public QWidget
{
    Q_OBJECT

public:
    WelcomeScreen(QWidget *parent = nullptr);
    ~WelcomeScreen();
private slots:  // 槽函数
    // 处理双击事件
    void onButtonDoubleClicked();
    // 切换页面
    void fromWelToMianScreen();
    // 重置点击计数
    void resetClickCount();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Ui::WelcomeScreen *ui;
    MainScreen *main_screen; // 这是主页面
    QTimer *doubleClickTimer;
    int clickCount;
};
#endif // WELCOMESCREEN_H
