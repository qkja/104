#ifndef __EPOLLSERVER_HPP__
#define __EPOLLSERVER_HPP__
#include <iostream>
#include <string>
#include <sys/epoll.h>
#include <cstdlib>
#include <unistd.h>
#include <functional>
#include <assert.h>
#include "Sock.hpp"
#include "log.hpp"

class EpollServer
{
public:
  static const int gszie = 128;
  static const int num = 100;
  using func_t = std::function<int(int)>;

public:
  EpollServer(std::uint16_t port, func_t func)
      : port_(port), listensock_(-1), epfd_(-1), func_(func)
  {
  }
  ~EpollServer()
  {
    if (listensock_ != -1)
      close(listensock_);
    if (epfd_ != -1)
      close(epfd_);
  }

public:
  void InitEpollServer()
  {
    listensock_ = Sock::Socket();
    Sock::Bind(listensock_, port_);
    Sock::Listen(listensock_);
    logMessage(DEBUG, "创建监听套接字成功fd: %d", listensock_);

    epfd_ = epoll_create(gszie);
    if (epfd_ < 0)
    {
      logMessage(FATAL, "%d %s", errno, strerror(errno));
      exit(4);
    }
    logMessage(DEBUG, "创建epoll成功 fd: %d", epfd_);
  }
  void HandlerEvent(struct epoll_event revs[], int n)
  {
    for (size_t i = 0; i < n; i++)
    {
      int sock = revs[i].data.fd;
      std::uint32_t event = revs[i].events;
      if (event & EPOLLIN)
      {
        // 读就绪
        if (sock == listensock_)
        {
          // 获取新链接
          std::string clientip;
          std::uint16_t clientport;
          int sockFd = Sock::Accept(listensock_, &clientip, &clientport);
          if (sockFd < 0)
          {
            logMessage(FATAL, "%d %s", errno, strerror(errno));
            continue;
          }
          struct epoll_event ev;
          ev.events = EPOLLIN;
          ev.data.fd = sockFd;
          int n = epoll_ctl(epfd_, EPOLL_CTL_ADD, sockFd, &ev);
          assert(n == 0);
          (void)n;
        }
        else
        {
          int n = func_(sock);
          if (n == 0 || n < 0)
          {
            int x = epoll_ctl(epfd_, EPOLL_CTL_DEL, sock, nullptr);
            close(sock);

            assert(x == 0);
            (void)x;
            logMessage(DEBUG, "client quit");
          }
        }
      }
    }
  }
  void Run()
  {
    struct epoll_event ev;
    ev.events = EPOLLIN;
    ev.data.fd = listensock_;

    int n = epoll_ctl(epfd_, EPOLL_CTL_ADD, listensock_, &ev);
    assert(n == 0);
    (void)n;

    struct epoll_event revs[num];
    int timeout = 1000l;
    while (true)
    {
      // n 就是就绪的队列
      int n = epoll_wait(epfd_, revs, num, timeout);
      switch (n)
      {
      case 0:
        logMessage(DEBUG, "time out ... %d", time(nullptr));
        break;
      case -1:
        logMessage(FATAL, "%d %s", errno, strerror(errno));

        break;
      default:
        HandlerEvent(revs, n);
        break;
      }
    }
  }

private:
  int epfd_;
  int listensock_;
  std::uint16_t port_;
  func_t func_;
};

#endif