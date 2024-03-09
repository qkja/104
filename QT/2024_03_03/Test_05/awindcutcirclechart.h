#ifndef AWINDCUTCIRCLECHART_H
#define AWINDCUTCIRCLECHART_H

#include <QMainWindow>

namespace Ui {
class AWindcutCircleChart;
}

class AWindcutCircleChart : public QMainWindow
{
    Q_OBJECT

public:
    explicit AWindcutCircleChart(QWidget *parent = nullptr);
    ~AWindcutCircleChart();
signals:
    void back();
private:
    Ui::AWindcutCircleChart *ui;
};

#endif // AWINDCUTCIRCLECHART_H
