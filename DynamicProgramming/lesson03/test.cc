/**
 * User: Qkj
 * Description: 简单多状态
 * Date: 2023-05-27
 * Time: 22:34
 */
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;



class Solution {
  public:
    // falg 表示我们在之前买了票
    int process(size_t index, bool flag,vector<int>& prices )
    {
      if(index >= prices.size())
        return 0;
      if(index == prices.size()-1)
      {
        if(flag)
        {
          // 已近买了,我们可以直接卖出
          return prices[index];
        }
        else
        {
          // 没有买,为了避免损失
          return 0;
        }
      }
      int p1 = 0;
      int p2 = 0;
      if(flag)
      {
        // 之前买票了, 
        // 1. 买了这个票
        p1 = process(index+2, false, prices) + prices[index];
        p2 = process(index+1, true, prices);

        //   dp[i][1] = std::max(dp[i+2][0]+prices[i], dp[i+1][1]);    
      }
      else
      {
        // 没有买票
        //   dp[i][0] = std::max(dp[i+1][1]-prices[i], dp[i+1][0]);  
        p1 = process(index+1, true, prices) - prices[index];
        p2 = process(index+1, false, prices);
      }
      return max(p1,p2);
    }

    int process2(vector<int>& prices)                
    {                                                
      int n = prices.size();                         
      vector<vector<int>> dp(n+2, vector<int>(2, 0));                   
      dp[n-1][0] = 0;
      dp[n-1][1] = prices[n-1];    

      for(int i = n-2; i>=0; i--)                    
      {                                              
        // 这是之前没有买的                          
        dp[i][0] = std::max(dp[i+1][1]-prices[i], dp[i+1][0]);  

        dp[i][1] = std::max(dp[i+2][0]+prices[i], dp[i+1][1]);    
      }    

      return dp[0][0];    

    }   

    int process3(vector<int>& prices)
    {
      int n = prices.size();

      // 这里有一个简单的转肽机的 思想
      vector<vector<int>> dp(n, vector<int>(3,0));
      dp[0][0] = -prices[0];
      dp[0][1] = 0;
      dp[0][1] = 0;
      for(int i = 1; i< n; i++)
      {
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1],dp[i-1][2]);
        dp[i][2] = dp[i-1][0]+prices[i];
      }
      return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    }

    int maxProfit(vector<int>& prices) {
      if(prices.empty())
        return 0;
      return process2(prices);
      //return process(0, false, prices);
    }
};













// https://leetcode.cn/problems/the-masseuse-lcci/
// class Solution
// {
// public:
//   // [0, index) 我们不用关心了,只需要从index开始,我们能拿到的分钟数

// int process1(int index, vector<int> &nums)
// {
//   if (index >= nums.size())
//     return 0;
//   // 要这个数
//   int p1 = nums[index] + process1(index + 2, nums);
//   // 不要这个数
//   int p2 = process1(index + 1, nums);
//   return std::max(p1, p2);
// }

//   int process2(vector<int> &nums)
//   {
//     int n = nums.size();
//     vector<int> dp(n + 2, 0);
//     for (int i = n - 1; i >= 0; i--)
//     {
//       dp[i] = std::max(dp[i + 2] + nums[i], dp[i + 1]);
//     }
//     return dp[0];
//   }

// int process3(vector<int> &nums)
// {
//   int n = nums.size();

//   vector<int> f(n, 0); // 选
//   vector<int> g(n, 0); // 不选
//   f[0] = nums[0];
//   g[0] = 0;
//   for (int i = 1; i < n; i++)
//   {
//     f[i] = g[i - 1] + nums[i]; // 那么i-1一定不选
//     g[i] = std::max(g[i - 1], f[i - 1]);
//   }
//   return std::max(f[n - 1], g[n - 1]);
// }

//   int massage(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     // return process1(0, nums);
//     // return process2(nums);
//     return process3(nums);
//   }
// };

