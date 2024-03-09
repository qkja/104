#ifndef REVISIONTIME_H
#define REVISIONTIME_H

#include <QWidget>

namespace Ui {
class RevisionTime;
}

class RevisionTime : public QWidget
{
    Q_OBJECT

public:
    explicit RevisionTime(QWidget *parent = nullptr);
    ~RevisionTime();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RevisionTime *ui;
};

#endif // REVISIONTIME_H
