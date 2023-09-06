#define _CRT_SECURE_NO_WARNINGS 1

/*
2022-09-27 17:20:37
利用好回溯
要想sum > muliti 必须得有一个数为1，
不满足幸运口袋时，当前数可能是1，可能后面还有满足幸运口袋的情况
直接count += 递归后面的

1 1 3 5 7
1 --》 1 1 --》 1 1 3 --》 1 1 3 5回溯
1 1 5 --》 1 1 5 7 回溯 --》1 1 7
--》 。。。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetLuckyPacketNum(int n, vector<int>& v, int pos, int sum, int multi)
{
	int count = 0;
	for (int i = pos; i < n; ++i)
	{
		sum += v[i];
		multi *= v[i];
		if (sum > multi){
			count = count + 1 + GetLuckyPacketNum(n, v, i + 1, sum, multi);
		}
		else if (v[i] == 1){ // 1 1 3 5 7 也有可能当前数是1，可能后面还是有幸运袋子的
			count += GetLuckyPacketNum(n, v, i + 1, sum, multi);
		}
		else{
			break; // 不是幸运袋子 当前不是，后面的数还要更大，更不可能是，return count就行
		}
		sum -= v[i];
		multi /= v[i]; // 去掉不满足条件的
		// 回溯去重
		while (i < n - 1 && v[i] == v[i + 1])
			++i;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (size_t i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << GetLuckyPacketNum(n, v, 0, 0, 1) << endl;
	return 0;
}





//#include <iostream>
//using namespace std;
//bool is_leap(int year)
//{
//	return (year % 4 == 0 && year % 100 != 0) 
//		|| (year % 400 == 0);
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int day = 0;
//	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	while (std::cin >> year >> month >> day) 
//	{ 
//		int days = day;
//		if (month > 2 && is_leap(year))
//			days++;
//		for (int i = 0; i < month; i++)
//			days += months[i];
//		std::cout << days << std::endl;
//	}
//}
// 64 位输出请用 printf("%lld")