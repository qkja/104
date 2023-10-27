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
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int left = 0;
    int right = 0;
    unordered_map<char, int> m;
    int result = 0;
    for (; right < s.size(); ++right)
    {
      m[s[right]]++;          // 入窗口
      while (m[s[right]] > 1) // 判断
      {
        m[s[left++]]--; // 出窗口
      }
      result = max(result, right - left + 1); // 更新结果
    }
    return result;
  }
};

// class Solution
// {
// public:
//   int lengthOfLongestSubstring(string s)
//   {
//     int left = 0;
//     int right = 0;
//     unordered_set<char> s_char;
//     int result = 0;
//     for (; right < s.size(); ++right)
//     {
//       // 这里需要收集结果
//       while (s_char.find(s[right]) != s_char.end())
//       {
//         result = max(result, right - left); // 更新结果
//         s_char.erase(s[left++]);            // 出窗口
//       }
//       // 入窗口
//       s_char.insert(s[right]);
//     }
//   }
// };

// class Solution
// {
// public:
//   int minSubArrayLen(int target, vector<int> &nums)
//   {
//     int ret = INT_MAX; // 这是结果
//     int left = 0, right = 0;
//     int sum = 0; // 子数组的和
//     int n = nums.size();
//     while (right < n)
//     {
//       sum += nums[right];    // 进窗口
//       while (sum >= target) // 这就是判断,为何是while,可能出现这样的情况  num = [1 1 1 1 1000] target = 10000
//       {
//         ret = min(ret, right - left + 1); // 更新结果
//         sum -= nums[left++];               // 出窗口
//       }
//       right++;
//     }
//     return ret == INT_MAX ? 0 : ret;
//   }
// };

//    https://leetcode.cn/problems/minimum-size-subarray-sum/submissions/
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

// class Solution
// {
// public:
//   int lengthOfLongestSubstring(string s)
//   {
//     if (s.empty())
//       return 0;
//     int begin = 0;
//     int maxLen = 0;
//     int end = 0;
//     unordered_map<char, int> m;
//     for (size_t end = 0; end < s.size(); end++)
//     {
//       // 判断是不是在hash 表呢
//       auto iter = m.find(s[end]);
//       // 判断是不是在hash 表中
//       if (iter == m.end())
//       {
//         // 进窗口
//         m[s[end]] = end;
//         maxLen = max(maxLen, (int)end - begin + 1);
//       }
//       else
//       {
//         while (iter != m.end()) // 找了这个元素
//         {
//           m.erase(s[begin++]);
//           iter = m.find(s[end]);
//         }
//         m[s[end]] = end;
//       }

//       // 更新结果
//     }
//     // maxLen = max(maxLen, (int)end - begin + 1);

//     return maxLen;
//   }
// };
// https://leetcode.cn/problems/max-consecutive-ones-iii/
// class Solution
// {
// public:
//     int longestOnes(vector<int> &nums, int k)
//     {
//         if (nums.empty())
//             return 0;
//         int begin = 0;
//         int end = 0;
//         int result = 0;
//         for (; end < nums.size(); end++)
//         {
//             while (nums[end] == 0 && k == 0)
//             {
//                 if (nums[begin] == 0)
//                 {
//                     k++;
//                 }
//                 begin++;
//             }

//             if (nums[end] == 0 && k != 0)
//             {
//                 k--;
//             }

//             result = max(result, end - begin + 1);
//         }
//         return result;
//     }
// };
// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/
// class Solution
// {
// public:
//     int minOperations(vector<int> &nums, int x)
//     {
//         if (nums.empty())
//             return 0;
//         // 正难则反
//         int sum = 0;
//         for (auto &e : nums)
//             sum += e;

//         x = sum - x;

