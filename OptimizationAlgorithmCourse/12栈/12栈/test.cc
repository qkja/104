#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using std::stack;
using std::string;
using std::vector;
class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    if (pushed.size() != popped.size())
      return false;
    stack<int> s;
    int index = 0;
    for (int i = 0; i < pushed.size(); i++)
    {
      s.push(pushed[i]);
      while (!s.empty())
      {
        if (s.top() == popped[index])
        {
          s.pop();
          index++;
        }
        else
        {
          break;
        }
      }
    }
    return s.empty();
  }
};

// class Solution
// {
// public:
//   string decodeString(string s)
//   {

//     stack<std::pair<int, string>> s1;

//     string count;
//     string sss;
//     for (char ch : s)
//     {

//       if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
//       {
//         sss += ch;
//       }
//       else if (ch == '[')
//       {
//         int ret = atoi(count.c_str());
//         count.clear();
//         s1.push(make_pair(ret, sss));
//         sss.clear();
//       }
//       else if (ch == ']')
//       {
//         std::pair<int, string> ret = s1.top();
//         s1.pop();
//         string ssss;
//         for (int i = 0; i < ret.first; i++)
//         {
//           ssss += sss;
//         }
//         sss = ssss;
//         sss = ret.second + sss;
//       }
//       else
//       {
//         count += ch;
//       }
//     }
//     return sss;
//   }
// };

// class Solution
// {
// public:
//   int calculate(string s)
//   {
//     if (s.empty())
//       return 0;
//     const std::string op = "+-*/";
//     stack<int> stack_elem; // 保存数据
//     stack<char> stack_op;  // 保存操作
//     vector<int> v;
//     for (int i = 0; i < s.size(); i++)
//     {
//       auto pos = op.find(s[i]);
//       if (pos != std::string::npos)
//         v.push_back(i);
//     }
//     if (v.empty())
//       return atoi(s.c_str());
//     int begin = 0;
//     stack_elem.push(atoi(s.substr(begin, v[0] - begin).c_str()));
//     begin = v[0] + 1;

//     for (int i = 0; i < v.size(); i++)
//     {
//       string right = (i == v.size() - 1) ? s.substr(begin) : s.substr(begin, v[i + 1] - begin);
//       begin = (i == v.size() - 1) ? -1 : v[i + 1] + 1;

//       if (s[v[i]] == '*')
//       {
//         int result = stack_elem.top() * atoi(right.c_str());
//         stack_elem.pop();
//         stack_elem.push(result);
//       }
//       else if (s[v[i]] == '/')
//       {
//         int result = stack_elem.top() / atoi(right.c_str());
//         stack_elem.pop();
//         stack_elem.push(result);
//       }
//       else
//       {
//         stack_elem.push(atoi(right.c_str()));
//         stack_op.push(s[v[i]]);
//       }
//     }
//     stack<int> stack_elem_r; // 保存数据
//     stack<char> stack_op_r;  // 保存操作
//     string result;

//     while (!stack_elem.empty())
//     {
//       stack_elem_r.push(stack_elem.top());
//       stack_elem.pop();
//     }

//     while (!stack_op.empty())
//     {
//       stack_op_r.push(stack_op.top());
//       stack_op.pop();
//     }

//     while (!stack_op_r.empty())
//     {
//       // 这里修改一下把.
//       int left = stack_elem_r.top();
//       stack_elem_r.pop();
//       int right = stack_elem_r.top();
//       stack_elem_r.pop();
//       int result = 0;
//       switch (stack_op_r.top())
//       {
//       case '-':
//         result = left - right;
//         break;
//       case '+':
//         result = left + right;
//         break;
//       default:
//         break;
//       }
//       stack_elem_r.push(result);
//       stack_op_r.pop();
//     }

//     return stack_elem_r.top();
//   }
// };
// int main()
// {
//   Solution().calculate("3+2*2");
//   return 0;
// }
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