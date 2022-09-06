#define _CRT_SECURE_NO_WARNINGS 1

#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include <stdio.h>
#include <string.h>
#include <errno.h>

#endif

int main()
{
	FILE* pf1 = fopen("test1.txt", "w");
	if (pf1 == NULL)
	{
		printf("%s", strerror(errno));
	}
	//写第一个文件
	int ch = 0;
	while ((ch = getchar()) != '\n')
	{
		fputc(ch, pf1);
	}

	fclose(pf1);

	//以 读 的形式打开第一个文件
	pf1 = fopen("test1.txt", "r");

	FILE* pf2 = fopen("test2.txt", "w");
	if (pf2 == NULL)
	{
		printf("%s", strerror(errno));
	}
	//拷贝第一个文件 到 第二个文件
	while ((ch = fgetc(pf1)) != EOF)
	{
		fputc(ch, pf2);
	}

	//继续写 第二个文件
	while ((ch = getchar()) != '\n')
	{
		fputc(ch, pf2);
	}

	//关闭文件
	fclose(pf1);
	fclose(pf2);
	pf1 = NULL;
	pf2 = NULL;
	return 0;
}


//int main()
//{
//	FILE* pf = fopen("test1.txt", "w");
//	int ch = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		printf("%c", ch);
//	}
//	scanf("%c", &ch);
//	printf("\nc == %c", ch);
//	
//
//	/*char str1[100] = 
//	char* p = "ssssss  aaass";
//	fprintf(pf, "%s", p);*/
//
//	/*char* p = "arrrrr\nssss";
//	fputs(p, pf);
//	fclose(pf);
//	pf = NULL;
//	pf = fopen("test1.txt", "r");
//	FILE* pfw = fopen("test2.txt", "w");
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		fputc(ch, pfw);
//	}
//	char str = 0;
//	while ((str = getchar()) != '\n')
//	{
//		fputc(str, pfw);
//	}
//*/
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test1.txt", "w");
//	char* p = "arrrrr\nssss";
//	fputs(p, pf);
//	fclose(pf);
//	pf = NULL;
//	pf = fopen("test1.txt", "r");
//	FILE* pfw = fopen("test2.txt", "w");
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		fputc(ch, pfw);
//	}
//	char str = 0;
//	while ((str = getchar()) != '\n')
//	{
//		fputc(str, pfw);
//	}
//	
//	return 0;
//}

//int missingNumber(int* nums, int numsSize)
//{
//	assert(nums);
//	int ret = 0;
//	for (int i = 0; i <= numsSize; i++)
//	{
//		ret ^= i;
//	}
//	for (int i = 0; i<numsSize; i++)
//	{
//		ret ^= nums[i];
//	}
//	return ret;
//}

//void fun(int n) 
//{
//	int i = 1;
//	while (i <= n)
//		i = i * 2;
//}

//for (int i = 0; i < n; i++)
//{
//	for (int j = 0; j < n; j++)
//	{
//		a[i][j] = i*j;
//	}
//	
//}

//void rotate(int* nums, int numsSize, int k){
//	assert(nums);
//	for (int j = 0; j<k; j++)
//	{
//		int ret = nums[numsSize - 1];
//		for (int i = numsSize - 1; i > 0; i--)
//		{
//			nums[i] = nums[i - 1];
//		}
//		nums[0] = ret;
//	}
//}
