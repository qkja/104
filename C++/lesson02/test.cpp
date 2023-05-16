/**
* User: Qkj
* Description: 
* Date: 2023-01-19
* Time: 13:29
*/
#include "test.h"
#include <iostream>
using namespace std;
//inline void func(double a, int b);
void func(double a, int b)
{
  int c = 10;
  c = 10;
  cout << "aaaa" <<endl;
}
int main()
{
  func(1.1, 10);
  return 0;
}






















//写两个函数   函数形成重载
//void func(int a, double b)
//{
//	printf("%d %lf", a, b);
//}
//
//void func(double a, int b)
//{
//	printf("%lf %d", a, b);
//}

// 引用看似传值,本质是传地址
