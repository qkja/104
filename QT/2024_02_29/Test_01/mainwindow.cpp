#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytabwidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyTabWidget* mytable = new MyTabWidget(this);
    mytable->mouseDoubleClickEvent(nullptr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

