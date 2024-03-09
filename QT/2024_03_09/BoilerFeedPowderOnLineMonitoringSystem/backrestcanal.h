#ifndef BACKRESTCANAL_H
#define BACKRESTCANAL_H

#include <QWidget>

namespace Ui {
class BackrestCanal;
}

class BackrestCanal : public QWidget
{

    Q_OBJECT

public:
    explicit BackrestCanal(QWidget *parent = nullptr);
    ~BackrestCanal();

private:
    Ui::BackrestCanal *ui;
};

#endif // BACKRESTCANAL_H
