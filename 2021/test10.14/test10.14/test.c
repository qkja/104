#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<Windows.h>

int main()
{
	int weight = 0;
	int height = 0;
	scanf("%d %d", &weight, &height);
	double ret = weight / ((height*height)*10000.0);
	printf("%.2lf", ret);
	//return 0;

	//int a = 0;
	//int b = 0;
	//int c = 0;
	//int p = 0;

	//scanf("%d %d %d", &a, &b, &c);
	//float circumference = a + b + c;
	//p = (a + b + c) / 2;

	//double area = sqrt(p*(p - a)*(p - b)*(p - c));
	//printf("circumference=%.2f area=%.2lf", circumference, area);
	//return 0;
	//for (int i = 10000; i < 100000; i++)
	//{
	//	//int num = i;
	//	//num /= 10;


	//	/*for (int j = 0; j < 5; j++)
	//	{

	//	}*/
	//}
	//int i = 0;
	////12345
	//int num = i;
	//int ret = i % 10;
	//num /= 10;
	//ret = i % 100;
	//for (int i = 10000; i<100000; i++)
	//{
	//	int ret = 0;
	//	int a = 0;
	//	int num = i;
	//	while (num>9)
	//	{
	//		//1234
	//		//a%=10;
	//		a = num - (num / 10)*10;
	//		num /= 10;
	//		//a=
	//		ret += a*num;
	//	}
	//	if (ret ==i)
	//	{
	//		printf("%d ", i);
	//	}
	//}
	system("pause");
	return 0;
}