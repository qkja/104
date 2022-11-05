#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
// write your code here cpp
#include<stdio.h> 
#include<math.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// 回文字符串分割
// 状态  f(i)  表示 前 i 个字符的最小分割次数
// 如何利用 f(i-1) 的结果   我们需要看 所有的情况  
// 前面的i-1个字符我不管 我们需要看看整体是不是回文串不是+1,是就是0
// f(i) = 
class Solution {
public:
    /**
     * 判断回文字符串
     * @param s string字符串
     * @return int整型
     */
    bool IsReply(const string& str)
    {
        int left = 0;
        int right = str.size() - 1;
        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    int minCut(string s) {
        // write code here
        if (s.empty())
            return -1;
        int len = s.size();
        vector<int> result;
        result.resize(len + 1);
        result[0] = 0;
        result[1] = 0;


        for (size_t i = 2; i < len + 1; i++)
        {
            result[i] = i - 1; // 先给一最大值
            // 先判断整体
            if (IsReply(s.substr(0, i)))
            {
                result[i] = 0;
                continue;
            }
            // i = 3  j = 1
            // aab
            for (size_t j = 1; j < i; j++)
            {

                string str = s.substr(j, i - j);
                // a        ab
                //aa // b
                if (IsReply(str))
                {
                    // 这里是回文
                    // 2
                    int len = result[j] + 1;
                    if (len < result[i])
                        result[i] = len;
                }
            }

        }
        return result[len];
    }
};


// f(1) = 0 f(0) = 1
//class Solution {
//public:
//    /**
//     *
//     * @param s string字符串
//     * @return int整型
//     */
//    bool IsReply(string str)
//    {
//        int left = 0;
//        int right = str.size() - 1;
//        while (left < right)
//        {
//            if (str[left] != str[right])
//                return false;
//            left++;
//            right--;
//        }
//        return true;
//    }
//
//    int minCut(string s) {
//        // write code here
//        if (s.empty())
//            return -1;
//        int len = s.size();
//        vector<int> result;
//        result.resize(len + 1);
//        result[0] = 0;
//        result[1] = 0;
//        for (int i = 2; i < len + 1; i++)
//        {
//            int min = 0;
//            cout << min << endl;
//            if (IsReply(s.substr(0, i)))
//            {
//                result[i] = 0;
//                continue;
//            }
//            else
//            {
//                min = result[i-1] + 1;
//            }
//            for (int j = 1; j < i; j++)
//            {
//                // 开始切割
//                string str = s.substr(j, i - j);
//                
//                int len = 0;
//                if (!IsReply(str))
//                    continue;
//                else
//                    len++;
//
//                if (result[j] + len < min)
//                {
//                    min = result[j] + len;
//                }
//            }
//            //cout << min << endl;
//
//            result[i] = min;
//        }
//        //cout << len << endl;
//        return result[len];
//    }
//};
//
//int main()
//{
//    string str = "ab";
//    cout << Solution().minCut(str) << endl;
//    return 0;
//}

//int main()
//{
//	int n, i;
//	while (scanf("%d", &n) != EOF)
//	{
//		printf("%d = ", n);
//		for (i = 2; i <= sqrt(n); i++)
//		{
//			while (n != i)
//			{
//				if (n % i == 0)
//				{
//					printf("%d * ", i);
//					n = n / i;
//				}
//				else break;
//			}
//		}
//		printf("%d\n", n); //这个时候最后一个因素i刚好等于n
//	}
//	return 0;
//}

//#define M 0.0000000001
//bool IsPrime(int ret)
//{
//	if (ret == 1)
//		return false;
//	for (int i = 2; i < ret; i++)
//	{
//		if (ret % i == 0)
//			return false;
//	}
//	return true;
//}
//void Factorization(set<int>& s, int mul)
//{
//
//}
//int main()
//{
//	int ret = 0;
//	set<int> s;
//	while (cin >> ret)
//	{
//		s.clear();
//		for (int i = 2; i <= ret; i++)
//		{
//			int j = ret % 2;
//			double d = (1.0 * ret) / 2;
//			if(abs(d - j) < M && IsPrime(i))
//				s.insert(i);
//		}
//
//		Factorization(s, ret);
//	}
//	return 0;
//}

// 美国节日 这个可以局部优化一下
// 这里只计算平年
//static int sumMonthDays[13] = { 0,31,59,90,120,151,181,
//212,243,273,304,334,365 };
//int DayofWeek(long long days,  int index)
//{
//	int ret = (days % 7 + index) % 7;
//	if (ret == 0)
//		ret = 7;
//	return ret;
//}
//// 这里保存一下 2020年的节日信息
//bool IsLeap(int year)
//{
//	return year % 400 == 0
//		|| (year % 4 == 0 && year % 100 != 0);
//}
//
//int Print(int year, int month, int n,int day)
//{
//	long long sumDay = 0;
//	for (int i = 2000; i < year; i++)
//	{
//		sumDay += 365;
//		if (IsLeap(i))
//			sumDay += 1;
//	}
//	int ret = DayofWeek(sumDay,6);
//	
//	// 这里涉及成 大型数组
//	//初始化
//	int days = sumMonthDays[month-1];
//	if (month > 2 && IsLeap(year))
//		days++;
//	days = DayofWeek(days, ret);
//
//	int arr[6][7] = { 0 };
//
//	// 这里知道第一个 1号是周几
//	// 假设 2 1 浩 6
//	//arr[0][days - 1] = 1;
//	int row = 0;
//	int col = days - 1;
//	int sub = sumMonthDays[month]
//		- sumMonthDays[month - 1];
//	if (month == 2 && IsLeap(year))
//		sub++;
//	for (int i = 0; i < sub; i++)
//	{
//		if (col == 7)
//		{
//			col = 0;
//			row++;
//		}
//		arr[row][col++] = i + 1;
//	}
//
//
//	if (day == 0)
//	{
//		for (int i = 5; i >= 0; i--)
//		{
//			if (arr[i][0] != 0)
//				return arr[i][0];
//		}
//	}
//	else
//	{
//		for (int i = 0; i < row; i++)
//		{
//			if (arr[i][day - 1] != 0)
//			{
//				return arr[i+n-1][day - 1];
//			}
//		}
//		
//	}
//	return 0;
//}
//
//int main()
//{
//	int year = 0;
//
//	while (cin >> year)
//	{
//		
//		printf("%d-%02d-%02d\n", year, 1, 1);
//		printf("%d-%02d-%02d\n", year, 1, Print(year, 1, 3, 1));
//		printf("%d-%02d-%02d\n", year, 2, Print(year, 2, 3, 1));
//		printf("%d-%02d-%02d\n", year, 5, Print(year, 5, 3, 0)); //
//		printf("%d-%02d-%02d\n", year, 7, 4);
//		printf("%d-%02d-%02d\n", year, 9, Print(year, 9, 1, 1));
//		printf("%d-%02d-%02d\n", year, 11, Print(year, 11, 4, 4));
//		printf("%d-%02d-%02d\n", year, 12, 25);
//
//	}
//	return 0;
//}

//int main()
//{
//	int year = 0;
//
//	/*cout << Print(2013, 1, 3, 1) << endl;
//	cout << Print(2013, 2, 3, 1) << endl;
//	cout << Print(2013, 5, 3, 0) << endl;*/
//	/*cout << Print(2014, 1, 3, 1) << endl;
//	cout << Print(2014, 2, 3, 1) << endl;
//	cout << Print(2014, 5, 3, 0) << endl;*/
//	//while (cin >> year)
//	//{
//	//	
//	//	
//	//	printf("%d-%02d-%02d\n", year, 1, 1);
//	//	printf("%d-%02d-%02d\n", year, 1, Print(year, 1, 3, 1));
//	//	printf("%d-%02d-%02d\n", year, 2, Print(year, 2, 3, 1));
//	//	printf("%d-%02d-%02d\n", year, 5, Print(year, 5, 3, 0)); //
//	//	printf("%d-%02d-%02d\n", year, 7, 4);
//	//	printf("%d-%02d-%02d\n", year, 9, Print(year, 9, 1, 1));
//	//	printf("%d-%02d-%02d\n", year, 11, Print(year, 11, 4, 4));
//	//	printf("%d-%02d-%02d\n", year, 12, 25);
//
//	//}
//	return 0;
//}

//int main()
//{
//	printf("%010d", 1);
//	return 0;
//}


//int main()
//{
//	int year = 0;
//	long long sumDay = 0;
//	const int index = 6;
//	//while (cin >> year)
//	while (1)
//	{
//		sumDay = 0;
//		/*for (int i = 2020; i < year; i++)
//		{
//			sumDay += 365;
//			if (IsLeap(i))
//				sumDay += 1;
//		}*/
//		cin >> sumDay;
//		//sumDay--;
//		int ret = (sumDay%7 + index) % 7;
//		if (ret == 0)
//			ret = 7;
//		// 计算 一月一日是 周几
//		cout << ret << endl;
//	}
//	return 0;
//}