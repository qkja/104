#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

//Î²²å
void TailInsert(struct Node** phead,int x)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	if (newnode != NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
	}
	if (*phead == NULL)
	{
		*phead = newnode;
		return;
	}
	struct Node* cur = *phead;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = newnode;
	
}

//´òÓ¡Á´±í
void display(struct Node* head)
{
	struct Node* cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//int main()
//{
//	struct Node* head = NULL;
//	TailInsert(&head, 1);
//	TailInsert(&head, 2);
//	TailInsert(&head, 3);
//	display(head);
//	return 0;
//}

//void test(int* pa)
//{
//	printf("%p\n", pa);
//	int b = 20;
//	pa = &b;
//}
//void test2(int x)
//{
//	printf("%d", x);
//	x = 20;
//	printf("%d", x);
//}
//int main()
//{
//	int a = 10;
//	test2(a);
//	printf("%d", a);
//	//int* pa = &a;
//	/*printf("%p\n", pa);
//	test(pa);
//	printf("%p\n", pa);*/
//	return 0;
//}
void test(int x)
{
	x = 20;
}

void test2(int* p)
{
	int b = 20;
	p = &b;
}

//int main()
//{
//	int a = 10;
//	printf("%p\n", &a);
//	test2(&a);
//	printf("%p\n", &a);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	test(a);
//	printf("%d", a);
//	return 0;
//}

int x = 5, y = 7;
void swap()
{
	int z;
	z = x;
	x = y;
	y = z;
}
//int main()
//{
//	int x = 3, y = 8;
//	swap();
//	printf("%d,%d\n",x, y);
//	double x[5] = { 2.0, 4.0, 6.0, 8.0, 10.0 };
//	char c2[] = { '\x10', '\xa', '\8' };
//
//	return 0;
//}

int* printNumbers(int n, int* returnSize)
{
	int count = 1;
	for (int i = 1; i <= n; i++)
	{
		count *= 10;
	}
	//1 2 3 4 5 6 7 8 9
	int* p = (int*)malloc(sizeof(int) * (count - 1));
	if (p != NULL)
	{
		for (int j = 1; j < count; j++)
		{
			p[j - 1] = j;
		}
	}

	*returnSize = --count;
	return p;

}

//int main()
//{
//	int n = 2;
//	int size = 0;
//	int* p = printNumbers(n, &size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	
//	return 0;
//}

int countDays(int year, int mon, int day)
{
	int count = 0;
	int arr[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (year % 400 == 10 || (year % 4 == 0 && year % 100 != 0))
	{
		for (int i = 1; i < mon; i++)
		{
			count += arr[i - 1];
		}
		count += day;
		return count;
	}
	for (int i = 1; i < mon; i++)
	{
		count += arr[i - 1];
	}
	count += day;
	if (mon >= 3)
	{
		return count - 1;
	}
	return count;
}

int main()
{
	int year = 0;
	int month = 0;
	int day = 10;
	scanf("%4d %d %d", &year, &month, &day);
	int days = countDays(year, month, day);
	printf("%d", days);
	return 0;
}
