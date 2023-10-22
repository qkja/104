#ifndef __TRANSSERVICE_HPP__
#define __TRANSSERVICE_HPP__

#include <assert.h>
#include "../log.hpp"
#include "../util.hpp"
// 大小写转化服务
// TCP && UDP: 支持全双工
void transService(int sock, const std::string &clientIp, uint16_t clientPort)
{
  assert(sock >= 0);
  assert(!clientIp.empty());
  assert(clientPort >= 1024);

  char inbuffer[BUFFER_SIZE];
  while (true)
  {
    ssize_t s = read(sock, inbuffer, sizeof(inbuffer) - 1); // 我们认为我们读到的都是字符串
    if (s > 0)
    {
      // read success
      inbuffer[s] = '\0';
      if (strcasecmp(inbuffer, "quit") == 0)
      {
        logMessage(DEBUG, "client quit -- %s[%d]", clientIp.c_str(), clientPort);
        break;
      }
      logMessage(DEBUG, "trans before: %s[%d]>>> %s", clientIp.c_str(), clientPort, inbuffer);
      // 可以进行大小写转化了
      for (int i = 0; i < s; i++)
      {
        if (isalpha(inbuffer[i]) && islower(inbuffer[i]))
          inbuffer[i] = toupper(inbuffer[i]);
      }
      logMessage(DEBUG, "trans after: %s[%d]>>> %s", clientIp.c_str(), clientPort, inbuffer);
      // 写回去
      write(sock, inbuffer, strlen(inbuffer));
    }
    else if (s == 0)
    {
      // pipe: 读端一直在读,写端不写了,并且关闭了写端,读端会如何？s == 0,代表对端关闭
      // s == 0: 代表对方关闭,client 退出
      logMessage(DEBUG, "client quit -- %s[%d]", clientIp.c_str(), clientPort);
      break;
    }
    else
    {
      logMessage(DEBUG, "%s[%d] - read: %s", clientIp.c_str(), clientPort, strerror(errno));
      break;
    }
  }

  // 只要走到这里,一定是client退出了,服务到此结束
  close(sock); // 如果一个进程对应的文件fd,打开了没有被归还,文件描述符泄漏！
  logMessage(DEBUG, "server close %d done", sock);
}
#endif