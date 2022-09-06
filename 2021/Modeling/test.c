#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h> 

#define STAR 0.0
#define END 2.0/3

double Integral_function(const double t, const double k)
{
	return (-k) * exp((-0.3 - k) * t) / (0.3 + k);
}

double find_value(const double y, const double k)
{
	return y - 0.2 * y - (Integral_function(END, k) - Integral_function(STAR, k));
}

double find_value_n(const double a, const double b)
{
	return 1.109e5 * (0.5 * a + b);
}

void test()
{
	double y1 = 0.0;
	double y2 = 0.0;
	double y3 = 0.0;
	double y4 = 0.0;

	printf("请输入 y1 到 y4 的值:>");
	scanf("%lf %lf %lf %lf", &y1, &y2, &y3, &y4);
	
	double k = 0.0;
	printf("请输入k的值> ");
	scanf("%lf", &k);

	double n = 0.0;
	double a = 0.0;
	double b = 0.0;
	
	a = find_value(y3, 0.42 * k);

	b = find_value(y4, k);

	n = find_value_n(a, b);

	double c = 0.9 * y3 - a;
	double d = 0.9 * y4 - b;

	double x1 = 1.22e11 * n / (1.22e11 + n);
	double x2 = 0.7 * y1;
	double x3 = 0.7 * y2;
	double x4 = a - 0.1 * y3 + b - 0.1 * y4;

	printf("%lf\n%lf\n%lf\n%lf\n", x1, x2, x3, x4);
	printf("%lf\n%lf", c, d);

}

int main()
{
	test();
	return 0;
}
