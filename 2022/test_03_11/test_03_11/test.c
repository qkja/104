#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int func(int x)
{
	int arr[9] = { -1 };
	int j = 0;
	int sum = 0;
	//12
	while (x != 0)
	{
		int ret = x % 10;
		int i = 0;
		for (; i < j; i++)
		{
			if (arr[i] == ret)
			{
				break;
			}
		}

		if (i == j)
		{
			arr[j++] = ret;
			sum = sum * 10 + ret;
		}
		x /= 10;
	}
	return sum;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = func(n);
	printf("%d\n", ret);
	return 0;
}