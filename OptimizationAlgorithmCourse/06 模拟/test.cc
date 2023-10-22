/**
 * User: Qkj
 * Description:模拟
 * Date: 2023-07-09
 * Time: 22:07
 */
#include <string>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
// class Solution
// {
// public:
//   string modifyString(string s)
//   {
//     for (int i = 0; i < s.size(); i++)
//     {
//       int prev = i - 1;
//       int next = i + 1;
//       if (s[i] == '?')
//       {
//         if (prev >= 0)
//         {
//           // 只需要关心 next的
//           if (next < s.size())
//           {
//             if (s[next] != '?')
//             {
//               for (int j = 0; j < 26; j++)
//               {
//                 if ('a' + j != s[prev] && 'a' + j != s[next])
//                 {
//                   s[i] = 'a' + j;
//                   break;
//                 }
//               }
//             }
//             else
//             {
//               s[i] = s[prev] == 'z' ? 'a' : s[prev] + 1;
//             }
//           }
//           else if (next == s.size())
//           {
//             s[i] = s[prev] == 'z' ? 'a' : s[prev] + 1;
//           }
//         }
//         else
//         {
//           if (next < s.size())
//           {
//             if (s[next] != '?')
//             {
//               for (int j = 0; j < 26; j++)
//               {
//                 if ('a' + j != s[next])
//                 {
//                   s[i] = 'a' + j;
//                   break;
//                 }
//               }
//             }
//             else
//             {
//               s[i] = 'a';
//             }
//           }
//           else if (next == s.size())
//           {
//             s[i] = 'a';
//           }
//         }
//       }
//     }
//     return s;
//   }
// };

// https://leetcode.cn/problems/teemo-attacking/
// class Solution
// {
// public:
//   int findPoisonedDuration(vector<int> &timeSeries, int duration)
//   {
//     if (timeSeries.empty())
//       return 0;
//     int maxLen = timeSeries[0] + duration - 1;
//     int result = 0;
//     if(timeSeries.size() == 1)
//     {
//       result+= duration;
//     }    for (int i = 1; i < timeSeries.size(); i++)
//     {
//       if (timeSeries[i] > maxLen)
//       {
//         result += duration;
//         maxLen = timeSeries[i] + duration - 1;
//       }
//       else
//       {
//         result += timeSeries[i] - timeSeries[i - 1] + 1;
//         maxLen = timeSeries[i] + duration - 1;
//       }
//     }
//     return result;
//   }
// };
// class Solution
// {
// public:
//   int findPoisonedDuration(vector<int> &timeSeries, int duration)
//   {
//     if (timeSeries.empty())
//       return 0;
//     int begin = timeSeries[0];
//     int end = begin + duration - 1;
//     int result = 0;
//     for (int i = 1; i < timeSeries.size(); i++)
//     {
//       if (timeSeries[i] > end)
//       {
//         result += (end - begin + 1);
//         begin = timeSeries[i];
//         end = begin + duration - 1;
//       }
//       else
//       {
//         result += (timeSeries[i] - begin);
//         begin = timeSeries[i];
//         end = begin + duration - 1;
//       }

//     }
//     return result+duration;
//   }
// };
// https://leetcode.cn/problems/zigzag-conversion/
// class Solution
// {
// public:
//   string convert(string s, int numRows)
//   {
//     if (numRows >= s.size())
//       return s;
//     string ret;
//     for (int i = 0; i < numRows; i++)
//     {
//       int n = i == numRows - 1 ? 1 : 2 * (numRows - i - 1);
//       for (int j = 0; j * n < s.size(); j++)
//       {
//         ret += s[i + j * n];
//       }
//     }
//     return ret;
//   }
// };

// class Solution
// {
// public:
//   string convert(string s, int numRows)
//   {
//     if (numRows == 1 || numRows >= s.size())
//       return s;
//     string ret;
//     int d = 2 * numRows - 2;
//     int n = s.size();
//     // 第一行
//     for (int i = 0; i < s.size(); i += d)
//       ret += s[i];
//     // 中间行
//     for (int k = 1; k < numRows - 1; k++)
//     {
//       for (int i = k, j = d - k; i < n || j < n; i += d, j += d)
//       {
//         if (i < n)
//           ret += s[i];
//         if (j < n)
//           ret += s[j];
//       }
//     }
//     for (int i = numRows - 1; i < s.size(); i += d)
//       ret += s[i];
//     return ret;
//   }
// };
// https://leetcode.cn/problems/count-and-say/
// class Solution
// {
// public:
//   string countAndSay(int n)
//   {
//     string result = "1";
//     for (int i = 1; i < n; i++)
//     {
//       string tmp;
//       for (int left = 0, right = 0; right < result.size();)
//       {
//         while (right < result.size() && result[right] == result[left])
//         {
//           right++;
//         }
//         tmp += to_string(right-left) + result[left];
//         left = right;
//       }
//       result = tmp;
//     }
//     return result;
//   }
// };
// https://leetcode.cn/problems/minimum-number-of-frogs-croaking/submissions/
#include <unordered_map>
class Solution
{
public:
  int minNumberOfFrogs(string croakOfFrogs)
  {
    string ret = "croak";
    int n = ret.size();
    vector<int> hash1(n);
    unordered_map<char, int> index;
    for (int i = 0; i < n; i++)
      index[ret[i]] = i;

    for (int i = 0; i < croakOfFrogs.size(); i++)
    {
      if (croakOfFrogs[i] == 'c')
      {
        if (hash1[n - 1] != 0)
          hash1[n - 1]--;
        // 必须++
        hash1[0]++;
      }
      else
      {
        int j = index[croakOfFrogs[i]];
        if (hash1[j - 1] == 0)
          return -1;
        hash1[j - 1]--;
        hash1[j]++;
      }
    }
    for (int i = 0; i < n - 1; i++)
      if (hash1[i] != 0)
        return -1;
    return hash1[n - 1];
  }
};