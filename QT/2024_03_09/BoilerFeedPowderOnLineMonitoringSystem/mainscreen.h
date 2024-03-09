#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QMainWindow>
#include <string>
#include <fstream>
#include "cipher.h"
#include "systemsetting.h"
#include "statusview.h"
#include "dataprocessing.h"
#include "assist.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();


private:

    void init();
    void parseConfigurationFile();
    void SystemSettingConnect();
    void StatusViewConnect();
    void DataProcessingConnect();
    void AssistConnect();

private:
    Ui::MainScreen *ui;

    Cipher* cipher; //密码
    SystemSetting* system_setting; //系统设置
    StatusView* status_view;// 状态查看
    DataProcessing* data_processing;// 数据处理
    Assist* assist;// 帮助

    std::string configuration_file;// 配置文件
};

#endif // MAINSCREEN_H
