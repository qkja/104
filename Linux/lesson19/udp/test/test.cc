/**
 * User: Qkj
 * Description:
 * Date: 2023-08-18
 * Time: 19:32
 */
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
using namespace std;

using namespace std;
int main()
{
  std::string buffer;

  // std::cout << "我已经好了"<< std::endl;
  // sleep(1);
  std::cerr << "Please Enter# ";
  std::getline(std::cin, buffer);
  cout << buffer;
  return 0;
}
// int main()
// {
//   int fd = socket(AF_INET, SOCK_DGRAM, 0);
//   cout << fd << endl;
//   struct sockaddr_in addr;
//   return 0;
// }
