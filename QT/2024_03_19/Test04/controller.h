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
signals:
    void mySignals(std::pair<int,int>&);
public slots:
    void handleResult(const QString &result)
    {

        qDebug() << "Result received:" << result;
        std::pair<int,int> p;
        int ret = result.toInt();
        p.first = ret;

        p.second = ret + rand()%10;
        emit mySignals(p);
    }
private:

};

#endif // CONTROLLER_H
