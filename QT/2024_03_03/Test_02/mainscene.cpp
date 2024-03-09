#include "mainscene.h"
#include "ui_mainscene.h"
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
Mainscene::Mainscene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainscene)
{
    ui->setupUi(this);

    // 配置主场景
    this->setFixedSize(320, 588); // 设置固定大小
    this->setWindowIcon(QIcon(":/res/Coin0001.png")); // 设置图片
    this->setWindowTitle("系统");

    // 实现退出
    connect(ui->actionquit, &QAction::triggered, this, [=](){
        this->close();
    });

    // 开始按钮
    MyPushButton* button_start = new MyPushButton(":/res/MenuSceneStartButton.png");
    button_start->setParent(this);

    button_start->move(this->width()*0.5 - button_start->width()*0.5, this->height()*0.7);


    this->choose = new ChooseLevelScene(); // 这是一个选择关卡的场景
    connect(button_start, &QPushButton::clicked, this, [=](){
        qDebug()<<"开始按钮";
        button_start->zoom1();
        button_start->zoom2();

        // 实现跳转到下一个场景
        //        自身隐藏

        // 加一个延迟
        QTimer::singleShot(500,this,[=](){
            this->hide();
            choose->show();
        });
//        this->show();

    });
}

Mainscene::~Mainscene()
{
    delete ui;
}

