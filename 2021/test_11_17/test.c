#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>




//#include<stdio.h>
//
//void Reverse(char* p, int sz)
//{
//	//ab
//	char* star = p;
//	char* end = p + sz - 1;
//
//	while (star < end)
//	{
//		char temp = 0;
//		temp = *star;
//		*star = *end;
//		*end = temp;
//
//		star++;
//		end--;
//	}
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	int ch = 0;
//	int i = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		arr[i] = ch;
//		i++;
//	}
//
//	Reverse(arr, i);
//	printf("%s", arr);
//	return 0;
//}



//int main()
//{
//	int n = 7;
//	int i = 0;
//	//scanf("%d", &n);
//
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <= i; j++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//
//
//	}
//	int k = 0;
//	for (k = 0; k <= n; k++)
//	{
//		int z = 0;
//		for (z = 0; z < k; z++)
//		{
//			printf(" ");
//		}
//		for (z = 0; z <= n - k; z++)
//		{
//			printf("* ");
//		}
//		printf("\n");
//	}
//}
//       *               1  
//     * * *             2            
//   * * * * *           3         
//  

  //    *             
  //   ***
  //  *****
  // *******
  //*********  0 4     9
  // *******   1 5     8
  //  *****    2 
  //   ***     3
  //    *      4


//int main()
//{
//	int n = 13;
//	int m = 13;
//
//	for (int i = 0; i < n; i++)
//	{
//		if (i < n / 2)
//		{
//			for (int j = 0;j <= m / 2 + i ;j++)
//			{
//				if (j < m / 2 - i)
//				{
//					printf(" ");
//				}
//				else
//				{
//					printf("*");
//				}
//
//			}
//		}
//
//		else
//		{
//			for (int j = 0; j < m -(i - m / 2); j++)
//			{
//				if (j < i - m / 2)
//				{
//					printf(" ");
//				}
//				else
//				{
//					printf("*");
//				}
//			}
//		}
//		printf("\n");
//
//		
//
//	}
//	return 0;
//
//}

//#include<stdio.h>
//
//int main()
//{
//	int n = 0;
//	int i = 0;
//	
//	
//	
//		for (i = 0; i < n; i++)
//		{
//			int j = 0;
//			for (j = 0; j < n - i; j++)
//			{
//				printf(" ");
//			}
//			for (j = 0; j <= i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//
//
//		}
//		int k = 0;
//		for (k = 0; k <= n; k++)
//		{
//			int z = 0;
//			for (z = 0; z < k; z++)
//			{
//				printf(" ");
//			}
//			for (z = 0; z <= n - k; z++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	
//	return 0;
//}



	/*	  int main()
	  {

	  }*/
 /*int main()
	  {

	  }*/
//int main()
//{
//	/*int n = 0;
//	int m = 0;*/
//	for (int i = 0; i < 13; i++)
//	{
//		for (int j = 0; j < 13; j++)
//		{
//			
//			if (j < 13 / 2 - i)
//				printf(" ");
//			else
//				printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//void Reverse1(char* p,int sz)
//{
//	//ab
//	char* star = p;
//	char* end = p + sz - 1;
//
//	while (star < end)
//	{
//		char temp = 0;
//
//		temp = *star;
//		*star = *end;
//		*end = temp;
//		star++;
//		end--;
//	}
//}
//
//void Reverse2(char* p1, char* p2,int sz)
//{
//	//aa\0      - 2
//	int c = sz;
//	for (int i = 0; i < c; i++)
//	{
//		*(p2 + i) = *(p1 + sz - 1 - i);
//		//sz--;
//	}
//}

//int main()
//{
//	char arr1[100] = { 0 };
//	char arr2[100] = { 0 };
//	int ch = 0;
//	int i = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		arr1[i] = ch;
//		i++;
//	}
//
//	Reverse1(arr1,arr2, i);
//	printf("%s", arr2);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//int main(int argc, char* argv[])
//{
//
//	char a[100];
//	char b[200];
//	gets(a);
//	int i, c;
//	c = strlen(a);
//	for (i = 0; i <= c; i++)
//		b[i] = a[c - i - 1];
//	printf("%s", b);
//	return 0;
//}

