#include "mainscreen.h"
#include "ui_mainscreen.h"
#include <string>
#include "QDebug"
#include <QString>
#include <iostream>
MainScreen::MainScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScreen),
    cipher(new Cipher(this)),
    system_setting(new SystemSetting(this)),
    status_view(new StatusView(this)),
    data_processing(new DataProcessing),
    assist(new Assist(this)),
    configuration_file("D:\\Code\\104\\QT\\2024_03_09\\BoilerFeedPowderOnLineMonitoringSystem\\configuration.txt")
{
    ui->setupUi(this);
    qDebug()<<"MainScreen()";
    init();


//    status_view = new StatusView;// 状态查看
//    data_processing = new DataProcessing;// 数据处理
//    assist = new Assist;// 帮助


    SystemSettingConnect();
    StatusViewConnect();
    DataProcessingConnect();
    AssistConnect();

}

MainScreen::~MainScreen()
{
    qDebug()<<"~MainScreen()";
    delete ui;
}

//这个函数是完成一些初始化,例如加载配置文件,完成密码的初始化
void MainScreen::init()
{
    // 解析配置文件
    parseConfigurationFile();
}

void MainScreen::parseConfigurationFile()
{
    std::ifstream ifs;
    ifs.open (configuration_file.c_str(), std::ifstream::in);
    if(ifs.is_open() == false)
    {
        qDebug() << "文件打不开";
        qDebug() << QString(configuration_file.c_str());
        qDebug() << QString(strerror(errno));
        return;
    }

    std::string str;
    std::getline(ifs, str);
    ifs.close();
    //qDebug() << QString(str.c_str());

    cipher->set(str.substr(str.find(':')+strlen(":")));
    //        qDebug() <<  QString(cipher->get().c_str());
}
//SystemSetting* system_setting; //系统设置
/*BackrestCanal*  backrest_canal; // 靠背管系数修正
Spout* spout;                   //   设定喷口面积
GiveAnAlarm* give_an_alarm;      //   设定报警限
WordOfCommand* word_of_command; //   修改口令
MyTime* mytime ;    */            //修定时间

// 有关于系统设置的链接
void MainScreen::SystemSettingConnect()
{
    //设定报警限
    connect(ui->give_an_alarm,&QAction::triggered,[=](){
        this->hide();
        this->system_setting->give_an_alarm->show();
    });

    connect(this->system_setting->give_an_alarm, &GiveAnAlarm::back,[=](){
        // 这里少一个如果控件被关闭,我们是否需要做一些动作
        qDebug()<< "报警界面已经取消";
        this->system_setting->give_an_alarm->close();
        this->show();
    });


}

//StatusView* status_view;// 状态查看
//DataProcessing* data_processing;// 数据处理
//Assist* assist;// 帮助



void MainScreen::StatusViewConnect(){}
void MainScreen::DataProcessingConnect(){}
void MainScreen::AssistConnect(){}
