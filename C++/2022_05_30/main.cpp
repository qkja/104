#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

int main()
{
  string str1 = "aaa";
  string str2 = "aaa";
  cout << sizeof(str1) << endl;
  cout << sizeof(str2) << endl;
  cout << (str1 == str2) << endl;
  cout << "&str1 : " << &str1  << endl;
  cout << "&str2 : " << &str2  << endl;
  return 0;
}
