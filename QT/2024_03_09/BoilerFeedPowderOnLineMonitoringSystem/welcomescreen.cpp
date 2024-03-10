#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <QPushButton>
#include <QDebug>
WelcomeScreen::WelcomeScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomeScreen)
{
    qDebug()<<"WelcomeScreen()";
    ui->setupUi(this);
    main_screen = new MainScreen(this);
    connect(ui->welcome_pushButton,&QPushButton::clicked,[=](){
        this->hide();
        main_screen->show();
    });
    connect(this->main_screen, &MainScreen::quitSignals,[=](){
        main_screen->hide();
        this->close();
    });
}

WelcomeScreen::~WelcomeScreen()
{
    qDebug()<<"~WelcomeScreen()";
    delete ui;
}

