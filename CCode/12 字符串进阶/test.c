/**
 * User: Qkj
 * Description: 函数栈帧
 * Date: 2023-07-18
 * Time: 14:02
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 【题目名称】
//
// 模拟实现memmove

#include <stdio.h>
#include <string.h>
void *my_memmove(void *destination, const void *source, size_t num)
{
  char *ptr = malloc(num);
  if (ptr == NULL)
    return NULL;
  for (int i = 0; i < num; i++)
  {
    ptr[i] = *(((char *)source) + i);
  }
  for (int i = 0; i < num; i++)
  {
    *(((char *)destination) + i) = ptr[i];
  }
  free(ptr);
  return destination;
}
// int main()
// {
//   char str1[] = "memmove can be very useful......";
//   char str2[] = "memmove can be very useful......";
//   memmove(str1 + 20, str1 + 15, 11);
//   my_memmove(str2 + 20, str2 + 15, 11);
//   puts(str1);
//   // puts("\n");
//   puts(str2);
//   return 0;
// }
// 【题目内容】
//
// 模拟实现memmove

// 【题目名称】
//
// 模拟实现memcpy
void *my_memcpy(void *destination, const void *source, size_t num)
{
  char *ptr = malloc(num);
  if (ptr == NULL)
    return NULL;
  for (int i = 0; i < num; i++)
  {
    ptr[i] = *(((char *)source) + i);
  }
  for (int i = 0; i < num; i++)
  {
    *(((char *)destination) + i) = ptr[i];
  }
  free(ptr);
  return destination;
}

//
// 【题目内容】
//
// 模拟实现memcpy

///* strstr example */
// #include <stdio.h>
// #include <string.h>
//
// 【题目名称】
//
// 模拟实现strstr
//
//
// 【题目内容】
// const char* my_strstr(const char * str1, const char * str2)
//{
//	int len = strlen(str2);
//	for (int i = 0; i < strlen(str1); i++)
//	{
//		if (str1[i] == *str2)
//		{
//			int ret = strncmp(str1 + i, str2, len);
//			if (ret == 0)
//				return str1 + i;
//		}
//	}
//	//printf("aaa");
//	return NULL;
//
// }
// int main()
//{
//	char str[] = "This is a simple string";
//	char * pch;
//	pch = strstr(str, "ss");
//	if (pch != NULL)
//		strncpy(pch, "sample", 6);
//	puts(str);
//	return 0;
// }
// int main()
//{
//	char str[] = "This is a simple string";
//	char * pch;
//	pch = my_strstr(str, "siple");
//	if (pch != NULL)
//		strncpy(pch, "sample", 6);
//	puts(str);
//	return 0;
// }
//
// 模拟实现strstr
//
// 【题目名称】
//
// 模拟实现strcat
//
// 【题目内容】
// char * my_strcat(char * destination, const char * source)
//{
//	char * ret = destination;
//	int len = strlen(destination);
//	destination += len;
//	while (*destination++ = *source++)
//	{
//
//	}
//	return ret;
// }
// int main()
//{
//	char arr1[10] = "aabc";
//	char* arr2 = "abc\0d";
//	//my_strcpy(arr, arr2);
//	printf("%d\n", my_strcmp(arr1, arr2));
//	return 0;
// }
//
//
//
// 模拟实现strcat
// 【题目名称】
//
// 模拟实现strcmp
//
// 【题目内容】
//
//
// int my_strcmp(const char * str1, const char * str2)
//{
//	int flag = 0;
//	while (*str1 != '\0' && *str2 != '\0')
//	{
//		if (*str1 < *str2)
//		{
//			flag = -1;
//			break;
//		}
//		else if (*str1 > *str2)
//		{
//			flag = 1;
//			break;
//		}
//		++str1;
//		++str2;
//	}
//	return flag;
// }
// int main()
//{
//	char arr1[10] = "aabc";
//	char* arr2 = "abc\0d";
//	//my_strcpy(arr, arr2);
//	printf("%d\n", my_strcmp(arr1, arr2));
//	return 0;
// }
//
// 模拟实现strcmp
// 【题目名称】
//
// 模拟实现strcpy
//
// 【题目内容】
//
// char * my_strcpy(char * destination, const char * source)
//{
//	char * ret = destination;
//	while (*destination++ = *source++)
//	{
//
//	}
//	return ret;
// }
//
//
//
// int main()
//{
//	char arr[10] = "abc";
//	char* arr2 = "ed";
//	my_strcpy(arr, arr2);
//	printf("%s\n", arr);
//	return 0;
// }
//
// 模拟实现strcpy
//
// 【题目名称】
//
// 模拟实现strlen
//
// 【题目内容】
//
// 模拟实现strlen
//
// size_t my_strlen(const char * str)
//{
//	if (str == NULL)
//		*str;  //这里直接让报错
//	int count = 0;
//	while (str[count++])
//	{}
//	return count;
// }
// int main()
//{
//	//strlen(NULL);
//	return 0;
// }