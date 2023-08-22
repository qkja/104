/**
 * User: Qkj
 * Description:
 * Date: 2023-08-21
 * Time: 20:59
 */
#include <iostream>
#include "./Sock.hpp"
#include <poll.h>
#include <unistd.h>
using namespace std;
#define NUM 1024
#define DFL -1

struct pollfd fdsArray[NUM] = {0};
static void show()
{
  cout << "已保存的fd: ";
  for (int i = 0; i < NUM; i++)
  {
    if (fdsArray[i].fd != DFL)
      cout << fdsArray[i].fd << " ";
  }
  cout << endl;
}

static void Usage(std::string proc)
{
  std::cerr << "Usage:\n\t" << proc << " port " << std::endl;
}

static void HandlerEvent(int listensock)
{
  for (int i = 0; i < NUM; i++)
  {
    if (fdsArray[i].fd == DFL)
      continue;
    if (i == 0 && fdsArray[i].fd == listensock)
    {
      if (fdsArray[i].revents & POLLIN)
      {

        std::string clientip;
        std::uint16_t clientport;
        int sock = Sock::Accept(listensock, &clientip, &clientport);

        cout << "获取成功fd: " << sock << endl;
        // sleep(3);

        int j = 0;
        for (; j < NUM; j++)
        {
          if (fdsArray[j].fd == DFL)
          {
            fdsArray[j].fd = sock;
            fdsArray[j].events = POLLIN;
            fdsArray[j].revents = 0;
            break;
          }
        }

        if (j == NUM)
        {
          cout << "我的服务器易已经到了最大的上线了" << endl;
          close(sock);
        }
        else
        {
          cout << "已经添加了" << endl;
          show();
        }
      }
    } // end  if (i == 0 && fdsArray[i] == listensock)
    else
    {
      // 一定是一个 文件
      if (fdsArray[i].revents & POLLIN)
      {
        // cout << "----------------" << endl;
        // sleep(3);
        // 一定是一个 合法 就绪了
        char buffer[1024] = {0};
        ssize_t s = read(fdsArray[i].fd, buffer, 1023); // 这里不是所有的报文,我么不不能保证
        // cout << "----------------" << endl;
        // sleep(3);

        if (s > 0)
        {
          buffer[s] = 0;
          cout << "发送: " << buffer;
        }
        else if (0 == s)
        {
          close(fdsArray[i].fd);
          fdsArray[i].fd = DFL;
          fdsArray[i].events = 0;
          fdsArray[i].revents = 0;
        }
        else
        {
        }
      }
    }
  }
}

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    Usage(argv[0]);
    exit(-1);
  }

  std::uint16_t port = atoi(argv[1]);
  int listenSock = Sock::Socket();
  Sock::Bind(listenSock, port);
  Sock::Listen(listenSock);

  for (int i = 0; i < NUM; i++)
  {
    fdsArray[i].fd = DFL;
    fdsArray[i].events = 0;
    fdsArray[i].revents = 0;
  }
  fdsArray[0].fd = listenSock;
  fdsArray[0].events = POLLIN; // 关心时间位poll
  while (true)
  {

    int n = poll(fdsArray, NUM, 1000); // 100 为毫秒

    switch (n)
    {
    case 0:
      cout << "time out..." << endl;
      break;
    case -1:
      cerr << errno << endl;
      // sleep(1);
      break;
    default:
      HandlerEvent(listenSock);
      break;
    }
  }
  return 0;
}
