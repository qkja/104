#ifndef BACKTOTUBE_H
#define BACKTOTUBE_H

#include <QWidget>

namespace Ui {
class BackToTube;
}

class BackToTube : public QWidget
{
    Q_OBJECT

public:
    explicit BackToTube(QWidget *parent = nullptr);
    ~BackToTube();
signals:
    void back();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::BackToTube *ui;
};

#endif // BACKTOTUBE_H
