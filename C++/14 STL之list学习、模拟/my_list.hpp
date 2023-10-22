#pragma once

// 节点
// template <class T>
// struct _list_node
// {
//     _list_node()
//         : _next(nullptr), _prev(nullptr), _data(T())
//     {
//     }
//     struct _list_node<T> *_next;
//     struct _list_node<T> *_prev;
//     T _data;
// };
// template <class T>
// struct _list_iterator
// {
//     typedef _list_node<T> Node;
//     typedef _list_iterator<T> self; // 这个是需要的,后面我们会 修改这个,如果tepdef就只可以修改这一个就可以了
//     Node *_node;                    // 我们给指针 ,节点的空间可能比较大

//     _list_iterator(Node *node)
//         : _node(node)
//     {
//     }
//     bool operator!=(const self &t) const
//     {
//         return _node != t._node;
//     }
//     bool operator==(const self &t) const
//     {
//         return !(*this != t);
//     }

//     // 前置
//     self &operator++()
//     {
//         _node = _node->_next;
//         return *this;
//     }

//     // 后置
//     self operator++(int)
//     {
//         self cur = *this; // 调用  的 是拷贝构造
//         _node = _node->_next;
//         return cur;
//     }
//     // 前置
//     self &operator--()
//     {
//         _node = _node->_prev;
//         return *this;
//     }
//     // 后置
//     self operator--(int)
//     {
//         self cur(*this);
//         _node = _node->_prev;
//         return cur;
//     }
//     T operator*()
//     {
//         return _node->_data;
//     }

//     T *operator->()
//     {
//         return &(_node->_data);
//     }
// };
// template <class T>
// class list
// {
// public:
//     typedef _list_node<T> Node;
//     typedef _list_iterator<T> iterator;

// public:
//     list()
//     {
//         // 首先 new 一个头节点
//         _head = new Node;
//         _head->_next = _head;
//         _head->_prev = _head;
//     }
//     // 第一个元素
//     iterator begin()
//     {
//         return iterator(_head->_next);
//     }
//     // 哨兵位
//     iterator end()
//     {
//         return iterator(_head);
//     }

// private:
//     Node *_head; // 哨兵位
// };

// #include <assert.h>
// #include <iostream>
// namespace bit
// {
//     ////  这个 是 list 节点
//     template <class T>
//     struct _list_node
//     {
//         _list_node<T> *_next;
//         _list_node<T> *_prev;
//         T _data;

//         // 先看看  构造函数 要不要写
//         _list_node(const T &t = T())
//             : _next(nullptr), _prev(nullptr), _data(t)
//         {
//         }
//     };

//     template <class T>

//     struct _list_iterator
//     {
//         typedef _list_node<T> Node;
//         typedef _list_iterator<T> self;

//         Node *_node;

//         _list_iterator(Node *node)
//             : _node(node)
//         {
//         }

//         // 析构  拷贝  都不需要

//         bool operator==(const self &t) const
//         {
//             return !(*this != t);
//         }

//         T *operator->()
//         {
//             return &_node->_data;
//         }

//         T operator*()
//         {
//             return _node->_data;
//         }
//         bool operator!=(const self &t) const
//         {
//             return _node != t._node;
//         }
//         // 前置
//         self &operator++()
//         {
//             _node = _node->_next;
//             return *this;
//         }

//         self &operator--()
//         {
//             _node = _node->_prev;
//             return *this;
//         }
//         // 后置
//         self operator++(int)
//         {
//             self cur = *this;
//             _node = _node->_next;
//             return cur;
//         }

//         self operator--(int)
//         {
//             self cur(*this);
//             _node = _node->_prev;
//             return cur;
//         }
//     };

//     template <class T> //  这个 就是一个模板
//     class list
//     {
//     public:
//         typedef _list_node<T> Node;

//         typedef _list_iterator<T> iterator;
//         typedef _list_iterator<const T> const_iterator;

//         //  要有 构造函数  作为 一个  标记位

//         list()
//         {
//             // 首先 new 一个头节点
//             _head = new Node;
//             _head->_next = _head;
//             _head->_prev = _head;
//         }

//         // 插入  不做说明的话 我们 插入 节点的前面
//         iterator insert(iterator pos, const T &val)
//         {
//             // 记录 迭代器 对应的 节点指针
//             Node *ppos = pos._node;
//             Node *cur = new Node(val);

//             // 记录 前一个 节点
//             Node *prev = ppos->_prev;

//             cur->_next = ppos;
//             ppos->_prev = cur;
//             cur->_prev = prev;
//             prev->_next = cur;

//             return iterator(cur);
//         }

//         void push_back(const T &val)
//         {
//             insert(end(), val);
//         }
//         // 迭代器
//         iterator begin()
//         {
//             return iterator(_head->_next);
//         }

//         const_iterator begin() const
//         {
//             return const_iterator(_head->_next);
//         }

//         const_iterator end() const
//         {
//             return const_iterator(_head);
//         }
//         iterator end()
//         {
//             return iterator(_head);
//         }

//     private:
//         Node *_head;
//     };
// }
// void func(const bit::list<int> &l)
// {
//     bit::list<int>::const_iterator it = l.begin();
//     while (it != l.end())
//     {
//         cout << *it << endl;
//         it++;
//     }
// }
// int main()
// {
//     bit::list<int> l;
//     l.push_back(1);
//     l.push_back(2);
//     l.push_back(3);
//     l.push_back(4);
//     l.push_back(5);
//     l.push_back(6);
//     l.push_back(7);

//     func(l);
//     return 0;
// }