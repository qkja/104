#ifndef FORM_SMALL_H
#define FORM_SMALL_H
#include "util.h"
#include <QWidget>

namespace Ui {
class Form_small;
}

class Form_small : public QWidget
{
    Q_OBJECT

public:
    explicit Form_small(QWidget *parent = nullptr);
    ~Form_small();
    void setValse(Value);
    Value getValse();
private:
    Ui::Form_small *ui;
};

#endif // FORM_SMALL_H
