#define  _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<windows.h>

int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	system("pause");
	return 0;
}


//```

//int main()
//{
//	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
//	int*p = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ",*(p+i));
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 10;
//	int c = 10;
//	int*parr[3] = {&a,&b,&c};
//	for (int i = 0; i<3; i++)
//	{
//		printf("*arr[%d] == %d\n",i, *parr[i]);
//	}
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;   
//
//
//	return 0;
//}


//### 指针数组
//
//### 函数指针
//
//## 指针与数组详解
//> 我们都对数组很是了解，对一些指针的的基础知识也不陌生，今天我们就仔细的看看他们之间有什么关系
//
//
//
//
//### 一维数组与指针
//> 先从简单的开始吧，我们从现象中寻找结论
//
//#### 数组名和p的关系
//##### 数组的地址和首元素的地址


//
//##### sizeof（arr）和sizeof（p）
//
//#### 一维数组传参
//
//
//#### 结论
//
//- 数组名是第一个元素的指针
//- arr[i] == *(arr + i)
//- 数组名不可以自增，但是int* p = arr, 的p可以
//- sizeof（arr）和sizeof（p）不一样
//- 一维数组传参传递的是指针
//
//
//### 二维数组与指针的关系
//
//> 二维数组本来就不太好理解，我们重点说一下这些知识点，让我们充分了解什么二维数组的本质
//
//#### 二维数组和一维数组的关系
//#### 二维数组的地址形式
//#### 二维数组名+1
//#### 二维数组传参



//int main()
//{
//	int a = 10;
//	scanf("%d", &a);
//	system("pause");
//	return 0;
//}