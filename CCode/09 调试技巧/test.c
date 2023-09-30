/**
 * User: Qkj
 * Description: 调试技巧
 * Date: 2023-07-18
 * Time: 14:02
 */

// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     for(i=0; i<=12; i++)
//     {
//         arr[i] = 0;
//         printf("hello bit\n");
//     }
//     return 0;
// }

// 【题目名称】

// 调整奇数偶数顺序

// 【题目内容】

// 调整数组使奇数全部都位于偶数前面。

// 题目：

// 输入一个整数数组，实现一个函数，

// 来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，

// 所有偶数位于数组的后半部分。
// #include <stdio.h>
// int main()
// {
//   int arr[] = {2,1,2,1};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   int left = 0;
//   int right = len - 1;
//   while (left < right)
//   {
//     while (left < right && arr[left] % 2 == 1)
//     {
//       left++;
//     }
//     while (left < right && arr[right] % 2 == 0)
//     {
//       right--;
//     }
//     int ret = arr[left];
//     arr[left] = arr[right];
//     arr[right] = ret;
//     left++;
//     right--;
//   }
//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   return 0;
// }
#include <stdio.h>
int my_strlen(char *ret)
{
  int count = 0;
  while (ret[count++] != '\0')
  {
  }
  return count;
}

char *my_strcpy(char *destination, const char *source)
{
  int count = 0;
  while (destination[count] = source[count++])
  {
  }

  return destination;
}
int main()
{
	char arr1[10] = { 0 };
	const char* arr2 = "abc";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
	return 0;
}