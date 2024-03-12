#ifndef SPOUT_H
#define SPOUT_H

#include <QWidget>
#include "util.hpp"
namespace Ui
{
    class Spout;
}

class Spout : public QWidget
{
    Q_OBJECT

public:
    explicit Spout(QWidget *parent = nullptr);
    ~Spout();
signals:
    void fromSpoutToMianScreenSignals();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Spout *ui;
};

#endif // SPOUT_H
