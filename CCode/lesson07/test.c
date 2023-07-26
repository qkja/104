/**
 * User: Qkj
 * Description: 指针初阶
 * Date: 2023-07-18
 * Time: 14:02
 */
#include <stdio.h>

// struct stu
// {
//   int num;
//   char name[10];
//   int age;
// };

// void fun(struct stu *p)
// {
//   printf("%s\n", (*p).name);
//   return;
// }

// int main()
// {
//   struct stu students[3] = {{9801,"zhang", 20},
//                             {9802,"wang", 19},
//                             {9803,"zhao", 18}};
//   fun(students + 1);
//   return 0;
// }

// #include <stdio.h>
// struct S
// {
//   int a;
//   int b;
// };
// int main()
// {
//   struct S a, *p = &a;
//   a.a = 99;
//   printf("%d\n", __________);
//   return 0;
// }

// struct student
// {
//   int num;
//   char name[32];
//   float score;
// }stu;

// unsigned long pulArray[] = {6, 7, 8, 9, 10};
// unsigned long *pulPtr;
// pulPtr = pulArray;
// *(pulPtr + 3) += 3;
// printf(“% d, % d\n”, *pulPtr, *(pulPtr + 3));

// 【题目名称】

// 喝汽水问题

// 【题目内容】

// 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）。

// #include <stdio.h>
// #include <string.h>
// int main()
// {
//   char arr[10001] = {0};
//   gets(arr);
//   int left = 0;
//   int right = strlen(arr) - 1;
//   while (left < right)
//   {
//     char ret = arr[left];
//     arr[left] = arr[right];
//     arr[right] = ret;
//     left++;
//     right--;
//   }
//   printf("%s\n", arr);
//   return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//   for (int i = 0; i < 13; i++)
//   {
//     // 打印空格
//     for (int j = abs(6 - i); j > 0; j--)
//     {
//       printf(" ");
//     }
//     // 打印星号
//     for (int j = 13 - abs(6 - i) * 2; j > 0; j--)
//     {
//       printf("*");
//     }
//     printf("\n");
//   }
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n = 0;
  scanf("%d", &n);
  printf("%d\n", 2 * n - 1);
  return 0;
}