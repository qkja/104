#ifndef GIVEANALARM_H
#define GIVEANALARM_H

#include <QWidget>
#include "util.hpp"
namespace Ui
{
    class GiveAnAlarm;
}

class GiveAnAlarm : public QWidget
{
    Q_OBJECT

public:
    explicit GiveAnAlarm(QWidget *parent = nullptr, std::unordered_map<std::string, std::string>* info_map = nullptr);
    ~GiveAnAlarm();

signals:
    void fromGiveAnAlarmToMainScreenSignals();
private slots:
    void on_pushButton_determine_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::GiveAnAlarm *ui;
     std::unordered_map<std::string, std::string>* info;
};

#endif // GIVEANALARM_H
