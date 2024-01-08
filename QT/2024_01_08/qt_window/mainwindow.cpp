#include "mainwindow.h"
#include "QMenu"
#include "QMenuBar"
#include "QAction"
#include "QToolBar"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);
    // 1. 创建菜单栏
    //    QMenuBar* menu_bar = new QMenuBar(this);
    QMenuBar* menu_bar = menuBar();
    this->setMenuBar(menu_bar);
    // 2. 创建菜单
    QMenu* menu1 = new QMenu("文件");
    QMenu* menu2 = new QMenu("编辑");
    QMenu* menu3 = new QMenu("构建");
    // 3. 将菜单添加到菜单栏
    menu_bar->addMenu(menu1);
    menu_bar->addMenu(menu2);
    menu_bar->addMenu(menu3);
    //4. 创建菜单
    QAction* act1 = new QAction("打开文件");
    QAction* act2 = new QAction("另存为");
    QAction* act3 = new QAction("关闭");
    menu1->addAction(act1);
    menu1->addAction(act2);
    menu1->addAction(act3);

    // 菜单栏补充: 一个窗口只能有一个,也就是我们这里可以使用成员函数来创建的
    // 为了避免我们new出多个, menuBar是 如过有,就返回指针,如果没有就开辟

    // 对菜单添加动作
    connect(act3, &QAction::triggered, this, &QMainWindow::close);

    ////////////////////////////////////////////////////////////

    // 工具栏是可以多次创建的

    //  工具栏类
    QToolBar* tool_bar = new QToolBar(this);
    //  添加工具类
    this->addToolBar(tool_bar);
    tool_bar->addAction(act1);
    tool_bar->addAction(act2);
    tool_bar->addAction(act3);

    // 禁止拖拽
    //    tool_bar->setMovable(false);

    // 设置停靠区域
    tool_bar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    // 工具栏可以在初始的时候停靠位置

    // 设置浮动状态

    ////////////////////////////////////////////////////
    // 状态栏

}

MainWindow::~MainWindow()
{
}

