/**
 * User: Qkj
 * Description: 函数栈帧
 * Date: 2023-07-18
 * Time: 14:02
 */
 // 1. main函数可以参数吗?可以的, 可以带三个 
// 2. 什么是可变参数列表, printf函数, 求一堆数据的最大值?请问如何传入参数
#include <stdarg.h>
#include <stdio.h>

//int FindMax(int num, ...)
//{
//	va_list arg;
//	va_start(arg, num);
//
//	int max = va_arg(arg, int);
//	for (int i = 0; i < num - 1; i++)
//	{
//		int x = va_arg(arg, int);
//		if (max < x)
//		{
//			max = x;
//		}
//	}
//	va_end(arg);
//	return max;
//}
//
//int main()
//{
//	int max = FindMax(5, 1, 2, 3, 9, 7);
//	printf("max = %d\n", max);
//	return 0;
//}

#include <stdarg.h>

int FindMax(int num, ...)
{
	va_list arg;
	va_start(arg, num);

	int max = va_arg(arg, int);
	for (int i = 0; i < num - 1; i++)
	{
		int x = va_arg(arg, int);
		if (max < x)
		{
			max = x;
		}
	}
	va_end(arg);
	return max;
}

int main()
{
	int max = FindMax(5, 'a', 'b', 'c', 'd', 'e');
	printf("max = %d\n", max);
	system("pause");
	return 0;
}