#ifndef WORDOFCOMMAND_H
#define WORDOFCOMMAND_H

#include <QWidget>

namespace Ui {
class WordOfCommand;
}

class WordOfCommand : public QWidget
{
    Q_OBJECT

public:
    explicit WordOfCommand(QWidget *parent = nullptr);
    ~WordOfCommand();

private:
    Ui::WordOfCommand *ui;
};

#endif // WORDOFCOMMAND_H
