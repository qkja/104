#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>

int main()
{

	FILE* pf = fopen("test.txt", "r");
	printf("pf = %p\n", pf);
	int ch1 = fgetc(pf);
	int ch2= fgetc(pf);
	pf;
	printf("pf = %p\n", pf);
	printf("%c %c\n", ch1, ch2);
	fclose(pf);  //关闭文件
	pf = NULL;
	return 0;
}
//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//
//	//写文件
//	for (int ch = 'a'; ch <= 'z'; ch++)
//	{
//		fputc(ch, pf);
//	}
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("mytest.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	// 这里就不判断了
//	fclose(pf);
//	pf = NULL; // 好习惯
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r"); //以读的的形式打开一个名为test.txt的文件
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//写文件
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c", ch);
//	}
//	printf("\n");
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}













//#include<stdio.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("打开文件失败\n");
//		return 0;
//	}
//	// 写文件
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL; // 好习惯
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("打开文件失败\n");
//		return 0;
//	}
//	// 写文件
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL; // 好习惯
//	return 0;
//}
/// <summary>
/// 1
/// </summary>
/// <returns></returns>
//int main()
//{
//	//打开一个名为test.txt的文件
//	FILE* pf = fopen("test.txt", "w"); 
//	if (pf == NULL)
//	{
//		printf("打开文件失败\n");
//		return 0;
//	}
//	// 写文件
//	return 0;
//}













//#include <stdio.h>
//
//int main()
//{
//
//	return 0;
//}