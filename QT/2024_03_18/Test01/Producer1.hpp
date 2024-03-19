#ifndef PRODUCER_HPP
#define PRODUCER_HPP
#include <iostream>
#include <thread>
#include <string>
#include "Task.hpp"
#include "BlockqQueue.hpp"
#include <windows.h>
#include <qdebug.h>
void producer(void* args)
{
    std::string str = "+-*/%";
    BlockqQueue<Task>* p = (BlockqQueue<Task> *)args;

    while (true)
    {

        int one = rand() % 10;
        int two = rand() % 10;
        char op = str[rand() % str.size()];
        Task t(one, two, op);
        p->push(t);
        qDebug() << "我生产了一个任务: " << one << " " << op << " " << two
                 << " = ?";
        Sleep(1000);
    }
}
#endif // PRODUCER_HPP
