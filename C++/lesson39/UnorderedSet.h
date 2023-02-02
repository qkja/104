#ifndef __UNORDEREDSET_H__
#define __UNORDEREDSET_H__

#include "HashTable.h"

namespace bit
{

  template <class K, class HashFunc = DefaultHash<K>>
  class unordered_set
  {
    struct SetKeyOfT
    {
      const K &operator()(const K &key)
      {
        return key;
      }
    };

  public:
    typedef typename Bucket::HashTable<K, K, SetKeyOfT, HashFunc>::iterator iterator;
    iterator begin()
    {
      return _ht.begin();
    }

    iterator end()
    {
      return _ht.end();
    }

    bool insert(const K &key)
    {
      return _ht.insert(key);
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
    Bucket::HashTable<K, K, SetKeyOfT, HashFunc> _ht;
  };
}
#endif