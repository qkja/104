// 这是一个循环的队列
#include <vector>

class CircularQueue
{
private:
  CircularQueue(int k)
      : _v(k + 1, 0), _front(0), _rear(0)
  {
  }

public:
  void push(int x)
  {
    if (IsFull())
      return;
    _v[_rear++] = x;
    _rear = _rear % _v.size();
  }
  void pop()
  {
    if (Empty())
      return;
    _front = (_front + 1) % _v.size();
  }
  bool Empty()
  {
    return _front == _rear;
  }
  bool IsFull()
  {
    return _front == (_rear + 1) % _v.size();
  }

public:
  std::vector<int> _v;
  int _front;
  int _rear;
};
