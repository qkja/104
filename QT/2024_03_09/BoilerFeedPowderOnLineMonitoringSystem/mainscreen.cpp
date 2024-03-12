#include "mainscreen.h"
#include "ui_mainscreen.h"
#include <string>
#include "QDebug"
#include <QString>
#include <iostream>
MainScreen::MainScreen(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainScreen),
    verify_password(new VerifyPassword(nullptr)),
//    system_setting(new SystemSetting(this)),
     system_setting(nullptr),
    status_view(new StatusView(this)),
    data_processing(new DataProcessing(this)),
    assist(new Assist(this)),
    configuration_file("D:\\Code\\104\\QT\\2024_03_09\\BoilerFeedPowderOnLineMonitoringSystem\\configuration.txt")
{
    ui->setupUi(this);
    qDebug() << "MainScreen()";
    this->setFixedSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    this->setWindowTitle("锅炉送粉在线监测系统");

    init();
    // 这是一个尝试
    system_setting = new SystemSetting(this, &info_map),

    verify_password->set(info_map["password"]);

    SystemSettingConnect();
    StatusViewConnect();
    DataProcessingConnect();
    AssistConnect();
}

MainScreen::~MainScreen()
{
    saveConfigurationFile();
    delete verify_password;
    qDebug() << "~MainScreen()";
    delete ui;
}

// 这个函数是完成一些初始化,例如加载配置文件,完成密码的初始化
void MainScreen::init()
{
    std::ifstream ifs;
    ifs.open(configuration_file.c_str(), std::ifstream::in);
    if (ifs.is_open() == false)
    {
        qDebug() << "文件打不开";
        qDebug() << QString(configuration_file.c_str());
        qDebug() << QString(strerror(errno));
        return;
    }

    std::string str;
    while (std::getline(ifs, str))
    {
        info_map[str.substr(0, str.find(':'))] = str.substr(str.find(':') + strlen(":"));
    }
    ifs.close();
}
// 这个是修改配置文件的
void MainScreen::saveConfigurationFile()
{
    std::vector<std::string> v;
    std::ifstream ifs;
    ifs.open(configuration_file.c_str(), std::ifstream::in);
    if (ifs.is_open() == false)
    {
        qDebug() << "文件打不开";
        qDebug() << QString(configuration_file.c_str());
        qDebug() << QString(strerror(errno));
        return;
    }
    std::string str;
    while (std::getline(ifs, str))
    {
        v.push_back(str.substr(0, str.find(':')));
    }
    ifs.close();
    // 文本读写
    std::ofstream ofs(configuration_file.c_str());
    for(size_t i = 0; i < v.size(); ++i)
    {
        ofs << v[i] <<":" << info_map[v[i]] << std::endl;
    }
    ofs.close();
//    qDebug()<<"保存文件已经结束 " << v.size();
}

// 有关于系统设置的链接
void MainScreen::SystemSettingConnect()
{
    // 设定报警限
    connect(ui->give_an_alarm, &QAction::triggered, [=]()
    {
        this->hide();
        this->system_setting->give_an_alarm->show(); });
    connect(this->system_setting->give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals, [=]()
    {
        // 这里少一个如果控件被关闭,我们是否需要做一些动作
        qDebug()<< "报警界面已经取消";
        this->system_setting->give_an_alarm->hide();
        this->show(); });

    // 靠背管系数修正
    connect(ui->backrest_canal, &QAction::triggered, [=]()
    {
        this->verify_password->show();
        connect(this->verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsTrue,[=](){
            qDebug()<<"验证界面已经可以了";
            this->hide();
            this->verify_password->hide();
            this->system_setting->backrest_canal->show();
        });
        connect(this->verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse,[=](){
            qDebug()<<"验证界面已经取消了";
            this->verify_password->hide();
        }); });
    connect(this->system_setting->backrest_canal, &BackrestCanal::fromBackrestCanalToMainScreenSignals, [=]()
    {
        qDebug()<< "设定系数修正的界面已经取消";
        this->system_setting->backrest_canal->hide();
        this->show(); });

    //    设定喷口面积
    connect(ui->spout, &QAction::triggered, [=]()
    {
        this->verify_password->show();
        connect(this->verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsTrue,[=](){
            qDebug()<<"验证界面已经可以了";
            this->hide();
            this->verify_password->hide();
            this->system_setting->spout->show();
        });
        connect(this->verify_password, &VerifyPassword::fromVerifyPasswordSignalsIsFalse,[=](){
            qDebug()<<"验证界面已经取消了";
            this->verify_password->hide();
        }); });
    connect(this->system_setting->spout, &Spout::fromSpoutToMianScreenSignals, [=]()
    {
        qDebug()<< "设定喷口面积界面已经取消";
        this->system_setting->spout->hide();
        this->show(); });

    // 修改口令
    connect(ui->word_of_command, &QAction::triggered, [=]()
    {
        this->hide();
        this->system_setting->word_of_command->show(); });

    connect(this->system_setting->word_of_command, &WordOfCommand::fromWordOfCommandToMainScreenSignals, [=]()
    {
        this->system_setting->word_of_command->hide();
        this->show(); });

    // 修改时间

    connect(ui->mytime, &QAction::triggered, [=]()
    {
        this->hide();
        this->system_setting->mytime->show(); });

    connect(this->system_setting->mytime, &MyTime::fromMyTimeToMianScreenSignals, [=]()
    {
        this->show();
        this->system_setting->mytime->hide(); });

    connect(ui->quit, &QAction::triggered, [=]()
    { emit quitSignals(); });
}

// StatusView* status_view;// 状态查看
void MainScreen::StatusViewConnect()
{

    connect(ui->rod_type_wind_powder_diagram, &QAction::triggered, [=]()
    {
        this->hide();
        this->status_view->rod_type_wind_powder_diagram->show(); });
    connect(ui->tangential_circle_diagram_of_primary_wind, &QAction::triggered, [=]()
    {
        this->hide();
        this->status_view->tangential_circle_diagram_of_primary_wind->show(); });
    // 趋势图
    connect(ui->trend_chart, &QAction::triggered, [=]()
    {
        this->hide();
        this->status_view->trend_chart->show(); });

    // 历史趋势图

    connect(ui->historical_trend_chart, &QAction::triggered, [=]()
    {
        this->hide();
        this->status_view->historical_trend_chart->show(); });
}


void MainScreen::DataProcessingConnect()
{
    connect(ui->alarm_database, &QAction::triggered, [=]()
    {
        this->hide();
        this->data_processing->alarm_database->show(); });

    connect(ui->channel_database, &QAction::triggered, [=]()
    {
        this->hide();
        this->data_processing->channel_database->show(); });
}
void MainScreen::AssistConnect() {}
