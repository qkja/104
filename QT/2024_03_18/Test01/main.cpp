#include "mainwindow.h"
#include <QApplication>
#include "Producer1.hpp"
#include "Consumer1.hpp"
#include "Task.hpp"
#include "BlockqQueue.hpp"
void fun(int argc, char *argv[])
{

}
int main(int argc, char *argv[])
{



    srand((unsigned long)time(nullptr));
    BlockqQueue<Task> bq;

    std::thread c(consumer, &bq, argc,argv);
    std::thread p(producer, &bq);
    c.join();
    p.join();
    return 0;
}

