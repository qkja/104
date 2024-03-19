#ifndef CONSUMER_H
#define CONSUMER_H
#include <QThread>
#include <QObject>
#include <iostream>
#include <thread>
#include "mainwindow.h"
#include <QApplication>
#include <string>
#include "Task.hpp"
#include "BlockqQueue.hpp"
#include <qdebug.h>
class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr)
        : QObject(parent)
    {

    }
public slots:
    void consumeData(void*args)
    {

        BlockqQueue<Task>* p = (BlockqQueue<Task> *)args;
        while (true)
        {
            // 这里是消费者的逻辑，等待数据并进行处理
            // 注意：这里没有放置一个无限循环，你需要在适当的时候退出循环，比如当应用程序关闭时
            // 你可以使用信号和槽来触发退出循环的条件
            Task t = p->pop();
            int one = 0;
            int two = 0;
            char op = 0;
            t.get(&one, &two, &op);
            int result = t();
            qDebug() << "我消费了一个任务: "<< one << " " << op << " " << two << " = " << result;
            QThread::msleep(1000); // 休眠1秒模拟消费者的操作
        }
    }

signals:

};

#endif // CONSUMER_H
