#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__
#include "format.hpp"
// 封装
// 请求: 132 + 1234
// 响应: "exitCode_ result_"

std::string encode(const std::string &in, uint32_t len)
{
  // "exitCode_ result_"
  // "len\r\n""exitCode_ result_\r\n"
  std::string encodein = std::to_string(len);
  encodein += CRLF;
  encodein += in;
  encodein += CRLF;
  return encodein;
}
#endif