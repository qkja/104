#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <stack>
#include <algorithm>

using std::string;
using std::stack;

//class Solution {
//public:
//	string removeDuplicates(string s) {
//		if (s.empty())
//			return s;
//		stack<char> sta;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (sta.empty() || sta.top() != s[i])
//				sta.push(s[i]);
//			else
//				sta.pop();
//		}
//		string result;
//		while (!sta.empty())
//		{
//			result += sta.top();
//			sta.pop();
//		}
//		std::reverse(result.begin(), result.end());
//		return result;
//	}
//};