// https://leetcode.cn/problems/house-robber-ii/
// class Solution
// {
// public:
//   int process1(int index, vector<int> nums)
//   {
//     if (index >= nums.size())
//       return 0;
//     // 要这个数
//     int p1 = 0;
//     int p2 = 0;
//     if (index == 0)
//     {
//       // 要了  0 位置的数
//       int ret = nums[nums.size() - 1];
//       nums[nums.size() - 1] = 0;
//       p1 = nums[index] + process1(index + 2, nums);
//       // 不要这个数
//       nums[nums.size() - 1] = ret;
//       p2 = process1(index + 1, nums);
//     }
//     else
//     {
//       p1 = nums[index] + process1(index + 2, nums);
//       // 不要这个数
//       p2 = process1(index + 1, nums);
//     }

//     return std::max(p1, p2);
//   }
//   int process2(vector<int> &nums)
//   {
//     int n = nums.size();

//     vector<int> f(n + 2, 0); // 要
//     vector<int> g(n + 2, 0); // 不要

//     for (int i = n - 1; i >= 0; i--)
//     {
//       if (i == n - 1)
//       {
//         f[i] = 0;
//         g[i] = std::max(g[i + 1], nums[i] + g[i + 2]);
//       }
//       else
//       {
//         f[i] = std::max(f[i + 1], nums[i] + f[i + 2]);
//         g[i] = std::max(g[i + 1], nums[i] + g[i + 2]);
//       }
//     }
//     return std::max(g[1], f[0]);
//   }
//   int rob1(vector<int> &nums, int left, int right)
//   {
//     if (left > right)
//       return 0;

//     int n = right - left + 1;

//     vector<int> f(n, 0);
//     vector<int> g(n, 0);

//     f[0] = nums[left];
//     g[0] = 0;
//     for (int i = 1; i < n; i++)
//     {
//       f[i] = g[i - 1] + nums[i + left];
//       g[i] = std::max(f[i - 1], g[i - 1]);
//     }
//     return std::max(f.back(), g.back());
//   }
//   int process3(vector<int> &nums)
//   {
//     //
//     int n = nums.size();
//     // 这里至少右两个元素
//     return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
//   }
//   int rob(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     if (nums.size() == 1)
//       return nums[0];
//     // return process1(0, nums);
//     // return process2(nums);
//     return process3(nums);
//   }
// };
// https://leetcode.cn/problems/delete-and-earn/

// class Solution
// {
// public:
//   int process(int index, vector<int> &nums, map<int, int> &m)
//   {
//     if (index >= nums.size())
//       return 0;
//     // 要当前的元素
//     int p1 = nums[index] * m.find(nums[index])->second;
//     if (index + 1 < nums.size() && (nums[index] + 1) != nums[index + 1])
//     {
//       p1 += process(index + 1, nums, m);
//     }
//     else if (index + 1 < nums.size() && (nums[index] + 1) == nums[index + 1])
//     {
//       p1 += process(index + 2, nums, m);
//     }

//     int p2 = process(index + 1, nums, m);

//     return std::max(p1, p2);
//   }

//   int process2(vector<int> &nums, map<int, int> &m)
//   {
//     int n = nums.size();
//     vector<int> dp(n + 2, 0);

//     for (int i = n - 1; i >= 0; i--)
//     {
//       int p1 = nums[i] * m.find(nums[i])->second;
//       if (i + 1 < nums.size() && (nums[i] + 1) != nums[i + 1])
//       {
//         p1 += dp[i + 1];
//       }
//       else if (i + 1 < nums.size() && (nums[i] + 1) == nums[i + 1])
//       {
//         p1 += dp[i + 2];
//       }
//       int p2 = dp[i + 1];
//       dp[i] = std::max(p1, p2);
//     }
//     return dp[0];
//   }

//   int process3(vector<int> &nums)
//   {
//     int n = nums.size();

