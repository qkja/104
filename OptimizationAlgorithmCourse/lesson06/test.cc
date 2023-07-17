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

class Solution
{
public:
  string convert(string s, int numRows)
  {
  }
};