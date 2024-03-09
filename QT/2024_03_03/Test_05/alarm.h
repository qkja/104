#ifndef ALARM_H
#define ALARM_H

#include <QMainWindow>
#include <vector>
#include "util.h"
#include <string>
namespace Ui {
class Alarm;
}


class Alarm : public QMainWindow
{
    Q_OBJECT

public:
    explicit Alarm(QWidget *parent = nullptr);
    ~Alarm();
signals:
    void back();
//    void readVal(std::string,  const std::vector<Value>);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void init();
private:
    Ui::Alarm *ui;
    std::vector<Value> _val;
    std::string path;
};

#endif // ALARM_H
