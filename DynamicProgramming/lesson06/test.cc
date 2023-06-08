/**
 * User: Qkj
 * Description: 回文串
 * Date: 2023-06-07
 * Time: 23:16
 */
#include <string>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution
{
public:
  int process(int left, int right, string &s)
  {
    if (left >= right)
      return 0;
    int p1 = INT32_MAX;
    int p2 = INT32_MAX;
    int p3 = INT32_MAX;
    if (s[left] == s[right])
      p1 = process(left + 1, right - 1, s);
    else
    {
      // 我们在左侧添加一个
      p2 = 1 + process(left, right - 1, s);
      p3 = 1 + process(left + 1, right, s);
    }
    return min(p1, min(p2, p3));
  }
  int process2(string &s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i; j < n; j++)
      {
        if (i == j)
        {
          dp[i][j] = 0;
        }
        else
        {
          int p1 = INT32_MAX;
          int p2 = INT32_MAX;
          int p3 = INT32_MAX;
          if (s[i] == s[j])
          {
            p1 = dp[i + 1][j - 1];
          }
          else
          {
            p2 = 1 + dp[i + 1][j];
            p3 = 1 + dp[i][j - 1];
          }
          dp[i][j] = min(p1, min(p2, p3));
        }
      }
    }
    return dp[0][n - 1];
  }
  int process3(string &s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i; j < n; j++)
      {
        if (s[i] == s[j])
        {
          if (i == j)
          {
            dp[i][j] = 0;
          }
          else
          {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }
        else
        {
          dp[i][j] = min(1 + dp[i + 1][j], 1 + dp[i][j - 1]);
        }
      }
    }
    return dp[0][n - 1];
  }
  int minInsertions(string s)
  {
    if (s.empty())
      return 0;
    return process(0, s.size() - 1, s);
  }
};

// https://leetcode.cn/problems/longest-palindromic-subsequence/

// class Solution
// {
// public:
//   // [left,right] 中最长回文字串的长度
//   int process(int left, int right, string &s)
//   {
//     if (left > right)
//       return 0;
//     if (left == right)
//       return 1;
//     int p1 = 0;
//     int p2 = 0;
//     int p3 = 0;
//     int p4 = 0;
//     if (s[left] == s[right])
//     {
//       p1 = 2 + process(left + 1, right - 1, s);
//     }
//     else
//     {
//       // 舍弃 左侧的
//       p2 = process(left + 1, right, s);
//       // 舍弃右侧
//       p3 = process(left, right - 1, s);
//       // 全部舍去
//       p4 = process(left + 1, right - 1, s);
//     }
//     return max(max(p1, p2), max(p3, p4));
//   }
//   // [0, n]
//   int process2(string &s)
//   {
//     int n = s.size();
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     for (int i = n - 1; i >= 0; i--)
//     {
//       for (int j = i; j < n; j++)
//       {
//         if (i == j)
//         {
//           dp[i][j] = 1;
//         }
//         else
//         {
//           if (s[i] == s[j])
//           {
//             dp[i][j] = 2 + dp[i + 1][j - 1];
//           }
//           else
//           {
//             dp[i][j] = max(dp[i][j], dp[i + 1][j]);
//             dp[i][j] = max(dp[i][j], dp[i][j - 1]);
//             dp[i][j] = max(dp[i][j], dp[i + 1][j - 1]);
//           }
//         }
//       }
//     }
//     return dp[0][n - 1];
//   }
//   int process3(string &s)
//   {
//     int n = s.size();
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     for (int i = n - 1; i >= 0; i--)
//     {
//       for (int j = i; j < n; j++)
//       {
//         if (s[i] == s[j])
//         {
//           if (i == j)
//           {
//             dp[i][j] = 1;
//           }
//           else if ((i + 1) == j)
//           {
//             dp[i][j] = 2;
//           }
//           else
//           {
//             dp[i][j] = 2 + dp[i + 1][j - 1];
//           }
//         }
//         else
//         {
//           dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//         }
//       }
//     }
//     return dp[0][n - 1];
//   }
//   int longestPalindromeSubseq(string s)
//   {
//     if (s.empty())
//       return 0;
//     return process(0, s.size() - 1, s);
//   }
// };

