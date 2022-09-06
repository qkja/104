#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//int main()
//{
//	const int a = 10;
//	
//	printf("%d", a);
//	return 0;
//}

//int main()
//{
//	//int n = 00;
//	//double h = 0;
//	//scanf("%lf %d", &h, &n);
//	//double sum = 0.0;
//	//double d = 0.0;
//	//
//	//while (n)
//	//{
//	//	if (1 == n)
//	//	{
//	//		d = h;
//	//	}
//	//	sum += h;
//	//	h /= 2;
//	//	n--;
//	//}
//
//	//printf("%lf %lf", sum, d);
//	//return 0;
//}

double fun(int n)
{

	double ret = 1.0;
	while (n)
	{
		ret *= 0.5;
		n--;
	}
	return ret;
}

int main()
{
	int n = 0;
	double h = 0.0;
	scanf("%lf %d", &h, &n);
	double ret = fun(n);
	printf("%lf %lf", h * (4 * (1 - ret) - 1), h * ret);

	return 0;
}
