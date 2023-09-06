#include "my_string.hpp"
// const int* f()
// {
//   return new int(1);
// }
// int main()
// {
//   int* p = (int*)f();
//   delete p;
//   return 0;
// }
#include <string>
#include <iostream>
using namespace std;
int main()
{
  string str = "hello";
  string::const_iterator iter = str.cbegin();
  // *(string::iterator)iter = '3';
  cout << str << endl; 
  return 0;
}