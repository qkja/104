#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    /**
     *	���������е���С������ɺ�
     *	���룺��������arr
     *	���أ����������е���С������ɺ�
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
            cout << *iter << " ";
            iter++;
        }

         for (int i = min_sum; i <= max_sum; i++)
         {
           auto iter = s.find(i);
           if (iter == s.end())
           {
             return i;
           }
         }
        return max_sum + 1;
    }
};
int main()
{
    // [3,3,1,10,6,9,8,5,7]
    // [9,7,4,10,9,5]
    //[8, 10, 2, 10, 4, 8, 6, 3, 5, 7, 10]
    vector<int> v = { 8, 10, 2, 10, 4, 8, 6, 3, 5, 7, 10 };
    Solution().getFirstUnFormedNum(v, v.size());
    // cout << Solution().getFirstUnFormedNum(v, v.size()) << endl;
    return 0;
}
