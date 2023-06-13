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
//
// class Solution
//{
//  public:
//    bool process(int index1, int index2, string &s, string &p)
//    {
//      if (index2 == p.size() && index1 == s.size())
//        return true;
//      else if (index2 >= p.size())
//        return false;
//      if (p[index2] == '*')
//      {
//        // 这里很麻烦,我们这里这样写
//        bool ret = false;
//        for (int i = 0; (index1 + i) <= s.size(); i++)
//        {
//          ret = ret || (process(index1 + i, index2 + 1, s, p));
//        }
//        return ret;
//      }
//      else if (p[index2] == '?')
//      {
//        // 去下面去找吧
//        return process(index1 + 1, index2 + 1, s, p);
//      }
//      else
//      {
//        if (p[index2] == s[index1])
//          return process(index1 + 1, index2 + 1, s, p);
//        else
//          return false;
//      }
//    }
//    bool process2(string &s, string &p)
//    {
//      int n = s.size();
//      int m = p.size();
//      if(n ==0)
//      {
//        for(int i = 0; i< m;i++)
//          if(p[i] != '*')
//            return false;
//        return true;
//      }
//
//      vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//      dp[n][m] = true;
//      for(int i = m-1; i>=0;i--)
//        if('*' == p[i])
//          dp[n][i] = true;
//        else
//          break;
//
//      for (int index2 = m - 1; index2 >= 0; index2--)
//      {
//        for (int index1 = n - 1; index1 >= 0; index1--)
//        {
//
//          if (p[index2] == '*')
//          {
//            // 这里很麻烦,我们这里这样写
//            bool ret = false;
//            for (int i = 0; (index1 + i) <=n; i++)
//            {
//              ret = ret || dp[index1 + i][index2 + 1];
//            }
//            dp[index1][index2] = ret;
//          }
//          else if (p[index2] == '?')
//          {
//            // 去下面去找吧
//            dp[index1][index2] = dp[index1 + 1][index2 + 1];
//          }
//          else
//          {
//            if (p[index2] == s[index1])
//              dp[index1][index2] = dp[index1 + 1][index2 + 1];
//            else
//              dp[index1][index2] = false;
//          }
//        }
//      }
//      return dp[0][0];
//    }
//
//    bool isMatch(string s, string p)
//    {
//      int m = s.size(), n = p.size();
//      s = " " + s, p = " " + p;
//      vector<vector<bool>> dp(m + 1, vector<bool>(n + 1)); // 1. 创建 dp 表
//      dp[0][0] = true;                                     // 2. 初始化
//      for (int j = 1; j <= n; j++)
//        if (p[j] == '*')
//          dp[0][j] = true;
//        else
//          break;
//      // 3. 填表
//      for (int i = 1; i <= m; i++)
//      {
//        for (int j = 1; j <= n; j++)
//        {
//          if (p[j] == '*')
//            dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//          else
//            dp[i][j] = (p[j] == '?' || s[i] == p[j]) && dp[i - 1][j -
//              1];
//        }
//      }
//      // 4. 返回值
//      return dp[m][n];
//    }
//};

// https://leetcode.cn/problems/regular-expression-matching/
// class Solution {
//
//  public:
//    // 这个尝试我没写正确,不过暂时停留
//    //bool processs(size_t index1, size_t index2, string& s, string& p)
//    //{
//    //  if(index2 == p.size() && index1 == s.size())
//    //    return true;
//
//    //  if(p[index2] == '*')
//    //  {
//    //    bool ret = false;
//    //    // 这个是最难的,
//    //    // 把前面的匹配全部进行清除,重新来
//    //    ret = ret || processs(0, index2+1, s,p);
//    //    // 我们一个都不适配
//    //    ret = processs(index1, index2+1, s,p);
//    //    if(index2 > 0)
//    //    {
//    //      if(p[index2-1] == s[index1])
//    //      {
//    //        ret = ret  || processs(index1+1, index2, s,p);
//    //      }
//    //      else if(p[index2-1] == '.')
//    //      {
//    //        // 拿到前面来说
//    //        ret = ret  || processs(index1+1, index2, s,p);
//    //      }
//    //      else
//    //      {
//    //        ret = ret || false;
//    //      }
//    //    }
//    //     return ret;
//    //    }
//    //    else if(p[index2] == '.')
//    //    {
//    //      return processs(index1+1,index2+1, s,p);
//    //    }
//    //    else
//    //    {
//    //      if(s[index1] == p[index2])
//    //        return processs(index1+1,index2+1, s,p);
//    //      else
//    //        return processs(index1,index2+1, s,p);
//    //    }
//    //  }
//    bool process(string s, string p)
//    {
//      // 创建dp表
//      int m = s.size();
//      int n = p.size();
//      s = ' '+s;
//      p = ' '+p;
//      vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
//      dp[0][0] = true;
//      for(int j = 2;j<=n;j+=2)
//      {
//        if(p[j] == '*')
//          dp[0][j] = true;
//        else
//          break;
//      }
//      for(int i = 1; i<=m;i++)
//      {
//        for(int j = 1; j<=n;j++)
//        {
//          if(p[j] == '*')
//          {
//            dp[i][j] = dp[i][j-2]||((p[j-1] == '.'||p[j-1]==s[i]) && dp[i-1][j]);
//          }
//          else
//          {
//            dp[i][j] = (p[j] == s[i] || p[j] == '.') && dp[i-1][j-1];
//          }
//        }
//      }
//      return dp[m][n];
//    }
//    bool isMatch(string s, string p) {
//      //return processs(0,0,s,p);
//      return process(s,p);
//    }
//};

