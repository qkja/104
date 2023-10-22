#ifndef __NETCAL_HPP__
#define __NETCAL_HPP__
#include "../util.hpp"
#include "../../request.hpp"
#include "../../response.hpp"
#include "../../package.hpp"
#include "../../unpack.hpp"
static Response calculator(const Request &req)
{
  Response resp;
  switch (req._op)
  {
  case '+':
    resp.result_ = req._one + req._two;
    break;
  case '-':
    resp.result_ = req._one - req._two;
    break;
  case '*':
    resp.result_ = req._one * req._two;
    break;
  case '/':
  { // x_ / y_
    if (req._two == 0)
      resp.exitCode_ = -1; // -1. 除0
    else
      resp.result_ = req._one / req._two;
  }
  break;
  case '%':
  { // x_ / y_
    if (req._two == 0)
      resp.exitCode_ = -2; // -2. 模0
    else
      resp.result_ = req._one % req._two;
  }
  break;
  default:
    resp.exitCode_ = -3; // -3: 非法操作符
    break;
  }

  return resp;
}

void netCalServer(int sock, const std::string &clientIp, uint16_t clientPort)
{
  assert(sock >= 0);
  assert(!clientIp.empty());
  assert(clientPort >= 1024);

  // 9\r\n100 + 200\r\n    9\r\n112 / 200\r\n
  std::string inbuffer;
  while (true)
  {
    char buff[128];
    ssize_t s = read(sock, buff, sizeof(buff) - 1);

    if (s == 0)
    {
      logMessage(NOTICE, "client[%s:%d] close sock, service done", clientIp.c_str(), clientPort);
      break;
    }
    else if (s < 0)
    {
      logMessage(WARINING, "read client[%s:%d] error, errorcode: %d, errormessage: %s",
                 clientIp.c_str(), clientPort, errno, strerror(errno));
      break;
    }

    // read success
    buff[s] = 0;
    inbuffer += buff;
    std::cout << "inbuffer: " << inbuffer << std::endl;

    // 1. 检查inbuffer是不是已经具有了一个strPackage
    uint32_t packageLen = 0;
    std::string package = decode(inbuffer, &packageLen); // 去掉报头
    if (packageLen == 0)
      continue; // 无法提取一个完整的报文,继续努力读取吧

    std::cout << "package: " << package << std::endl;
    Request req;
    // 2. 已经获得一个完整的package
    if (req.deserialize(package)) // 反序列化
    {
      req.debug();
      // 3. 处理逻辑, 输入的是一个req,得到一个resp
      Response resp = calculator(req); // resp是一个结构化的数据
      // 4. 对resp进行序列化
      std::string respPackage;
      resp.serialize(&respPackage);
      // 5. 对报文进行encode --
      respPackage = encode(respPackage, respPackage.size());
      // 6. 简单进行发送 -- 后续处理
      write(sock, respPackage.c_str(), respPackage.size()); // 把结果写回去
    }
  }
}

static bool makeReuquest(const std::string &str, Request *req)
{
#define OPS "+-*/"
  // 123+1  1*1 1/1
  char strtmp[BUFFER_SIZE];
  snprintf(strtmp, sizeof strtmp, "%s", str.c_str());
  char *left = strtok(strtmp, OPS);
  if (!left)
    return false;
  char *right = strtok(nullptr, OPS);
  if (!right)
    return false;
  char mid = str[strlen(left)];

  req->_one = atoi(left);
  req->_two = atoi(right);
  req->_op = mid;
  return true;
}

void netCalClient(int fd)
{
  volatile bool quit = false;
  std::string message;
  printf("请输入形如 1+1 这样的信息\n");
  while (!quit)
  {
    message.clear();
    std::cout << "请输入你的消息>>> ";
    std::getline(std::cin, message);
    if (strcasecmp(message.c_str(), "quit") == 0)
    {
      quit = true;
      break;
    }

    Request req;
    if (makeReuquest(message, &req) == false)
    {
      std::cerr << "输入错误" << std::endl;
      continue;
    }
    req.serialize(&message);                   // 序列化
    message = encode(message, message.size()); // 封装
    ssize_t s = write(fd, message.c_str(), message.size());

    if (s > 0)
    {
      message.resize(1024);
      ssize_t ss = read(fd, (char *)(message.c_str()), 1024);
      if (ss > 0)
        message[ss] = 0;

      uint32_t packageLen = 0;
      message = decode(message, &packageLen); // 去掉报头
      if (packageLen == 0)
        continue; // 无法提取一个完整的报文,继续努力读取吧
      Response resp;
      resp.deserialize(message);

      std::cout << "Server Echo>>> "
                << "_exitcode: " << resp.exitCode_ << "result: " << resp.result_ << std::endl;
    }
    else if (s <= 0)
    {
      break;
    }
  }
}

#endif