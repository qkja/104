#ifndef ASSIST_H
#define ASSIST_H

#include <QWidget>
#include "util.hpp"
class Assist : public QWidget
{
    Q_OBJECT
public:
    explicit Assist(QWidget *parent = nullptr);
    ~Assist();
signals:
};

#endif // ASSIST_H