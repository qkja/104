#ifndef __NETCALCULATOR_SPLIT_HPP__
#define __NETCALCULATOR_SPLIT_HPP__

#include "util.hpp"
#include <cstring>
#define SEP 'X'
#define SEP_LEN sizeof(SEP)
#define SPACE " "
#define SPACE_LEN strlen(SPACE)
struct Request
{
  int x;
  int y;
  char op;
};
struct Response
{
  int result;
  int exit_code;
};
bool Parser(std::string &in, struct Request *req)
{

  // 序列化
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
  req->x = atoi(dataOne.c_str());
  req->y = atoi(dataTwo.c_str());
  req->op = oper[0];
  return true;
}
// 序列化
void Serialize(std::string *out, struct Response *resp)
{
  std::string xstr = std::to_string(resp->exit_code);
  std::string ystr = std::to_string(resp->result);
  // std::string opstr = std::to_string(op_); // op_ -> char -> int -> 43 ->

  *out = xstr;
  *out += SPACE;
  *out += ystr;
  *out += "\r\n";
}
// 分割报文
// xxxxxxxxxxxxxxxx\3xxxxxxxxxxxxxxxx\3xxxx
int splitPagce(std::vector<std::string> *result, std::string &package)
{
  while (true)
  {
    std::size_t pos = package.find(SEP);
    if (pos == std::string::npos)
      break;
    result->push_back(package.substr(0, pos));
    package.erase(0, pos + SEP_LEN);
  }
  return 0;
}



#endif