#include "widget.h"
#include <QApplication>
#include "BlockqQueue.hpp"
#include "controller.h"
#include "producerthread.h"
#include "workerthread.h"
int main(int argc, char *argv[])
{

    srand((unsigned int)time(NULL));
    QApplication a(argc, argv);
    Controller controller;
    Widget w(&controller);
    w.show();

    BlockqQueue<int> bq;

    // 创建控制器对象

    ProducerThread producer(&bq);
    // 创建工作线程
    WorkerThread workerThread(&bq);
    // 连接信号和槽
    QObject::connect(&workerThread, &WorkerThread::workFinished,
                     &controller, &Controller::handleResult);

    // 线程启动了
    producer.start();
    workerThread.start();
    return a.exec();
}
