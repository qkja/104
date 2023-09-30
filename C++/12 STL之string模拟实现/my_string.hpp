#pragma once
#include <iostream>
#include <cstring>
namespace my_string
{
  class string
  {
  public:
    // 迭代器
    typedef char *iterator;
    typedef const char *const_iterator;

  public:
    // 带有缺省值的默认构造函数
    string(const char *str = "")
        : _size(strlen(str))
    {
      _capacity = _size;
      _str = new char[_capacity + 1]; // 多一个
      strcpy(_str, str);              // 会拷贝 '\0' 的
    }

  public:
    // 迭代器操作
    iterator begin()
    {
      return _str;
    }
    const_iterator cbegin() const
    {
      return _str;
    }
    iterator end()
    {

      return _str + _size; // 注意,我们end指向的是最后一个有效元素的下一个位置
    }
    // 这里解释一下,我们为何返回const_iterator就一定是不可以修改的迭代器
    // 这是因为我们使用string::const_iterator 进行接受,但是如果你要是强制类型转换,在我们这里手写的可以,但是在STL不行,毕竟他是复用了迭代器
    const_iterator cend() const
    {
      return _str + _size;
    }

  private:
    char *_str;            //   存储字符的空间
    std::size_t _size;     //   有效字符的长度
    std::size_t _capacity; //   能够存储 有效数组的长度
  };
}