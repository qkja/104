#ifndef BACKRESTCANAL_H
#define BACKRESTCANAL_H

#include <QWidget>
#include "util.hpp"
namespace Ui
{
    class BackrestCanal;
}

class BackrestCanal : public QWidget
{

    Q_OBJECT

public:
    explicit BackrestCanal(QWidget *parent = nullptr);
    ~BackrestCanal();
signals:
    void fromBackrestCanalToMainScreenSignals();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BackrestCanal *ui;
};

#endif // BACKRESTCANAL_H
