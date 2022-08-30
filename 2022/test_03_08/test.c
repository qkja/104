#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int removeElement(int* nums, int numsSize, int val) 
{
	assert(nums);
	int j = 0;
	for (int i = 0; i < numsSize; i++)
	{
		while(i < numsSize && nums[i] == val)
		{
			i++;
		}
		if (i == numsSize)
		{
			break;
		}
		nums[j++] = nums[i];
	}
	return j;
}
int main()
{
	int arr[] = {1,3,2,3,3,3};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = removeElement(arr,sz,3);
	for (int i = 0; i < ret; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <assert.h>

void func(char* arr, int j)
{
    assert(arr);

    for (int i = 0; i < j; i++)
    {
        printf("%c", arr[i]);
        if ((i + 1) % 8 == 0)
        {
            printf("\n");
        }
    }
    if (j % 8 != 0)
    {
        for (int i = j % 8; i < 8; i++)
        {
            printf("0");
        }
    }
}
int main()
{
    char arr[101] = { 0 };
    int ch = 0;
    int j = 0;
    while ((ch = getchar()) != '\n')
    {
        arr[j++] = ch;
    }
    func(arr, j);
    return 0;
}