#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>



void swap(int* pa, int* pb)
{
	*pa = (*pa) ^ (*pb);
	*pb = (*pa) ^ (*pb);
	*pa = (*pa) ^ (*pb);
}


//1 2 3 4 5 
void fun(int arr[], int sz)
{
	int l = 0;
	int r = sz - 1;

	while (l < r)
	{
		
		swap(&arr[l], &arr[r]);
		l++;
	    r--;
	}
	
}





int romanToInt(char* p)
{
	int sum = 0;
	while (*p != '\0')
	{
		if (*p == 'I')
		{
			if (*(p + 1) == 'V')
			{
				sum += 4;
				p += 2;
			}
			else if (*(p + 1) == 'X')
			{
				sum += 9;
				p += 2;
			}
			else
			{
				sum += 1;
				p++;
			}
		}

		else if (*p == 'X')
		{
			if (*(p + 1) == 'L')
			{
				sum += 40;
				p += 2;
			}
			else if (*(p + 1) == 'C')
			{
				sum += 90;
				p += 2;
			}
			else
			{
				sum += 10;
				p++;
			}

		}

		else if (*p == 'C')
		{
			if (*(p + 1) == 'D')
			{
				sum += 400;
				p += 2;
			}
			else if (*(p + 1) == 'M')
			{
				sum += 900;
				p += 2;
			}
			else
			{
				sum += 100;
				p++;
			}
		}

		else if (*p == 'V')
		{
			sum += 5;
			p++;
		}
		else if (*p == 'L')
		{
			sum += 50;
			p++;
		}
		else if (*p == 'D')
		{
			sum += 500;
			p++;
		}
		else if (*p == 'M')
		{
			sum += 1000;
			p++;
		}

	}
	return sum;
}

int main()
{



	char arr[] = "DCXXI";
	int ret = romanToInt(arr);
	printf("%d\n", ret);
	/*int x = 0x89ABCDEF;
	int c = 0xFF;

	int d = x & c;
	printf("%#x\n", d);
*/

	/*int arr[] = { 1, 2, 3, 4};
	fun(arr, 4);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}*/

	//写一个函数使得数组两端进行对调
	/*int a = 10;
	int b = 20;
	printf("before: a = %d b= %d \n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("after : a = %d b= %d \n",a,b);*/



	//int a = 1;
	////00000000 00000000 00000000 00000001
	////11111111 11111111 11111111 11111110
	////10000000 00000000 00000000 00000010

	//int b = ~a;
	//printf("%d\n", b);
	system("pause");
	return 0;
}
