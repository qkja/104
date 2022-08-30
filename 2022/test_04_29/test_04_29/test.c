#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	//printf("%d\n", sizeof(void));
//	int a = 0;
//	void* pa = &a;
//	*pa;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	void* pa = &a;
//	void* pb = pa + 1;
//	printf("%d", pb - pa);
//	return 0;
//}

//int main()
//{
//	const int cap = 10;
//	cap = 20;
//	//int arr[cap] = { 0 };
//	return 0;
//}

//int main()
//{
//	const int cap = 10;
//	int* p = &cap;
//	*p = 20;
//	printf("%d\n", cap);
//	return 0;
//}

//int main()
//{
//	char* p = "hello";//常量字符串
//	*p = 'H';
//	printf("%c", p);
//	return 0;
//}

//int main()
//{
//	/*const int cap = 10;
//	int const cap = 10;*/
//	//int arr[cap] = {0};
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	const int* pa = &a;
//	int* const pb = &a;
//	int const *pc = &a;
//	const int* const pd = &a;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 20;
//	const int* pa = &a;
//	pa = &b;
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 20;
//	
//	const int * const pd = &a;
//	*pd = 20;
//    pd = &b;
//	return 0;
//}
//void fun()
//{
//	static int a = 1;
//	a++;
//	printf("%d ",a);
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		fun();
//		i++;
//	}
//	printf("\n");
//	return 0;
//}

void show()
{
	printf("你可调用到我\n");
}
