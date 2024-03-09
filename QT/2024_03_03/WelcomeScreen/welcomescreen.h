#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeScreen; }
QT_END_NAMESPACE

class WelcomeScreen : public QMainWindow
{
    Q_OBJECT

public:
    WelcomeScreen(QWidget *parent = nullptr);
    ~WelcomeScreen();
    void toMainScreen();

private slots:
    void on_verticalSlider_actionTriggered(int action);

private:
    Ui::WelcomeScreen *ui;
};
#endif // WELCOMESCREEN_H
