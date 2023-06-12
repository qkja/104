/**
 * User: Qkj
 * Description: 两个数组的 dp （含字符串数组）
 * Date: 2023-06-08
 * Time: 23:51
 */
#include <string>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/longest-common-subsequence/
// class Solution
//{
// public:
//  // 我们关心[index1, n]和 [index2, n]的最长公共子序列
//  int process(size_t index1, size_t index2, string &text1, string &text2)
//  {
//    if (index1 >= text1.size())
//      return 0;
//    if (index2 >= text2.size())
//      return 0;
//
//    if (text1[index1] == text2[index2])
//    {
//      return 1 + process(index1 + 1, index2 + 1, text1, text2);
//    }
//    else
//    {
//      // test1 这个字符舍弃
//      int p1 = process(index1 + 1, index2, text1, text2);
//      int p2 = process(index1, index2 + 1, text1, text2);
//      return max(p1, p2);
//    }
//  }
//  int process2(string &text1, string &text2)
//  {
//    int n = text1.size();
//    int m = text2.size();
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//    for (int i = n - 1; i >= 0; i--)
//    {
//      for (int j = m - 1; j >= 0; j--)
//      {
//        if (text1[i] == text2[j])
//        {
//          dp[i][j] = dp[i + 1][j + 1] + 1;
//        }
//        else
//        {
//          dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
//        }
//      }
//    }
//    return dp[0][0];
//  }
//
//  int process3(string &text1, string &text2)
//  {
//    int n = text1.size();
//    int m = text2.size();
//    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//
//    for(int i =1; i<=n;i++)
//    {
//      for(int j= 1; j<=m;j++)
//      {
//        if(text1[i-1] == text2[j-1])
//          dp[i][j] = 1+dp[i-1][j-1];
//        else
//          dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
//      }
//    }
//    return dp[n][m];
//  }
//  int longestCommonSubsequence(string text1, string text2)
//  {
//    if (text1.empty() || text2.empty())
//      return 0;
//    // return process(0, 0, text1, text2);
//    return process2(text1, text2);
//  }
//};
// https://leetcode.cn/problems/uncrossed-lines/
// class Solution
//{
// public:
//  int process(int index1, int index2, vector<int> &text1, vector<int> &text2)
//  {
//    if (index1 >= text1.size())
//      return 0;
//    if (index2 >= text2.size())
//      return 0;
//
//    if (text1[index1] == text2[index2])
//    {
//      return 1 + process(index1 + 1, index2 + 1, text1, text2);
//    }
//    else
//    {
//      // test1 这个字符舍弃
//      int p1 = process(index1 + 1, index2, text1, text2);
//      int p2 = process(index1, index2 + 1, text1, text2);
//      return max(p1, p2);
//    }
//  }
//  int process2(vector<int> &text1, vector<int> &text2)
//  {
//    int n = text1.size();
//    int m = text2.size();
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//    for (int i = n - 1; i >= 0; i--)
//    {
//      for (int j = m - 1; j >= 0; j--)
//      {
//        if (text1[i] == text2[j])
//        {
//          dp[i][j] = dp[i + 1][j + 1] + 1;
//        }
//        else
//        {
//          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
//        }
//      }
//    }
//    return dp[0][0];
//  }
//  int process3(vector<int> &text1, vector<int> &text2)
//  {
//    int n = text1.size();
//    int m = text2.size();
//    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//
//    for(int i =1; i<=n;i++)
//    {
//      for(int j= 1; j<=m;j++)
//      {
//        if(text1[i-1] == text2[j-1])
//          dp[i][j] = 1+dp[i-1][j-1];
//        else
//          dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
//      }
//    }
//    return dp[n][m];
//  }
//  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
//  {
//    if (nums1.empty() || nums2.empty())
//      return 0;
//    // return process(0, 0, nums1, nums2);
//    return process2(nums1, nums2);
//  }
//};
// https://leetcode.cn/problems/distinct-subsequences/submissions/
// class Solution
// {
// public:
//   int process(size_t index1, size_t index2, string &s, string &t)
//   {
//     if (index2 >= t.size())
//       return 1;
//     if (index1 >= s.size())
//       return 0;
//     // 不要
//     int p1 = 0;
//     // 要
//     int p2 = 0;
//     if (s[index1] == t[index2])
//     {
//       p1 = process(index1 + 1, index2, s, t);
//       p2 = process(index1 + 1, index2 + 1, s, t);
//     }
//     else
//     {
//       p2 = process(index1 + 1, index2, s, t);
//     }
//     return p1 + p2;
//   }

//   int process2(string &s, string &t)
//   {
//     int n = s.size(); // 5
//     int m = t.size(); // 6
//     vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
//     for (int i = 0; i <= n; i++)
//       dp[i][m] = 1;

//     for (int i = n - 1; i >= 0; i--)
//     {

//       for (int j = m - 1; j >= 0; j--)
//       {
//         double p1 = 0;
//         double p2 = 0;
//         if (s[i] == t[j])
//         {
//           p1 = (double)dp[i + 1][j];
//           p2 = (double)dp[i + 1][j + 1];
//         }
//         else
//         {
//           p2 = (double)dp[i + 1][j];
//         }
//         dp[i][j] = (double)((double)p1 + (double)p2);
//       }
//     }

//     return dp[0][0];
//   }
//   int process3(string &s, string &t)
//   {
//     int m = t.size();
//     int n = s.size();
//     vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));
//     for (int i = 0; i <= n; i++)
//       dp[0][i] = 1;
//     for (int i = 1; i <= m; i++)
//     {
//       for (int j = 1; j <= n; j++)
//       {
//         dp[i][j] += dp[i][j - 1];
//         if (t[i - 1] == s[j - 1])
//           dp[i][j] += dp[i - 1][j - 1];
//       }
//     }
//     return dp[m][n];
//   }
//   int numDistinct(string s, string t)
//   {

//     if (s.empty() || t.empty())
//       return 0;
//     return process(0, 0, s, t);
//   }
// };

// https://leetcode.cn/problems/wildcard-matching/

class Solution
{
public:
  bool isMatch(string s, string p)
  {
    int m = s.size(), n = p.size();
    s = " " + s, p = " " + p;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1)); // 1. 创建 dp 表
    dp[0][0] = true;                                     // 2. 初始化
    for (int j = 1; j <= n; j++)
      if (p[j] == '*')
        dp[0][j] = true;
      else
        break;
    // 3. 填表
    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (p[j] == '*')
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        else
          dp[i][j] = (p[j] == '?' || s[i] == p[j]) && dp[i - 1][j -
                                                                1];
      }
    }
    // 4. 返回值
    return dp[m][n];
  }
};