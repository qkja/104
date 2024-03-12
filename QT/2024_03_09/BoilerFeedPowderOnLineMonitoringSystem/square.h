#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPen>
#include "util.hpp"
namespace Ui
{
    class Square;
}

class Square : public QWidget
{
    Q_OBJECT

public:
    explicit Square(QWidget *parent = nullptr);
    ~Square();

private:
    Ui::Square *ui;
};

#endif // SQUARE_H
