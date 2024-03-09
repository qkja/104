#ifndef SPOUT_H
#define SPOUT_H

#include <QWidget>

namespace Ui {
class Spout;
}

class Spout : public QWidget
{
    Q_OBJECT

public:
    explicit Spout(QWidget *parent = nullptr);
    ~Spout();

private:
    Ui::Spout *ui;
};

#endif // SPOUT_H
