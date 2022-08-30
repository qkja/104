#include <iostream>
#include <stdio.h>

class B
{
public:
  virtual void func()
  {

  }

};

int g_val1 = 1; // 已初始化
int g_val2;     // 未初始化
int main()
{
  // 栈区
  int a = 10;

  // 堆区
  int* p1 = new int;
  
  // 字符常量区
  const char* ptr = "abdve";

  printf("代码区              %p\n", main);
  printf("字符常量区          %p\n", ptr);
  printf("已初始化全局变量区  %p\n", &g_val1);
  printf("未初始化全局变量区  %p\n", &g_val2);
  printf("堆区                %p\n", p1);
  printf("栈区                %p\n", &a);

  // 打印 一下 虚函数表
  B b;
  printf("虚表地址 %p\n",*(long long*)(&b));

  
  
  delete p1;
  return 0;
}
