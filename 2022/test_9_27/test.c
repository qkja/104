#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdio.h>

#include <stdio.h>
#include <string.h>

int main()
{
	//二维数组
	int a[3]= { 0 };      
	printf("%d", sizeof(&a));
	return 0;
}
//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };        // 4*4
//	printf("%d\n", sizeof(&a[0] + 1));         // 
//	printf("%d\n", sizeof(*(&a[0] + 1)));      // 4*4            // 4         // 4*4
//	return 0;
//}
//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(*(a + 0)));  
//	return 0;
//}
//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a+0));                 // 48
//	//printf("%d\n", sizeof(a[0][0]));           // 4
//	//printf("%d\n", sizeof(a[0]));              // 16
//	//printf("%d\n", sizeof(a[0] + 1));          // 4
//	//printf("%d\n", sizeof(*(a[0] + 1)));       // 4
//	//printf("%d\n", sizeof(a + 1));             // 4
//	//printf("%d\n", sizeof(*(a + 1)));          // 4*4
//	//printf("%d\n", sizeof(&a[0] + 1));         // 4
//	//printf("%d\n", sizeof(*(&a[0] + 1)));      // 4*4
//	//printf("%d\n", sizeof(*a));                // 4*4
//	//printf("%d\n", sizeof(a[3]));              // 4*4
//	return 0;
//}
//int main()
//{
//	二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));                 // 48
//	printf("%d\n", sizeof(a[0][0]));           // 4
//	printf("%d\n", sizeof(a[0]));              // 16
//	printf("%d\n", sizeof(a[0] + 1));          // 4
//	printf("%d\n", sizeof(*(a[0] + 1)));       // 4
//	printf("%d\n", sizeof(a + 1));             // 4
//	printf("%d\n", sizeof(*(a + 1)));          // 4*4
//	printf("%d\n", sizeof(&a[0] + 1));         // 4
//	printf("%d\n", sizeof(*(&a[0] + 1)));      // 4*4
//	printf("%d\n", sizeof(*a));                // 4*4
//	printf("%d\n", sizeof(a[3]));              // 4*4
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- *++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//}


//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//	return 0;
//}



//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//}

//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知结构体类型的变量test的大小有20个字节
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p + 0x1); // 0x1000
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}




//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;



//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	return 0;
//}
//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));                 // 3*4 *4
//	printf("%d\n", sizeof(a[0][0]));           // 4
//	printf("%d\n", sizeof(a[0]));              // 4*4
//	printf("%d\n", sizeof(a[0] + 1));          // 4
//	printf("%d\n", sizeof(*(a[0] + 1)));       // 4
//	printf("%d\n", sizeof(a + 1));             // 4 * 4
//	printf("%d\n", sizeof(*(a + 1)));          // 4*4
//	printf("%d\n", sizeof(&a[0] + 1));         // 
//	printf("%d\n", sizeof(*(&a[0] + 1)));      // 4*4
//	printf("%d\n", sizeof(*a));                // 4
//	printf("%d\n", sizeof(a[3]));              // 4*4
//	return 0;
//}
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//	printf("%d\n", strlen(*arr));
//	printf("%d\n", strlen(arr[1]));
//	return 0;
//}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));            // 6
//	printf("%d\n", sizeof(arr + 0));        // 4
//	printf("%d\n", sizeof(*arr));           // 1
// 	printf("%d\n", sizeof(arr[1]));         // 1
//	printf("%d\n", sizeof(&arr));           // 4
//	printf("%d\n", sizeof(&arr + 1));       // 4
//	printf("%d\n", sizeof(&arr[0] + 1));    // 4
//
//
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));
//	//printf("%d\n", strlen(&arr));
//	//printf("%d\n", strlen(&arr + 1));
//	//printf("%d\n", strlen(&arr[0] + 1));
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a + 0));
//	printf("%d\n", sizeof(*a));
//	printf("%d\n", sizeof(a + 1));
//	printf("%d\n", sizeof(a[1]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", sizeof(*&a));
//	printf("%d\n", sizeof(&a + 1));
//	printf("%d\n", sizeof(&a[0]));
//	printf("%d\n", sizeof(&a[0] + 1));
//	return 0;
//}



//#include<windows.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("************************\n");
//	printf("***     0. exit      ***\n");
//	printf("*** 1.Add      2.Sub ***\n");
//	printf("*** 3.Mul      4 Div ***\n");
//	printf("************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//
//	int (*pfArr[5])(int, int) = { 0, Add, Sub, Mul, Div };//pfArr是一个函数指针的数组，也叫转移表
//
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器\n");
//			break;
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("输入2个操作数:>");
//			scanf("%d %d", &x, &y);
//			ret = pfArr[input](x, y);
//			printf("ret = %d\n", ret);
//		}
//		else
//		{
//			printf("选择错误\n");
//		}
//	} while (input);
//
//	return 0;
//}

//void calculator(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个数: ");
//	scanf("%d %d", &x, &y);
//	printf("%d\n", (*pf)(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择: > ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("已退出\n");
//			break;
//		case 1:
//			calculator(Add);
//			break;
//		case 2:
//			calculator(Sub);
//			break;
//		case 3:
//			calculator(Mul);
//			break;
//		case 4:
//			calculator(Div);
//			break;
//		default:
//			printf("请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
//
//





//#include<stdio.h>
//#include<windows.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("************************\n");
//	printf("***     0. exit      ***\n");
//	printf("*** 1.Add      2.Sub ***\n");
//	printf("*** 3.Mul      4 Div ***\n");
//	printf("************************\n");
//}
//void calculator(int(*pf)(int,int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个数: ");
//	scanf("%d %d", &x, &y);
//	printf("%d\n", (*pf)(x, y));
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择: > ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("已退出\n");
//			break;
//		case 1:
//			calculator(Add);
//			break;
//		case 2:
//			calculator(Sub);
//			break;
//		case 3:
//			calculator(Mul);
//			break;
//		case 4:
//			calculator(Div);
//			break;
//		default:
//			printf("请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}




//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("************************\n");
//	printf("***     0. exit      ***\n");
//	printf("*** 1.Add      2.Sub ***\n");
//	printf("*** 3.Mul      4 Div ***\n");
//	printf("************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	do
//	{
//		menu();
//		printf("请选择: > ");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0:
//			printf("已退出\n");
//			break;
//		case 1:
//			printf("请输入两个数: ");
//			scanf("%d %d",&x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个数: ");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入两个数: ");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Mul(x, y));
//
//			break;
//		case 4:
//			printf("请输入两个数: ");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", Div(x, y));
//
//			break;
//		default:
//			printf("请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}




//int main()
//{
//	int arr[4][4] = { 0 };
//	int(*p)[4] = arr;
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int arr[4][4] = { 0 };
//	int(*p)[4][4] = &arr;
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<windows.h>

//int main()
//{
//	int arr[4][4] = { 0 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr[0][0]);
//
//	printf("===============\n");
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr + 1);
//	printf("%p\n", &arr[0][0] + 1);
//
//
//	system("pause");
//	return 0;
//}






//int main()
//{
//    int arr[10] = { 0 };
//    int(*p)[10] = &arr;
//    for (int i = 0; i < 10; i++)
//    {
//        printf("%d ", *((*p) + i));
//    }
//    return 0;
//}




//int main()
//{
//    int arr[10] = { 0 };
//    printf("%p\n", arr);
//    printf("%p\n", &arr);
//    printf("==============\n");
//    printf("%p\n", arr + 1);
//    printf("%p\n", &arr + 1);
//    system("pause");
//    return 0;
//}