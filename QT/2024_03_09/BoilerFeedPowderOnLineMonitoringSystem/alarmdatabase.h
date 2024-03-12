#ifndef ALARMDATABASE_H
#define ALARMDATABASE_H

#include <QWidget>

namespace Ui {
class AlarmDatabase;
}

class AlarmDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmDatabase(QWidget *parent = nullptr);
    ~AlarmDatabase();

private:
    Ui::AlarmDatabase *ui;
};

#endif // ALARMDATABASE_H
