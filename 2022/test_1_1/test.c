#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	double B = 0.0;
	double H = 0.0;
	while (1)
	{
		scanf("%lf %lf", &B, &H);
		printf("%lf\n", (B * 10) / (H * 1000));
	}
	return 0;
}