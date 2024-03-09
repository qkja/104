#ifndef GIVEANALARM_H
#define GIVEANALARM_H

#include <QWidget>

namespace Ui {
class GiveAnAlarm;
}

class GiveAnAlarm : public QWidget
{
    Q_OBJECT

public:
    explicit GiveAnAlarm(QWidget *parent = nullptr);
    ~GiveAnAlarm();


signals:
    void back();
private slots:
    void on_pushButton_determine_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::GiveAnAlarm *ui;
};

#endif // GIVEANALARM_H
