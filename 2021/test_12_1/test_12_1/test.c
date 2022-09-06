#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

//KiKi想获得某年某月有多少天
//请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。

//int main()
//{
//
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	while ((scanf("%d %d", &year, &month)) != EOF)
//	{
//		
//		switch (month)
//		{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//			day = 31;
//			//printf("%d\n", 31);
//			break;
//		case 2:
//			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//			{
//				day = 29;
//				//printf("%d\n", 29);
//			}
//			else
//			{
//				day = 28;
//				//printf("%d\n", 28);
//			}
//			break;
//		case 4:
//		case 6:
//		case 9:
//			day = 30;
//			//printf("%d\n", 30);
//			break;
//
//		}
//		printf("%d\n", day);
//	}
//	
//	system("pause");
//	return 0;
//}

//从键盘输入a, b, c的值，编程计算并输出一元二次方程ax2 + bx + c = 0的根，
//当a = 0时，输出“Not quadratic equation”，
//当a ≠ 0时，根据△ = b2 - 4 * a*c的三种情况计算并输出方程的根。

#include<math.h>

//int main()
//{
//	float a = 0.0;
//	float b = 0.0;
//	float c = 0.0;
//	float dis = 0.0;
//	double x1 = 0.0;
//	double x2 = 0.0;
//	scanf("%f %f %f", &a, &b, &c);
//
//	if (0.0 == a)  //浮点数最好不要比较  精度
//		printf("Not quadratic equation\n");
//	else
//	{
//		dis = b * b - 4 * a * c;
//		if (dis == 0)
//		{
//			x1 = (-b - sqrt(dis)) / (2 * a);
//			printf("x1=x2=%.2f\n", x1);;
//		}
//		else if (dis > 0)
//		{
//			x1 = (-b - sqrt(dis)) / (2 * a);
//			x2 = (-b + sqrt(dis)) / (2 * a);
//			printf("x1=%.2f;x2=%.2f\n", x1, x2);
//		}
//		else
//		{
//			float m, n;
//			m = -b / (2 * a);
//			n = sqrt(-dis) / (2 * a);
//			if (b != 0.0)
//			{
//				printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", m, n, m, n);
//			}
//			else if (b == 0.0)
//			{
//				printf("x1=0.00-%.2fi;x2=0.00+%.2fi\n", n, n);
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int n = 2005;
//	printf("20%.2d", n);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	float b = 10.0;
//	
//	int c = 0 ? a : b;
//
//	return 0;
//}



