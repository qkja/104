#ifndef __TCPCLIENT_HPP__
#define __TCPCLIENT_HPP__

#include "util.hpp"

class TCPClient
{

public:
  TCPClient(std::string serverIp, std::uint16_t serverPort)
      : _serverIp(serverIp), _serverPort(serverPort), _fd(0) {}
  ~TCPClient()
  {
    close(_fd);
  }

public:
  void init()
  {
    // 1. 创建socket SOCK_STREAM
    _fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_fd < 0)
    {
      std::cerr << "socket: " << strerror(errno) << std::endl;
      exit(SOCKET_ERR);
    }

    memset(&_server, 0, sizeof(_server));
    _server.sin_family = AF_INET;
    _server.sin_port = htons(_serverPort);
    inet_aton(_serverIp.c_str(), &_server.sin_addr);

    if (connect(_fd, (const struct sockaddr *)&_server, sizeof(_server)) != 0)
    {
      std::cerr << "connect: " << strerror(errno) << std::endl;
      exit(CONN_ERR);
    }

    std::cout << "info : connect success: " << _fd << std::endl;
  }
  
  void start()
  {
    volatile bool quit = false;

    std::string message;
    while (!quit)
    {
      message.clear();
      std::cout << "请输入你的消息>>> ";
      std::getline(std::cin, message);
      if (strcasecmp(message.c_str(), "quit") == 0)
        quit = true;

      ssize_t s = write(_fd, message.c_str(), message.size());
      if (s > 0)
      {
        message.resize(1024);
        ssize_t ss = read(_fd, (char *)(message.c_str()), 1024);
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

private:
  int _fd;
  std::uint16_t _serverPort;
  std::string _serverIp;
  struct sockaddr_in _server;
};

#endif
