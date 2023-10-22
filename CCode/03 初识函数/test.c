/**
 * User: Qkj
 * Description: 分支和循环语句
 * Date: 2023-07-18
 * Time: 14:02
 */
// #include <stdio.h>
// int func(int a)
// {
//     int b;
//     switch (a)
//     {
//         case 1: b = 30;
//         case 2: b = 20;
//         case 3: b = 16;
//         default: b = 0;
//     }
//     return b;
// }

// int main()
// {
//   printf("%d\n", func(1));
//   return 0;
// }

// #include <stdio.h>
// int main()
// {
//   int x = 3;
//   int y = 3;
//   switch (x % 2)
//   {
//   case 1:
//     switch (y)
//     {
//     case 0:
//       printf("first");
//     case 1:
//       printf("second");
//       break;
//     default:
//       printf("hello");
//     }
//   case 2:
//     printf("third");
//   }
//   return 0;
// }

// #include <stdio.h>

// int main()
// {
// 	int i = 0;
// 	for (i = 0; i<10; i++)
// 	{
// 		if (i = 5)
// 			printf("%d ", i);
// 	}
// 	return 0;
// }
// https://www.nowcoder.com/questionTerminal/7fd309b4ab854e6e9afda4794b1334a5?
// 【题目名称】

// 最大公约数

// 【题目内容】

// 给定两个数，求这两个数的最大公约数

// 例如：

// 输入：20 40

// 输出：20
// #include <stdio.h>
// int greatest_common_divisor(int x, int y)
// {
//   while (x % y)
//   {
//     int z = x % y;
//     x = y;
//     y = z;
//   }
//   return y;
// }

// int main()
// {
//   int a, b;
//   while (scanf("%d %d", &a, &b) != EOF)
//   { // 注意 while 处理多个 case

//     printf("%d\n", greatest_common_divisor(a, b));
//   }
//   return 0;
// }

// 【题目名称】

// 打印闰年

// 【题目内容】

// 打印1000年到2000年之间的闰年
// #include <stdio.h>
// int is_leap_year(int year)
// {
//   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//     return 1;
//   return 0;
// }
// int main()
// {
//   for (int i = 1000; i < 2000; i++)
//   {
//     if (is_leap_year(i))
//     {
//       printf("%d ", i);
//     }
//   }
//   return 0;
// }

// #include <stdio.h>
// int is_prime_number(int num)
// {
//   for (int i = 2; i <= sqrt(num); i++)
//   {
//     if (num % i == 0)
//       return 0;
//   }
//   return 1;
// }
// int main()
// {
//   for (int i = 100; i < 200; i++)
//   {
//     if (is_prime_number(i))
//     {
//       printf("%d ", i);
//     }
//   }
//   return 0;
// }

// 【题目名称】

// 从大到小输出

// 【题目内容】

// 写代码将三个整数数按从大到小输出。

// 例如：

// 输入：2 3 1

// 输出：3 2 1
// #include <stdio.h>

// int main()
// {
//   int x = 0;
//   int y = 0;
//   int z = 0;

//     scanf("%d %d %d", &x, &y, & z);
//   // 先比较 x y
//   if (x > y)
//   {
//     if (z > x)
//     {
//       printf("%d %d %d\n", z, x, y);
//     }
//     else
//     {
//       if (z > y)
//       {
//         printf("%d %d %d\n", x, z, y);
//       }
//       else
//       {
//         printf("%d %d %d\n", x, y, z);
//       }
//     }
//   }
//   else
//   {
//     // y>x
//     if (z > y)
//     {
//       printf("%d %d %d\n", z, y, x);
//     }
//     else
//     {
//       // y>x
//       if (z > x)
//       {
//         printf("%d %d %d\n", y, z, x);
//       }
//       else
//       {
//         printf("%d %d %d\n", y, x, z);
//       }
//     }
//   }
//   return 0;
// }

// 【题目名称】

// 打印3的倍数的数

// 【题目内容】

// 写一个代码打印1-100之间所有3的倍数的数字

// #include <stdio.h>