//22  2222 222222

//第一步 判断  是几位数

int JuNum(int num)
{
	int i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}

	return i;
}

//第二步  将  a  ->  aa  ->aaa

int My_power(int y)
{

	int count = 1;
	while (y)
	{
		count *= 10; 
		y--;
	}
	return count;
}

//有瑕疵      --      已修改
int fun(int num, int de,int j)
{
	//11
	int ret = My_power(j); //该乘以 10  还是  10 ....
	num = num * ret;
	return num + de;
}

//int main()
//{
//	printf("%d\n", fun(22, 2, 1));
//	return 0;
//}

//int main()
//{
//	//24690
//	int num = 0;
//	scanf("%d", &num);
//	long sum = 0;
//	int n = JuNum(num);
//	int de = num;
//	for (int i=0;i<5;i++)
//	{
//		sum += num;
//		num = fun(num, de, n);
//	}
//
//	printf("%ld\n", sum);
//	
//	return 0;
//}

//22    2222   222222  22222222  2222222222 

//  2147483647
//  2222222222 

//int main()
//{
//	//printf("%d\n", fun(22, 22, 2));
//	//printf("%d\n", fun(2222, 22, 2));
//	
//	/*printf("%d\n", fun(2,2 ,1));
//	printf("%d\n", fun(22,2 ,1));
//	printf("%d\n", fun(222,2 ,1));
//	printf("%d\n", fun(2222,2 ,1));
//	printf("%d\n", fun(22222,2 ,1));*/
//	/*printf("%d\n", fun(22, 2));
//	printf("%d\n", fun(2222, 2));*/
//	/*printf("%d\n", My_power(1));
//	printf("%d\n", My_power(2));
//	printf("%d\n", My_power(3));*/
//	return 0;
//}









//22 2222 222222
//2 22

//int fun(int num, int j)
//{
//	int count = num;
//	while (j)
//	{
//		num = count;
//		count *= 10;
//		j--;
//		//num = 
//	}
//	return count + num;
//}

//void Alternative_sum(int num)
//{
//	//判断 num 是几位数
//	int j = JuNum(num);
//	long sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		num = fun(num,j);
//		sum += num;
//
//	}
//}

//int main()
//{
//	printf("%d\n", fun(2, 1));
//	printf("%d\n", fun(22, 2));
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//    long ret = Alternative_sum(n);
//	printf("%d\n", ret);
//	return 0;
//}

//void Print(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}

//int My_power(int x, int y)
//{
//	//2  ^   3
//	/*if (0 == y)
//	{
//		return 1;
//	}*/
//
//	int count = 1;
//	while (y)
//	{
//		count *= x; 
//		y--;
//	}
//	return count;
//}

//int My_power(int x, int y)
//{
//	int count = 1;
//	while (y)
//	{
//		count *= x;
//		y--;
//	}
//	return count;
//}
//
//int Judging_daffodil(int num)
//{
//	int target = num;
//	int arr[6] = { 0 };
//	int i = 0;
//
//	while (num)
//	{
//		arr[i] = num % 10;
//		num /= 10;
//		i++;
//	}
//	int j = i;
//	int sum = 0;
//	for (i--; i >= 0; i--)
//	{
//		sum += My_power(arr[i], j);
//	}
//
//	if (sum == target)
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	for (int i = 0; i < 100000; i++)
//	{
//		if (1 == Judging_daffodil(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int main()
//{
//
//
//	if (1 == Judging_daffodil(10))
//	{
//		printf("YES");
//	}
//	/*printf("%d\n", My_power(1, 0));
//	printf("%d\n", My_power(10, 0));*/
//	//printf("%d\n", My_power(10, 1));
//	//printf("%d\n", My_power(10, 2));
//	/*Judging_daffodil(12);
//	printf("\n");
//	Judging_daffodil(2);
//	printf("\n");
//	Judging_daffodil(2000);*/
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//	return 0;
//}

//int main()
//{
//	extern int a;
//	printf("%d", a);
//	return 0;
//}