#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using std::stack;
using std::string;
using std::vector;
class Solution
{
public:
  int calculate(string s)
  {
    if (s.empty())
      return 0;
    const std::string op = "+-*/";
    stack<int> stack_elem; // 保存数据
    stack<char> stack_op;  // 保存操作
    vector<int> v;
    for (int i = 0; i < s.size(); i++)
    {
      auto pos = op.find(s[i]);
      if (pos != std::string::npos)
        v.push_back(pos);
    }

    int begin = 0;
    stack_elem.push(atoi(s.substr(begin, v[0] - begin).c_str()));
    begin = v[0] + 1;

    for (int i = 0; i < v.size(); i++)
    {
      string right = (i == v.size() - 1) ? s.substr(begin) : s.substr(begin, v[i + 1] - begin);
      begin = (i == v.size() - 1) ? -1 : v[i + 1] + 1;

      if (s[v[i]] == '*')
      {
        int result = stack_elem.top() * atoi(right.c_str());
        stack_elem.pop();
        stack_elem.push(result);
      }
      else if (s[v[i]] == '/')
      {
        int result = stack_elem.top() / atoi(right.c_str());
        stack_elem.pop();
        stack_elem.push(result);
      }
      else
      {
        stack_elem.push(atoi(right.c_str()));
        stack_op.push(s[v[i]]);
      }
    }
    // 这个时候惊醒便利
    while (!stack_op.empty())
    {
      int right = stack_elem.top();
      stack_elem.pop();
      int left = stack_elem.top();
      stack_elem.pop();
      int result = 0;
      switch (stack_op.top())
      {
      case '-':
        result = left - right;
        break;
      case '+':
        result = left + right;
        break;

      default:
        break;
      }
      stack_elem.push(result);
      stack_op.pop();
    }
    return stack_elem.top();
  }
};

// https://leetcode.cn/problems/backspace-string-compare/submissions/
// class Solution
// {
// public:
//   bool backspaceCompare(string s, string t)
//   {
//     stack<char> stack_s;
//     stack<char> stack_t;
//     for (int i = 0; i < s.size(); i++)
//     {
//       if (stack_s.empty())
//       {
//         if (s[i] == '#')
//           continue;
//         else
//           stack_s.push(s[i]);
//       }
//       else if (s[i] == '#')
//       {
//         stack_s.pop();
//       }
//       else
//       {
//         stack_s.push(s[i]);
//       }
//     }
//     for (int i = 0; i < t.size(); i++)
//     {
//       if (stack_t.empty())
//       {
//         if (t[i] == '#')
//           continue;

//         else
//           stack_t.push(t[i]);
//       }
//       else if (t[i] == '#')
//       {
//         stack_t.pop();
//       }
//       else
//       {
//         stack_t.push(t[i]);
//       }
//     }
//     while (!stack_s.empty() && !stack_t.empty())
//     {
//       if (stack_s.top() != stack_t.top())
//         return false;
//       stack_t.pop();
//       stack_s.pop();
//     }
//     return stack_s.empty() && stack_t.empty();
//   }
// };
// class Solution {
// public:
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
// };