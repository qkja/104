/**
 * User: Qkj
 * Description: 数据存储
 * Date: 2023-07-18
 * Time: 14:02
 */
#include <stdio.h>
#include <string.h>


//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i<1000; i++)
//	{
//		a[i] = -1 - i;
//		printf("%x\n", a[i]);
//
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf(“%d %d”, a + b, c);
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[30][30] = { 0 };
//	arr[0][0] = 1;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			arr[i][j] = j == 0 ? 1 : arr[i - 1][j] + arr[i - 1][j - 1];
//			printf("%-5d", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

#include<stdio.h>
//int main()
//{
//	int killer = 0;
//	//分别假设凶手是a,b,c,d,看谁是凶手时满足3个人说了真话，一个人说了假话
//	for (killer = 'a'; killer <= 'd'; killer++)
//	{
//		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
//			printf("凶手是：%c", killer);
//	}
//	return 0;
//}

#include <stdio.h>

void swapArgs(int * a, int * b) //交换函数
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void diveRank(int * p, int n)
{
	if (n >= 5) //此时的n也是用来控制循环层数的。
	{
		if ((p[1] == 2) + (p[0] == 3) == 1 && //B第二，我第三
			(p[1] == 2) + (p[4] == 4) == 1 && //我第二，E第四
			(p[2] == 1) + (p[3] == 2) == 1 && //我第一，D第二
			(p[2] == 5) + (p[3] == 3) == 1 && //C最后，我第三
			(p[4] == 4) + (p[0] == 1) == 1)   //我第四，A第一
			//由于此时是执行的全排列，所以查重也省了。
		{
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", p[i]);
			}
			putchar('\n');
		}
		return;
	}

	int i;
	for (i = n; i < 5; i++) //这个递归方式就完成了对1~5的全排列，方法是从后向前不停的执行交换。可以参考改进二和原代码，将这个递归程序写回成循环后，可以更好的理解。
	{
		swapArgs(p + i, p + n);
		diveRank(p, n + 1);
		swapArgs(p + i, p + n);
	}
}

int main()
{
	int p[5] = { 1, 2, 3, 4, 5 }; //当然由于是全排列，所以初值必须给好。

	diveRank(p, 0);

	return 0;
}