#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int* masterMind(char* solution, char* guess, int* returnSize) 
{
	assert(solution && guess);
	int n = 0;
	int m = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (solution[j] == guess[i])
			{
				if (i == j)
				{
					n++;
				} 
				else
				{
					m++;
				}
			}
		}
	}
	int* p = (int*)malloc(sizeof(int) * 2);
	if (p != NULL)
	{
		p[0] = n;
		p[1] = m;
	}
	*returnSize = 2;
	return p;
}

//int main()
//{
//	char arr1[] = "RGBY"; //j
//	char arr2[] = "GGRR"; //i
//	int ret = 0;
//	int* p = masterMind(arr1,arr2,&ret);
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	return 0;
//}
//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	int* p = a + 5; //6
//	int* q = NULL;  //
//	//*q = *(p + 5);//11
//	printf("%d %d\n", *p, *q);
//	return 0;
//}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//#define MAX_NUM (2)
//#define MAX_LENGTH (4)
//#define FOUND 'F'
//int min(int a, int b) 
//{
//    if (a < b)
//        return a;
//    return b;
//}
//int* masterMind(char* solution, char* guess, int* returnSize) {
//    int i = 0;
//    int count = 0;
//    int rs = 0;
//    int ys = 0;
//    int gs = 0;
//    int bs = 0;
//    int rg = 0;
//    int yg = 0;
//    int gg = 0;
//    int bg = 0;
//    int* answer = (int*)malloc(sizeof(int) * 2);
//    answer[0] = 0;
//    answer[1] = 0;
//
//    for (i = 0; i < MAX_LENGTH; i++) {
//        if (i < MAX_LENGTH) {
//            if (guess[i] == solution[i]) {
//                answer[0]++;
//            }
//
//        }
//    }
//    for (i = 0; i < MAX_LENGTH; i++) {
//        if (solution[i] == 'R')
//            ++rs;
//        else if (solution[i] == 'G')
//            ++gs;
//        else if (solution[i] == 'B')
//            ++bs;
//        else if (solution[i] == 'Y')
//            ++ys;
//        else
//            solution[i] == FOUND;
//    }
//    for (i = 0; i < MAX_LENGTH; i++) {
//        if (guess[i] == 'R')
//            ++rg;
//        else if (guess[i] == 'G')
//            ++gg;
//        else if (guess[i] == 'B')
//            ++bg;
//        else if (guess[i] == 'Y')
//            ++yg;
//        else
//            guess[i] == FOUND;
//    }
//    count += min(rs, rg) + min(gs, gg) + min(bs, bg) + min(ys, yg);
//    answer[1] = count - answer[0];
//    *returnSize = MAX_NUM;
//    return answer;
//}
int* twoSum(int* numbers, int numbersLen, int target, int* returnSize)
{
	// write code here
	assert(numbers);
	*returnSize = 2;
	int* p = (int*)malloc(sizeof(int) * 2);
	if (p != NULL)
	{
		for (int i = 0; i < numbersLen - 1; i++)
		{
			for (int j = i + 1; j < numbersLen; j++)
			{
				if (numbers[i] + numbers[j] == target)
				{
					p[0] = i+1;
					p[1] = j+1;
					return p;
				}
			}
		}
	}
	
	return NULL;
}

int main()
{
	int arr[] = { 3,2,4 };
	int ret = 0;
	int temp = 6;
	int*p = twoSum(arr, 3, temp, &ret);
	for (int i = 0; i < 2; i++)
	{
		printf("%d ", p[i]);
	}
	return 0;
}

//int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
//	// write code here
//}



