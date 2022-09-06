#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <deque>

namespace bit
{
    template <class T, class Container = std::deque<T>>
    //  是一个 双端  队列
    class stack
    {
    public:
        void push(const T& x) {
            _con.push_back(x);
        }

        void pop() {
            _con.pop_back();
        }
        const T& top() {
            return _con.back();
        }

        bool empty() {
            return _con.empty();
        }
        size_t size() {
            return _con.size();
        }
    private:
        Container _con;
    };

    template<class T, class Container = std::deque<T>>
    class queue
    {
    public:
        void push(const T& x) {
            _con.push_back(x);
        }

        void pop() {
            _con.popfront();
        }

        const T& top() {
            return _con.front();
        }
        bool empty() {
            return _con.empty();
        }
        size_t size() {
            return _con.size();
        }
        T& back() {
            return _con.back();
        }

        const T& back()const {

            return _con.back();
        }

        T& front() {
            return _con.front();
        }

        const T& front()const {
            return _con.front();
        }
    private:
        Container _con;
    };
}