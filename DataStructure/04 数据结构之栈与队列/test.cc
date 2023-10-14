#include <string>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

// class Solution
// {
// public:
//   bool isValid(string s)
//   {
//     stack<char> sta;
//     for (int i = 0; i < s.size(); ++i)
//     {
//       if (s[i] == '[' || s[i] == '(' || s[i] == '{')
//       {
//         sta.push(s[i]);
//       }
//       else
//       {
//         if (sta.empty())
//           return false;
//         char ch = sta.top();
//         sta.pop();
//         string str;
//         str += ch;
//         str += s[i];
//         if (str != "()" && str != "{}" && str != "[]")
//           return false;
//       }
//     }
//     return sta.empty();
//   }
// };

// class MyStack
// {
// public:
//   MyStack()
//   {
//   }

//   void push(int x)
//   {
//     q1.push(x);
//   }

//   int pop()
//   {
//     if (empty())
//       return -1;
//     while (q1.size() != 1)
//     {
//       q2.push(q1.front());
//       q1.pop();
//     }
//     int ret = q1.front();
//     q1.pop();
//     insert();
//     return ret;
//   }

//   int top()
//   {
//     if (empty())
//       return -1;
//     while (q1.size() != 1)
//     {
//       q2.push(q1.front());
//       q1.pop();
//     }
//     int ret = q1.front();
//     q1.pop();
//     q2.push(ret);
//     insert();
//     return ret;
//   }

//   bool empty()
//   {
//     return q1.empty() && q2.empty();
//   }

// private:
// private:
//   void insert()
//   {
//     while (!q2.empty())
//     {
//       q1.push(q2.front());
//       q2.pop();
//     }
//   }
//   std::queue<int> q1; // 这里是主要的
//   std::queue<int> q2; // 辅助的
// };
// class MyQueue
// {
// public:
//   MyQueue()
//   {
//   }

//   void push(int x)
//   {
//     s1.push(x);
//   }

//   int pop()
//   {
//     if (empty())
//       return -1;
//     if (s2.empty())
//     {
//       while (!s1.empty())
//       {
//         s2.push(s1.top());
//         s1.pop();
//       }
//     }
//     int ret = s2.top();
//     s2.pop();
//     return ret;
//   }

//   int peek()
//   {
//     if (s1.empty() && s2.empty())
//       return -1;
//     if (s2.empty())
//     {
//       while (!s1.empty())
//       {
//         s2.push(s1.top());
//         s1.pop();
//       }
//     }
//     return s2.top();
//   }

//   bool empty()
//   {
//     return s1.empty() && s2.empty();
//   }

// private:
//   std::stack<int> s1;
//   std::stack<int> s2;
// };

// class MyCircularQueue
// {
// public:
//   MyCircularQueue(int k)
//       : _v(k + 1, 0), _front(0), _rear(0)
//   {
//   }

//   bool enQueue(int value)
//   {
//     if (isFull())
//       return false;
//     _v[_rear++] = value;
//     _rear = _rear % _v.size();
//     return true;
//   }

//   bool deQueue()
//   {
//     if (isEmpty())
//       return false;
//     _front = (_front + 1) % _v.size();
//     return true;
//   }

//   int Front()
//   {
//     if (isEmpty())
//       return -1;
//     return _v[_front];
//   }

//   int Rear()
//   {
//     if (isEmpty())
//       return -1;
//     if (_rear == 0)
//       return _v.back();
//     else
//       return _v[_rear - 1];
//   }

//   bool isEmpty()
//   {
//     return _front == _rear;
//   }

//   bool isFull()
//   {
//     return _front == (_rear + 1) % _v.size();
//   }
//   std::vector<int> _v;
//   int _front;
//   int _rear;
// };
