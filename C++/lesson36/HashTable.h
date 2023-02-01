#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <iostream>
#include <vector>

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
  States _states;
};

template<class K, class V>
class HashTable 
{
  private:
    typedef HashData<K, V> Data;
  public:
    bool insert(const std::pair<K, V>& kv)
    {
      // 提出一个负载因子的概念
      
      if(_hashTable.size() == 0 ||
          10 *_n / _hashTable.size() >= 7)
      {
        // 扩容
        std::size_t newSize = _hashTable.size() == 0?10:2*_hashTable.size();
        // 扩容以后要重新映射
        
        HashTable<K, V> newHT;
        newHT._hashTable.resize(newSize);
        for(auto& e:_hashTable)
        {
          if(e._states == EXITS)
          {
            newHT.insert(e);
          }
        }
        //std::swap(newHT._hashTable, _hashTable);
        newHT._hashTable.swap(_hashTable);
      }


      std::size_t starti = kv.first; // 暂时认为是无符号的整数
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

#endif
