#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//struct Per
//{
//	int age;
//	char ch;
//	struct Per s1;
//} s;


//#define MAX 10
//#define MAXS 2 * MAX
//
//int main()
//{
//
//	printf("%d", MAXS);
//	//in/*gg*/t h = 10;
//	//int a = 10;
//	/*printf("%d;", MAX);*/
//	/*float num = 15.0L;
//	printf("%e\n");*/
//
//	//int a = 10;
//	//printf("%10d\n", a);
//	//printf("%-10d\n", a);
//	//printf("%10.3d\n", a);
//	/*int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("%p\n", &a);
//	printf("%p\n", &b);
//	printf("%p\n", &c);*/
//	/*int a = 10;
//	printf("%d\n", a);
//	printf("%d\n", s.age);
//	printf("%c\n", s.ch);
//	printf("%d\n", s.ch);*/
//	return 0;
//}

#include<stdio.h>

void swap1(int* pa, int* pb)
{
	int c = 0;
	c = *pa;
	*pa = *pb;
	*pb = c;
}

void swap2(int* pa, int* pb)
{
	*pa = *pa + *pb;
	*pb = *pa - *pb;
	*pa = *pa - *pb;
}

void swap3(int* pa, int* pb)
{
	*pa = *pa ^ *pb;
	*pb = *pa ^ *pb;
	*pa = *pa ^ *pb;
}

int binary_num_1_1(int n)
{
	unsigned int m = (unsigned int)n;
	int arr[32] = { 0 };
	int i = 0;
	int count = 0;
	//3   011
	while (m)
	{
		arr[i] = m % 2;
		m /= 2;
		i++;
	}
	for (i-- ; i >= 0; i--)
	{
		if (1 == arr[i])
		count++;
	}
	return count;

}

int main()
{
	int n = -2;
	printf("%d", binary_num_1_1(n));
	return 0;
}

//int binary_num_1_2(int n)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (1 == ((n >> i) & 1))
//			count++;
//	}
//	return count;
//}
//
//int binary_num_1_3(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n&(n - 1);  //n & (n-1)  会把二进制数列中最右边的1去掉
//	}
//	return count;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret1 = binary_num_1_1(n);
//	int ret2 = binary_num_1_2(n);
//	int ret3 = binary_num_1_3(n);
//	printf("%d\n", ret1);
//	printf("%d\n", ret2);
//	printf("%d\n", ret3);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("Before :a = %d b = %d\n", a, b);
//
//	//swap1(&a, &b);
//	//swap2(&a, &b); 
//	swap3(&a, &b);
//
//	printf("After  :a = %d b = %d\n", a, b);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//
//	int c = n ^ m;  //将不同的变成 1
//
//	int ret = binary_num_1_3(c);
//	printf("%d", ret);
//	return 0;
//}

//int judg(int n)
//{
//	if (0 == n)
//		return 1;
//	return n & (n - 1);
//}

//int main()
//{
//	int n = 0;
//
//	scanf("%d", &n);
//	int ret = judg(n);
//	if (0 == ret)
//	{
//		printf("是\n");
//	}
//	else
//	{
//		printf("不是\n");
//	}
//	return 0;
//}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret1 = binary_num_1_1(n);
	int ret2 = binary_num_1_2(n);
	int ret3 = binary_num_1_3(n);
	int ret4 = binary_num_1_4(n);
	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);
	printf("%d\n", ret4);
	return 0;
}