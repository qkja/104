/**
 * User: Qkj
 * Description: 子数组 字串问题
 * Date: 2023-05-30
 * Time: 16:34
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
class Solution
{
public:
    int process(string &s)
    {
        int n = s.size();
        vector<int> dp(n, 1);
        vector<int> result(26, 0);
        result[s[0] - 'a'] = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] + 1 == s[i] ||
                s[i - 1] == 'z' && s[i] == 'a')
            {
                dp[i] += dp[i - 1];
            }
            result[s[i] - 'a'] = max(result[s[i] - 'a'], dp[i]);
        }
        int sum = 0;
        for (auto &e : result)
            sum += e;
        return sum;
    }
    int findSubstringInWraproundString(string s)
    {
        if (s.empty())
            return 0;
        return process(s);
    }
};

// https://leetcode.cn/problems/word-break/
// class Solution
// {
// public:
//     int process(string &s, unordered_set<string> &set)
//     {
//         int n = s.size();
//         vector<bool> dp(n, false);
//         for (int i = 0; i < n; i++)
//         {
//             int flag = false;
//             for (int j = i; j >= 0; j--)
//             {
//                 auto iter = set.find(s.substr(j, i - j + 1));
//                 bool ret = false;
//                 if (iter != set.end())
//                     ret = true;

//                 if (j != 0)
//                 {
//                     ret = ret && dp[j - 1];
//                 }
//                 flag = (flag || ret);
//             }
//             dp[i] = flag;
//         }

//         return dp.back();
//     }
//     int process2(string s, unordered_set<string> &set)
//     {
//         int n = s.size();
//         vector<bool> dp(n + 1, false);
//         dp[0] = true;
//         s.insert(s.begin(), ' ');

//         for (int i = 1; i <= n; i++)
//         {
//             int flag = false;
//             for (int j = i; j >= 1; j--)
//             {
//                 auto iter = set.find(s.substr(j, i - j + 1));
//                 bool ret = false;
//                 if (iter != set.end())
//                     ret = true;
//                 ret = ret && dp[j - 1];
//                 flag = (flag || ret);
//             }
//             dp[i] = flag;
//         }

//         return dp.back();
//     }
//     bool wordBreak(string s, vector<string> &wordDict)
//     {
//         if (s.empty() || wordDict.empty())
//             return false;
//         unordered_set<string> set;
//         for (auto &e : wordDict)
//             set.insert(e);

//         // return process(s, set);
//         return process2(s, set);
//     }
// };

// https://leetcode.cn/problems/longest-turbulent-subarray/
// class Solution {
//  public:
//    int process(vector<int>& v)
//    {
//      int n = v.size();
//      vector<int> f(n, 1); // 上生趋势
//      vector<int> g(n, 1); // 下降趋势
//      int maxLen = 1;
//      for(int i = 1; i<n;i++)
//      {
//        int a = v[i-1];
//        int b = v[i];
//        // a b
//        if(a > b)
//        {
//          g[i] = f[i-1]+1;
//        }
//        else if(a < b)
//        {
//          f[i] = g[i-1] + 1;
//        }
//        maxLen = max(maxLen, max(f[i], g[i]));
//      }
//      return maxLen;
//    }
//    int maxTurbulenceSize(vector<int>& arr) {
//      if(arr.empty())
//        return 0;
//      return process(arr);
//
//    }
//};
//
//

// https://leetcode.cn/problems/arithmetic-slices/
// class Solution {
//  public:
//    int process(vector<int>& v)
//    {
//      int n = v.size();
//      int result = 0;
//
//      // dp[i] 以 i位置为结尾,我们可以子数组里面存在的等擦数列
//      vector<int> dp(n, 0);
//      for(int i = 2; i < n; i++)
//      {
//        int a = v[i-2];
//        int b = v[i-1];
//        int c = v[i];
//        if((c-b) == (b-a))
//          dp[i] = dp[i-1]+1;
//        else
//          dp[i] = 0;
//        result += dp[i];
//      }
//      return result;
//    }
//    int numberOfArithmeticSlices(vector<int>& nums) {
//      if(nums.size() < 3)
//        return 0;
//      return process(nums);
//    }
//};
//
// https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product
// class Solution {
//  public:
//    int process(vector<int>& v)
//    {
//      int n = v.size();
//      //确顶状态定义
//      vector<int> f(n, 0); //正数
//      vector<int> g(n, 0);  //负数
//      //转台方
//      //初始化
//      if(v[0] > 0)
//      {
//        f[0] = 1;
//        g[0] = 0;
//      }
//      else if(v[0] == 0)
//      {
//        f[0] = g[0] = 0;
//      }
//      else
//      {
//        f[0] = 0;
//        g[0] = 1;
//      }
//      //填表顺序
//      int maxLen = f[0];
//      for(int i = 1; i< n;i++)
//      {
//        if(v[i] > 0)
//        {
//          // 必须以自己为尾部
//          f[i] = max(f[i-1]+1, 1);
//          if(g[i-1] != 0)
//            g[i] = g[i-1]+1;
//        }
//        else if (v[i]<0)
//        {
//          // 必须以自己为尾部
//          if(g[i-1] != 0)
//            f[i] = g[i-1]+1;
//          g[i] = max(f[i-1]+1, 1);
//        }
//        else
//        {
//          f[i] = 0;
//          g[i] = 0;
//        }
//
//        maxLen = max(maxLen, f[i]);
//      }
//
//      //返回值
//      return maxLen;
//    }
//    int process2(vector<int>& v)
//    {
//      int n = v.size();
//      //确顶状态定义
//      vector<int> f(n+1, 0); //正数
//      vector<int> g(n+1, 0); //正数
//
//      int maxLen = 0;
//      for(int i = 1; i <= n; i++)
//      {
//        if(v[i-1] == 0)
//          continue;
//
//        if(v[i-1] > 0)
//        {
//          f[i] = f[i-1]+1;
//          g[i] = g[i-1] == 0?0:g[i-1]+1;
//        }
//        else
//        {
//          f[i] = g[i-1] == 0?0:g[i-1]+1;
//          g[i] = f[i-1]+1;
//        }
//
//        maxLen = max(maxLen, f[i]);
//      }
//      return maxLen;
//    }
//    int getMaxLen(vector<int>& nums) {
//      if(nums.empty())
//        return 0;
//      return process(nums);
//    }
//};
//

// https://leetcode.cn/problems/maximum-subarray/submissions/
// class Solution
//{
// public:
//  int process3(vector<int> &nums)
//  {
//    // dp[i] 表示我们在 0-i里面的中连续和的最大值
//    //
//    // ,如果我们的v[i]+dp[i-1] < v[i],不如把最大的和给v[i]
//    int n = nums.size();
//    vector<int> dp(n, 0);
//    dp[0] = nums[0];
//    int maxSum = dp[0];
//    for (int i = 1; i < nums.size(); i++)
//    {
//      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
//      maxSum = max(maxSum, dp[i]);
//    }
//    // 返回值
//    return maxSum;
//  }
//  int maxSubArray(vector<int> &nums)
//  {
//    if (nums.empty())
//      return 0;
//    return process3(nums);
//  }
//};
//// https://leetcode.cn/problems/maximum-sum-circular-subarray/
// class Solution
//{
// public:
//   int process3(vector<int> &nums)
//   {
//
//     int n = nums.size();
//     vector<int> f(n + 1, 0);
//     vector<int> g(n + 1, 0);
//     int maxSum = INT32_MIN;
//     int minSum = INT32_MAX;
//     int sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//       sum += nums[i - 1];
//       // 最大值
//       f[i] = max(f[i - 1] + nums[i - 1], nums[i - 1]);
//       maxSum = max(maxSum, f[i]);
//
//       // 最小值
//       g[i] = min(g[i - 1] + nums[i - 1], nums[i - 1]);
//       minSum = min(minSum, g[i]);
//     }
//     // 返回值
//     int ret = sum - minSum;
//     if (sum == minSum)
//     {
//       return maxSum;
//     }
//     else
//     {
//       return max(sum - minSum, maxSum);
//     }
//   }
//   int maxSubarraySumCircular(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     return process3(nums);
//   }
// };
//
//// https://leetcode.cn/problems/maximum-product-subarray/
// class Solution
//{
// public:
//   int process3(vector<int> &nums)
//   {
//     int n = nums.size();
//     vector<int> f(n + 1, 1);
//     vector<int> g(n + 1, 1);
//     int maxSum = INT32_MIN;
//     int sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//       // 最大值
//       int ret = nums[i - 1];
//       f[i] = max(ret, max(f[i - 1] * ret, ret * g[i - 1]));
//       maxSum = max(maxSum, f[i]);
//       g[i] = min(min(f[i - 1] * ret, ret * g[i - 1]), ret);
//     }
//
//     return maxSum;
//   }
//   int maxProduct(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     return process3(nums);
//   }
// };
