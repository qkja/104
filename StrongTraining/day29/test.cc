#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
  /**
   *	正数数组中的最小不可组成和
   *	输入：正数数组arr
   *	返回：正数数组中的最小不可组成和
   */
  int getFirstUnFormedNum(vector<int> arr, int len)
  {
    set<int> s;
    int min_sum = arr[0];
    int max_sum = arr[0];
    vector<vector<int>> dp(len, vector<int>(len));
    dp[0][0] = max_sum;
    for (int i = 1; i < len; i++)
    {
      max_sum += arr[i];
      min_sum = min(min_sum, arr[i]);
      dp[0][i] = max_sum;
    }
    s.insert(max_sum);
    s.insert(min_sum);

    for (int i = 1; i < len; i++)
    {
      for (int j = 0; j < len; j++)
      {
        if (i <= j)
        {
          dp[i][j] = dp[0][j] - dp[0][i - 1];
          s.insert(dp[i][j]);
        }
      }
    }

    auto iter = s.begin();
    cout << min_sum << endl;
    cout << max_sum << endl;
    while (iter != s.end())
    {
      cout << *iter << endl;
      iter++;
    }

    // for (int i = min_sum; i <= max_sum; i++)
    // {
    //   auto iter = s.find(i);
    //   if (iter == s.end())
    //   {
    //     return *iter;
    //   }
    // }
    return max_sum + 1;
  }
};
int main()
{
  // [3,3,1,10,6,9,8,5,7]
  // [9,7,4,10,9,5]
  vector<int> v = {9, 7, 4, 10, 9, 5};
  // cout << Solution().getFirstUnFormedNum(v, v.size()) << endl;
  return 0;
}
