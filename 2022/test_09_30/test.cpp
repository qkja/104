#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>
using namespace std;






class Solution {
public:
    void push(int value) {

        // 这里 我们让 辅助栈的元素个数一样
        s.push(value);
        if (minStack.empty() || value <= minStack.top())
        {
            minStack.push(value);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }
    void pop() {
        s.pop();
        minStack.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return minStack.top();
    }
private:
    stack<int> s;
    stack<int> minStack;
};

//class Solution {
//public:
//    void push(int value) {
//        s.push(value);
//        if (minStack.empty())
//        {
//            minStack.push(value);
//        }
//        else
//        {
//            int ret = minStack.top();
//            if (value <= ret)
//            {
//                minStack.push(value);
//            }
//        }
//    }
//    void pop() {
//        int ret = s.top();
//        s.pop();
//        if (ret == minStack.top())
//        {
//            minStack.pop();
//        }
//    }
//    int top() {
//        return s.top();
//    }
//    int min() {
//        return minStack.top();
//    }
//private:
//    stack<int> s;
//    stack<int> minStack;
//};