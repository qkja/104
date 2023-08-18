#ifndef __UDPSERVER_HPP__
#define __UDPSERVER_HPP__
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class UDPServer
{
public:
  UDPServer(std::uint16_t port, std::string ip = "")
      : _port(port),
        _ip(ip)
  {
  }

  ~UDPServer() {}

public:
  void init()
  {
    // 1.  创建套接字
    _socketFd = socket(AF_INET, SOCK_DGRAM, 0);

    if (_socketFd < 0)
    {
      std::cout << "创建套接字失败 " << strerror(errno) << "socket" << _socketFd << std::endl;
      exit(1);
    }
    std::cout << "创建套接字成功 socket: " << _socketFd << std::endl;

    // 2. 绑定网络信息 包含ip地址 端口号 和 本地或者域间
    struct sockaddr_in local;
    bzero(&local, sizeof local); // 初始化
    local.sin_family = PF_INET;
    local.sin_port = htons(_port);
    local.sin_addr.s_addr = _ip.empty() ? INADDR_ANY : inet_addr(_ip.c_str()); // INADDR_ANY 就是0

    if (bind(_socketFd, (const sockaddr *)&local, sizeof(local)) == -1)
    {
      std::cout << "UDP 套接字bind 失败  " << strerror(errno) << std::endl;
      exit(2);
    }
    std::cout << "UDP 套接字bind 成功" << std::endl;
  }

  void start()
  {

    // while (true)
    // {
    //   std::cout << "服务器已经启动成功 fd: " << _socketFd<< std::endl;
    //   sleep(1);
    // }

    char inbuffer[1024];  // 读去信息
    char outbuffer[1024]; // 发送信息
    while (true)
    {
      memset(inbuffer, '\0', sizeof(inbuffer));
      // 正常进行网络读写
      // 谁给我发消息,我们怎么会消息
      // 后面两个参数是输出行参数
      struct sockaddr_in peer;      // 输出型参数
      socklen_t len = sizeof(peer); // 输入输出型参数
      ssize_t s = recvfrom(_socketFd, inbuffer, sizeof(inbuffer) - 1, 0, (struct sockaddr *)&peer, &len);
      if (s > 0)
      {
        inbuffer[s] = 0; // 当做字符串
      }
      else if (s == -1)
      {
        std::cerr << "读取数据失败 " << strerror(errno) << std::endl;
        continue;
      }

      // 读取成功的,除了读取到对方的数据,你还要读取到对方的网络地址[ip:port]
      std::string peerIp = inet_ntoa(peer.sin_addr); // 拿到了对方的IP
      uint16_t peerPort = ntohs(peer.sin_port);      // 拿到了对方的port
      printf("client# [%s:%d]# %s\n", peerIp.c_str(), peerPort, inbuffer);
    }
  }

private:
  int _socketFd; // fd
  std::uint16_t _port;
  std::string _ip;
};

#endif