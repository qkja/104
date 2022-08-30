#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//
//void swap(int* pa, int* pb)
//{
//	assert(pa && pb);
//	int ret = *pa;
//	*pa = *pb;
//	*pb = ret;
//}
//
//void adjustUp(int* a, int root,int len)
//{
//	assert(a);
//	int parent = root;
//	int child = 2 * root + 1;
//	while (child > 0)
//	{
//		if (child + 1 < len && a[child + 1] > a[child])
//		{
//			child++;
//		}
//		if (a[child] > a[parent])
//		{
//			swap(&a[child], &a[parent]);
//		}
//		else
//		{
//			break;
//		}
//		child = parent;
//		parent = (child - 1) / 2;
//	}
//}
//
//
//
//void adjustDown(int* a, int len)
//{
//	assert(a);
//	//还是保持大堆
//	int parent = 0;
//	int child = 2 * parent + 1;
//	while (child < len)
//	{
//		if (child + 1 < len && a[child + 1] > a[child])
//		{
//			child++;
//		}
//		if (a[child] > a[parent])
//		{
//			swap(&a[child], &a[parent]);
//		}
//		else
//		{
//			break;
//		}
//		parent = child;
//		child = 2 * parent + 1;
//	}
//}
//
//void pop(int* a, int len)
//{
//	assert(a);
//	//交换
//	swap(&a[0], &a[len - 1]);
//	len = len - 1;
//	adjustDown(a, len);
//}
//
//void HeapSort(int* a, int n)
//{
//	assert(a);
//	//建大堆
//	for (int parent = (n - 1 - 1) / 2; parent >= 0; parent--)
//	{
//		adjustUp(a, parent, n);
//	}
//	//排序
//	for (int i = 0; i < n; i++)
//	{
//		pop(a, n - i);
//	}
//}
//
//int main()
//{
//	int arr[] = {5,4,3,2,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	HeapSort(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

