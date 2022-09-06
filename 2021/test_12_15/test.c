#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<float.h>
#define EPSILON 0.000000001   //自己定义精度

#include<windows.h>
#include<math.h>
#include<float.h>

int main()
{
	double x = 0.0;
	if (fabs(x) < DBL_EPSILON)
	{
		printf("hehe\n");
	}
	return 0;
}

//int main()
//{
//	double x = 1.0;
//	double y = 0.1;
//
//	if (fabs((x - 0.9) - 0.1) < DBL_EPSILON)
//	{
//		printf("You can see me!!!\n");
//	}
//	else
//	{
//		printf("oops!!!\n");
//	}
//	return 0;
//}

//int main()
//{
//
//	/*DBL_EPSILON;
//	FLT_EPSILON;*/
//
//	double x = 1.0;
//	double y = 0.1;
//
//
//	/*if ((x - y) > - 精度 && (x - y) < 精度)
//	{
//
//	}*/
//	/*printf("%.50f\n", x - 0.9);
//	printf("%.50f\n", y);*/
//
//	/*if ((x - 0.9) == 0.1)*/
//	if (fabs((x - 0.9)-0.1) < DBL_EPSILON)
//	{
//		printf("You can see me!!!\n");
//	}
//	else
//	{
//		printf("oops!!!\n");
//	}
//	/*double d = 3.6;
//	printf("%.50lf\n", d);*/
//	return 0;
//}

//int main()
//{
//	BOOL x = TRUE;
//	printf("%d", sizeof(BOOL));
//	return 0;
//}









//#include<stdio.h>
//#include<stdlib.h>
////#include<stdbool.h>
////#include<stdio.h>
////#include<stdlib.h>
//#include<Windows.h>

//#include<stdbool.h>
//int main()
//{
//	//BOOl x = 
//	return 0;
//}
//
//int main()
//{    
//	BOOL x = TRUE;
//
//
//
//	//_Bool fag = 1;
//	//fag = true;
//	//if (fag)
//	//{
//
//	//	printf("%d", sizeof(fag));
//	//	/*printf("hehe");
//	//	printf("hehe%d",sizeof(fag));*/
//	//}
//	return 0;
//}