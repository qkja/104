#ifndef PASSWORD_H
#define PASSWORD_H
#include <string>
#include <QWidget>
#include "util.h"
namespace Ui {
class password;
}

class password : public QWidget
{
    Q_OBJECT

public:
    password(MyPassword *pass_,QWidget *parent = nullptr);
    ~password();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
signals:
    void back_true();
    void back_false();
private:
    Ui::password *ui;
    MyPassword* pass;
};

#endif // PASSWORD_H
