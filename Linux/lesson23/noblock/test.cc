/**
 * User: Qkj
 * Description:
 * Date: 2023-08-21
 * Time: 20:26
 */
#include "./../util.hpp"
#include <errno.h>
#include <string.h>
using namespace Util;
using namespace std;
// int main()
// {
//   SetNonBlock(0);
//   char buffer[1024];
//   while (true)
//   {
//     buffer[0] = 0;
//     scanf("%s", buffer);
//     cout << "刚刚获取的字符# " << buffer << endl;
//     sleep(1);
//   }

//   return 0;
// }

int main()
{
  SetNonBlock(0);
  char buffer[1024];
  while (true)
  {
    buffer[0] = 0;
    int n = scanf("%s", buffer);
    if (-1 == n)
    {
      cout << "errno " << errno << "desc " << strerror(errno) << endl;
    }
    cout << "刚刚获取的字符# " << buffer << endl;
    sleep(1);
  }

  return 0;
}