//     vector<int> f(n, 0); // 选
//     vector<int> g(n, 0); // 不选
//     f[0] = nums[0];
//     g[0] = 0;
//     for (int i = 1; i < n; i++)
//     {
//       f[i] = g[i - 1] + nums[i]; // 那么i-1一定不选
//       g[i] = std::max(g[i - 1], f[i - 1]);
//     }
//     return std::max(f[n - 1], g[n - 1]);
//   }
//   int deleteAndEarn(vector<int> &nums)
//   {
//     if (nums.empty())
//       return 0;
//     int maxVal = nums[0];
//     for (int i = 1; i < nums.size(); i++)
//     {
//       maxVal = std::max(maxVal, nums[i]);
//     }
//     vector<int> v(maxVal + 1, 0);
//     for (int i = 0; i < nums.size(); i++)
//     {
//       v[nums[i]] += nums[i];
//     }
//     return process3(v);
//   }
// int deleteAndEarn(vector<int> &nums)
// {
//   if (nums.empty())
//     return 0;
//   map<int, int> m;
//   for (auto &e : nums)
//     m[e]++;

//   set<int> s;
//   for (auto &e : nums)
//     s.insert(e);
//   vector<int> v;
//   for (auto e : s)
//   {
//     v.push_back(e);
//   }

//   // return process(0, v, m);
//   return process2(v, m);
// }
// };

// https://leetcode.cn/problems/JEj789/
class Solution
{
  public:
    // 处于[x][y]我们需要花费分最小钱数
    int process(int x, int y, int row, int col, vector<vector<int>> &costs)
    {
      if (x == row || y == col)
        return INT32_MAX;
      if (x == row - 1)
        return costs[x][y];
      int p1 = 0;
      int p2 = 0;
      if (y == 0)
      {
        p1 = process(x + 1, 1, row, col, costs);
        p2 = process(x + 1, 2, row, col, costs);
      }
      else if (y == col - 1)
      {
        p1 = process(x + 1, 0, row, col, costs);
        p2 = process(x + 1, 1, row, col, costs);
      }
      else
      {
        p1 = process(x + 1, y - 1, row, col, costs);
        p2 = process(x + 1, y + 1, row, col, costs);
      }
      return std::min(p1, p2) + costs[x][y];
    }
    int process2(vector<vector<int>> &costs)
    {
      int row = costs.size();
      int col = costs.back().size();
      vector<vector<int>> dp(row + 1, vector<int>(col, 0));
      for (int i = row - 1; i >= 0; i--)
      {
        for (int j = 0; j < col; j++)
        {
          int p1 = 0;
          int p2 = 0;
          if (j == 0)
          {
            p1 = dp[i + 1][1];
            p2 = dp[i + 1][2];
          }
          else if (j == 2)
          {
            p1 = dp[i + 1][0];
            p2 = dp[i + 1][1];
          }
          else
          {
            p1 = dp[i + 1][0];
            p2 = dp[i + 1][2];
          }
          dp[i][j] = std::min(p1, p2) + costs[i][j];
        }
      }

      int minCostVal = dp[0][0];
      for (int i = 1; i < col; i++)
      {
        minCostVal = min(minCostVal, dp[0][i]);
      }
      return minCostVal;
    }
    int process3(vector<vector<int>> &costs)
    {
      int n = costs.size();

      // 到达某一个房子我们最小需要花费钱数
      //  三个状态  图红色,图绿色,图白色
      vector<vector<int>> dp(n + 1, vector<int>(3, 0));
      for (int i = 1; i <= n; i++)
      {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
      }

      int minCostVal = dp[n][0];
      for (int i = 1; i < 3; i++)
      {
        minCostVal = min(minCostVal, dp[n][i]);
      }
      return minCostVal;
    }

    int minCost(vector<vector<int>> &costs)
    {
      if (costs.empty())
        return 0;
      // int row = costs.size();
      // int col = costs.back().size();
      // int minCostVal = INT32_MAX;
      // for (int i = 0; i < col; i++)
      // {
      //   minCostVal = min(minCostVal, process(0, i, row, col, costs));
      // }
      // return minCostVal;
      return process2(costs);
    }
};
