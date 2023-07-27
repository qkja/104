/**
 * User: Qkj
 * Description: 动态内存
 * Date: 2023-07-18
 * Time: 14:02
 */

// char *GetMemory(void)
// {
// 	char p[] = "hello world";
// 	return p;
// }
// void Test(void)
// {
// 	char *str = NULL;
// 	str = GetMemory();
// 	printf(str);
// }

// 【题目名称】

// 找单身狗

// 【题目内容】

// 一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。

// 编写一个函数找出这两个只出现一次的数字。
#include <stdio.h>
// #include <stdio.h>

// int main()
// {
//   int arr[] = {2, 2, 1, 1, 3, 4, 4, 3, 10, 11};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   int ret = 0;
//   for (size_t i = 0; i < len; i++)
//   {
//     ret ^= arr[i];
//   }

//   // 找到 最后一个1
//   int count = 0;
//   while (0 == ((ret >> count) & 1))
//   {
//     count++;
//   }
//   ret = (1 << count);
//   int a = 0;
//   int b = 0;
//   for (int i = 0; i < len; i++)
//   {
//     if ((arr[i] & ret) == 0)
//     {
//       a ^= arr[i];
//     }
//     else
//     {
//       b ^= arr[i];
//     }
//   }
//   printf("%d %d\n", a, b);
//   return 0;
// }

// char * my_strncpy ( char * destination, const char * source, size_t num )
// {
//   for (size_t i = 0; i < num; i++)
//   {
//     destination[i] = source[i];
//   }
//   return destination;
// }

// char *strncat(char *destination, const char *source, size_t num)
// {

//   for (size_t i = 0; i < num; i++)
//   {
//     destination[i+strlen(destination)] = source[i];
//   }
//   return destination;
// }
// int atoi(const char *str)
// {
//   int falg = 1;
//   int i = 0;
//   if (*str == '-')
//   {
//     i++;
//     falg = -1;
//   }
//   int ret = 0;
//   for (; i < strlen(str); i++)
//   {
//     if (str[i] < '0' || str[i] > '9')
//       return -1;
//     ret = ret * 10 + str[i] - '0';
//   }
//   return ret;
// }