// https://leetcode.cn/problems/interleaving-string/
// class Solution {
// public:
//    bool process(string s1, string s2, string s3)
//    {
//      int m = s1.size();
//      int n = s2.size();
//      vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
//
//      if(m+n != (int)s3.size())
//        return false;
//      s1 = " "+s1;
//      s2 = " "+s2;
//      s3 = " "+s3;
//      dp[0][0] = true;
//
//      for(int j = 1; j<= n;j++)
//        if(s2[j] == s3[j])
//          dp[0][j] = true;
//        else
//          break;
//
//      for(int i = 1; i<= m;i++)
//        if(s1[i] == s3[i])
//          dp[i][0] = true;
//        else
//          break;
//      for(int i = 1; i<=m ;i++)
//      {
//        for(int j = 1; j<=n;j++)
//        {
//          dp[i][j] = (s1[i] == s3[i+j] && dp[i-1][j])
//            ||(s2[j] == s3[i+j] && dp[i][j-1]);
//        }
//      }
//      return dp[m][n];
//    }
//    bool isInterleave(string s1, string s2, string s3) {
//      return process(s1,s2,s3);
//    }
//};

// https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
class Solution
{
public:
  int process(size_t index1, size_t index2, string &s1, string &s2)
  {
    if (index1 >= s1.size() && index2 >= s2.size())
      return 0;
    if (index1 >= s1.size())
    {
      int ret = 0;
      for (size_t i = index2; i < s2.size(); i++)
        ret += s2[i];
      return ret;
    }
    if (index2 >= s2.size())
    {
      int ret = 0;
      for (size_t i = index1; i < s1.size(); i++)
        ret += s1[i];
      return ret;
    }
    int p1 = INT32_MAX;
    int p2 = INT32_MAX;
    if (s1[index1] == s2[index2])
    {
      p1 = process(index1 + 1, index2 + 1, s1, s2);
    }
    else
    {
      p2 = min(s1[index1] + process(index1 + 1, index2, s1, s2), s2[index2] + process(index1, index2 + 1, s1, s2));
    }
    return min(p1, p2);
  }
  int process2(string &s1, string &s2)
  {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MAX));
    dp[n][m] = 0;
    for (int i = m - 1; i >= 0; i--)
    {
      dp[n][i] = dp[n][i + 1] + s2[i];
    }
    for (int i = n - 1; i >= 0; i--)
      dp[i][m] = dp[i + 1][m] + s1[i];
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (s1[i] == s2[j])
          dp[i][j] = dp[i + 1][j + 1];
        else
          dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
      }
    }
    return dp[0][0];
  }

  int process3(string &s1, string &s2)
  {
    // 求最长公共子序列的最大和

    int n = s1.size();
    int m = s2.size();
    int sum = 0;
    for (auto &e : s1)
      sum += e;
    for (auto &e : s2)
      sum += e;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return sum - 2 * dp[n][m];
  }
  int minimumDeleteSum(string s1, string s2)
  {
    return process(0, 0, s1, s2);
  }
};

// https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
// class Solution
// {
// public:
//   int process(vector<int> &nums1, vector<int> &nums2)
//   {
//     int n = nums1.size();
//     int m = nums2.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     int maxLen = 0;
//     for (int i = 1; i <= n; i++)
//     {
//       for (int j = 1; j <= m; j++)
//       {
//         if (nums1[i - 1] == nums2[j - 1])
//           dp[i][j] = 1 + dp[i - 1][j - 1];
//         else
//           dp[i][j] = 0;
//         maxLen = max(maxLen, dp[i][j]);
//       }
//     }
//     return maxLen;
//   }
//   int findLength(vector<int> &nums1, vector<int> &nums2)
//   {
//     if (nums1.empty() || nums2.empty())
//       return 0;
//     return process(nums1, nums2);
//   }
// };
