#ifndef VERIFYPASSWORD_H
#define VERIFYPASSWORD_H
#include <string>
#include <QWidget>

namespace Ui {
class VerifyPassword;
}

class VerifyPassword : public QWidget
{
    Q_OBJECT

public:
    explicit VerifyPassword(QWidget *parent = nullptr);
    ~VerifyPassword();
    bool is_true(const std::string &str);
    void set(const std::string& str);
    std::string get();
signals:
    void fromVerifyPasswordSignalsIsTrue();
    void fromVerifyPasswordSignalsIsFalse();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::VerifyPassword *ui;
      std::string password; //密码
};

#endif // VERIFYPASSWORD_H
