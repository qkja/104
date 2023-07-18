/**
 * User: Qkj
 * Description: 初始C语言 下
 * Date: 2023-07-15
 * Time: 09:40
 */
// #include <stdio.h>
// int sum(int a)
// {
//     int c = 0;
//     static int b = 3;
//     c += 1;
//     b += 2;
//     return (a + b + c);
// }
// int main()
// {
//     int i;
//     int a = 2;
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d,", sum(a));
//     }
// }
// https://www.nowcoder.com/practice/5cd9598f28f74521805d2069ce4a108a?tpId=107&&tqId=33287&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
// #include <stdio.h>

// int main()
// {
//   printf("     **     \n");
//   printf("     **     \n");
//   printf("************\n");
//   printf("************\n");
//   printf("    *  *    \n");
//   printf("    *  *    \n");
//   return 0;
// }
// https://www.nowcoder.com/practice/a4f527b043c04551bf4b80b4275a53bd?tpId=107&&tqId=33364&rp=1&ru=/ta/beginner-programmers&qru=/ta/beginner-programmers/question-ranking
#include <stdio.h>

int main()
{
  int a = 0;
  scanf("%d", &a);
  if (a % 5 == 0)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}