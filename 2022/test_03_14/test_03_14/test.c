#define _CRT_SECURE_NO_WARNINGS 1

//void qsort( void *base, size_t num, size_t width,
//int(__cdecl *compare )(const void *elem1, const void *elem2 ) );
int compare(int* e1,int* e2)
{
	return *e1 - *e2;
}
int main()
{
	int arr[] = { 1, 3, 4, 2, 6, 5, 7, 8, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), compare);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//#include <stdio.h>
//#include <stdlib.h> 
//int compare(int* e1, int* e2)
//{
//	return *e1 - *e2;
//}
//int main()
//{
//	int arr[1000] = { 0 };
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	for (int i = 0; i<n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	qsort(arr, (size_t)k, sizeof(arr[0]), compare);
//
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}