#ifndef __LOG_HPP__
#define __LOG_HPP__
#include <iostream>
#include <ctime>

std::ostream &Log()
{
    std::cout << "Fot Debug |" << " timestamp: " << (uint64_t)time(nullptr) << " | ";
    return std::cout;
}
#endif

