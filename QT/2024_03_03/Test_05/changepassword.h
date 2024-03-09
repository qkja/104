#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H
#include "util.h"
#include <QWidget>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassword(MyPassword* pass,QWidget *parent = nullptr);
    ~ChangePassword();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangePassword *ui;
    MyPassword* _pass;
};

#endif // CHANGEPASSWORD_H
