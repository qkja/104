#ifndef WORDOFCOMMAND_H
#define WORDOFCOMMAND_H
#include "util.hpp"
#include <QWidget>

namespace Ui
{
    class WordOfCommand;
}

class WordOfCommand : public QWidget
{
    Q_OBJECT

public:
    explicit WordOfCommand(QWidget *parent = nullptr);
    ~WordOfCommand();
signals:
    void fromWordOfCommandToMainScreenSignals();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WordOfCommand *ui;
};

#endif // WORDOFCOMMAND_H
