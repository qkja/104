#ifndef __UNORDEREDMAP_H__
#define __UNORDEREDMAP_H__

#include "HashTable.h"

namespace bit
{
  template <class K, class V, class HashFunc = DefaultHash<K>>
  class unordered_map
  {
    struct MapKeyOfT
    {
      const K &operator()(const std::pair<K, V> &pair)
      {
        return pair.first;
      }
    };

  public:
    typedef typename Bucket::HashTable<K, std::pair<K, V>, MapKeyOfT, HashFunc>::iterator iterator;
    iterator begin()
    {
      return _ht.begin();
    }

    iterator end()
    {
      return _ht.end();
    }

    std::pair<iterator, bool> insert(const std::pair<K, V> &kv)
    {
      return _ht.insert(kv);
    }

    bool erase(const K &key)
    {
      return _ht.erase(key);
    }

    iterator find(const K &key)
    {
      return _ht.find(key);
    }

  private:
    Bucket::HashTable<K, std::pair<K, V>, MapKeyOfT, HashFunc>
        _ht;
  };
}
#endif