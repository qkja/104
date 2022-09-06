#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//优化插入排序

void insertSort(int* arr, int len)
{
	assert(arr);
	for (int i = 1; i < len; i++)
	{
		int ret = arr[i];
		int j = i - 1;
		while (j >= 0)
		{
			if (arr[j] > ret)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
			j--;
		}
		arr[j + 1] = ret;
	}
}

//如何优化

//halfInsert函数得到不比arr[keyi]大的最后一个数
int halfInsert(int* arr,int keyi)
{
	assert(arr);

	int left = 0;
	int right = keyi-1;
	
	int ret = arr[keyi];
	while (left <= right)
	{
		int mid = (left + right) >> 1;

		if (arr[mid] <= ret)
		{
			left = mid + 1;
			if (arr[left] > ret)
			{
				return mid;
			}
		}
		else
		{
			right = mid - 1;
		}
	}
	return right;
}

void halfInsertSort(int* arr, int len)
{
	assert(arr);
	for (int i = 1; i < len; i++)
	{
		int keyi = halfInsert(arr, i) + 1;
		int ret = arr[i];
		for (int j = i - 1; j >= keyi; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[keyi] = ret;
	}
}

void bubbleSort1(int* arr, int len)
{
	assert(arr);
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int ret = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = ret;
			}
		}
	}
}

//优化  方案 1
void bubbleSort2(int* arr, int len)
{
	assert(arr);
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int ret = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = ret;
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}

void bubbleSort3(int* arr, int len)
{
	assert(arr);
	int sortBoundary = len - 1;
	for (int i = 0; i < len - 1; i++)
	{
		int flag = 0;
		int lastExchangeIndex = 0;
		for (int j = 0; j < sortBoundary; j++)
		{
			
			if (arr[j] > arr[j + 1])
			{
				int ret = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = ret;
				flag = 1;
				lastExchangeIndex = j;
			}
		}

		sortBoundary = lastExchangeIndex;

		if (0 == flag)
		{
			break;
		}
	}
}
void swap(int* pa, int* pb)
{
	assert(pa && pb);
	int ret = *pa;
	*pa = *pb;
	*pb = ret;
}
//霍尔法

//这次统一选右侧
int PartSort1(int* arr, int left, int right)
{
	assert(arr);
	int keyi = right;
	while (left < right)
	{
		while (left < right && arr[left] <= arr[keyi])
		{
			left++;
		}
		while (left < right && arr[right] >= arr[keyi])
		{
			right--;
		}
		swap(&arr[left], &arr[right]);
	}
	swap(&arr[left], &arr[keyi]);
	return left;
}
//挖坑法

int PartSort2(int* arr, int left, int right)
{
	assert(arr);
	int piti = right;
	int ret = arr[right];
	while (left < right)
	{
		while (left < right && arr[left] <= ret)
		{
			left++;
		}
		arr[piti] = arr[left];
		piti = left;
		while (left < right && arr[right] >= ret)
		{
			right--;
		}
		arr[piti] = arr[right];
		piti = right;
	}
	arr[piti] = ret;
	return piti;
}
//前后指针法

int PartSort3(int* arr, int left, int right)
{
	assert(arr);
	int keyi = right;
	int prev = left -1;
	for (int cur = left; cur < right; cur++)
	{
		if (arr[cur] > arr[keyi] && arr[++prev] != arr[cur])
		{
			swap(&arr[prev], &arr[cur]);
		}
	}
	prev++;
	swap(&arr[keyi], &arr[prev]);
	return prev;
}


//void merge(int* arr, int left, int right,int* ret)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int mid = (left + right) >> 1;
//	merge(arr, left, mid,ret);
//	merge(arr, mid+1, right,ret);
//	int i = left;
//	int s1 = left;
//	int e1 = mid;
//	int s2 = mid + 1;
//	int e2 = right;
//	while (s1 <= e1 && s2 <= e2)
//	{
//		if (arr[s1] <= arr[s2])
//		{
//			ret[i++] = arr[s1++];
//		}
//		else
//		{
//			ret[i++] = arr[s2++];
//		}
//	}
//
//	while (s1 <= e1)
//	{
//		ret[i++] = arr[s1++];
//	}
//	while (s2 <= e2)
//	{
//		ret[i++] = arr[s2++];
//	}
//	memcpy(arr+left, ret+left, sizeof(int) * (right - left + 1));
//}
//
//void mergeSort(int* arr, int len)
//{
//	assert(arr);
//	int* ret = (int*)malloc(sizeof(int) * len);
//	assert(ret);
//	merge(arr, 0, len - 1,ret);
//	free(ret);
//}

