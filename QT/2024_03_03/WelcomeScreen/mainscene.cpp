#include "mainscene.h"
#include <QMenuBar>

MainScene::MainScene(QWidget *parent) : QMainWindow(parent)
{

    this->init();
}

void MainScene::init()
{
    this->setFixedSize(1000, 800);
    this->setWindowTitle("你好");
    // 设置菜单栏
    init_Bar();

}

void MainScene::init_Bar()
{
    QMenuBar* bar = this->menuBar();
    this->setMenuBar(bar);
    QMenu * systemSettingMenu = bar->addMenu("系统设置");

    QAction * quitAction1 = systemSettingMenu->addAction("设定背靠管");
    QAction * quitAction2 = systemSettingMenu->addAction("设定喷口");
    QAction * quitAction3 = systemSettingMenu->addAction("设定系数");
    QAction * quitAction4 = systemSettingMenu->addAction("修改口令");
    QAction * quitAction5 = systemSettingMenu->addAction("修定时间");
    QAction * quitAction6 = systemSettingMenu->addAction("退出");
    connect(quitAction6,&QAction::triggered,[=](){this->close();});



    QMenu * statusViewMenu = bar->addMenu("状态查看");
    QMenu * dataProcessingMenu = bar->addMenu("数据处理");
    QMenu * helpMenu = bar->addMenu("帮助");



}



void MainScene::doit()
{
    // 这里是我们主页面所有的操作
    qDebug() <<"你好";
}
