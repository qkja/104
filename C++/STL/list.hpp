#include <iostream>

#include <assert.h>
namespace bit
{
  //  这个 是 list 节点
  template<class T>
  struct _list_node
  {
    _list_node<T>* _next;
    _list_node<T>* _prev;
    T _data;

    // 先看看  构造函数 要不要写
    _list_node(const T& t = T())
      :_next(nullptr)
       ,_prev(nullptr)
       ,_data(t)
    {
    }
  };


  //  迭代器
  //  T  T&  T*
  //template<class T,class Ref,class Ptr>
  template<class T>
  struct _list_iterator 
  {
    typedef _list_node<T> Node;
    //typedef _list_iterator<T,Ref,Ptr> self;
    typedef _list_iterator<T> self;
    Node* _node;

    _list_iterator(Node* node)
      :_node(node)
    {
    }

    // 析构  拷贝  都不需要
    
    bool operator==(const self& t) const
    {
      return !(*this != t);
    }

    T* operator->()
    {
      return &_node->_data;
    }

    T  operator*()
    {
      return _node -> _data;
    }


    bool operator!=(const self& t) const
    {
      return _node != t._node;
    }
    //前置
    self& operator++()
    {
      _node = _node->_next;
      return *this;
    }

    self& operator--()
    {
      _node = _node->_prev;
      return *this;
    }
    // 后置
    self operator++(int)
    {
      self cur = *this;
      _node = _node->_next;
      return cur;
    }

    self operator--(int)
    {
      self cur(*this);
      _node = _node->_prev;
      return cur;
    }

  };

  template<class T> //  这个 就是一个模板
  class list
  {
  public:
    typedef _list_node<T> Node;
    typedef _list_iterator<T> iterator;
    typedef _list_iterator<const T> const_iterator;
    //typedef _list_iterator<T,T&,T*> iterator;
    //typedef _list_iterator<T,const T& ,const T*> const_iterator;
    //  要有 构造函数  作为 一个  标记位
  
    list()
    {
      // 首先 new 一个头节点
      _head = new Node;
      _head->_next = _head;
      _head->_prev = _head;
    }

    // 在指定的位置插入数据
    
    // 尾插
   // void push_back(const T& data)
   // {
   //   // 找  尾
   //   Node* cur = new Node(data);
   //   Node* tail = _head->_prev;
   //   tail->_next = cur;
   //   cur->_prev = tail;
   //   cur->_next = _head;
   //   _head->_prev = cur;
   // }
   // size_t size()const 
   // {
   //   int count = 0;
   //   const_iterator it = begin();
   //   while(it != end())
   //   {
   //     it++;
   //     count++;
   //   }
   //   return count;
   // }

   // bool empty()const 
   // {
   //   // 这个 有问题
   //   //return _head->_next == _head->_prev;
   //   return 0 == size();
   // }

    // 插入  不做说明的话 我们 插入 节点的前面
    iterator insert(iterator pos, const T& val)
    {
      // 记录 迭代器 对应的 节点指针
      Node* ppos = pos._node;
      Node* cur = new Node(val);

      // 记录 前一个 节点
      Node* prev = ppos->_prev;

      cur->_next = ppos;
      ppos->_prev = cur;
      cur->_prev = prev;
      prev->_next = cur;

      return iterator(cur);
    }
    iterator erase(iterator pos)
    {
      Node* ppos = pos._node;
      // 不能 删哨兵位
      assert(pos != _head);
      Node* prev = ppos->_prev;
      Node* next = ppos->_next;

      prev->_next = next;
      next->_prev = prev;
      delete ppos;
      return iterator(next);
    }
    void push_back(const T& val)
    {
      insert(end(), val);
    }

    void push_front(const T& val)
    {
      insert(begin(), val);
    }


    void pop_back()
    {
       erase(--end());
    }

    void pop_front()
    {
      erase(begin());
    }
    // 迭代器
    iterator begin()
    {
      return iterator(_head->_next);
    }

    const_iterator begin() const 
    {
      return const_iterator(_head->_next);
    }

    const_iterator end() const 
    {
      return const_iterator(_head);
    }
    iterator end()
    {
      return iterator(_head);
    }

  private:

    Node* _head;
  };
}
