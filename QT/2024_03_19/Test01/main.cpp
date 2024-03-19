#include "widget.h"

#include <QApplication>
#include <controller.h>
#include <workerthread.h>
#include <qthread.h>
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <qtimer.h>
#include "BlockqQueue.hpp"
#include "producerthread.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    BlockqQueue<int> bq;

    // 创建控制器对象
    Controller controller;
    ProducerThread pro(&bq);
    // 创建工作线程
    WorkerThread workerThread(&bq);
    // 连接信号和槽
    QObject::connect(&workerThread, &WorkerThread::workFinished,
                     &controller, &Controller::handleResult);


   QThread t1;


    // 启动工作线程
    pro.start();
    workerThread.start();

    return a.exec();
}
