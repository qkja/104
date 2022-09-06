#define _CRT_SECURE_NO_WARNINGS 1
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

void Play_game(void)
{
	int ret = 0;
	int r = rand()%100 + 1;
	
	while (1)
	{
		printf("请输入你的猜测: > ");
	    scanf("%d", &ret);

		if (ret < r)
		{
			printf("猜小了\n");
		}
		else if (ret > r)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}//end of while
}

void menu(void)
{

	printf("******************\n");
	printf("****  0.exit  ****\n");
	printf("****  1.play  ****\n");
	printf("******************\n");

}

int main()
{
	srand((unsigned int)time(NULL));

	int input = 0;
	do
	{
		menu();
		printf("请输入你要选择的数: > ");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Play_game();
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}











//int main()
//{
//
//
//
//
//
//	//int n = 0;
//	//int m = 0;
//	//scanf("%d %d", &n, &m);
//	//int ret = 0;
//	//while (ret = n % m)
//	//{
//	//	n = m;
//	//	m = ret;
//	//}
//	//printf("%d\n", m);
//
//	/*char ch = 98;
//	printf("%c", ch);*/
//	//int n = 0;
//	//scanf("%d", &n);
//	////12
//	//int dev = 0;
//	//int de = 0;
//	//while (n>0)
//	//{
//	//	 dev = n % 10;
//	//	 de = de * 10 + dev;
//	//	 n /= 10;
//	//}
//	//printf("%d", de);
//	//return 0;
//}