// https://leetcode.cn/problems/palindrome-partitioning-ii/
// class Solution {
//  public:
//    bool isPalindrome(string& s, int left, int right)
//    {
//      while(left < right)
//      {
//        if(s[left] != s[right])
//          return false;
//        left++;
//        right--;
//      }
//      return true;
//    }
//
//    int process(string& s)
//    {
//      int n = s.size();
//      vector<int> dp(n+1, 0);
//      dp[0] = -1;
//      for(int i = 1; i <= n; i++)
//      {
//        int minLen = INT32_MAX;
//        for(int j = i-1; j >=0 ;j--)
//        {
//          bool ret = isPalindrome(s, j,i-1);
//          if(ret)
//            minLen = min(minLen, dp[j]);
//        }
//        dp[i] = minLen+1;
//      }
//      return dp.back();
//    }
//    int minCut(string s) {
//      if(s.empty())
//        return 0;
//      return  process(s);
//    }
//};
// https://leetcode.cn/problems/palindrome-partitioning-iv/
// class Solution
// {
// public:
//   bool process(string &s)
//   {
//     int n = s.size();
//     vector<vector<bool>> dp(n, vector<bool>(n, false));
//     for (int i = n - 1; i >= 0; i--)
//     {
//       for (int j = i; j < n; j++)
//       {
//         if (s[i] == s[j])
//         {
//           dp[i][j] = (i + 1 < j) ? (dp[i + 1][j - 1]) : true;
//         }
//       }
//     }
//     for (int i = 0; i < n; i++)
//     {
//       for (int j = i; j < n; j++)
//       {
//         if (dp[i][j])
//         {
//           if ((i - 1 >= 0) && ((j + 1) <= (n - 1)) && dp[0][i - 1] && dp[j + 1][n - 1])
//             return true;
//         }
//       }
//     }
//     return false;
//   }
//   bool checkPartitioning(string s)
//   {
//     if (s.empty())
//       return false;
//     return process(s);
//   }
// };
// https://leetcode.cn/problems/longest-palindromic-substring/submissions/
// class Solution
// {
// public:
//   string process(string &s)
//   {
//     int n = s.size();
//     int ret = 0;
//     int index = -1;
//     vector<vector<bool>> dp(n, vector<bool>(n, false));
//     for (int i = n - 1; i >= 0; i--)
//     {
//       for (int j = i; j < n; j++)
//       {
//         if (s[i] == s[j])
//         {
//           dp[i][j] = (i + 1 < j) ? (dp[i + 1][j - 1]) : true;
//         }
//         if (dp[i][j] && (j - i + 1) >= ret)
//         {
//           ret = (j - i + 1);
//           index = i;
//         }
//       }
//     }

//     return s.substr(index, ret);
//   }
//   string longestPalindrome(string s)
//   {
//     if (s.empty())
//       return 0;
//     return process(s);
//   }
// };

// https://leetcode.cn/problems/palindromic-substrings/
// class Solution
// {
// public:
//   int process(string &s)
//   {
//     int n = s.size();
//     int ret = 0;
//     vector<vector<bool>> dp(n, vector<bool>(n, false));
//     for (int i = n - 1; i >= 0; i--)
//     {
//       for (int j = i; j < n; j++)
//       {
//         if (s[i] == s[j])
//         {
//           dp[i][j] = (i + 1 < j) ? (dp[i + 1][j - 1]) : true;
//         }
//         if (dp[i][j])
//           ret++;
//       }
//     }
//     return ret;
//   }
//   int countSubstrings(string s)
//   {
//     if (s.empty())
//       return 0;
//     return process(s);
//   }
// };
