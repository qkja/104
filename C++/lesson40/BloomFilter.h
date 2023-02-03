#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__
#include <iostream>
#include <bitset>
#include <string>

namespace bit
{
  struct BKDRHash
  {
    size_t operator()(const std::string &s)
    {
      // BKDR
      size_t value = 0;
      for (auto ch : s)
      {
        value *= 31;
        value += ch;
      }
      return value;
    }
  };
  struct APHash
  {
    size_t operator()(const std::string &s)
    {
      size_t hash = 0;
      for (long i = 0; i < s.size(); i++)
      {
        if ((i & 1) == 0)
        {
          hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
        }
        else
        {
          hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
        }
      }
      return hash;
    }
  };
  struct DJBHash
  {
    size_t operator()(const std::string &s)
    {
      size_t hash = 5381;
      for (auto ch : s)
      {
        hash += (hash << 5) + ch;
      }
      return hash;
    }
  };


  template <class K, std::size_t M, class HashFun1, class HashFun2, class HashFun3>
  class BloomFilter
  {
  public:
    void Set(const K &key)
    {
      std::size_t hash1 = HashFun1()(key) % M;
      std::size_t hash2 = HashFun2()(key) % M;
      std::size_t hash3 = HashFun3()(key) % M;

      _bs.set(hash1);
      _bs.set(hash2);
      _bs.set(hash3);
    }

    bool Test(const K &key)
    {
      std::size_t hash1 = HashFun1()(key) % M;
      if (_bs.test(hash1) == false)
      {
        return false;
      }
      std::size_t hash2 = HashFun2()(key) % M;
      if (_bs.test(hash2) == false)
      {
        return false;
      }
      std::size_t hash3 = HashFun3()(key) % M;
      if (_bs.test(hash3) == false)
      {
        return false;
      }

      // 此时 是真实都在,也能是误判
      return true;
    }

  private:
    std::bitset<M> _bs; // 开出M个比特位
  };

  // void test()
  // {
  //   BloomFilter<std::string, 43, BKDRHash, APHash, DJBHash> bf;

  // }
}

#endif