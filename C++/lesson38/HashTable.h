#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <iostream>
#include <vector>

template <class K>
struct DefaultHash
{
  std::size_t operator()(const K &key)
  {
    return key;
  }
};

// 使用特化
template <>
struct DefaultHash<std::string>
{
  std::size_t operator()(const std::string &key)
  {
    std::size_t hash = 0;
    for (auto &e : key)
    {
      hash = hash * 131 + e;
    }
    return hash;
  }
};

namespace Bucket
{
  template <class T>
  struct HashNode
  {
    T _data;
    HashNode<T> *_next;
    HashNode(const T &data)
        : _data(data), _next(nullptr)
    {
    }
  };

  /// @brief  声明
  template <class K, class T, class KeyOfT, class HashFunc>
  class HashTable;

  template <class K, class T, class KeyOfT, class HashFunc>
  class __HTIerator
  {

    typedef HashNode<T> Node;
    typedef __HTIerator<K, T, KeyOfT, HashFunc> Self;

    Node *_node;
    HashTable<K, T, KeyOfT, HashFunc> *_pth;

  public:
    __HTIerator(Node *node, HashTable<K, T, KeyOfT, HashFunc> *pth)
        : _node(node), _pth(pth)
    {
    }

    T &operator*()
    {
      return _node->_data;
    }

    T *operator->()
    {
      return &(_node->_data);
    }

    bool operator==(const Self &s)
    {
      return s._node == _node;
    }

    bool operator!=(const Self &s)
    {
      return !(*this == s);
      // return s._node != _node;
    }
    // 后置++
    Self &operator++(int)
    {
      return ++(*this);
    }

    // 前置++
    Self &operator++()
    {
      if (_node->_next != nullptr)
      {
        _node = _node->_next;
        return *this;
      }
      else
      {
        // 找到当前同
        KeyOfT kt;
        HashFunc hf;
        // 这里有问题
        std::size_t hashi = hf(kt(_node->_data)) % _pth->_tables.size();
        ++hashi;
        for (; hashi < _pth->_tables.size(); hashi++)
        {
          if (_pth->_tables[hashi] != nullptr)
          {
            _node = _pth->_tables[hashi];
            break;
          }
        }

        if (hashi == (_pth->_tables.size()))
          _node = nullptr;
      }
      return *this;
    }
  };

  template <class K, class T, class KeyOfT, class HashFunc>
  class HashTable
  {
  private:
    typedef HashNode<T> Node;
    // 友元 这里有点问题 
    template <class K1, class T1, class KeyOfT1, class HashFunc1>
    friend class __HTIerator;

  public:
  

    typedef __HTIerator<K, T, KeyOfT, HashFunc> iterator;

    iterator begin()
    {
      for (size_t i = 0; i < _tables.size(); ++i)
      {
        if (_tables[i] != nullptr)
        {
          return iterator(_tables[i], this);
        }
      }
      return iterator(nullptr, this);
    }

    iterator end()
    {
      return iterator(nullptr, this);
    }

  public:
    ~HashTable()
    {
      for (std::size_t i = 0; i < _tables.size(); i++)
      {
        Node *cur = _tables[i];
        while (cur)
        {
          Node *next = cur->_next;
          delete cur;
          cur = next;
        }
        _tables[i] = nullptr;
      }
    }

  public:
    bool erase(const K &key)
    {
      Node *node = find(key);

      if (node == nullptr)
        return false;
      // 找到头节点一定存在
      HashFunc hf;
      std::size_t hashi = hf(key) % _tables.size();

      // 头节点覆盖删除节点
      node->_data = _tables[hashi]->_data;

      // 删除头节点
      Node *cur = _tables[hashi];
      _tables[hashi] = _tables[hashi]->_next;
      delete cur;
      return true;
    }

    /// @brief  统一使用 key 不可以,主要是 map 我们不应该使用  pair搜索
    /// @param key
    /// @return
    Node *find(const K &key)
    {
      if (_tables.size() == 0)
        return nullptr;

      HashFunc hf;
      KeyOfT kt;

      std::size_t hashi = hf(key);
      hashi %= _tables.size();

      Node *cur = _tables[hashi];
      while (cur)
      {
        if (kt(cur->_data) == key)
          return cur;
        cur = cur->_next;
      }
      return nullptr;
    }

    bool insert(const T &data)
    {
      // 拿到  key 的值
      KeyOfT kt;
      // 拿到key % 的值
      HashFunc hf;

      if (find(kt(data)))
      {
        return false;
      }

      // 扩容 负载因子是1 的时候扩容
      if (_n == _tables.size())
      {
        std::size_t newSize = _tables.size() == 0 ? 10 : 2 * _tables.size();
        std::vector<Node *> newTable;
        newTable.resize(newSize);

        for (std::size_t i = 0; i < _tables.size(); i++)
        {
          Node *cur = _tables[i];

          while (cur)
          {
            Node *next = cur->_next;
            // 分析好了
            std::size_t hashi = hf(kt(cur->_data)) % newTable.size();

            cur->_next = newTable[hashi];
            newTable[i] = cur;
            cur = next;
          }
          _tables[i] = nullptr;
        }

        newTable.swap(_tables);
      }

      std::size_t hashi = hf(kt(data));
      hashi %= _tables.size();

      // 如果是空指针还是不是空指针
      // 直接头插
      Node *cur = new Node(data);
      cur->_next = _tables[hashi];
      _tables[hashi] = cur;
      _n++;
      return true;
    }

  private:
    std::vector<Node *> _tables;
    std::size_t _n = 0;
  };
}
#endif