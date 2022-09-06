#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//写一个代码

//运行代码

//主函数
//#define M 10

int g_val = 10;
int main() //int 表示 整型 表示函数运行结束后返回一个整型的值  return 0  这里的0就是一个整数，被返回  
		   //C99标准
{
	printf("%p\n", &g_val);
	int g_val = 100;
	printf("%d\n", g_val);

	printf("%p\n", &g_val);

	//M = 12;

	/*int ch = 12;
	printf("%c", ch);*/

	/*printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof (double));*/
	//printf("Hello World\n");
	/*printf("Hello World\n");
	printf("Hello World\n");
	printf("Hello World\n");*/
	return 0;
}
//void main() //老标准   C99之前
//{
//
//}

//写一个C语言代码的时候
//首先写一个main函数
//main函数是程序的入口
//程序是从main函数第一行开始执行的
//main函数必须要有 而且 有且只有一个
// main函数也叫主函数
//