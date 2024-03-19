#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QDebug>
#include "BlockqQueue.hpp"
class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread( BlockqQueue<int>* blockqQueue = nullptr,QObject *parent = nullptr)
        : QThread(parent)
    {
        _blockqQueue = blockqQueue;
    }
    void run() override
    {
        qDebug() << "Worker Thread ID:" << QThread::currentThreadId();

        while(1)
        {
             int ret = _blockqQueue->pop();
             std::string str;
             str += std::to_string(ret);
             str += " : Work done!";
             emit workFinished(str.c_str());
        }
    }

signals:
    void workFinished(const QString &result);
private:
     BlockqQueue<int>* _blockqQueue;
};

#endif // WORKERTHREAD_H
