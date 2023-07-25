/**
 * User: Qkj
 * Description: 操作符
 * Date: 2023-07-18
 * Time: 14:02
 */
// #include <stdio.h>
// int main()
// {
// 	int a, b, c;
// 	a = 5;
// 	c = ++a;
// 	b = ++c, c++, ++a, a++;
// 	b += a++ + c;
// 	printf("a = %d b = %d c = %d\n:", a, b, c);
// 	return 0;
// }

// #include <stdio.h>
// int different_bit_num(int x, int y)
// {
//   // ^ 相同为0,不同为1
//   int ret = x ^ y;
//   // int ret = 2;
//   int count = 0;
//   for (int i = 0; i < 32; i++)
//   {
//     if (((ret >> i) & 1) == 1)
//     {
//       count++;
//     }
//   }
//   return count;
// }

// int main()
// {
//   // printf("%d\n", different_bit_num(1,2));

//   int a, b;
//   while (scanf("%d %d", &a, &b) != EOF)
//   {
//     printf("%d\n", different_bit_num(a, b));
//   }
//   return 0;
// }

// #include <stdio.h>

// int main()
// {
//   int a = 1;
//   int b = 2;
//   a = a ^ b;
//   b = a ^ b; // a^b^b
//   a = a ^ b;

//   printf("a = %d b = %d\n", a, b);

//   return 0;
// }

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param n int整型
 * @return int整型
 */

// int NumberOf1(int n)
// {

//   int ret = n;
//   // int ret = 2;
//   int count = 0;
//   for (int i = 0; i < 32; i++)
//   {
//     if (((ret >> i) & 1) == 1)
//     {
//       count++;
//     }
//   }
//   return count;
// }

// 【题目名称】

// 打印整数二进制的奇数位和偶数位

// 【题目内容】

// 获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
// #include <stdio.h>

// int main()
// {
//   int a = -1;
//   int arr1[16] = {0};
//   int arr2[16] = {0};
//   int index1 = 0;
//   int index2 = 0;
//   for (int i = 0; i < 32; i++)
//   {
//     int ret = ((a >> i) & 1);
//     if (i % 2 == 0)
//       arr1[index1++] = ret;
//     else
//       arr2[index2++] = ret;
//   }
//   for (int i = 0; i < 16; i++)
//   {
//     printf("%d ", arr1[i]);
//   }
//   printf("\n");
//   for (int i = 0; i < 16; i++)
//   {
//     printf("%d ", arr2[i]);
//   }
//   printf("\n");

//   return 0;
// }

// #include <stdio.h>
// int main()
// {
//   int arr[] = {1,2,3,4,5};
//   short *p = (short*)arr;
//   int i = 0;
//   for(i=0; i<4; i++)
//   {
//     *(p+i) = 0;
//   }

//   for(i=0; i<5; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   return 0;
// }
// #include <stdio.h>
// void print(int *arr, int len)
// {
//   for (size_t i = 0; i < len; i++)
//   {
//     printf("%d ", (*arr)++);
//   }
// }
//  printf("%d ", i);
// int main()
// {
//   int arr[] = {1, 2, 3, 4, 5};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   print(arr, len);
//   return 0;
// }

// #include <stdio.h>
// int the_k_power_of_n(int n, int k)
// {
//   if (k == 0)
//     return 1;
//   return n * the_k_power_of_n(n, --k);
// }
// int is_narcissistic_number(int n)
// {
//   int k = 0;
//   int ret = n;
//   int arr[6] = {0};
//   while (ret)
//   {
//     arr[k++] = ret % 10;
//     ret /= 10;
//   }
//   // printf("%d ", k);

//   for (size_t i = 0; i < k; i++)
//   {
//     n -= the_k_power_of_n(arr[i], k);
//   }
//   return n == 0;
// }
// int main()
// {
//   for (size_t i = 0; i < 100000; i++)
//   {
//     if (is_narcissistic_number(i))
//       printf("%d ", i);
//   }

//   // if (is_narcissistic_number(153))
//   //   printf("%d ", 153);
//   return 0;
// }

// 【题目名称】

// 计算求和

// 【题目内容】

// 求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，

// 例如：2+22+222+2222+22222
// #include <stdio.h>
// int mian()
// {
//   int n = 5;
//   int x = n;
//   int ret = 0;
//   for (int i = 0; i < 5; i++)
//   {
//     ret += n;
//     n = n * 10 + x;
//   }
//   printf("%d ", ret);
//   return 0;
// }

// #include <stdio.h>
// int i;
// int main()
// {
//     i--;
//     // -1
//     if (i > sizeof(i))
//     {
//         printf(">\n");
//     }
//     else
//     {
//         printf("<\n");
//     }
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     int i = 1;
//     int ret = (++i)+(++i)+(++i);
//     printf("ret = %d\n", ret);
// 	return 0;
// }

#include <stdio.h>
int main()
{
  int a = 0x11223344;
  char *pc = (char *)&a;
  *pc = 0;
  printf("%x\n", a);
  return 0;
}