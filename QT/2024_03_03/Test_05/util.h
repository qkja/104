#ifndef UTIL_H
#define UTIL_H
#include <string>
struct Value
{
    int min_val = 1;
    int max_val = 2;
};

class MyPassword
{
public:
    std::string get()
    {
        return _passward;

    }
    void set(const std::string& passward)
    {
        _passward = passward;
    }
private:
    std::string _passward;
};

#endif // UTIL_H
