#ifndef __TCPSERVER_HPP__
#define __TCPSERVER_HPP__
#include "log.hpp"
#include "util.hpp"

class ServerTCP
{
public:
  using callback_t = std::function<void(int, std::string, uint16_t)>;

public:
  ServerTCP(callback_t func, uint16_t port, const std::string &ip = "")
      : func_(func), port_(port), ip_(ip), tp_(nullptr), listenSock_(-1)
  {
  }
  ~ServerTCP()
  {
  }

public:
  void init()
  {
    // 1. 创建socket
    listenSock_ = socket(PF_INET, SOCK_STREAM, 0);
    if (listenSock_ < 0)
    {
      logMessage(FATAL, "socket: %s", strerror(errno));
      exit(SOCKET_ERR);
    }
    logMessage(DEBUG, "socket: %s, %d", strerror(errno), listenSock_);

    // 2. bind绑定
    // 2.1 填充服务器信息
    struct sockaddr_in local; // 用户栈
    memset(&local, 0, sizeof local);
    local.sin_family = PF_INET;
    local.sin_port = htons(port_);
    ip_.empty() ? (local.sin_addr.s_addr = INADDR_ANY) : (inet_aton(ip_.c_str(), &local.sin_addr));
    // 2.2 本地socket信息,写入sock_对应的内核区域
    if (bind(listenSock_, (const struct sockaddr *)&local, sizeof local) < 0)
    {
      logMessage(FATAL, "bind: %s", strerror(errno));
      exit(BIND_ERR);
    }
    logMessage(DEBUG, "bind: %s, %d", strerror(errno), listenSock_);

    // 3. 监听socket,为何要监听呢？TCP是面向连接的！
    if (listen(listenSock_, 5 /*后面再说*/) < 0)
    {
      logMessage(FATAL, "listen: %s", strerror(errno));
      exit(LISTEN_ERR);
    }
    logMessage(DEBUG, "listen: %s, %d", strerror(errno), listenSock_);
    // 运行别人来连接你了

    // 4. 加载线程池
    tp_ = ThreadPool<Task>::getInstance();
  }

  void loop()
  {
    tp_->start();
    logMessage(DEBUG, "thread pool start success, thread num: %d", tp_->threadNum());
    while (true)
    {
      struct sockaddr_in peer;
      socklen_t len = sizeof(peer);
      // 4. 获取连接, accept 的返回值是一个新的socket fd ？？
      // 4.1 listenSock_: 监听 && 获取新的链接-> sock
      // 4.2 serviceSock: 给用户提供新的socket服务
      int serviceSock = accept(listenSock_, (struct sockaddr *)&peer, &len);
      if (serviceSock < 0)
      {
        // 获取链接失败
        logMessage(WARINING, "accept: %s[%d]", strerror(errno), serviceSock);
        continue;
      }
      // 4.1 获取客户端基本信息
      uint16_t peerPort = ntohs(peer.sin_port);
      std::string peerIp = inet_ntoa(peer.sin_addr);

      logMessage(DEBUG, "accept: %s | %s[%d], socket fd: %d",
                 strerror(errno), peerIp.c_str(), peerPort, serviceSock);

      // 创建任务
      Task t(serviceSock, peerIp, peerPort, func_);
      // 提交任务
      tp_->push(t);
    }
  }

private:
  // sock
  int listenSock_;
  // port
  uint16_t port_;
  // ip
  std::string ip_;
  // 引入线程池
  ThreadPool<Task> *tp_;
  callback_t func_;
};

#endif