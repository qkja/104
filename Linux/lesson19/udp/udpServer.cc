/**
 * User: Qkj
 * Description:
 * Date: 2023-08-18
 * Time: 19:57
 */
#include "udpServer.hpp"

static void Usage(const std::string proc)
{
  std::cout << "Usage:\n\t" << proc << "  port [ip]  " << std::endl;
}

int main(int argc, char *argv[])
{
  if (argc != 2 && argc != 3)
  {
    Usage(argv[0]);
    exit(3);
  }
  int port = atoi(argv[1]);
  std::string ip;
  if (argc == 3)
  {
    ip = argv[2];
  }

  UDPServer ser(port, ip);
  ser.init();
  ser.start();
  return 0;
}