#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>


//int main()
//{
//    long num = 0;
//    FILE* fp = NULL;
//    if ((fp = fopen("fname.dat", "r")) == NULL)
//    {
//        printf("Can’t open the file! ");
//        exit(0);
//    }
//    while (fgetc(fp) != EOF)
//    {
//        num++;
//    }
//    printf("num=%d\n", num);
//    fclose(fp);
//    return 0;
//}

//int main()
//{
//	//FILE *fopen( const char *filename, const char *mode );
//	FILE* pf = fopen("test.txt", "w");
//	FILE* pf2 = fopen("test2.txt", "r");
//	if (pf2 == NULL)
//	{
//		printf("%s", strerror(errno));
//		fclose(pf);
//		pf = NULL;
//		return 0;
//	}
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputs("abcd\n", pf);
//	fputs("aaaa", pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}