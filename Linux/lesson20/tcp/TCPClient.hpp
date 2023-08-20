#ifndef __TCPCLIENT_HPP__
#define __TCPCLIENT_HPP__

#include "util.hpp"

class TCPClient
{

public:
  using callback_t = std::function<void(int)>;

  TCPClient(callback_t func, std::string serverIp, std::uint16_t serverPort)
      : _func(func), _serverIp(serverIp), _serverPort(serverPort), _fd(0) {}
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
    _func(_fd);
  }

private:
  int _fd;
  std::uint16_t _serverPort;
  std::string _serverIp;
  struct sockaddr_in _server;
  callback_t _func;
};

#endif
