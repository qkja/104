#ifndef __EXECCOMMAND_HPP__
#define __EXECCOMMAND_HPP__
#include "../util.hpp"
void execCommand(int sock, const std::string &clientIp, uint16_t clientPort)
{
  assert(sock >= 0);
  assert(!clientIp.empty());
  assert(clientPort >= 1024);

  char command[BUFFER_SIZE];
  while (true)
  {
    ssize_t s = read(sock, command, sizeof(command) - 1); // 我们认为我们读到的都是字符串
    if (s > 0)
    {
      command[s] = '\0';
      logMessage(DEBUG, "[%s:%d] exec [%s]", clientIp.c_str(), clientPort, command);
      // 考虑安全
      std::string safe = command;
      if ((std::string::npos != safe.find("rm")) || (std::string::npos != safe.find("unlink")))
      {
        break;
      }
      // 我们是以r方式打开的文件,没有写入
      // 所以我们无法通过dup的方式得到对应的结果
      FILE *fp = popen(command, "r");
      if (fp == nullptr)
      {
        logMessage(WARINING, "exec %s failed, beacuse: %s", command, strerror(errno));
        break;
      }
      char line[1024];
      while (fgets(line, sizeof(line) - 1, fp) != nullptr)
      {
        write(sock, line, strlen(line));
      }
      // dup2(fd, 1);
      // dup2(sock, fp->_fileno);
      // fflush(fp);
      pclose(fp);
      logMessage(DEBUG, "[%s:%d] exec [%s] ... done", clientIp.c_str(), clientPort, command);
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