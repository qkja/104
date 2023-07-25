/**
 * User: Qkj
 * Description: 函数
 * Date: 2023-07-18
 * Time: 14:02
 */
// 【题目名称】

// 函数判断素数

// 【题目内容】

// 实现一个函数，判断一个数是不是素数。

// 利用上面实现的函数打印100到200之间的素数。
#include <stdio.h>
#include <math.h>

// int is_prime_number(int val)
// {
//     for (int i = 2; i <= sqrt(1.0*val); i++)
//     {
//         if (val % i == 0)
//             return 0;
//     }
//     return 1;
// }
// int is_leap_year(int year)
// {
//   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//     return 1;
//   return 0;
// }
// int main()
// {
//     for (int i = 100; i < 200; i++)
//     {
//         if (is_prime_number(i) == 1)
//             printf("%d ", i);
//     }
//     printf("\n");

//     return 0;
// }
// void swap(int *pa, int *pb)
// {
//   int ret = *pa;
//   *pa = *pb;
//   *pb = ret;
// }
// int main()
// {
//   int a = 1;
//   int b = 2;
//   printf("before a = %d, b = %d\n", a, b);
//   swap(&a, &b);
//   printf("after  a = %d, b = %d\n", a, b);
//   return 0;
// }
// 【题目名称】

// 乘法口诀表

// 【题目内容】

// 实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定

// 如：输入9，输出9*9口诀表，输出12，输出12*12的乘法口诀表。

// void print_multiplication_table(int n)
// {
//   for (size_t i = 1; i <= n; i++)
//   {
//     for (int j = 1; j <= i; j++)
//       printf("%-2dx%2d = %-3d", i, j, i * j);
//     printf("\n");
//   }
// }
// int main()
// {
//   print_multiplication_table(9);
//   return 0;
// }

// int Fun(int n)
// {
//   if(n==5)
//     return 2;
//   else
//     return 2*Fun(n+1);
// }

// 【题目名称】

// 打印一个数的每一位

// 【题目内容】

// 递归方式实现打印一个整数的每一位

// void print_erery_bit_num(int num)
// {
//   if (num >= 10)
//     print_erery_bit_num(num / 10);
//   printf("%d ", num % 10);
// }

// int main()
// {
//   print_erery_bit_num(1);
//   printf("\n");
//   print_erery_bit_num(11);
//   printf("\n");
//   print_erery_bit_num(111);

//   return 0;
// }

// int factorial_r(int n)
// {
//   if (n == 1)
//     return 1;
//   return n*factorial_r(n - 1);
// }
// int factorial(int n)
// {
//   int result = 1;
//   for (int i = 2; i <= n; i++)
//     result *= i;
//   return result;
// }
// int main()
// {
//   printf("%d\n", factorial_r(9));
//   printf("%d\n", factorial(9));
//   return 0;
// }

// int my_strlen_r(const char *str)
// {
//   if (*str == '\0')
//     return 0;
//   return 1 + my_strlen_r(str + 1);
// }

// int my_strlen(const char *str)
// {
//   int ret = 0;
//   while (*str++)
//   {
//     ret++;
//   }
//   return ret;
// }

// int main()
// {
//   printf("%d\n", my_strlen_r("abcd"));
//   printf("%d\n", my_strlen_r("a"));
//   printf("%d\n", my_strlen("abcd"));
//   printf("%d\n", my_strlen("a"));

//   return 0;
// }

// int fib_r(int n)
// {
//   // 1  1   2 3 5
//   if (n < 3)
//     return 1;
//   return fib_r(n - 1) + fib_r(n - 2);
// }
// int fib(int n)
// {
//   int left = 1;
//   int right = 1;
//   for (int i = 3; i <= n; i++)
//   {
//     int ret = right + left;
//     left = right;
//     right = ret;
//   }
//   return right;
// }
// int main()
// {
//   printf("%d\n", fib_r(10));
//   printf("%d\n", fib(10));
//   return 0;
// }
// int the_k_power_of_n(int n, int k)
// {
//   if (k == 0)
//     return 1;
//   if (k == 1)
//     return n;
//   return n * the_k_power_of_n(n, --k);
// }

// int main()
// {
//   printf("%d\n", the_k_power_of_n(0, 0));
//   printf("%d\n", the_k_power_of_n(1, 0));
//   printf("%d\n", the_k_power_of_n(2, 3));

//   return 0;
// }
// int DigiSum(int n)
// {
//   if (n < 10)
//     return n;
//   return n % 10 + DigiSum(n / 10);
// }
// int main()
// {
//   printf("%d\n", DigiSum(1729));
//   printf("%d\n", DigiSum(10));
//   return 0;
// }

int my_strlen(const char *str)
{
  int ret = 0;
  while (*str++)
  {
    ret++;
  }
  return ret;
}

void reverse_string(char *str)
{
  char *left = str;
  char *right = str + my_strlen(str) - 1;
  char tmp = *left;
  *left = *right;
  // 这里需要把 right 弄成\0
  *right = '\0';
  if (my_strlen(str + 1) > 1)
    reverse_string(str + 1);
  *right = tmp;
}

int main()
{
  char arr[] = "abcdef";
  reverse_string(arr);
  printf("%s\n", arr);  
  return 0;
}