#pragma once
// 这是业务逻辑
#include "netcalculator_split.hpp"
using sevice_t = std::function<Response(const Request &req)>;

Response calculator(const Request &req)
{
  Response resp = {0, 0};
  switch (req.op)
  {
  case '+':
    resp.result = req.x + req.y;
    break;
  case '-':
    resp.result = req.x - req.y;
    break;
  case '*':
    resp.result = req.x * req.y;
    break;
  case '/':
  { // x_ / y_
    if (req.y == 0)
      resp.exit_code = -1; // -1. 除0
    else
      resp.result = req.x / req.y;
  }
  break;
  case '%':
  { // x_ / y_
    if (req.y == 0)
      resp.exit_code = -2; // -2. 模0

    else
      resp.result = req.x % req.y;
  }
  break;
  default:
    resp.exit_code = -3; // -3: 非法操作符
    break;
  }

  return resp;
}

Response GET(const Request &req)
{
  
}
// GET
// POST
// 