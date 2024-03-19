#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDebug>
#include "BlockqQueue.hpp"
class Controller : public QObject
{
    Q_OBJECT
public:

    explicit Controller(QObject *parent = nullptr) : QObject(parent) {

    }

public slots:
    void handleResult(const QString &result)
    {

        qDebug() << "Result received:" << result;
    }
private:

};

#endif // CONTROLLER_H
