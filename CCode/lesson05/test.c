/**
 * User: Qkj
 * Description: 函数
 * Date: 2023-07-18
 * Time: 14:02
 */
#include <stdio.h>

// #include <stdio.h>
// int main()
// {
//     char str[] = "hello bit";
//     printf("%d %d\n", sizeof(str), strlen(str));
// 	return 0;
// }
// #include <stdio.h>
// int main()
// {
//     int arr[] = {1,2,(3,4),5};
//     printf("%d\n", sizeof(arr));
//     return 0;
// }

// void swap_array(int *arr1, int len1, int* arr2, int len2)
// {
//   for(int i = 0; i < len1; i++)
//   {
//     int ret = arr1[i];
//     arr1[i] = arr2[i];
//     arr2[i] = ret;
//   }
// }
// void init(int *arr, int len)
// {
//   for (int i = 0; i < len; i++)
//   {
//     arr[i] = 0;
//   }
// }

// void reverse(int *arr, int len)
// {
//   int left = 0;
//   int right = len - 1;
//   while (left < right)
//   {
//     int ret = arr[left];
//     arr[left] = arr[right];
//     arr[right] = ret;
//     left++;
//     right--;
//   }
// }
// void print(int *arr, int len)
// {
//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
// printf("\n");
// }
// int main()
// {
//   int arr[10] = {1};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   init(arr, len);
//   for (int i = 0; i < len; i++)
//     arr[i] = i;
//   // print(arr, len);

//   reverse(arr, len);
//   print(arr, len);
//   return 0;
// }

void bubble_sort(int *arr, int len)
{
  // 3 2 1
  for (int i = 0; i < len - 1; i++)
  {
    for (int j = 1; j < len - i; j++)
    {
      if (arr[j - 1] > arr[j])
      {
        int ret = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = ret;
      }
    }
  }
}
int main()
{
  int arr[] = {3, 2, 1};
  int len = sizeof(arr) / sizeof(arr[0]);
  bubble_sort(arr, len);
  for (int i = 0; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}