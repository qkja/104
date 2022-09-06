#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

namespace bit
{
    template<class T>
    struct less
    {

        bool operator()(const T& t1, const T& t2) const
        {
            return t1 < t2;
        }
    };

    template<class T>
    struct greater
    {
        bool operator()(const T& x, const T& y) const
        {
            return x > y;
        }
    };

    template<class T, class Container = std::vector<T>, class Compare = bit::less<T>>
    class priority_queue
    {
    public:
        priority_queue(const Compare& comFunc = Compare())
            :_comFunc(comFunc)
        {
        }

       /* priority_queue()
        {
        }*/

        template <class InputIterator>

        priority_queue(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push(*first);
                ++first;
            }
        }
        // 建堆
        void push(const T& x)
        {
            _con.push_back(x);
            adjustUp(_con.size() - 1);
        }

        void pop()
        {
            assert(!_con.empty());
            std::swap(_con[0], _con[size() - 1]);
            _con.pop_back();
            adjustDwon(0);
        }
        const T& top()
        {
            return _con[0];
        }

        bool empty()
        {
            return _con.empty();
        }
        size_t size()
        {
            return _con.size();
        }

    private:

        //大堆 用  小于  
        //小堆 用  大于
        void adjustDwon(size_t parent)
        {
            //Compare _comFunc;

            size_t child = 2 * parent + 1;
            while (child < size())
            {
                if (child + 1 < _con.size() && _comFunc(_con[child], _con[child + 1]))
                {
                    child++;
                }

                if (_comFunc(_con[parent], _con[child]))
                {
                    std::swap(_con[parent], _con[child]);
                    parent = child;
                    child = 2 * child + 1;
                }
                else
                {
                    break;
                }
            }

        }
        void adjustUp(int child)
        {
            // 先 建大堆_comFunc
           // Compare _comFunc;

            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                if (_comFunc(_con[parent], _con[child]))
                {
                    std::swap(_con[parent], _con[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                {
                    break;
                }
            }
        }
    private:
        Container _con;
        Compare _comFunc;
    };

}

