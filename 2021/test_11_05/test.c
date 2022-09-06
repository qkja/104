#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <climits>

//int main()
//{
//	//INT_MAX;
//
//	return 0;
//}
//#include<stdio.h>                                                                             
//#include<stdlib.h>
//
//int g_val1 = 10;
//int g_val2 = 10;
//int g_val3;
//int g_val4;
//
//int main()
//{
//    const char* str = "abcdef";
//
//    printf("code      : %p\n", main);
//
//    printf("read only : %p\n", str);
//
//    printf("init g_val1 : %p\n", &g_val1);
//    printf("init g_val2 : %p\n", &g_val2);
//    printf("uninit g_val2 : %p\n", &g_val3);
//    printf("uninit g_val2 : %p\n", &g_val4);
//
//    char* p1 = (char*)malloc(sizeof(char*) * 10);
//    char* p2 = (char*)malloc(sizeof(char*) * 10);
//
//    printf("heap addr : %p\n", p1);
//    printf("heap addr : %p\n", p2);
//
//    printf("stack addr : %p\n", &str);
//    printf("stack addr : %p\n", &p1);
//    printf("stack addr : %p\n", &p2);
//
//    return 0;
//}

int MyAdd(int a, int b)
{
	int c = 0;
	c =a + b;
	return c;
}

int main()
{
	int x = 0xA;
	int y = 0xB;
	int z = 0;

	z = MyAdd(x, y);
	printf("z = %d\n", z);
	return 0;
}