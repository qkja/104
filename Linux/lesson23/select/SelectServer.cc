/**
 * User: Qkj
 * Description:
 * Date: 2023-08-21
 * Time: 20:59
 */
#include <iostream>
#include "./Sock.hpp"
#include <sys/select.h>
#include <unistd.h>
using namespace std;

#define DFL -1

int fdsArray[sizeof(fd_set) * 8] = {0};
int g_num = sizeof(fdsArray) / sizeof(fdsArray[0]);
static void show()
{
  cout << "已保存的fd: ";
  for (int i = 0; i < g_num; i++)
  {
    if (fdsArray[i] != DFL)
      cout << fdsArray[i] << " ";
  }
  cout << endl;
}

static void Usage(std::string proc)
{
  std::cerr << "Usage:\n\t" << proc << " port " << std::endl;
}

static void HandlerEvent(int listensock, fd_set readfds)
{
  for (int i = 0; i < g_num; i++)
  {
    if (fdsArray[i] == DFL)
      continue;
    if (i == 0 && fdsArray[i] == listensock)
    {
      if (FD_ISSET(listensock, &readfds))
      {
        // sleep(3);
        // 已经有一个新连接
        // cout << "事件就绪了" << endl;
        // sleep(3);

        std::string clientip;
        std::uint16_t clientport;
        int sock = Sock::Accept(listensock, &clientip, &clientport);

        cout << "获取成功fd: " << sock << endl;
        // sleep(3);

        int j = 0;
        for (; j < g_num; j++)
        {
          if (fdsArray[j] == DFL)
          {
            fdsArray[j] = sock;
            break;
          }
        }

        if (j == g_num)
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
      if (FD_ISSET(fdsArray[i], &readfds))
      {
        // cout << "----------------" << endl;
        // sleep(3);
        // 一定是一个 合法 就绪了
        char buffer[1024] = {0};
        ssize_t s = read(fdsArray[i], buffer, 1023); // 这里不是所有的报文,我么不不能保证
        // cout << "----------------" << endl;
        // sleep(3);

        if (s > 0)
        {
          buffer[s] = 0;
          cout << "s: " << s << "发送: " << buffer << endl;
        }
        else if (0 == s)
        {
          close(fdsArray[i]);
          fdsArray[i] = DFL;
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

  for (int i = 0; i < g_num; i++)
    fdsArray[i] = DFL;
  fdsArray[0] = listenSock;

  while (true)
  {
    int maxFd = DFL;
    fd_set readfds; // 读文件描述集
    FD_ZERO(&readfds);

    for (int i = 0; i < g_num; i++)
    {
      if (fdsArray[i] == DFL)
        continue;
      FD_SET(fdsArray[i], &readfds);
      if (fdsArray[i] > maxFd)
        maxFd = fdsArray[i];
    }

    FD_SET(listenSock, &readfds);
    struct timeval tiemout = {5, 0};
    int n = select(maxFd + 1, &readfds, nullptr, nullptr, &tiemout);

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
      HandlerEvent(listenSock, readfds);
      break;
    }
  }
  return 0;
}
