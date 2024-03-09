#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置固定的界面
    this->setFixedSize(1000, 800);
    this->setWindowTitle("欢迎");
    QPushButton* welcome_button = new QPushButton(this);
    welcome_button->setFixedSize(150,80);
    welcome_button->setText("锅炉燃烧");
    qDebug() << this->height();
    qDebug() << this->width();
    welcome_button->move(this->height()*0.5+welcome_button->height()*0.5,
                         this->width()*0.5-welcome_button->width()*0.5);

    mainWindow = new MyMainWindow;

    connect(welcome_button, &QPushButton::clicked,[=](){

        // 切换窗口
        this->hide();// 主窗体隐藏
        mainWindow->show();
    });

    connect(this->mainWindow, &MyMainWindow::back,[=](){
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

