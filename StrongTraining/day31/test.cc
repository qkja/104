// write your code here cpp
// #include <iostream>
// #include <unordered_map>
// using namespace std;
// // 这里只计算平年
// static int sumMonthDays[13] = { 0,31,59,90,120,151,181,
// 212,243,273,304,334,365 };
// int DayofWeek(long long days,  int index)
// {
// 	int ret = (days % 7 + index) % 7;
// 	if (ret == 0)
// 		ret = 7;
// 	return ret;
// }
// // 这里保存一下 2020年的节日信息
// bool IsLeap(int year)
// {
// 	return year % 400 == 0
// 		|| (year % 4 == 0 && year % 100 != 0);
// }

// int Print(int year, int month, int n,int day)
// {
// 	long long sumDay = 0;
// 	for (int i = 2000; i < year; i++)
// 	{
// 		sumDay += 365;
// 		if (IsLeap(i))
// 			sumDay += 1;
// 	}
// 	int ret = DayofWeek(sumDay,6);
	
// 	// 这里涉及成 大型数组
// 	//初始化
// 	int days = sumMonthDays[month-1];
// 	if (month > 2 && IsLeap(year))
// 		days++;
// 	days = DayofWeek(days, ret);

// 	int arr[6][7] = { 0 };

// 	// 这里知道第一个 1号是周几
// 	// 假设 2 1 浩 6
// 	//arr[0][days - 1] = 1;
// 	int row = 0;
// 	int col = days - 1;
// 	int sub = sumMonthDays[month]
// 		- sumMonthDays[month - 1];
// 	if (month == 2 && IsLeap(year))
// 		sub++;
// 	for (int i = 0; i < sub; i++)
// 	{
// 		if (col == 7)
// 		{
// 			col = 0;
// 			row++;
// 		}
// 		arr[row][col++] = i + 1;
// 	}


// 	if (day == 0)
// 	{
// 		for (int i = 5; i >= 0; i--)
// 		{
// 			if (arr[i][0] != 0)
// 				return arr[i][0];
// 		}
// 	}
// 	else
// 	{
// 		for (int i = 0; i < row; i++)
// 		{
// 			if (arr[i][day - 1] != 0)
// 			{
// 				return arr[i+n-1][day - 1];
// 			}
// 		}
		
// 	}
// 	return 0;
// }

// int main()
// {
// 	int year = 0;

// 	while (cin >> year)
// 	{
		
// 		printf("%d-%02d-%02d\n", year, 1, 1);
// 		printf("%d-%02d-%02d\n", year, 1, Print(year, 1, 3, 1));
// 		printf("%d-%02d-%02d\n", year, 2, Print(year, 2, 3, 1));
// 		printf("%d-%02d-%02d\n", year, 5, Print(year, 5, 3, 0)); //
// 		printf("%d-%02d-%02d\n", year, 7, 4);
// 		printf("%d-%02d-%02d\n", year, 9, Print(year, 9, 1, 1));
// 		printf("%d-%02d-%02d\n", year, 11, Print(year, 11, 4, 4));
// 		printf("%d-%02d-%02d\n", year, 12, 25);

//         cout << endl;
// 	}
// 	return 0;
// }
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
// 这里在处理素数的途中,我们计算
void is_prime_number(int val, string& result) {
    for (int i = 2; val > 1 && i <= sqrt(val); i++) {
        while (val % i == 0) {
            if (result.empty()) {
                result +=  to_string(i);
            } else  {
                result += " * " + to_string(i);
            }
            val /= i;
        }
    }
    if (val != 1 && !result.empty())
        result += " * " + to_string(val);
    else if (val != 1 && result.empty())
        result +=  to_string(val);

}

int main() {
    int n = 0;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> v;
        string result;
        is_prime_number(n, result);
        cout << n << " = ";
        cout << result << endl;
        // 那指数进行相除,最好可以得到质数
    }
}
// 64 位输出请用 printf("%lld")