//         int begin = 0;
//         int end = 0;
//         sum = 0;
//         int minLen = -1;
//         for (; end < nums.size(); end++)
//         {
//             sum += nums[end];
//             while (begin <= end && sum > x)
//             {
//                 sum -= nums[begin++];
//             }
//             // 此时 我们
//             if (sum == x)
//             {
//                 minLen = max(minLen, end - begin + 1);
//             }
//         }
//         return minLen == -1 ? -1 : nums.size() - minLen;
//     }
// };
// https://leetcode.cn/problems/fruit-into-baskets/submissions/
// class Solution
// {
// public:
//     int totalFruit(vector<int> &fruits)
//     {
//         if (fruits.empty())
//             return 0;
//         unordered_map<int, int> m; // val,次数
//         int begin = 0;
//         int end = 0;
//         int result = 0;
//         for (; end < fruits.size(); end++)
//         {
//             // 先来直接入  map
//             m[fruits[end]]++;
//             while (m.size() > 2)
//             {
//                 // 继续  这里开始出
//                 if (--m[fruits[begin]] == 0)
//                     m.erase(fruits[begin]);
//                 begin++;
//             }
//             result = max(result, end - begin + 1);
//         }
//         return  result;
//     }
// };

// https://leetcode.cn/problems/find-all-anagrams-in-a-string/
// class Solution
// {
// public:
//     vector<int> findAnagrams(string s, string p)
//     {
//         vector<int> result;
//         if (s.empty() || p.empty())
//             return result;
//         vector<int> v(26, 0);
//         for (auto e : p)
//         {
//             v[e - 'a']++;
//         }
//         int k = 0;
//         int begin = 0;
//         int end = 0;
//         vector<int> ret(26, 0);
//         for (; end < s.size(); end++)
//         {
//             // 入窗口
//             ret[s[end] - 'a']++;
//             k++;

//             // 判断这个是否是合法的
//             // 不合法
//             while (ret[s[end] - 'a'] > v[s[end] - 'a'])
//             {
//                 ret[s[begin++] - 'a']--;
//                 k--;
//             }

//             if (ret[s[end] - 'a'] <= v[s[end] - 'a'])
//             {
//                 // 首先是 合法的
//                 if (k == p.size())
//                 {
//                     result.push_back(begin);
//                 }
//             }
//         }
//         return result;
//     }
// };

// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/
// class Solution
// {
// public:
//     vector<int> findSubstring(string s, vector<string> &words)
//     {
//         vector<int> result;
//         if (s.empty() || words.empty())
//             return result;

//         int len = words.back().size();
//         int count = 0;
//         int begin = 0;
//         int end = 0;
//         unordered_map<string, int> m1;
//         for (auto &e : words)
//             m1[e]++;

//         int k = 0;
//         unordered_map<string, int> m2;

//         while (k < len)
//         {
//             for (end = k, begin=k,count = 0; end+len <= s.size(); end += len)
//             {
//                 // 进窗口
//                 string str = s.substr(end, len);
//                 m2[str]++;
//                 auto iter = m1.find(str);
//                 if (iter != m1.end() && m2[str] <= iter->second)
//                 {
//                     count++;
//                 }
//                 // 判断是不是要出窗口
//                 if ((end - begin + 1) > len*words.size())
//                 {
//                     string ss = s.substr(begin, len);
//                     // 在这里需要找到的
//                     auto it = m1.find(ss);
//                     if (it != m1.end() && m2[ss] <= m1[ss])
//                         count--;
//                     m2[ss]--;
//                     begin += len;
//                 }
//                 // 更新结果
//                 if (count == words.size())
//                 {
//                     result.push_back(begin);
//                 }
//             }
//             k++;
//             m2.clear();
//         }
//         return result;
//     }
// };
// https://leetcode.cn/problems/minimum-window-substring/submissions/
// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         string result;
//         if (s.size() < t.size())
//             return result;
//         // unordered_map<char, int> m1;
//         // unordered_map<char, int> m2;
//         vector<int> m1(26, 0);
//         vector<int> m2(26, 0);
//         for (auto &e : t)
//             m1[e - 'a']++;

