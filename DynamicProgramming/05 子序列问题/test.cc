/**
 * User: Qkj
 * Description: 子序列问题
 * Date: 2023-06-02
 * Time: 15:23
 */
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <unordered_map>
// using namespace std;
// // https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/
// class Solution
// {
// public:
//   int process(vector<int> &v)
//   {

//     int n = v.size();
//     unordered_map<long long, vector<int>> m;
//     for (int i = 0; i < n; i++)
//     {
//       m[v[i]].push_back(i);
//     }

//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     int maxLen = 0;
//     for (int j = 1; j < n; j++)
//     {

//       for (int i = j - 1; i >= 0; i--)
//       {
   
//         long long ret = (long long)2*(long long)v[i] - v[j] ;
//         auto iter = m.find(ret);
//         if (iter == m.end())
//           continue;
//         for (int k = 0; k < iter->second.size(); k++)
//         {
//           int index = (iter->second)[k];
//           if (index >= i)
//             continue;
//           dp[i][j] += (dp[index][i] + 1);
//         }
//         maxLen += dp[i][j];
//       }
//     }
//     return maxLen;
//   }
//   int numberOfArithmeticSlices(vector<int> &nums)
//   {
//     if (nums.size() < 3)
//       return 0;
//     return process(nums);
//   }
// };
// https://leetcode.cn/problems/longest-arithmetic-subsequence/<Paste>
// class Solution
// {
// public:
//   int find(vector<int> &v, int right, int target)
//   {
//     for (int i = right; i >= 0; i--)
//       if (v[i] == target)
//         return i;
//     return -1;
//   }
//   int process(vector<int> &v)
//   {
//     int n = v.size();
//     vector<vector<int>> dp(n, vector<int>(n, 2));
//     unordered_map<int, int> m;
//     int maxLen = 2;
//     m[v[0]] = 0;
//     for (int j = 1; j < n; j++)
//     {

//       for (int i = j - 1; i >= 0; i--)
//       {
//         int len = v[j] - v[i];
//         int ret = v[i] - len;
//         if (m.find(ret) != m.end())
//         {
//           int index = find(v, i - 1, v[i] - len);
//           if (index != -1)
//             dp[i][j] = dp[index][i] + 1;
//           // 存在会出错的,我们需要筛选
//           //    dp[i][j] = 1+dp[m[ret]][i];
//         }
//         // int index = find(v, i-1, v[i]-len);
//         // if(index != -1)
//         //   dp[i][j] = dp[index][i]+1;
//         maxLen = max(maxLen, dp[i][j]);
//       }
//       m[v[j]] = j;
//     }

//     return maxLen;
//   }
//   int longestArithSeqLength(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     return process(nums);
//   }
// };

// https://leetcode.cn/problems/maximum-length-of-pair-chain/
// class Solution
// {
// public:
//   int process(vector<vector<int>> v)
//   {
//     sort(v.begin(), v.end(), [](const vector<int> &v1, const vector<int> &v2)
//          { return v1[0] < v2[0]; });
//     int n = v.size();
//     vector<int> dp(n, 1);
//     int maxLen = 1;
//     for (int i = 1; i < n; i++)
//     {
//       for (int j = 0; j < i; j++)
//       {

//         if (v[j][1] < v[i][0])
//         {
//           dp[i] = max(dp[i], dp[j] + 1);
//         }
//       }
//       maxLen = max(maxLen, dp[i]);
//     }
//     return maxLen;
//   }
//   int findLongestChain(vector<vector<int>> &pairs)
//   {
//     if (pairs.empty())
//       return 0;
//     return process(pairs);
//   }
// };

// https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/
// class Solution
// {
// public:
//   int process(vector<int> &v, int difference)
//   {
//     int n = v.size();
//     unordered_map<int, int> m;
//     m[v[0]] = 1;
//     int maxLen = 1;
//     for (int i = 1; i < n; i++)
//     {
//       int result = 1;
//       auto iter = m.find(v[i] - difference);
//       if (iter != m.end())
//       {
//         result = m[(v[i] - difference)] + 1;
//       }

//       m[v[i]] = result;

//       maxLen = max(maxLen, result);
//     }
//     return maxLen;
//   }
//   int longestSubsequence(vector<int> &arr, int difference)
//   {
//     if (arr.empty())
//       return 0;
//     return process(arr, difference);
//   }
// };
// https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/
// class Solution
//{
//	public:
//		int process(vector<int> &v)
//		{
//			int n = v.size();
//			unordered_map<int, int> m;
//			for (size_t i = 0; i < n; i++)
//			{
//				m[v[i]] = i;
//			}
//			vector<vector<int>> dp(n, vector<int>(n, 2));
//			int result = 2;
//			for (int j = 2; j < n; j++)
//			{
//				for (int i = 1; i < j; i++)
//				{
//					int a = v[j] - v[i];
//					if (m.count(a) && a < v[i])
//					{
//						dp[i][j] = dp[m[a]][i] + 1;
//						result = max(result, dp[i][j]);
//					}
//				}
//			}
//			return result < 3 ? 0 : result;
//		}
//		int lenLongestFibSubseq(vector<int> &arr)
//		{
//			if (arr.empty())
//				return 0;
//			return process(arr);
//		}
//};
// https://leetcode.cn/problems/longest-increasing-subsequence/
// class Solution {
//  public:
//    int process(vector<int>& v)
//    {
//      int n = v.size();
//      vector<int> dp(n, 1);
//      int maxLen = 1;
//      for(int i= 1; i < n;i++)
//      {
//        int ret = 0;
//        for(int j = i-1; j>=0;j--)
//        {
//          if(v[j] < v[i])
//          {
//            ret = max(ret, dp[j]);
//          }
//        }
//        dp[i] += ret;
//        maxLen = max(maxLen, dp[i]);
//      }
//      return maxLen;
//    }
//    int lengthOfLIS(vector<int>& nums)
//    {
//      if(nums.empty())
//        return 0;
//      return process(nums);
//    }
//};

