#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

//class Solution
//{
//public:
//	string addBinary(string a, string b)
//	{
//		if (a.empty())
//			return b;
//		if (b.empty())
//			return a;
//		std::string result;
//
//		int end1 = a.size() - 1;
//		int end2 = b.size() - 1;
//		int sum = 0;
//		while (end1 >= 0 && end2 >= 0)
//		{
//			sum = a[end1] - '0' + b[end2] - '0' + sum;
//			result += ((sum % 2) + '0');
//			sum /= 2;
//			end1--;
//			end2--;
//		}
//		while (end1 >= 0)
//		{
//			sum = sum + a[end1] - '0';
//			result += ((sum % 2) + '0');
//			sum /= 2;
//			end1--;
//		}
//		while (end2 >= 0)
//		{
//			sum = sum + b[end2] - '0';
//			result += ((sum % 2) + '0');
//			sum /= 2;
//			end2--;
//		}
//		// 判断 sum 值
//		if (sum != 0)
//		{
//			result += '1';
//		}
//		std::reverse(result.begin(), result.end());
//		return result;
//	}
//};

//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		string result;
//		if (strs.empty())
//			return result;
//		vector<std::pair<char, int>> v;
//		for (int i = 0; i < strs.size(); i++)
//		{
//			// 拿到一个字符
//			const auto& str = strs[i];
//			for (int j = 0; j < str.size(); j++)
//			{
//				if (j >= v.size())
//				{
//					v.push_back(std::make_pair(str[j], 1));
//				}
//				else
//				{
//					if (str[j] == v[j].first)
//						v[j].second++;
//					else
//						break;
//				}
//			}
//		}
//		// 判断
//		for (int i = 0; i < v.size(); i++)
//		{
//			if (v[i].second == strs.size())
//				result += v[i].first;
//		}
//		return result;
//	}
//};

//class Solution {
//public:
//	string longestPalindrome(string s)
//	{
//		if (s.empty())
//			return s;
//
//		int n = s.size();
//		vector<vector<bool>> dp(n, vector<bool>(n, false));
//		int index = -1;
//		int maxLen = -1;
//		for (int i = n-1; i >= 0; i--)
//		{
//			for (int j = i; j < n; j++)
//			{
//				if (s[i] == s[j])
//				{
//					if (i == j || i + 1 == j)
//						dp[i][j] = true;
//					else
//						dp[i][j] = dp[i + 1][j - 1];
//
//					if (dp[i][j] && j-i+1 > maxLen)
//					{
//						maxLen = j - i + 1;
//						index = i;
//					}
//				}
//			}
//		}
//		return s.substr(index, maxLen);
//	}
//};

class Solution
{
public:
	string multiplyChild(const string &str, char ch)
	{
		int i = str.size() - 1;
		int count = 0;
		string result;
		while (i >= 0)
		{
			int ret = (str[i] - '0') * (ch - '0');
			result += std::to_string(((ret + count) % 10));
			count = (count + ret) / 10;
			i--;
		}
		if (count != 0)
			result += std::to_string(count % 10);
		reverse(result.begin(), result.end());
		return result;
	}
	// 两个字符串相加
	void addition(string &s1, const string &s2)
	{
		int i = s1.size() - 1;
		int j = s2.size() - 1;
		int count = 0;
		string result;
		while (i >= 0 && j >= 0)
		{
			int ret = (s1[i] - '0') + (s2[j] - '0') + count;
			result += std::to_string(ret % 10);
			count = ret / 10;
			i--;
			j--;
		}
		while (i >= 0)
		{
			// 此时s1还是存在剩余
			int ret = s1[i] - '0' + count;
			result += std::to_string(ret % 10);
			count = ret / 10;
			i--;
		}
		while (j >= 0)
		{
			// 此时s1还是存在剩余
			int ret = s2[j] - '0' + count;
			result += std::to_string(ret % 10);
			count = ret / 10;
			j--;
		}
		if (count != 0)
			result += std::to_string(count);
		reverse(result.begin(), result.end());
		s1 = result;
	}
	string multiply(string num1, string num2)
	{
		if (num1[0] == '0' || num2[0] == '0')
			return "0";
		if (num1.empty())
			return num2;
		if (num2.empty())
			return num1;
		string result;
		string s;
		for (int i = num2.size() - 1; i >= 0; i--)
		{
			// 这里判断一下字符是不是o
			if (num2[i] != '0')
			{
				addition(result, multiplyChild(num1, num2[i]) + s);
			}
			s += "0";
		}
		return result;
	}
};	