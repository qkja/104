#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


typedef int HPDataType;
void* AdjustDown(HPDataType* a, size_t size, size_t root)
{
	assert(a);
	int parent = root;
	int chiled = 2 * parent + 1;

	while (chiled < size)
	{
		if (chiled + 1 < size && a[chiled] > a[chiled + 1])
		{
			chiled++;
		}
		if (a[parent] > a[chiled])
		{
			int ret = a[chiled];
			a[chiled] = a[parent];
			a[parent] = ret;
			parent = chiled;
			chiled = 2 * parent + 1;
		}
		else
		{
			break;
		}
		
	}
}