//         int count = 0;
//         for (auto e : m1)
//             if (e)
//                 count++;
//         int k = 0;
//         int begin = 0;
//         int end = 0;
//         for (; end < s.size(); end++)
//         {
//             // 直接如
//             m2[s[end] - 'a']++;
//             // 这里最好不要污染m1
//             // auto iter = m1.find(s[end]);
//             // 这避免一下我们 重复使用
//             // if (iter != m1.end() && m2[s[end]] - 1 < m1[s[end]] && m2[s[end]] >= m1[s[end]])
//             if (m1[s[end] - 'a'] != 0 && m2[s[end] - 'a'] - 1 < m1[s[end] - 'a'] && m2[s[end] - 'a'] >= m1[s[end - 'a']])
//                 k++;
//             while (k == count)
//             {
//                 // 此时绝对可以了
//                 string str = s.substr(begin, end - begin + 1);
//                 if (result.empty())
//                     result = str;
//                 else
//                     result = str.size() < result.size() ? str : result;

//                 // 这里需要出
//                 m2[s[begin - 'a']]--;
//                 // 判断   k 值是否需要变化
//                 // 这里我们重点看到的是  begin的
//                 // auto iter2 = m1.find(s[begin]);
//                 // if (iter2 != m1.end() && m2[s[begin]-'a'] < m1[s[begin]-'a'])
//                 if (m1[s[begin] - 'a'] != 0 && m2[s[begin] - 'a'] < m1[s[begin] - 'a'])
//                     k--;
//                 begin++;
//             }
//         }
//         return result;
//     }
// };

// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         string result;
//         if (s.size() < t.size())
//             return result;
//         unordered_map<char, int> m1;
//         unordered_map<char, int> m2;
//         for (auto &e : t)
//             m1[e]++;
//         int k = 0;
//         int begin = 0;
//         int end = 0;
//         for (; end < s.size(); end++)
//         {
//             // 直接如
//             m2[s[end]]++;
//             // 这里最好不要污染m1
//             auto iter = m1.find(s[end]);
//             // 这避免一下我们 重复使用
//             if (iter != m1.end() && m2[s[end]]-1<m1[s[end]]&&    m2[s[end]] >= m1[s[end]])
//                 k++;
//             while (k == m1.size())
//             {
//                 // 此时绝对可以了
//                 string str = s.substr(begin, end - begin + 1);
//                 if (result.empty())
//                     result = str;
//                 else
//                     result = str.size() < result.size() ? str : result;

//                 // 这里需要出
//                 m2[s[begin]]--;
//                 // 判断   k 值是否需要变化
//                 // 这里我们重点看到的是  begin的
//                 auto iter2 = m1.find(s[begin]);

//                 if (iter2 != m1.end() && m2[s[begin]] < m1[s[begin]])
//                     k--;
//                 begin++;
//             }
//         }
//         return result;
//     }
// };

// class Solution
// {
// public:
//     string minWindow(string s, string t)
//     {
//         string result;
//         if (s.empty() || t.empty())
//             return result;
//         int m1[128] = {0};
//         int m2[128] = {0};
//         int kinds = 0;
//         for (auto &e : t)
//         {
//             if (m1[e]++ == 0)
//             {
//                 kinds++;
//             }
//         }

//         int begin = 0;
//         int end = 0;
//         int count = 0; // 统计种类
//         int minLen = INT32_MAX;
//         int index = -1;
//         for (; end < s.size(); end++)
//         {
//             // 直接进窗口
//             m2[s[end]]++;
//             if (m2[s[end]] == m1[s[end]])
//                 count++;

//             while (count == kinds)
//             {
//                 if (end - begin + 1 < minLen)
//                 {
//                     minLen = end - begin + 1;
//                     index = begin;
//                 }
//                 char out = s[begin++];
//                 // 需要判断一下
//                 if (m2[out]-- == m1[out])
//                     count--;
//             }
//         }
//         if(index == -1)
//         return result;
//         return s.substr(index, minLen);
//     }
// };