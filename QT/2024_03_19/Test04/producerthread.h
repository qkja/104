#ifndef PRODUCER_H
#define PRODUCER_H
#include <QThread>
#include <QDebug>
#include "BlockqQueue.hpp"
class ProducerThread : public QThread
{
    Q_OBJECT
public:
    ProducerThread(BlockqQueue<int>* blockqQueue = nullptr, QObject *parent = nullptr)
        : QThread(parent)
    {
        _blockqQueue = blockqQueue;
    }
    void run() override
    {
        qDebug() << "Worker Thread ID:" << QThread::currentThreadId();
        for(int i = 0; i < 100; i++)
        {
            _blockqQueue->push(i);
//            sleep(1);
             usleep(1000000);
        }
    }

signals:
    void workFinished(const QString &result);
private:
    BlockqQueue<int>* _blockqQueue;
};
#endif // PRODUCER_H
