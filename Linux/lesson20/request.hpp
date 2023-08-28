#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__
#include "format.hpp"

// 请求

/// 业务: 客户端把要计算的两个加数发过去 , 然后由服务器进行计算 , 最后再把结果返回给客户端
class Request
{
public:
  Request()
  {
  }
  ~Request()
  {
  }

public:
  // 序列化
  void serialize(std::string *out)
  {
    std::string xstr = std::to_string(_one);
    std::string ystr = std::to_string(_two);

    *out = xstr;
    *out += SPACE;
    *out += _op;
    *out += SPACE;
    *out += ystr;
  }

  // 反序列化
  /// 客户端读入一段 形如  1 + 2 的字符串,
  bool deserialize(std::string &in)
  {
    // 100 + 200
    std::size_t spaceOne = in.find(SPACE);
    if (std::string::npos == spaceOne)
      return false;
    std::size_t spaceTwo = in.rfind(SPACE);
    if (std::string::npos == spaceTwo)
      return false;

    std::string dataOne = in.substr(0, spaceOne);
    std::string dataTwo = in.substr(spaceTwo + SPACE_LEN);
    std::string oper = in.substr(spaceOne + SPACE_LEN, spaceTwo - (spaceOne + SPACE_LEN));
    if (oper.size() != 1)
      return false;

    // 转成内部成员
    _one = atoi(dataOne.c_str());
    _two = atoi(dataTwo.c_str());
    _op = oper[0];
    return true;
  }

  void debug()
  {
    std::cout << "#################################" << std::endl;
    std::cout << "_one: " << _one << std::endl;
    std::cout << "_op: " << _op << std::endl;
    std::cout << "_two : " << _two << std::endl;
    std::cout << "#################################" << std::endl;
  }

public:
  int _one;
  int _two;
  char _op;
};
#endif
