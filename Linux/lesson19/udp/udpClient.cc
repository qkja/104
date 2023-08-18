/**
 * User: Qkj
 * Description:
 * Date: 2023-08-18
 * Time: 20:54
 */
#include "udpClient.hpp"

static void Usage(std::string name)
{
  std::cout << "Usage:\n\t" << name << " server_ip server_port" << std::endl;
}
int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    Usage(argv[0]);
    exit(1);
  }

  UDPClient udpClient(argv[1], atoi(argv[2]));

  udpClient.init();
  udpClient.start();

  return 0;
}