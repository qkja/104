#ifndef __BITSET_H__
#define __BITSET_H__
#include <istream>
#include <vector>

namespace bit
{
  template <std::size_t N>
  class bit_set
  {
  public:
    bit_set()
    {
      _bits.resize(N / 8 + 1, 0);
    }

    void reset(std::size_t x)
    {
      // 在那个 第几个char
      std::size_t i = x / 8;
      // 在第几个字节
      std::size_t j = x % 8;
      _bits[i] &= ~(1 << j);
    }

    void set(std::size_t x)
    {
      // 在那个 第几个char
      std::size_t i = x / 8;
      // 在第几个字节
      std::size_t j = x % 8;

      // 取决大小端 char 暂且不涉及 int 会
      // 左移是往高位移动,我们不关心
      _bits[i] |= (1 << j);
    }

    bool test(int x)
    {
      // 在那个 第几个char
      std::size_t i = x / 8;
      // 在第几个字节
      std::size_t j = x % 8;

      // 这里就可以了
      return _bits[i] & (1 << j);
    }

  private:
    std::vector<char> _bits;
  };
}

#endif
