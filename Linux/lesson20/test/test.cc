/**
 * User: Qkj
 * Description:
 * Date: 2023-08-20
 * Time: 10:50
 */
#include <unistd.h>
#include <iostream>
#include <sys/types.h> /* See NOTES */
#include <string>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <signal.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

void handlerHTTPRequest(int sock)
{
  char buffer[10240];
  ssize_t s = read(sock, buffer, sizeof buffer);
  if (s > 0)
    cout << buffer;
  handlerHTTPRequest2(sock);
}

void handlerHTTPRequest2(int sock)
{
  std::string response;
  response = "HTTP/1.0 302 Temporarily Moved\r\n";
  response += "Location: HTTPS://www.qq.com\r\n";
  response += "\r\n";

  send(sock, response.c_str(), response.size(), 0);
}
class ServerTcp
{
public:
  ServerTcp(uint16_t port, const std::string &ip = "")
      : port_(port),
        ip_(ip),
        listenSock_(-1)
  {
    quit_ = false;
  }
  ~ServerTcp()
  {
    if (listenSock_ >= 0)
      close(listenSock_);
  }

public:
  void init()
  {
    // 1. 创建socket
    listenSock_ = socket(PF_INET, SOCK_STREAM, 0);
    if (listenSock_ < 0)
    {
      exit(1);
    }
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
      exit(2);
    }

    // 3. 监听socket,为何要监听呢？tcp是面向连接的!
    if (listen(listenSock_, 5 /*后面再说*/) < 0)
    {
      exit(3);
    }
    // 运行别人来连接你了
  }
  void loop()
  {
    signal(SIGCHLD, SIG_IGN); // only Linux
    while (!quit_)
    {
      struct sockaddr_in peer;
      socklen_t len = sizeof(peer);

      int serviceSock = accept(listenSock_, (struct sockaddr *)&peer, &len);
      if (quit_)
        break;
      if (serviceSock < 0)
      {
        // 获取链接失败
        cerr << "accept error ...." << endl;
        continue;
      }
      // 5.1 v1 版本 -- 多进程版本 -- 父进程打开的文件会被子进程继承吗？会的
      pid_t id = fork();
      assert(id != -1);
      if (id == 0)
      {
        close(listenSock_); // 建议
        if (fork() > 0)
          exit(0);
        // 孙子进程
        handlerHTTPRequest(serviceSock);
        exit(0); // 进入僵尸
      }
      close(serviceSock);
      wait(nullptr);
    }
  }

  bool quitServer()
  {
    quit_ = true;
    return true;
  }

private:
  // sock
  int listenSock_;
  // port
  uint16_t port_;
  // ip
  std::string ip_;
  // 安全退出
  bool quit_;
};

int main()
{
  ServerTcp ser(8080);
  ser.init();
  ser.loop();
  return 0;
}
