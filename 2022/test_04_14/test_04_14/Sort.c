//#define _CRT_SECURE_NO_WARNINGS 1
//#include "Sort.h"
//
//void InterSort(int* arr,int len)
//{
//	assert(arr);
//	for (int i = 1; i < len; i++)
//	{
//		int j = i - 1;
//		int ret = arr[i];
//		while (j >= 0)
//		{
//			if (arr[j] > ret)
//			{
//				arr[j + 1] = arr[j];
//			}
//			else
//			{
//				break;
//			}
//			j--;
//		}
//		arr[j + 1] = ret;
//	}
//}
//
//void bubbleSort(int* arr, int len)
//{
//	assert(arr);
//	for (int i = 0; i < len - 1; i++)
//	{
//		int flag = 0;
//		for (int j = 0; j < len - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int ret = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = ret;
//				flag = 1;
//			}
//			
//		}
//		if (0 == flag)
//		{
//			break;
//		}
//	}
//}
//
//void shell(int* arr, int len, int gap)
//{
//	assert(arr);
//	for (int i = gap ; i < len; i ++)
//	{
//		int ret = arr[i];
//		int j = i - gap;
//		while (j >= 0)
//		{
//			if (arr[j] > ret)
//			{
//				arr[j + gap] = arr[j];
//			}
//			else
//			{
//				break;
//			}
//			j -= gap;
//		}
//		arr[j + gap] = ret;
//	}
//}
//
//void shellSort(int* arr, int len)
//{
//	assert(arr);
//
//	int gap = len;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		shell(arr, len, gap);
//	}
//}
//void selectSort1(int* arr, int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[j] < arr[i])
//			{
//				int ret = arr[j];
//				arr[j] = arr[i];
//				arr[i] = ret;
//			}
//		}
//	}
//}
//
//void selectSort(int* arr, int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		int mini = left;
//		int maxi = left;
//		for (int i = left; i <= right; i++)
//		{
//			if (arr[i] < arr[mini])
//			{
//				mini = i;
//			}
//			if (arr[i] > arr[maxi])
//			{
//				maxi = i;
//			}
//		}
//
//		swap(&arr[left], &arr[mini]);
//		//防止被掉包
//		if (left == maxi)
//		{
//			maxi = mini;
//		}
//
//		swap(&arr[right], &arr[maxi]);
//
//		left++;
//		right--;
//	}
//}
//
//
//void swap(int* pa, int* pb)
//{
//	assert(pa && pb);
//	int ret = *pa;
//	*pa = *pb;
//	*pb = ret;
//}
//
//void HeapSort(int* arr, int len)
//{
//	assert(arr);
//	
//	//建堆  向下调整
//
//	for (int parent = (len - 1 - 1) / 2; parent >= 0; parent--)
//	{
//		adjustDown(arr, len, parent);
//	}
//
//	//交换  
//	for (int i = 0; i < len-1; i++)
//	{
//		swap(&arr[0], &arr[len - 1 - i]);
//		adjustDown(arr, len-1-i, 0);
//	}
//}
//
//void adjustDown(int* arr, int len, int root)
//{
//	//建 大堆
//	assert(arr);
//	int parent = root;
//	int child = 2 * parent + 1;
//	while (child < len)
//	{
//		if (child + 1 < len && arr[child + 1] > arr[child])
//		{
//			child++;
//		}
//		if (arr[child] > arr[parent])
//		{
//			swap(&arr[child], &arr[parent]);
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
//int getMid(int* arr, int left, int right)
//{
//	assert(arr);
//	int mid = (left + right) >> 1;
//	int i = left;
//	if (arr[left] < arr[mid])
//	{
//		if (arr[mid] < arr[right])
//		{
//			return mid;
//		}
//		else
//		{
//			if (arr[left] < arr[right])
//			{
//				return left;
//			}
//			else
//			{
//				return right;
//			}
//		}
//	}
//	//3 1 2
//	else
//	{
//		if (arr[mid] > arr[right])
//		{
//			return mid;
//		}
//		else
//		{
//			if (arr[left] < arr[right])
//			{
//				return left;
//			}
//			else
//			{
//				return right;
//
//			}
//		}
//
//	}
//}
//
//void QuickSort(int* arr, int len)
//{
//	assert(arr);
//
//	Quick(arr, 0, len-1);
//}
//
//void Quick1(int* arr, int left, int right)
//{
//	assert(arr);
//
//	if (left >= right)
//	{
//		return;
//	}
//
//	int pos = PartSort3(arr, left, right);
//	Quick(arr, left, pos - 1);
//	Quick(arr, pos + 1, right);
//}
//
//void QuickSort1(int* arr, int len)
//{
//	assert(arr);
//
//	Quick1(arr, 0, len - 1);
//}
//
//void Quick(int* arr, int left, int right)
//{
//	assert(arr);
//
//	if (left >= right)
//	{
//		return;
//	}
//
//	if (right - left + 1 < 13)
//	{
//		InterSort(arr + left, right - left + 1);
//		return;
//	}
//
//	int mid = getMid(arr, left, right);
//	swap(&arr[left], &arr[mid]);
//	int pos = PartSort3(arr, left, right);
//	Quick(arr, left, pos - 1);
//	Quick(arr, pos + 1, right);
//}
//
//int PartSort1(int* arr, int left, int right)
//{
//	assert(arr);
//	
//	int keyi = left;
//	while (left < right)
//	{
//		while (arr[right] > arr[keyi])
//		{
//			right--;
//		}
//		while (left < right && arr[left] <= arr[keyi])
//		{
//			left++;
//		}
//		swap(&arr[left], &arr[right]);
//	}
//	swap(&arr[keyi], &arr[left]);
//	return left;
//}
//
//int PartSort2(int* arr, int left, int right)
//{
//	assert(arr);
//	int ret = arr[left];
//	int piti = left;
//	while (left < right)
//	{
//		while (left < right && arr[right] >= ret)
//		{
//			right--;
//		}
//		arr[piti] = arr[right];
//		piti = right;
//		while (left < right && arr[left] <= ret)
//		{
//			left++;
//		}
//
//		arr[piti] = arr[left];
//		piti = left;
//	}
//	arr[left] = ret;
//	return left;
//}
//
//int PartSort3(int* arr, int left, int right)
//{
//	assert(arr);
//	int prev = left;
//	int keyi = left;
//	for (int cur = left + 1; cur <= right; cur++)
//	{
//		if (arr[cur] < arr[keyi] && arr[cur] != arr[++prev])
//		{
//			swap(&arr[prev], &arr[cur]);
//		}
//	}
//	swap(&arr[keyi], &arr[prev]);
//	return prev;
//}