// int main()
// {
//   for (int i = 1; i <= 100; i++)
//   {
//     if (i % 3 == 0)
//       printf("%d ", i);
//   }
//   return 0;
// }
// #include <stdio.h>
// int main()
// {
// 	int a = 0, b = 0;
// 	for (a = 1, b = 1; a <= 100; a++)
// 	{
// 		if (b >= 20) break;
// 		if (b % 3 == 1)
// 		{
// 			b = b + 3;
// 			continue;
// 		}
// 		b = b-5;
// 	}
// 	printf("%d\n", a);
// 	return 0;
// }
#include <stdio.h>
// 【题目名称】

// 二分查找

// 【题目内容】

// 编写代码在一个整形有序数组中查找具体的某个数

// 要求：找到了就打印数字所在的下标，找不到则输出：找不到。
// int binary_search(int arr[], int len, int target)
// {
//   int left = 0;
//   int right = len - 1;
//   while (left <= right)
//   {
//     int mid = (left + right) / 2;
//     if (arr[mid] == target)
//       return mid;
//     else if (arr[mid] > target)
//       right = mid - 1;
//     else
//       left = mid + 1;
//   }
//   return -1;
// }
// int main()
// {
//   int arr[] = {1, 2, 3, 4, 5, 6};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   int ret = binary_search(arr, len, 8);
//   if (ret != -1)
//     printf("找到了 %d \n", ret);
//   else
//     printf("没有找到\n");

//   return 0;
// }

// 【题目名称】

// 乘法口诀表

// 【题目内容】

// 在屏幕上输出9*9乘法口诀表
// #include <stdio.h>

// int main()
// {
//   for(int i = 1; i<=9;i++)
//   {
//     for(int j =1;j<=i;j++)
//     {
//       printf("%d x %d = %-4d", i,j,i*j);
//     }
//     printf("\n");
//   }
//   return 0;
// }
// #include <stdio.h>

// int main()
// {
//   int arr[10] = {0};
//   int max = arr[0];
//   for (int i = 1; i < 10; i++)
//   {
//     if (arr[i] > max)
//       max = arr[i];
//   }
//   printf("%d\n", max);
//   return 0;
// }

// #include <stdio.h>

// int main()
// {
//   double result = 0.0;
//   int flag = -1;
//   for (int i = 1; i <= 100; i++)
//   {
//     flag = -1 * flag;
//     result += (flag * 1.0 / i);
//   }
//   printf("%lf\n", result);
//   return 0;
// }

// #include <stdio.h>
// int nums_nine(int num)
// {
//   int ret = 0;
//   while (num)
//   {
//     int a = num % 10;
//     if (a == 9)
//       ret++;
//     num /= 10;
//   }
//   return ret;
// }
// int main()
// {
//   int result = 0;
//   for (int i = 1; i <= 100; i++)
//   {
//     result += nums_nine(i);
//   }
//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// void menu()
// {
//   printf("**********************************\n");
//   printf("*********** 1.play **********\n");
//   printf("*********** 0.exit **********\n");
//   printf("**********************************\n");
// }
// // TDD-测试驱动开发。
// // RAND_MAX--rand函数能返回随机数的最大值。
// void game()
// {
//   int random_num = rand() % 100 + 1;
//   int input = 0;
//   while (1)
//   {
//     printf("请输入猜的数字>:");
//     scanf("%d", &input);
//     if (input > random_num)
//     {
//       printf("猜大了\n");
//     }
//     else if (input < random_num)
//     {
//       printf("猜小了\n");
//     }
//     else
//     {
//       printf("恭喜你，猜对了\n");
//       break;
//     }
//   }
// }
// int main()
// {
//   int input = 0;
//   srand((unsigned)time(NULL));
//   do
//   {
//     menu();
//     printf("请选择>:");
//     scanf("%d", &input);
//     switch (input)
//     {
//     case 1:
//       game();
//       break;
//     case 0:
//       break;
//     default:
//       printf("选择错误,请重新输入!\n");
//       break;
//     }
//   } while (input);
//   return 0;
// }