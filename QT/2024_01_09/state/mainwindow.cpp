#include "mainwindow.h"
#include "QStatusBar"
#include "QDockWidget"
#include "QTextBlock"
#include "QTextEdit"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);
    // 1. 状态栏
    QStatusBar* status = new QStatusBar(this);
    this->setStatusBar(status);

    status->showMessage("成功", 3000);

    // 临时信息,永久信息,注意,;临时信息会将永久信息给覆盖掉


    // 浮动窗口
    QDockWidget* dock = new QDockWidget(this);
    this->addDockWidget(Qt::TopDockWidgetArea,dock);

    // 中心部件
    //    QText* test = new QTextBlock(this);

}

MainWindow::~MainWindow()
{
}

