#ifndef CHANNELDATABASE_H
#define CHANNELDATABASE_H

#include <QWidget>

namespace Ui {
class ChannelDatabase;
}

class ChannelDatabase : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelDatabase(QWidget *parent = nullptr);
    ~ChannelDatabase();

private:
    Ui::ChannelDatabase *ui;
};

#endif // CHANNELDATABASE_H
