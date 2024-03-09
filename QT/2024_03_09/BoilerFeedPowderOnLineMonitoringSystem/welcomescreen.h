#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QWidget>
#include "mainscreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeScreen; }
QT_END_NAMESPACE

class WelcomeScreen : public QWidget
{
    Q_OBJECT

public:
    WelcomeScreen(QWidget *parent = nullptr);
    ~WelcomeScreen();

private:
    Ui::WelcomeScreen *ui;
    MainScreen* main_screen; // 这是主页面
};
#endif // WELCOMESCREEN_H
