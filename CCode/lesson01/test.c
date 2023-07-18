/**
 * User: Qkj
 * Description: 初始C语言 上
 * Date: 2023-07-15
 * Time: 09:40
 */
// #include <stdio.h>
// int num = 10;
// int main()
// {
//     int num = 1;
//     printf("num = %d\n", num);
// 	return 0;
// }

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//     printf("%d\n", strlen("c:\test\121"));
//     printf("%d\n", sizeof("c:\test\121"));
//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char arr[] = {'b', 'i', 't'};
//     printf("%d\n", strlen(arr));
// 	return 0;
// }

// 【题目名称】

// 求两个数的较大值

// 【题目内容】

// 写一个函数求两个整数的较大值

// 如：

// 输入：10 20

// 输出较大值：20
#include <stdio.h>

int max_two_num(int x, int y)
{
  if (x > y)
    return x;
  return y;
}
int main()
{
  int a = 10;
  int b = 20;
  printf("max: %d\n", max_two_num(a, b));
  return 0;
}