//int main()
//{
//	int arr[] = {2,2,3,4,2,3,3,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	mergeSort(arr,sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#define CAP 50000

//int main()
//{
//	
//	srand((unsigned)time(NULL));//种子
//
//	int* arr1 = (int*)malloc(sizeof(int) * CAP);
//	int* arr2 = (int*)malloc(sizeof(int) * CAP);
//	assert(arr1 && arr2);
//	for (int i = 0; i < CAP; i++)
//	{
//		int n = rand() % CAP + 1;
//		arr1[i] = n;
//		arr2[i] = n;
//	}
//	int begin1 = clock();
//	bubbleSort3(arr1, CAP);
//	int end1 = clock();
//
//	int begin2 = clock();
//	bubbleSort1(arr2, CAP);
//	int end2 = clock();
//	printf("bubbleSortIndex     %d\n", end1 - begin1);
//	printf("bubbleSort          %d\n", end2 - begin2);
//	free(arr1);
//	free(arr2);
//	return 0;
//}

int* sortTwoArray(int* arr1, int len1, int* arr2, int len2, int* returnSize)
{
	assert(arr1 && arr2);
	*returnSize = len1 + len2;
	int* array = (int*)malloc(sizeof(int) * (len1 + len2));
	assert(array);
	int s1 = 0;
	int e1 = len1-1;

	int s2 = 0;
	int e2 = len2-1;
	int i = 0;
	while (s1 <= e1 && s2 <= e2)
	{
		if (arr1[s1] <= arr2[s2])
		{
			array[i++] = arr1[s1++];
		}
		else
		{
			array[i++] = arr2[s2++];
		}
	}

	while (s1 <= e1)
	{
		array[i++] = arr1[s1++];
	}
	while (s2 <= e2)
	{
		array[i++] = arr2[s2++];
	}
	return array;
}

//int main()
//{
//	int arr1[] = { 1,3};
//	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//	int arr2[] = { 2,4,6,8,10};
//	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//	int count = 0;
//	int* array = sortTwoArray(arr1, sz1, arr2, sz2,&count);
//
//	for (int i = 0; i < count; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	return 0;
//}
//non - recursive
void mergeSortNoR(int* arr, int len)
{
	assert(arr);
	int* ret = (int*)malloc(sizeof(int)*len);
	assert(ret);
	int gap = 1;
	while (gap < len)
	{
		for (int i = 0; i < len; i+=2*gap)
		{
			int left = i;
			int mid = left + gap - 1;
			if (mid >= len)
			{
				mid = len - 1;
			}
			int right = mid + gap;
			if (right >= len)
			{
				right = len - 1;
			}

			int j = left;

			int s1 = left;
			int e1 = mid;

			int s2 = mid+1;
			int e2 = right;

			while (s1 <= e1 && s2 <= e2)
			{
				if (arr[s1] <= arr[s2])
				{
					ret[j++] = arr[s1++];
				}
				else
				{
					ret[j++] = arr[s2++];
				}
			}

			while (s1 <= e1)
			{
				ret[j++] = arr[s1++];
			}
			while (s2 <= e2)
			{
				ret[j++] = arr[s2++];
			}
		}
		memcpy(arr, ret , sizeof(int) * len);
		gap *= 2;
	}
	free(ret);
}

//int main()
//{
//	int arr[] = { 3,3,4,5,6,7,3,3,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	mergeSortNoR(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

void CountSort(int* arr, int len)
{
	assert(arr);
	//计算  最大值   最小值

	int max = arr[0];
	int min = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	//900 999
	//开辟空间
	int* cur = (int*)calloc(max - min + 1, sizeof(int));
	assert(cur);
	for (int i = 0; i < len; i++)
	{
		int index = arr[i] - min;
		cur[index]++;
	}
	//放到数组中 ，从后方放吧
	int j = len - 1;
	for (int i = max - min; i >=0; i--)
	{
		while (cur[i] > 0)
		{
			arr[j--] = i + min;
			cur[i]--;
		}
	}
	free(cur);
	cur = NULL;
}

int main()
{
	int arr[] = {1,1,1,1,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
