#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        _s1.push(x);
        if (_s2.empty())
        {
            _s2.push(x);
        }
        else
        {
            // 判断栈顶的元素
            int ret = _s2.top();
            if (ret >= x)
            {
                _s2.push(x);
            }
        }
    }

    void pop() {
        if (_s1.empty())
        {
            return;
        }

        int ret = _s1.top();
        _s1.pop();
        if (ret == _s2.top())
            _s2.pop();
    }

    int top() {
        return _s1.top();
    }

    int min() {
        return _s2.top();
    }
private:
    stack<int> _s1; 
    stack<int> _s2; // 记录 最小元素
};

//class CQueue {
//public:
//    CQueue() {
//
//    }
//    //
//    void appendTail(int value) {
//        _sPush.push(value);
//    }
//
//    int deleteHead() {
//        // 为空
//        if (_sPush.empty() && _sPop.empty())
//        {
//            return -1;
//        }
//        // 
//        if (_sPop.empty())
//        {
//            while (!_sPush.empty())
//            {
//                int val = _sPush.top();
//                _sPop.push(val);
//                _sPush.pop();
//            }
//        }
//        int ret = _sPop.top();
//        _sPop.pop();
//        return ret;
//    }
//private:
//    stack<int> _sPop;
//    stack<int> _sPush;
//};