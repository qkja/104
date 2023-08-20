#ifndef __ECHO_HPP__
#define __ECHO_HPP__
#include "../util.hpp"
void echo(int fd)
{
  volatile bool quit = false;

  std::string message;
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

    ssize_t s = write(fd, message.c_str(), message.size());
    if (s > 0)
    {
      message.resize(1024);
      ssize_t ss = read(fd, (char *)(message.c_str()), 1024);
      if (ss > 0)
        message[ss] = 0;
      std::cout << "Server Echo>>> " << message << std::endl;
    }
    else if (s <= 0)
    {
      break;
    }
  }
}

#endif
