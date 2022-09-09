#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int f(int x)
//{
//	int c = 0;
//	while (x)
//	{
//		c++;
//		x = x & (x - 1);
//	}
//	return c;
//}

int c = 0;
int fib(int n)
{
	c++;
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	//printf("%d", f(9999));
	//printf("%o %o", 0123, 123);
	fib(8);
	printf("%d", c);
	return 0;
}