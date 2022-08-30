#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>

//void show(const int* p1)
//{
//	//C中任何函数传参都要形成临时变量
//	printf("%p\n", &p1);
//	printf("The vaule is %d\n", *p1);
//}
//int My_Mathpow(int x, int n)
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else if (1 == n)
//	{
//		return x;
//	}
//	return x * My_Mathpow(x, n - 1);
//}
//
//int fun(const int x)
//{
//	//是    ---  1
//	//不是  ---  0
//	int k = 0;
//	int val = 0;
//	while (val < x)
//	{
//		val = My_Mathpow(2, k);
//		if (val == x)
//		{
//			break;
//		}
//		k++;
//	}
//	if (val>x)
//		return 0;
//	return 1;
//	
//}
int main()
{
	/*int arr[] = { 1, 2, 3, 4, 6, 4, 3, 2, 1 };
	int i = 0;
	int ret = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		ret = ret^arr[i];
	}
	printf("找到了,是 %d\n", ret);
*/
	//如何判断一个数是不是2的次方

	//int n = 8;
	//if (!(n&(n - 1)))
	//{
	//	printf("YES\n");
	//}
	//else
	//{
	//	printf("NO\n");
	//}






	/*int ret = My_Mathpow(3, 3);
	printf("%d\n", ret);*/
	/*int n = 0;
	scanf("%d", &n);
	int ret = fun(n);
	if (1 == ret)
	{
		printf("%d 是 2 的次方\n ", n);
	}
	else
	{
		printf("%d 不是 2 的次方\n ", n);
	}*/
	//1;

	//true;
	/*boolean flg  = -1;
	if (flg)
	{
		printf("hehehe %u",flg);
	}*/

	/*
	goto star;
	printf("hhhhhhhhhhhhhhhhheeee\n");
star:
	int a = 10;
	int b = 20;
	int c = 30;
	printf("%d", a + b + c);*/
	/*int a = 10;
	int *p = &a;

	printf("%p\n", &p);
	show(p);*/
	/*int a = 10;
	int b = 20;*/

	/* int *const p = &a;
	int*q = p;*/
	//const int * const p = &a;
	//*p = 20;
	//p = &a;
	//int * const p = &a;
	//*p = 20;
	//p = &b;
	/*const int *p = &a;
	int const *p = &a;*/
	//int * const p = &a;
	/*const int * const p = &a;*/


	//const int* p = &a;
	//p = &b;
	//printf("%d\n", *p);

	
	//*p = 20;

	//*p = 20;
	system("pause");
	return 0;
}
//1000
//0001
//0000
//


//0000 0001
//0000 0000
//0000 0001

//0000 0010
//0000 0001
//0000 0011

//0000 0011   3
//0000 0010   2
//0000 0011   3


//0000 0100   4
//0000 0011   3
//0000 0010
//0000 0010



//0000 0000   

//如果一个的数字是2 的K次方 那么 n & (n-1) == 0;
