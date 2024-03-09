#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include "mainscene.h"
WelcomeScreen::WelcomeScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeScreen)
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

    connect(welcome_button, &QPushButton::clicked,this, &WelcomeScreen::toMainScreen);
}

WelcomeScreen::~WelcomeScreen()
{
    delete ui;
}

void WelcomeScreen::toMainScreen()
{
    // 这里进入主界面
    MainScene* main_scene = new MainScene(this);
    this->hide();
    main_scene->show(); // 这里可能有点问题
    main_scene->doit();

}

