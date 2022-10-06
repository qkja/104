#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;


//day 2
// 常量指针 const int* p ;
// 指针常量 int* onst p ;
//排序子序列

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v;
	v.reserve(n + 1);

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ret;
		v.push_back(ret);
	}
	// 这个的作用  避免越界
	// 也避免 1 2 3 2 2 这种情况
	v[n] = 0;

	// 计数器 
	int count = 0;
	int i = 0; // 这个是一个循环
	while (i < n)
	{
		// 非递减序列
		if (v[i] < v[i + 1])
		{
			// 主意不能一直加 范围 i+1也会越界
			while (i < n && v[i] <= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
		else if (v[i] == v[i + 1])
		{
			i++;
		}
		else
		{
			while (i < n && v[i] >= v[i + 1])
			{
				i++;
			}
			count++;
			i++;
		}
	}
	cout << count << endl;
	return 0;
}

////////////////////////////////////////////////////////
// day 1
// 循环输入
//int main()
//{
//	int n = 0;
//	while (cin >> n)
//	{
//		cout << n << endl;;
//	}
//	return 0;
//}

// 组队竞赛
//int main()
//{
//	int n = 0;
//	cin >> n;
//	if (n <= 0)
//		return 0;
//	vector<int> v;
//	v.reserve(3 * n);
//	int ret = 0;
//	for (int i = 0; i < 3 * n; i++)
//	{
//		cin >> ret;
//		v.push_back(ret);
//	}
//	sort(v.begin(), v.end());
//	int sum = 0;
//	for (int i = 0; i < n; i++)
//	{
//		sum += v[3 * n - 2 * (i + 1)];
//	}
//	cout << sum;
//	return 0;
//}
// 删除公共字符串 这里用 hash
//int main() 
//{
//	string str1;
//	string str2;
//	getline(std::cin, str1);
//	getline(std::cin, str2);
//	unordered_set<char> s;
//	// 遍历 str2 放在 set
//	s.insert(str2.begin(), str2.end());
//	// 遍历 str1 在str2对应的  set中找不到
//	string str;
//
//	for (auto ch : str1)
//	{
//		if (s.find(ch) == s.end())
//		{
//			str += ch;
//		}
//	}
//	cout << str;
//	return 0;
//}


//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	Goods()
//	{
//		cout << 1;
//	}
//};
//
//int main()
//{
//	vector<Goods*> v;
//	v.resize(2);
//	return 0;
//}