// https://leetcode.cn/problems/wiggle-subsequence/submissions/
// class Solution {
// public:
//  int process(vector<int>& v)
//  {
//    int n = v.size();
//    vector<int> f(n, 1);
//    vector<int> g(n, 1);
//    int maxLen = 1;
//    for(int i = 1; i < n; i++)
//    {
//      int ret1 = 0;
//      int ret2 = 0;
//      for(int j = i-1; j>=0; j--)
//      {
//        if(v[j] < v[i])
//        {
//          ret1 = max(ret1, g[j]);
//        }
//        if(v[j] > v[i])
//        {
//          ret2 = max(ret2, f[j]);
//        }
//      }
//      f[i] += ret1;
//      g[i] += ret2;
//      maxLen = max(maxLen, max(f[i], g[i]));
//    }
//    return maxLen;
//  }
//    int wiggleMaxLength(vector<int>& nums) {
//      if(nums.empty())
//        return 0;
//      if(nums.size() == 1)
//        return 1;
//      if(nums.size() == 2 && nums[0] != nums[1])
//        return 2;
//
//
//      return process(nums);
//    }
//};

// https://leetcode.cn/problems/number-of-longest-increasing-subsequence/submissions/

// class Solution
// {
// public:
//   int process(vector<int> &v)
//   {
//     int n = v.size();
//     vector<int> f(n, 1);
//     vector<int> g(n, 1);
//     int maxLen = 0;

//     for (int i = 1; i < n; i++)
//     {
//       int ret = 0;
//       int count = 0;
//       for (int j = i - 1; j >= 0; j--)
//       {
//         if (v[j] < v[i])
//         {
//           ret = max(ret, f[j]);
//         }
//       }
//       // 这里我们拿到了  3
//       for (int j = i - 1; j >= 0; j--)
//       {
//         if (v[j] < v[i] && f[j] == ret)
//         {
//           count += g[j];
//         }
//       }
//       g[i] = max(g[i], count);

//       f[i] += ret;
//       maxLen = max(maxLen, f[i]);
//     }
//     int result = 0;
//     for (int i = 0; i < n; i++)
//     {
//       if (maxLen == f[i])
//         result += g[i];
//     }
//     return result;
//   }

//   int process2(vector<int> &v)
//   {

//     int n = v.size();
//     vector<int> f(n, 1);
//     vector<int> g(n, 1);

//     int retlen = 1;
//     int retcount = 1;
//     for (int i = 1; i < n; i++)
//     {
//       for (int j = 0; j < i; j++)
//       {
//         if (v[j] < v[i])
//         {
//           if ((f[j] + 1) == f[i])
//           {
//             g[i] += g[j];
//           }
//           else if ((f[j] + 1) > f[i])
//           {
//             f[i] = f[j] + 1;
//             g[i] = g[j];
//           }
//         }
//       }
//       // 每次判断
//       if (f[i] > retlen)
//       {
//         retlen = f[i];
//         retcount = g[i];
//       }
//       else if (f[i] == retlen)
//       {
//         retcount += g[i];
//       }
//     }
//     return retcount;
//   }
//   int findNumberOfLIS(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     if (nums.size() == 1)
//       return 1;
//     return process(nums);
//   }
// };

// https://leetcode.cn/problems/longest-increasing-subsequence/submissions/
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp(nums.size());
//         int result = 0;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             dp[i] = 1;
//             int maxdp = 0;
//             for(int j = 0; j < i; j++)
//             {
//                 if(nums[j] < nums[i])
//                 maxdp = max(maxdp, dp[j]);
//             }
//             dp[i] = max(dp[i], maxdp+1);
//             result = max(result,   dp[i] );
//         }
//         return result;
//     }
// };
// https://leetcode.cn/problems/wiggle-subsequence/submissions/
// class Solution {
// public:
//     int wiggleMaxLength(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> f(n, 1);
//         vector<int> g(n, 1);
//         int result = 1;
//         for(int i = 1; i < nums.size(); ++i)
//         {
//             int ret = nums[i] - nums[i-1];
//             if(ret > 0)
//             {
//                 f[i] = g[i-1]+1;
//                 g[i] = g[i-1];

//             }   
//             else if(ret < 0)
//             {
//                 g[i] = f[i-1]+1;
//                 f[i] = f[i-1];
//             }   
//             else 
//             {
//                 f[i] = f[i-1];
//                 g[i] = g[i-1];
//             }  
//             result = max(max(f[i], g[i]), result);
//         }
//         return result;
//     }
// };

