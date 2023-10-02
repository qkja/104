#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main() 
//{
//	std::string str;
//	std::vector<int> v;
//
//	std::getline(std::cin, str);
//	int begin = 0;
//	while (true)
//	{
//		auto pos = str.find(',',begin);
//		if (pos == std::string::npos)
//		{
//			v.push_back(atoi(str.substr(begin).c_str()));
//			break;
//		}
//		v.push_back(atoi(str.substr(begin, pos - begin).c_str()));
//		begin = pos + 1;
//	}
//
//	int len = v.size();
//	std::vector<std::vector<int>> dp(len, std::vector<int>(len));
//	for (int i = 0; i < len; i++)
//	{
//		dp[0][i] = i == 0 ? (v[i]) : (dp[0][i - 1] + v[i]);
//	}
//		
//	for (int i = 1; i < len; i++)
//	{
//		for (int j = i; j < len; j++)
//		{
//			dp[i][j] = dp[0][j] - dp[0][i - 1];
//		}
//	}
//
//	int sum = 0;
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = i; j < len; j++)
//		{
//			if ((j - i + 1) % 2 == 1)
//				sum += dp[i][j];
//		}
//	}
//	std::cout << sum << std::endl;
//	return 0;
//}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//int main() 
//{
//	std::string str;
//	std::vector<int> v;
//
//	std::getline(std::cin, str);
//	int begin = 0;
//	while (true)
//	{
//		auto pos = str.find(' ', begin);
//		if (pos == std::string::npos)
//		{
//			v.push_back(atoi(str.substr(begin).c_str()));
//			break;
//		}
//		v.push_back(atoi(str.substr(begin, pos - begin).c_str()));
//		begin = pos + 1;
//	}
//	std::unordered_map<int, int> m;
//	int len = v.size();
//	std::vector<int> dp(len, 0);
//	int maxLen = INT_MIN;
//	for (int i = 0; i < len; i++)
//	{
//		auto iter = m.find(v[i]);
//		if (iter == m.end())
//		{
//			// 没有找到
//			dp[i] = i == 0 ? 1 : dp[i - 1] + 1;
//		}
//		else
//		{
//			dp[i] = i - iter->second;
//		}
//		
//		maxLen = std::max(maxLen, dp[i]);
//		if (4 == maxLen)
//		{
//			int a = 0;
//		}
//		m[v[i]] = i;
//
//	}
//	std::cout << maxLen << std::endl;
//	return 0;
//}
//// 64 位输出请用 printf("%lld")

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
//using namespace std;
//// 使用滑动窗口
//int func(std::vector<int>& arr)
//{
//	if (arr.size() == 1)
//		return 1;
//	unordered_map<int, int> m;
//	int maxLen = 0;
//	int left = 0;
//	int right = 0;
//	int len = arr.size();
//	while (right < len)
//	{
//		int val = arr[right++];
//		m[val]++;
//		while (m[val] >1)
//		{
//			int nums = arr[left++];
//			m[nums]--;
//		}
//		maxLen = max(maxLen, right - left);
//	}
//	return maxLen;
//}
//int main()
//{
//	std::string str;
//	std::vector<int> v;
//	std::getline(std::cin, str);
//	int begin = 0;
//	while (true)
//	{
//		auto pos = str.find(' ', begin);
//		if (pos == std::string::npos)
//		{
//			v.push_back(atoi(str.substr(begin).c_str()));
//			break;
//		}
//		v.push_back(atoi(str.substr(begin, pos - begin).c_str()));
//		begin = pos + 1;
//	}
//
//	cout << func(v) << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int bfs(int row, int col,int k, int m, int n, vector<vector<bool>>& b)
//{
//	if (k == 0)
//	{
//		b[row][col] = false;
//		return 0;
//	}
//	// 站在row,col位置
//	for (int i = 0; i < 4; i++)
//	{
//		if (row - 1 >= 0 && col < n && b[row - 1][col])
//		{
//			return 1 + bfs()
//		}
//	}
//}
//
//int main() {
//	int k = 0;
//	int m = 0;
//	int n = 0;
//	cin >> k;
//	cin >> m;
//	cin >> n;
//	vector<vector<bool>> b(m, vector<bool>(n, true));
//	cout << bfs(0, 0, k, m, n, b) << endl;;
//	return 0;
//}
//// 64 位输出请用 printf("%lld")