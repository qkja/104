/**
 * User: Qkj
 * Description: 子序列问题 
 * Date: 2023-06-02
 * Time: 15:23
 */
#include <vector>
using namespace std;

// https://leetcode.cn/problems/longest-increasing-subsequence/
//class Solution {
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
//class Solution {
//public:
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

//https://leetcode.cn/problems/number-of-longest-increasing-subsequence/submissions/

class Solution {
  public:
    int process(vector<int>& v)      
    {             
      int n = v.size();      
      vector<int> f(n, 1);      
      vector<int> g(n, 1);      
      int maxLen = 0;    

      for(int i= 1; i < n;i++)                                       
      {               
        int ret = 0;      
        int count = 0;
        for(int j = i-1; j>=0;j--)      
        {         
          if(v[j] < v[i])      
          {           
            ret = max(ret, f[j]);      
          }      
        }      
        // 这里我们拿到了  3
        for(int j = i-1; j >=0; j--)
        {
          if(v[j] < v[i] && f[j] == ret)
          {
            count += g[j];
          }
        }
        g[i] = max(g[i], count);

        f[i] += ret;  
        maxLen = max(maxLen, f[i]);                                                                                                  
      }     
      int result = 0;
      for(int i = 0; i<n;i++)
      {
        if(maxLen == f[i])
          result += g[i];
      }
      return result;         
    }

    int process2(vector<int>& v)
    {

      int n = v.size();
      vector<int> f(n, 1);
      vector<int> g(n, 1);

      int retlen = 1;
      int retcount = 1;
      for(int i =1; i<n; i++)
      {
        for(int j=0; j < i; j++)
        {
          if(v[j] < v[i])
          {
            if((f[j] +1) == f[i])
            {
              g[i] += g[j];
            }
            else if((f[j] +1)  > f[i])
            {
              f[i] = f[j]+1;
              g[i] = g[j];
            }
          }

        }
        // 每次判断
        if(f[i] > retlen)
        {
          retlen = f[i];
          retcount = g[i];
        }                                                                                                                          
        else if(f[i] == retlen)
        {
          retcount += g[i];
        }
      }
      return retcount;

    }   
    int findNumberOfLIS(vector<int>& nums) {
      if(nums.empty())
        return 0; 
      if(nums.size() == 1)
        return 1;
      return process(nums);
    }
};
