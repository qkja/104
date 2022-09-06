#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

#include<errno.h>

//把test.c 的内容拷贝到 test.txt中
//int main()
//{
//
//	FILE* wpf = fopen("test.txt", "w");
//
//	FILE* rpf = fopen("test.c", "r");
//
//	if (rpf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		fclose(wpf);
//		wpf = NULL;
//		return 1;
//	}
//
//	//拷贝
//	int ch = 0;
//	while ((ch = fgetc(rpf)) != EOF)
//	{
//		fputc(ch, wpf);
//	}
//	
//    //关闭文件
//	fclose(rpf);  
//	rpf = NULL;
//	fclose(wpf);
//	wpf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "w");
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//写文件
//	for (int ch = 'a';ch <= 'z'; ch++)
//	{
//		fputc(ch, pf);
//	}
//	printf("\n");
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r"); 
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//写文件
//	int ch = 98;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c", ch);
//	}
//	printf("\n");
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

#define SWAP(n) ((n&0xaaaaaaaa)>>1)|((n&0x55555555)<<1)

//int main()
//{
//	int a = 1;
//	printf("%d", SWAP(a));
//	return 0;
//}
#include <stddef.h>
//struct A
//{
//	int a;
//	char c;
//	double d;
//};

//int main()
//{
//	printf("%d", offsetof(struct A, c));
//	return 0;
//}

struct A
{
	int a;
	char c;
	double d;
};

#define MYOFFSETOF(STRUCT_Name,MEMBER_Name) (int)&(((STRUCT_Name*)0)->MEMBER_Name)
//
//int main()
//{
//	printf("%d\n", offsetof(struct A, d));
//	printf("%d\n", MYOFFSETOF(struct A, d));
//	return 0;
//}

#include<stdio.h>

//int main()
//{
//    int n = 0;
//    while ((scanf("%d", &n) != EOF))
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i == j || i + j  == n-1)
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf(" ");
//                }
//
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

