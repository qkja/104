#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<errno.h>

//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//typedef struct S s_S;
//
//
//int main()
//{
//	s_S s = { 100, 314, "abcde" };
//	system("pause");
//	return 0;
//}


//int main()
//{
//	//char buf[1024] = { 0 };
//
//	//FILE* pf = fopen("test.txt", "r");
//	//if (pf == NULL)
//	//{
//	//	printf("%s\n", strerror(errno));
//	//	return 0;
//	//}
//
//	/*fgets(buf,1024, pf);
//	puts(buf);
//	puts(buf);
//	puts(buf);*/
//	/*fgets(buf,1024, pf);
//	printf("%s\n", buf);*/
//	/*fgets(buf, 1024, pf);
//	printf("%s", buf);
//	fgets(buf, 1024, pf);
//	printf("%s", buf);*/
//
//	//fgetc   获取   到屏幕
//	//fputc   输出   之文件
//	/*fputc('q', pf);
//	fputc('k', pf);
//	fputc('j', pf);*/
//
//	//int ch = fgetc(pf);
//	//printf("%c", ch);
// //   ch = fgetc(pf);
//	//printf("%c", ch);
// //   ch = fgetc(pf);
//	//printf("%c", ch);
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//
//	//写文件
//	fclose(pf);
//	pf = NULL;
//	//关闭文件
//
//	/*int ch = fgetc(stdin);
//	fputc(ch, stdout);
//	ch = fgetc(stdin);
//	fputc(ch, stdout);*/
//	//FILE *pfRead = fopen("main.txt", "r");
//	//if (pfRead == NULL)
//	//{
//	//	printf("%s\n", strerror(errno));
//	//}
//
//
//	//printf("%c", fgetc(pfRead));
//	//printf("%c", fgetc(pfRead));
//	//printf("%c", fgetc(pfRead));
//	///*fputc('b', pfWrite);
//	//fputc('i', pfWrite);
//	//fputc('t', pfWrite);*/
//
//	//fclose(pfRead);
//	//pfRead = NULL;
//	/*FILE *pfWrite = fopen("main.txt", "w");
//	if (pfWrite == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	fputc('b', pfWrite);
//	fputc('i', pfWrite); 
//	fputc('t', pfWrite);
//
//	fclose(pfWrite);
//	pfWrite = NULL;*/
//	//FILE* pf = fopen("D:\\码云库\\test_10_30_2\\test_10_30_2\\test.txt","r");
//	////打开失败  空指针
//
//	//if (pf == NULL)
//	//{
//	//	printf("%s\n",strerror(errno));
//
//	//	printf("lose\n");
//	//}
//	//fclose(pf);
//	//if (pf == NULL)
//	//{
//	//	printf("%s\n", strerror(errno));
//
//	//	printf("lose\n");
//	//}
//	//pf = NULL;
//	//if (pf == NULL)
//	//{
//	//	printf("%s\n", strerror(errno));
//
//	//	printf("lose\n");
//	//}
//
//	//printf("%s\n", strerror(errno));
//	//char *a = "abcde";
//	//FILE* pf = fopen("main.txt", "w");
//	//fwrite(a, 5, 1, pf);
//	//fclose(pf);
//	//pf = NULL;
//	/*_Bool fag = 7;
//	if (fag)
//		printf("heheeh\n");*/
//	//int a = 100000;
//	//FILE* pf = fopen("test.txt", "wb");
//	//fwrite(&a, 4, 1, pf);  //以二进制方式存储
//	//fclose(pf);
//	//pf = NULL;
//
//
//	system("pause");
//	return 0;
//}



//int GetMax(int x, int y)
//{
//	if (x > y)
//	{
//		return x;
//	}
//	return y;
//}
//
//
//
//
//
//int FindMax(int num, ...)
//{
//	va_list arg;
//	va_start(arg, num);
//	int max = va_arg(arg, int);
//	for (int i = 0; i < num - 1; i++)
//	{
//		int x = va_arg(arg, int);
//		if (max < x)
//		{
//			max = x;
//		}
//	}
//	va_end(arg);
//	return max;
//}
//int main()
//{
//	int max = FindMax(5, 1, 2, 3, 9, 7);
//	printf("max = %d\n", max);
//	system("pause");
//	return 0;
//}

//int main()
//{
//
//
//	/*char *ps = "abcd ef";
//	printf("%s", ps);*/
//	system("pause");
//	//int a = 10;
//	//int b = 20;
//	//printf("%d\n", a);
//	//printf("%d %d\n", a,b);
//	///*printf("%d\n", a);*/
//	//int max = GetMax(a, b);
//	//printf("max = %d\n", max);
//	return 0;
//}


//int sum(int a, int b)
//{
//	return a + b;
//}
//double sum(double a, double b)
//{
//	return a + b;
//}
//int main()
//{
//
//	/*int ret = sum(5, 3);
//	double ret1 = sum(1.0, 2.0);*/
//	
//    //C语言中支持重载吗
//	//试试
//	/*int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	if (n == 1|| n == 2)
//	{
//		printf("yes\n");
//	}
//	else
//	{
//	   for (i = 2; i < n - 1; i++)
//	   {
//		   if (n%i == 0)
//		   {
//			  break;
//		   }
//    	}
//	   if (i == n - 1)
//	   {
//		printf("yes\n");
//	   }
//	}*/
//	
//	system("pause");
//	return 0;
//}