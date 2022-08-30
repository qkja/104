#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf(" %d %d ", a + b, c);
//	return 0;
//}

//int main()
//{
//	unsigned int a = 0x1234; 
//	unsigned char b = *(unsigned char*)&a;
//	printf("%#x", b);
//	return 0;
//}

//int main()
//{
//
//    printf("%d", '\0');
//    char a[1000] = { 0 };
//    int i = 0;
//    for (i = 0; i < 1000; i++)
//    {
//        a[i] = -1 - i;
//    }
//    printf("%d", strlen(a));
//    return 0;
//}

void Triangle(const int n)
{
	int arr[10][10] = { {1},{1,1} };

	/*arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;*/

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (0 == j || i == j)
			{
				arr[i][j] = 1;
			}

			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	Triangle(n);
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	Triangle(n);
//	/*int arr[10][10] = { 0 };
//
//	arr[0][0] = 1;
//	arr[1][0] = 1;
//	arr[1][1] = 1;
//
//	for (int i = 2; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			if (0 == j || i == j)
//			{
//				arr[i][j] = 1;
//			}
//
//			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}*/
//	return 0;
//}

#include<stdio.h>
//int fib(int n)
//{
//	if (n <= 2)
//		return n;
//	return fib(n - 1) + fib(n - 2);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fib(n));
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int fib(int i);
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fib(n));
//	return 0;
//}
//int fib(int n) {//台阶为1,2时走法分别1，2种 1:(1) 2:(1,1),(2)
//				//要走完n阶时，即我第一步要么走的1阶，要么就是2阶，   eg:      上3阶 
//				//若第一步是走1阶的时候，那么还剩n-1个台阶          第一步：走1阶，剩余2阶
//				//若第一步是走2阶的时候，那么还剩n-2个台阶          第一步：走2阶，剩余1阶
//				//即转变为求我走1阶剩余台阶的走法+走2阶时剩余台阶的走法，即可递推到走最后一步的走法有多少种
//	return n <= 2 ? n : fib(n - 1) + fib(n - 2);
//}


//int main()
//{
//	char arr[4] = { 'A','B','C','D' };
//	char i = '0';
//	for (i = '0'; i < '4'; i++)
//	{
//		/*for (int j = 0; j < 4; j++)
//		{
//			arr[j] = i;
//			if()
//		}*/
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	char murd = 0;
//	char arr[4] = { 'A','B','C','D' };
//	int i = 0;
//	while (i < 4)
//	{
//		murd = arr[i];
// 		if ((murd != 'A') + (murd == 'D') + (murd == 'C') + (murd != 'D') == 3)
//		{
//			break;
//		}
//		i++;
//	}
//
//	printf("%c\n", murd);
//	return 0;
//}

#include<stdio.h>

//int main()
//{
//	/*char arr[5] = { 'A','B','C','D','E'};*/
//
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if ((1 == (b == 2) + (a == 3)) &&
//							(1 == (b == 2) + (e == 4)) &&
//							(1 == (c == 1) + (d == 2)) &&
//							(1 == (c == 5) + (d == 3)) &&
//							(1 == (e == 4) + (a == 1)))
//						{
//							if (a * b * c * d * e == 120)
//							{
//								goto end;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//end:
//
//	printf("A = %d\nB = %d\nC = %d\nD = %d\nE = %d\n", a, b, c, d, e);
//
//	return 0;
//}

//int main()
//{
//	/*int a = 1 | 0;
//	int b = 0 | 4;
//	printf("%d", a);
//	printf("%d", b);*/
//	return 0;
//}

int fun(int x)
{

	int count = 1;
	x--;
	while (x)
	{
		count *= 10;
		x--;
	}

	return count;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int arr[10] = { 0 };
	//if (n < 10)
	//{
	//	printf("%d", n % 2);
	//	return 0;
	//}
	////11
	while (n > 0)
	{
		int ret = n % 10;
		arr[i] = ret % 2;
		i++;
		n /= 10;	
	}
	//12   ---    10           2    

	while (i > 0)
	{
		n += arr[i - 1] * fun(i);
		i--;
	}
	printf("%d", n);

	//123
	//3
	return 0;
}