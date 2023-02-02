#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <iostream>
#include <vector>

// 开放地址法
namespace Bucket
{
  template<class K, class V>
  struct HashNode
  {
    std::pair<K, V> _kv;
    HashNode<K, V>* _next;
    HashNode(const std::pair<K, V>& kv)
      :_kv(kv)
       ,_next(nullptr)
    {}
  };

  template<class K, class V>
  class HashTable
  {
    private:
      typedef HashNode<K, V> Node;

    public:

      Node* find(const K& key)
      {
        if(_tables.size() == 0)
          return nullptr;
        std::size_t hashi = key;
        hashi %= _tables.size();
        
        Node* cur = _tables[hashi];
        while(cur)
        {
          if(cur->_kv.first == key)
            return cur;
          cur = cur->_next;
        }
        return nullptr;
      }

      bool insert(const std::pair<K, V>& kv)
      {
        if(find(kv.first))
        {
          return false;
        }

        // 扩容 负载因子是1 的时候扩容
        if(_n == _tables.size())
        {
          std::size_t newSize = _tables.size() == 0?10:2*_tables.size();
          HashTable<K, V> newHT;
          newHT._tables.resize(newSize, nullptr);
          for(std::size_t i =0; i<_tables.size();i++)
          {
            Node* cur = _tables[i];
            while(cur)
            {
              newHT.insert(cur->_kv);
              cur = cur->_next;
            }
          }
          newHT._tables.swap(_tables);
        }

        std::size_t hashi = kv.first;
        hashi %= _tables.size();

        // 如果是空指针还是不是空指针
        // 直接头插
        Node* cur =  new Node(kv);
        cur->_next = _tables[hashi];
        _tables[hashi] = cur;

        return true;
      }
    private:

      std::vector<Node*> _tables;
      std::size_t _n = 0;
  };

};

// 闭散列
namespace CloseHash
{
enum States
{
  EMPTY,
  EXITS,
  DELETE
};

template<class K, class V>
struct HashData
{
  std::pair<K, V> _kv;
  States _states = EMPTY;
};

template<class K>
struct DefaultHash 
{
  std::size_t operator()(const K& key)
  {
    return key;
  }
};

// 使用特化
template<>
struct DefaultHash<std::string>
{
  std::size_t operator()(const std::string& key)
  {
    std::size_t hash = 0;
    for(auto& e:key)
    {
      hash = hash*131+e;
    }
    return hash;
    //return key[0];
  }
};

//struct StringHash
//{
//  std::size_t operator()(const std::string& key)
//  {
//    return key[0];
//  }
//};


template<class K, class V, class HashFunc=DefaultHash<K>>
class HashTable 
{
  private:
    typedef HashData<K, V> Data;
  public:
    Data* find(const K& key)
    {

      // 这里一定要记得判断
      if(_n == 0)
        return nullptr;

      HashFunc hf;
      std::size_t starti = hf(key);
      //std::size_t starti = key;
      starti %= _hashTable.size();

      std::size_t hashi = starti;
      std::size_t i = 1;
      while(_hashTable[hashi]._states != EMPTY)
      {
        if(_hashTable[hashi]._states == EXITS&&
            _hashTable[hashi]._kv.first == key)
        {
          // 说实话我们不想返回 地址
          return &_hashTable[hashi];
        }
        hashi = starti + i;
        i++;
        hashi%=_hashTable.size();
      }

      return nullptr;
    }

    bool erase(const K& key)
    { 
      Data* ret = find(key);
      if(ret)
      {
        ret->_states = DELETE;
        _n--; // 这里注意一下
        return true;
      }
      return false;
    }
   
    bool insert(const std::pair<K, V>& kv)
    {
      // 还未去庸语
      if(find(kv.first))
        return false;

      // 提出一个负载因子的概念
      if(_hashTable.size() == 0 ||
          10 *_n / _hashTable.size() >= 7)
      {
        // 扩容
        std::size_t newSize = _hashTable.size() == 0?10:2*_hashTable.size();
        // 扩容以后要重新映射
        
        HashTable<K, V, HashFunc> newHT;
        newHT._hashTable.resize(newSize);
        for(auto& e:_hashTable)
        {
          if(e._states == EXITS)
          {
            newHT.insert(e._kv);
          }
        }

        //std::swap(newHT._hashTable, _hashTable);
        newHT._hashTable.swap(_hashTable);
      }


      HashFunc hf;
      std::size_t starti = hf(kv.first); // 暂时认为是无符号的整数
      starti %= _hashTable.size(); // 这里我们应该% size 否则  超过size你插入不进去 [] 会检测 是否小于size

      std::size_t hashi = starti;
      std::size_t i = 1;


      
      // 线性探测 二次探测
      while(_hashTable[hashi]._states == EXITS)  // 判断条件很难
      {
        hashi = starti + i;
        ++i;
        // hashi 有可能会出去
        hashi %= _hashTable.size();
      }

      _hashTable[hashi]._kv = kv;
      _hashTable[hashi]._states = EXITS;
      _n++;
      return true;
    }
  
  private:
    std::vector<Data> _hashTable; // 就是一个数组结构
    std::size_t _n = 0;
};
}

#endif
