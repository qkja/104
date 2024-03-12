#ifndef ALARMVALUE_H
#define ALARMVALUE_H
#include <string>
#include <QWidget>

namespace Ui {
class AlarmValue;
}

class AlarmValue : public QWidget
{
    Q_OBJECT
public:
    explicit AlarmValue(QWidget *parent = nullptr);
    ~AlarmValue();
    // 设置标题
    void setMyTitle(const std::string& text);
    // 设置范围
    void setMyRange(const int minVal,const int maxVal);
    // 设置值
    void setMyVal(const std::string &minVal, const std::string &maxVal,int multiple);


    void setLableText();
    void setLableIntOrDouble(const std::string);
private:
    Ui::AlarmValue *ui;
};


#endif // ALARMVALUE_H
