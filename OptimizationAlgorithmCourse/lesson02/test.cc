/**
 * User: Qkj
 * Description:
 * Date: 2023-06-18
 * Time: 19:43
 */
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/
//  class Solution
//  {
//  public:
//    int minSubArrayLen(int target, vector<int> &nums)
//    {
//      if (nums.empty() || target <= 0)
//        return 0;
//      int sum = 0;
//      int minLen = INT32_MAX;
//      int begin = 0;
//      for (size_t end = 0; end < nums.size(); end++)
//      {
//        sum += nums[end];

//       while (begin <= end && sum >= target)
//       {
//         minLen = min(minLen, (int)end - begin + 1);
//         sum -= nums[begin++];
//       }
//     }
//     return minLen ==INT32_MAX ? 0 : minLen;
//   }
// };
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/submissions/
// class Solution
// {
// public:
//   bool isRepeat(int left, int right, string &str)
//   {
//     if (left > right)
//       return false;
//     unordered_set<char> s;
//     for (int i = left; i <= right; i++)
//     {
//       s.insert(str[i]);
//     }
//     return (right - left + 1) == (int)s.size();
//   }

//   int lengthOfLongestSubstring(string s)
//   {
//     if (s.empty())
//       return 0;
//     int begin = 0;
//     int maxLen = 0;
//     int end = 0;
//     for (size_t end = 0; end < s.size(); end++)
//     {
//       if (isRepeat(begin, end, s))
//       {
//         maxLen = max(maxLen, (int)end - begin + 1);
//       }
//       else
//       {
//         while (!isRepeat(begin, end, s))
//         {
//           begin++;
//         }
//       }
//     }
//     // maxLen = max(maxLen, (int)end - begin + 1);

//     return maxLen;
//   }
// };

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    if (s.empty())
      return 0;
    int begin = 0;
    int maxLen = 0;
    int end = 0;
    unordered_map<char, int> m;
    for (size_t end = 0; end < s.size(); end++)
    {
      // 判断是不是在hash 表呢
      auto iter = m.find(s[end]);
      // 判断是不是在hash 表中
      if (iter == m.end())
      {
        // 进窗口
        m[s[end]] = end;
        maxLen = max(maxLen, (int)end - begin + 1);
      }
      else
      {
        while (iter != m.end()) // 找了这个元素
        {
          m.erase(s[begin++]);
          iter = m.find(s[end]);
        }
        m[s[end]] = end;
      }

      // 更新结果
    }
    // maxLen = max(maxLen, (int)end - begin + 1);

    return maxLen;
  }
};