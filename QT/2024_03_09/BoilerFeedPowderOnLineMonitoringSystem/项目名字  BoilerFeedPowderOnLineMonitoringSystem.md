项目名字:  BoilerFeedPowderOnLineMonitoringSystem

欢迎界面:  WelcomeScreen

主界面: MainScreen

密码验证界面:PasswordVerificationScreen

配置文件:configuration_file

```cpp
class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();
private:

    void init();

private:
    Ui::MainScreen *ui;

    Cipher* cipher; //密码

    std::string configuration_file;// 配置文件
};
```







下面加上我们菜单栏的几个功能







系统设置:SystemSetting :system_setting_menu_1

状态查看:StatusView       :status_view_menu_2

数据处理:DataProcessing:data_processing_menu_3

帮助:Assist:assist_menu_4

```cpp
class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();
private:

    void init();
    void parseConfigurationFile();
private:
    Ui::MainScreen *ui;

    Cipher* cipher; //密码

    SystemSetting* system_setting; //系统设置
    StatusView* status_view;// 状态查看
    DataProcessing* data_processing;// 数据处理
    Assist* assist;// 帮助

    std::string configuration_file;// 配置文件
};

```





系统设置界面:SystemSetting

靠背管系数修正:BackrestCanal

 设定喷口面积:Spout

设定报警限 :GiveAnAlarm

修改口令 :WordOfCommand

修定时间:MyTime

退出系统:Quit



验证密码界面:VerifyPassword



```cpp
void MainScreen::SystemSettingConnect()
{
    //设定报警限
    connect(ui->give_an_alarm,&QAction::triggered,[=](){
        this->hide();
        this->system_setting->give_an_alarm->show();
    });
    connect(this->system_setting->give_an_alarm, &GiveAnAlarm::fromGiveAnAlarmToMainScreenSignals,[=](){
        // 这里少一个如果控件被关闭,我们是否需要做一些动作
        qDebug()<< "报警界面已经取消";
        this->system_setting->give_an_alarm->hide();
        this->show();
    });

    //靠背管系数修正
    connect(ui->backrest_canal,&QAction::triggered,[=](){
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
        });
    });
    connect(this->system_setting->backrest_canal, &BackrestCanal::fromBackrestCanalToMainScreenSignals,[=](){
        qDebug()<< "设定系数修正的界面已经取消";
        this->system_setting->backrest_canal->hide();
        this->show();
    });


//    设定喷口面积
    connect(ui->spout, &QAction::triggered,[=](){
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
        });
    });
    connect(this->system_setting->spout, &Spout::fromSpoutToMianScreenSignals,[=](){
        qDebug()<< "设定喷口面积界面已经取消";
        this->system_setting->spout->hide();
        this->show();
    });

    //修改口令
    connect(ui->word_of_command, &QAction::triggered,[=](){
        this->hide();
        this->system_setting->word_of_command->show();
    });

    connect(this->system_setting->word_of_command, &WordOfCommand::fromWordOfCommandToMainScreenSignals,[=](){
        this->system_setting->word_of_command->hide();
        this->show();
    });


    // 修改时间


    connect(ui->mytime, &QAction::triggered,[=](){
        this->hide();
        this->system_setting->mytime->show();
    });

    connect(this->system_setting->mytime, &MyTime::fromMyTimeToMianScreenSignals,[=](){
        this->show();
         this->system_setting->mytime->hide();
    });


    connect(ui->quit,&QAction::triggered,[=](){
        emit quitSignals();
    } );
}

```











下面看状态查看



状态查看:StatusView       :status_view_menu_2



棒型风粉图:RodTypeWindPowderDiagram:rod_type_wind_powder_diagram











一次风切圆图:TangentialCircleDiagramOfPrimaryWind :  tangential_circle_diagram_of_primary_wind



趋势图:TrendChart:trend_chart

历史趋势图:HistoricalTrendChart:historical_trend_chart





```cpp
class StatusView : public QWidget
{
    Q_OBJECT
public:
    friend class MainScreen;
    explicit StatusView(QWidget *parent = nullptr);
    ~StatusView();
signals:
private:
    RodTypeWindPowderDiagram* rod_type_wind_powder_diagram; //棒型风粉图
    TangentialCircleDiagramOfPrimaryWind *
                    tangential_circle_diagram_of_primary_wind; //一次风切圆图
    TrendChart* trend_chart;
    HistoricalTrendChart* historical_trend_chart;
};
```











数据处理:DataProcessing



报警数据库:AlarmDatabase:alarm_database

通道数据库:ChannelDatabase:channel_database



```cpp
class DataProcessing : public QWidget
{
    Q_OBJECT
public:
    explicit DataProcessing(QWidget *parent = nullptr);
    ~DataProcessing();
signals:
public:
    AlarmDatabase* alarm_database;//报警数据库:
    ChannelDatabase* channel_database;//通道数据库:
};
```











-----







实现双击按钮跳转页面的功能



```cpp
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTimer>

class PageSwitcher : public QWidget
{
    Q_OBJECT

public:
    PageSwitcher(QWidget *parent = nullptr)
        : QWidget(parent)
    {
        // 创建一个页面按钮
        buttonSwitchPage = new QPushButton("Switch Page", this);

        // 设置按钮位置
        buttonSwitchPage->setGeometry(50, 50, 150, 30);

        // 创建计时器，用于检测双击
        doubleClickTimer = new QTimer(this);
        doubleClickTimer->setInterval(QApplication::doubleClickInterval());

        // 连接按钮的双击信号和槽
        connect(buttonSwitchPage, &QPushButton::doubleClicked, this, &PageSwitcher::onButtonDoubleClicked);

        // 连接计时器的timeout信号和槽
        connect(doubleClickTimer, &QTimer::timeout, this, &PageSwitcher::resetClickCount);

        // 初始化点击计数器
        clickCount = 0;
    }

private slots:
    // 处理按钮双击事件
    void onButtonDoubleClicked()
    {
        // 增加点击计数
        clickCount++;

        // 如果是双击，切换页面
        if (clickCount == 2)
        {
            switchToNextPage();
            resetClickCount();
        }

        // 启动计时器
        doubleClickTimer->start();
    }

    // 切换页面
    void switchToNextPage()
    {
        // 在这里实现切换页面的逻辑，可以使用StackedWidget等布局管理器
        // 这里简单打印一条消息
        qDebug() << "Switching to Next Page";
    }

    // 重置点击计数
    void resetClickCount()
    {
        clickCount = 0;
        doubleClickTimer->stop();
    }

private:
    QPushButton *buttonSwitchPage;
    QTimer *doubleClickTimer;
    int clickCount;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PageSwitcher pageSwitcher;
    pageSwitcher.setGeometry(100, 100, 300, 150);
    pageSwitcher.show();

    return a.exec();
}
```

