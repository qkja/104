#pragma once

template <class T>
class Vector
{
public:
  typedef T *iterator; // 原生指针
  typedef const T *const_iterator;

public:
  Vector()
      : _start(nullptr), _finish(nullptr), _endOfStoage(nullptr)
  {
  }

  // Vector(size_t n, const T& value = T()) // 这个有问题,使用下面面的形式参数
  Vector(int n, const T &value = T())
      : _start(nullptr), _finish(nullptr), _endOfStoage(nullptr)
  {
    Vector<T> vv;
    for (int i = 0; i < n; i++)
    {
      vv.push_back(value);
    }
    swap(vv);
  }
  // 拷贝构造
  Vector(const Vector<T> &v) // 这里建议这样写   当然类内 const Vector& v 这样也可以,只不过不推荐
      : _start(nullptr), _finish(nullptr), _endOfStoage(nullptr)
  {
    // 现代写法
    Vector<T> vv;
    for (const T &val : v)
    {
      vv.push_back(val);
    }
    // 我让你帮我写好,vv这个变量你还要给我析构了.
    swap(vv);
  }
  template <class InputIterator>
  Vector(InputIterator first, InputIterator last)
      : _start(nullptr), _endOfStoage(nullptr), _finish(nullptr)
  {
    Vector<T> vv;
    while (first != last)
    {
      vv.push_back(*first);
      first++;
    }
    swap(vv);
  }
  ~Vector()
  {
    if (_start)
    {
      delete[] _start;
      _finish = nullptr;
      _endOfStoage = nullptr;
    }
  }
  Vector<T> &operator=(Vector<T> v)
  {
    // 这里我们不传入 引用,这里就编译器自动调用拷贝构造,我们直接可以传入了.
    swap(v);
    return *this;
  }

public:
  size_t size() const
  {
    return _finish - _start;
  }

  //  计算 容量
  size_t capacity() const
  {
    return _endOfStoage - _start;
  }

  T &operator[](size_t pos)
  {
    assert(pos >= 0 && pos < size());
    return *(_start + pos);
  }
  const T &operator[](size_t pos) const
  {
    assert(pos >= 0 && pos < size());
    return *(_start + pos);
  }

  void reserve(size_t n = 0)
  {
    size_t oldsize = size();

    if (n > capacity())
    {
      // 开一块空间
      T *tmp = new T[n];
      // 判断  原本空间有没有 数据
      if (_start)
      {
        // 这里直接 赋值  对于 自定义类型 会自动调用赋值重载   -- 深拷贝
        for (int i = 0; i < size(); i++)
        {
          tmp[i] = _start[i];
        }
        // memcpy(tmp, _start, size()*sizeof(T));
        delete[] _start;
      }

      _start = tmp;
      _finish = tmp + oldsize;
      _endOfStoage = tmp + n;
    }
  }
  iterator insert(iterator pos, const T &x)
  {
    assert(pos >= _start && pos <= _finish);
    if (_finish == _endOfStoage)
    {
      size_t len = pos - _start; // 记录 防止失效
      size_t newCap = _endOfStoage - _start == 0 ? 4 : 2 * capacity();
      reserve(newCap);
      // 更新 pos 解决了一部分迭代器失效问题
      pos = _start + len;
    }
    //  开始  插入数据
    iterator it = _finish;
    while (it != pos)
    {
      *it = *(it - 1);
      it--;
    }
    *pos = x;
    _finish++;
    return pos;
  }
  void swap(Vector<T> &v)
  {
    std::swap(_start, v._start);
    std::swap(_finish, v._finish);
    std::swap(_endOfStoage, v._endOfStoage);
  }
  void pop_back()
  {
    if (size() != 0) //  这里 最好不要用 空来判断  害怕clear
    {
      --_finish;
    }
  }
  iterator erase(iterator pos)
  {
    assert(pos >= _start && pos < _finish);
    iterator it = pos + 1;
    while (it != _finish)
    {
      *(it - 1) = *it;
      it++;
    }
    _finish--;
    return pos;
  }
  void push_back(const T &val)
  {
    insert(_finish, val);
  }
  void resize(size_t n, const T &val = T())
  {
    // 三种 情况
    reserve(n);
    if (n > size())
    {
      while (size() < n)
      {
        //
        *_finish = val;
        _finish++;
      }
    }
    else
    {
      // 这里是缩小空间
      _finish = _start + n;
    }
  }

public:
  iterator begin()
  {
    return _start;
  }
  const_iterator begin() const
  {
    return _start;
  }
  iterator end()
  {
    return _finish;
  }
  const_iterator end() const
  {
    return _finish;
  }

private:
  iterator _start;
  iterator _finish;      // 指向后一个有效元素的下一个位置
  iterator _endOfStoage; // 这个是控制空间的
};