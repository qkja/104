/**
 * User: Qkj
 * Description:
 * Date: 2023-08-23
 * Time: 17:23
 */
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main()
{

  char buffer[100] = {0};
  string str;
  while (1)
  {
    ssize_t s = read(0, buffer, 100);
    buffer[s - 1] = 0;
    // str.insert(str.size(), buffer, s - 1);
    str += buffer;
    cout << str.size() << " : " << str << endl;
  }

  //  printf("%d %s,", strlen(buffer), buffer);
  return 0;
}
