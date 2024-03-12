#ifndef MAINSCREEN_H
#define MAINSCREEN_H
#include "util.hpp"
#include <QMainWindow>
#include <string>
#include <fstream>
#include "systemsetting.h"
#include "statusview.h"
#include "dataprocessing.h"
#include "assist.h"
#include "verifypassword.h"
#include <unordered_map>
#include "util.hpp"
#include <vector>

namespace Ui
{
    class MainScreen;
}

class MainScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = nullptr);
    ~MainScreen();
signals:
    void quitSignals();

private:
    void init();
    void SystemSettingConnect();
    void StatusViewConnect();
    void DataProcessingConnect();
    void AssistConnect();
    void saveConfigurationFile();
private:
    Ui::MainScreen *ui;

    SystemSetting *system_setting;   // 系统设置
    StatusView *status_view;         // 状态查看
    DataProcessing *data_processing; // 数据处理
    Assist *assist;                  // 帮助
    VerifyPassword *verify_password;

    std::unordered_map<std::string, std::string> info_map;
    std::string configuration_file; // 配置文件
};

#endif // MAINSCREEN_H
