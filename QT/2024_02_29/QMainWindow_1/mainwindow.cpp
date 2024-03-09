#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 充值窗口的大小
    resize(1000, 800);

    // 1. 设置菜单栏--只能有一个
    QMenuBar* bar = menuBar();
    setMenuBar(bar);   //将菜单栏放在窗口中

    QMenu* file =  bar->addMenu("文件");
    QMenu* edit =  bar->addMenu("编辑");

    //1.1 创建菜单项
    QAction* newAction = file->addAction("新建");
    file->addSeparator(); // 添加分割线
    QAction* openAction  = file->addAction("打开");

    // 2. 创建工具栏,可以有多个
    QToolBar* tools = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,tools);

    //默认是可以推拽的
    tools->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    tools->setFloatable(false); // 设置是否浮动
    tools->setMovable(false); // 设置是否可以移动
    tools->addAction(newAction);
    tools->addSeparator(); // 添加分割线
    tools->addAction(openAction);
    QPushButton* button = new QPushButton(this);
    button->setText("aaa");
    tools->addWidget(button); // 添加控件


    /////////////////////////////////////////////////////////////
    //    状态栏,最多只有一个

    QStatusBar* status =   statusBar();
    setStatusBar(status);
    // 设置标签控件
    QLabel* leftLabel = new QLabel(this);
    leftLabel->setText("左侧标签");
    status->addWidget(leftLabel);
    QLabel* rightLabel = new QLabel(this);
    rightLabel->setText("有侧标签");
    status->addPermanentWidget(rightLabel);
    //    铆接部件,也叫做浮动窗口,他是可以有多个的
    QDockWidget* dock = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    // 中心部件,这里也是只有一个
    QTextEdit* edit_2 = new QTextEdit(this);
    setCentralWidget(edit_2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

