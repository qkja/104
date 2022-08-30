#define _CRT_SECURE_NO_WARNINGS 1




//#include<stdio.h>

//int main()
//{
//
//    int n = 0;
//    while ((scanf("%d", &n)) != EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (j < n - 1 - i)
//                    printf("  ");
//                else
//                    printf("* ");
//            }
//            printf("\n");
//        }
//    }
//   
//    
//    return 0;
//}

//int main()
//{
//	int score[7] = { 0 };
//	int max = 0;
//	int min = 100;
//	int sum = 0;
//	for (int i = 0; i < 7; i++)
//	{
//		scanf("%d", &score[i]);
//
//		max = max > score[i] ? max : score[i];
//		min = min < score[i] ? min : score[i];
//		sum += score[i];
//	}
//	printf("%.2lf\n", (sum - max - min) / 5.0);
//	return 0;
//}

//#include<stdio.h>

//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    printf("%ld", 2 << (n - 1));
//    return 0;
//}
//int main()
//{
//	int n = 0;
//	while ((scanf("%d", &n)) != EOF)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (i == n - 1)
//			{
//				for (int j = 0; j <= i; j++)
//				{
//					printf("* ");
//				}
//				printf("\n");
//				break;
//			}
//			for (int j = 0; j <= i; j++)
//			{
//				if (j == 0 || i == j)
//				{
//					printf("* ");
//				}
//				else
//					printf("  ");
//			}
//			printf("\n");
//		}
//	}
//	
//	
//	return 0;
//}

//#include<stdio.h>

//int add_n(int n)
//{
//	n && (n += add_n(n - 1));
//	return n;
//}



//int main()
//{
//	/*int n = 0;
//	scanf("%d", &n);
//	int ret = add_n(n);
//	printf("%d", ret);*/
//	return 0;
//}

#include<string.h>

void reserve(char* s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char t = s[i];

        //abcde\0
        s[i] = s[len - i - 1], s[len - i - 1] = t;
    }
}

int fmax(int x, int y)
{
    return x > y ? x : y;
}

char* addBinary(char* a, char* b) {
    reserve(a);
    reserve(b);
    //111     111
    // 10     01 
    //

    int len_a = strlen(a);
    int len_b = strlen(b);

    int n = fmax(len_a, len_b);
    int carry = 0;
    int len = 0;
    char* ans = (char*)malloc(sizeof(char) * (n + 2));
    for (int i = 0; i < n; ++i) {
        //111
        //01 
        carry += i < len_a ? (a[i] == '1') : 0;
        carry += i < len_b ? (b[i] == '1') : 0;
        ans[len++] = carry % 2 + '0';
        //1
        carry /= 2;
    }

    if (carry) {
        ans[len++] = '1';
    }
    ans[len] = '\0';
    reserve(ans);

    return ans;
}
