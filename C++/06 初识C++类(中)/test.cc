#include <iostream>
#include <string>
using namespace std;
class A
{
public:
  A()
  {
    a = 0;
    cout << "无参构造函数" << endl;

  }
  void Print()
  {
    cout << "无参构造函数" << endl;
    cout << "a = " << a << endl;
  }

public:
  int a;
};

int main()
{
   A a();
  // A a; //  为什么  不是 写   A a()?
  // a.Print();
  return 0;
}