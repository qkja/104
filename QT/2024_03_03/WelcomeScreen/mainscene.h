#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
class MainScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainScene(QWidget *parent = nullptr);
private:
    void init(); // 初始化主页面
    void init_Bar(); // 初始化主页面
//    void init(); // 初始化主页面
//    void init(); // 初始化主页面
//    void init(); // 初始化主页面
public:
    // 主页面所有的操作
    void doit();

};

#endif // MAINSCENE_H
