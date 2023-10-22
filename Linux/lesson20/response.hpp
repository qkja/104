#ifndef __RESPONSE_HPP__
#define __RESPONSE_HPP__
#include "format.hpp"

// 响应
class Response
{
public:
  Response() : exitCode_(0), result_(0)
  {
  }
  ~Response()
  {
  }
  // 序列化 -- 不仅仅是在网络中应用,本地也是可以直接使用的!
  void serialize(std::string *out)
  {
    // "exitCode_ result_"
    std::string ec = std::to_string(exitCode_);
    std::string res = std::to_string(result_);

    *out = ec;
    *out += SPACE;
    *out += res;
  }

public:
  // 反序列化
  bool deserialize(std::string &in)
  {
    // "0 100"
    std::size_t pos = in.find(SPACE);
    if (std::string::npos == pos)
      return false;
    std::string codestr = in.substr(0, pos);
    std::string reststr = in.substr(pos + SPACE_LEN);

    // 将反序列化的结果写入到内部成员中,形成结构化数据
    exitCode_ = atoi(codestr.c_str());
    result_ = atoi(reststr.c_str());
    return true;
  }

  void debug()
  {
    std::cout << "#################################" << std::endl;
    std::cout << "exitCode_: " << exitCode_ << std::endl;
    std::cout << "result_: " << result_ << std::endl;
    std::cout << "#################################" << std::endl;
  }

public:
  // 退出状态,0标识运算结果合法,非0标识运行结果是非法的,!0是几就表示是什么原因错了!
  int exitCode_;
  // 运算结果
  int result_;
};
#endif
