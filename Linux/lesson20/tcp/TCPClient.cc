/**
 * User: Qkj
 * Description:
 * Date: 2023-08-18
 * Time: 22:54
 */
#include "TCPClient.hpp"
// #include "./task/echo.hpp"
#include "./task/netCal.hpp"

static void Usage(std::string proc)
{
  std::cerr << "Usage:\n\t" << proc << " serverIp serverPort" << std::endl;
  std::cerr << "Example:\n\t" << proc << " 127.0.0.1 8081\n"
            << std::endl;
}

// ./clientTCP serverIp serverPort
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    Usage(argv[0]);
    exit(USAGE_ERR);
  }
  std::string serverIp = argv[1];
  uint16_t serverPort = atoi(argv[2]);

  TCPClient tcpClient(netCalClient, serverIp, serverPort);
  tcpClient.init();
  tcpClient.start();
  return 0;
}
