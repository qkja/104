/**
 * User: Qkj
 * Description:
 * Date: 2023-08-22
 * Time: 16:10
 */
#include "EpollServer.hpp"
#include <memory>
static void Usage(std::string proc)
{
  std::cerr << "Usage:\n\t" << proc << " port " << std::endl;
}
int myfunc(int sock)
{
  char buffer[1024] = {0};
  ssize_t s = read(sock, buffer, 1023); // 这里不是所有的报文,我么不不能保证

  if (s > 0)
  {
    buffer[s] = 0;
    logMessage(DEBUG, "client[%d]# %s", sock, buffer);
  }
  return s;
}
int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    Usage(argv[0]);
    exit(-1);
  }

  std::uint16_t port = atoi(argv[1]);

  std::unique_ptr<EpollServer> epollServer(new EpollServer(port, myfunc));
  epollServer->InitEpollServer();
  epollServer->Run();
  return 0;
}