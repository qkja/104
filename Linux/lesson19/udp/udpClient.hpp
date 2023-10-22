#ifndef __UDPCLIENT_HPP__
#define __UDPCLIENT_HPP__
#include <string>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <assert.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

class UDPClient
{
public:
  UDPClient(std::string server_ip, std::uint16_t server_port)
      : _server_ip(server_ip), _server_port(server_port)
  {
  }

public:
  void init()
  {
    // 初始化客户端

    _fd = socket(AF_INET, SOCK_DGRAM, 0);
    assert(_fd > 0);

    bzero(&_server, sizeof _server);
    _server.sin_family = AF_INET;
    _server.sin_port = htons(_server_port);
    _server.sin_addr.s_addr = inet_addr(_server_ip.c_str());
  }
  void start()
  {
    std::string buffer;
    while (true)
    {
      // std::cout << "我已经好了"<< std::endl;
      // sleep(1);
      std::cerr << "Please Enter# ";
      std::getline(std::cin, buffer);
      // 发送消息给server
      // std::cout << buffer <<std::endl;
      sendto(_fd, buffer.c_str(), buffer.size(), 0,
             (const struct sockaddr *)&_server, sizeof(_server)); // 首次调用sendto函数的时候,我们的client会自动bind自己的ip和port
    }
  }

private:
  int _fd;
  std::string _server_ip;
  std::uint16_t _server_port;
  struct sockaddr_in _server;
};
#endif