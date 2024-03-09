#ifndef WELCOME_H
#define WELCOME_H

#include <QObject>

class welcome : public QObject
{
    Q_OBJECT
public:
    explicit welcome(QObject *parent = nullptr);

signals:

};

#endif // WELCOME_H
