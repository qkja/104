#ifndef __UNPACK_HPP__
#define __UNPACK_HPP__
#include "format.hpp"

// 解包

// decode,整个序列化之后的字符串进行提取长度
// 1. 必须具有完整的长度
// 2. 必须具有和len相符合的有效载荷
// 我们才返回有效载荷和len
// 否则,我们就是一个检测函数!
// 9\r\n100 + 200\r\n    9\r\n112 - 200\r\n
std::string decode(std::string &in, uint32_t *len)
{
  assert(len);
  // 1. 确认是否是一个包含len的有效字符串
  *len = 0;
  std::size_t pos = in.find(CRLF);
  if (pos == std::string::npos)
    return ""; // 1234\r\nYYYYY for(int i = 3; i < 9 ;i++) [)
  // 2. 提取长度
  std::string inLen = in.substr(0, pos);
  int intLen = atoi(inLen.c_str());
  // 3. 确认有效载荷也是符合要求的
  int surplus = in.size() - 2 * CRLF_LEN - pos;
  if (surplus < intLen)
    return "";
  // 4. 确认有完整的报文结构
  std::string package = in.substr(pos + CRLF_LEN, intLen);
  *len = intLen;
  // 5. 将当前报文完整的从in中全部移除掉
  int removeLen = inLen.size() + package.size() + 2 * CRLF_LEN;
  in.erase(0, removeLen);
  // 6. 正常返回
  return package;
}
#endif