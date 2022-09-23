#include <stdio.h>
int* f()
{
  int a = 100;
  return &a;
}
int main()
{
  int * p = f();

  printf("%d\n",*p);
  printf("%d\n",*p);

  return 0;
}
//int main()
//{
//  // 解引用  访问几个字节
//  // + 1 跳过几个字节 为何是这样的  这是很合适的  
//  // 野指针
//  int a; // 有的编译器是随机值  或者都不能编译成功
//  int* p;
//  *p = 20; 
//  printf("%d",a);
//  return 0;
//}


//int main()
//{
//  // 32为地址线 可以管理多少内存
//  // 2^32 / 1024 = kb => 4gb 的大小  64位是16g的内存
//  // 保存地址  32位的空间  4个字节
//  // 64位是 8个字节
//  
//  return 0;
//}

//int main()
//{
//  // 指针  32位地址线 对应2^32的编号 
//  // 我们把指针,地址,编号都认为是指针
//  int a = 10;
//  int *p = NULL;
//  // 这里p里面存储的就是 a的地址,也可以说p就是a的地址
//  p = &a;
//  printf("%p\n",p);
//  printf("%d\n",p);
//  return 0;
//}
