#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <QVBoxLayout>
WelcomeScreen::WelcomeScreen(QWidget *parent)
    : QWidget(parent), ui(new Ui::WelcomeScreen)
{
    qDebug() << "WelcomeScreen()";
    ui->setupUi(this);


    this->setFixedSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    if(FULL_SCREEN_OR_NOT){
         this->showFullScreen();
    }

    this->setWindowTitle("欢迎界面");
    ui->welcome_pushButton->setFixedSize(100,80);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(ui->welcome_pushButton, 0, Qt::AlignCenter);

    main_screen = new MainScreen(this);
    // 这个是单机按钮的功能
    //    connect(ui->welcome_pushButton, &QPushButton::clicked, [=]()
    //            {
    //        this->hide();
    //        main_screen->show(); });



    // 下面实现双击按钮进入主页面的功能

    // 创建计时器
    doubleClickTimer = new QTimer(this);
    doubleClickTimer->setInterval(QApplication::doubleClickInterval());

    // 连接按钮的双击信号和槽
    connect(ui->welcome_pushButton, &QPushButton::clicked, this,
            &WelcomeScreen::onButtonDoubleClicked);

    // 连接计时器的timeout信号和槽
    connect(doubleClickTimer, &QTimer::timeout, this,
            &WelcomeScreen::resetClickCount);

    // 初始化点击计数器
    clickCount = 0;

    connect(this->main_screen, &MainScreen::quitSignals, [=]()
    {
        main_screen->hide();
        this->close();
    });
}

WelcomeScreen::~WelcomeScreen()
{
    qDebug() << "~WelcomeScreen()";
    delete ui;
}

void WelcomeScreen::onButtonDoubleClicked()
{
    // 增加点击计数
    clickCount++;

    // 如果是双击，切换页面
    if (clickCount == 2)
    {
        fromWelToMianScreen();
        resetClickCount();
    }

    // 启动计时器
    doubleClickTimer->start();
}

void WelcomeScreen::fromWelToMianScreen()
{
    qDebug() << "Switching to Next Page";

    this->hide();
    this->main_screen->show();
}

void WelcomeScreen::resetClickCount()
{
    clickCount = 0;
    doubleClickTimer->stop();
}

void WelcomeScreen::keyPressEvent(QKeyEvent *event)
{
    // 如果按下的是Esc键，退出全屏模式
    if (event->key() == Qt::Key_Escape)
        showNormal();
}
