#ifndef SETSPOUT_H
#define SETSPOUT_H

#include <QMainWindow>

namespace Ui {
class SetSpout;
}

class SetSpout : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetSpout(QWidget *parent = nullptr);
    ~SetSpout();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SetSpout *ui;
};

#endif // SETSPOUT_H
