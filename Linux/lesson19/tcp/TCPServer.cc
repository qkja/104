/**
 * User: Qkj
 * Description:
 * Date: 2023-08-18
 * Time: 22:53
 */
#include "./task/transService.hpp"
#include "TCPServer.hpp"
static void Usage(std::string proc)
{
  std::cerr << "Usage:\n\t" << proc << " port ip" << std::endl;
  std::cerr << "example:\n\t" << proc << " 8080 127.0.0.1\n"
            << std::endl;
}

// ./ServerTCP local_port local_ip
int main(int argc, char *argv[])
{
  if (argc != 2 && argc != 3)
  {
    Usage(argv[0]);
    exit(USAGE_ERR);
  }
  std::uint16_t port = atoi(argv[1]);
  std::string ip;
  if (argc == 3)
    ip = argv[2];

  ServerTCP svr(transService, port, ip);
  svr.init();
  svr.loop();
  return 0;
}