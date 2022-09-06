#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void func1(int a)
//{
//
//}
//
//int func2(void)
//{
//
//	return 0;
//}
//
//int main()
//{
//	func2();
//	//func2(void);
//	return 0;
//}

//int main()
//{
//	
//	printf("%d", sizeof(void a));
//	return 0;
//}

//int main()
//{
//	void a;
//	return 0;
//}
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digits == NULL)
    {
        return NULL;
    }

    int count = digits[0];
    for (int i = 1; i < digitsSize; i++)
    {
        count = count * 10 + digits[i];
    }
    if (count % 10 == 9)
    {
        *returnSize = digitsSize + 1;
    }
    else
    {
        *returnSize = digitsSize;
    }
    count += 1;
    int* cur = (int*)malloc(sizeof(int) * (*returnSize));
    assert(cur);
    for (int i = *returnSize - 1; i >= 0; i--)
    {
        cur[i] = count % 10;
        count /= 10;
    }
    return cur;
}

int main()
{
    int arr[] = { 9 };
    int count = 0;
    int* cur = plusOne(arr, 1, &count);
    free(cur);
    return 0;
}