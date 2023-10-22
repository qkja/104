#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
// https://leetcode.cn/problems/sum-of-all-subset-xor-totals/
//class Solution {
//public:
//    int sum = 0;
//    int path = 0;
//    void dfs(vector<int>& nums, int pos)
//    {
//
//        sum += path;
//        for (int i = pos; i < nums.size(); i++)
//        {
//            path ^= nums[i];
//            dfs(nums, i + 1);
//            path ^= nums[i];
//        }
//    }
//    int subsetXORSum(vector<int>& nums) {
//
//        dfs(nums, 0);
//        return sum;
//    }
//};
// https://leetcode.cn/problems/permutations-ii/
//class Solution 
//{
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    vector<bool> check;
//    void dfs(vector<int>& nums)
//    {
//        if (nums.size() == path.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            // 只关心不合法的
//           /* if (check[i] == true || (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
//            {
//                continue;
//            }
//            path.push_back(nums[i]);
//            check[i] = true;
//            dfs(nums);
//            path.pop_back();
//            check[i] = false;*/
//
//            // 只关心合法的
//            if ((check[i] == false) && ( i == 0 || (nums[i] != nums[i - 1] || check[i - 1] == true)))
//            {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs(nums);
//                path.pop_back();
//                check[i] = false;
//            }
//        }
//    }
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        check.resize(nums.size(), false);
//        sort(nums.begin(), nums.end());
//
//        dfs(nums);
//        return ret;
//    }
//};
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
//class Solution {
//public:
//    vector<string> v = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    vector<string> ret;
//    string path;
//    void dfs(string& digits, int pos)
//    {
//        if (pos == digits.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//        // 只关注这一个字符, 我们必须要
//        for (int j = 0; j < v[digits[pos] - '0'].size(); ++j)
//        {
//            path.push_back(v[digits[pos] - '0'][j]);
//            dfs(digits, pos + 1);
//            path.pop_back();
//        }
//
//    }
//    vector<string> letterCombinations(string digits) {
//        if (digits.empty())
//            return ret;
//        dfs(digits, 0);
//        return ret;
//    }
//};
//https://leetcode.cn/problems/generate-parentheses/
//class Solution {
//public:
//    int left = 0;
//    int right = 0;
//    int n = 0;
//    string path;
//    vector<string> result;
//    void dfs()
//    {
//        if (right == n)
//        {
//            result.push_back(path);
//            return;
//        }
//
//        // 添加 左
//        if (left < n)
//        {
//            path.push_back('(');
//            left++;
//            dfs();
//            left--;
//            path.pop_back();
//        }
//
//        // 添加右的
//        if (right < left)
//        {
//            right++;
//            path.push_back(')');
//            dfs();
//            path.pop_back();
//            right--;
//        }
//
//    }
//    vector<string> generateParenthesis(int _n) {
//        n = _n;
//        dfs();
//        return result;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    int _k = 0;
//    int _n = 0;
//    vector<bool> flag;
//    void BFS(int index)
//    {
//        if (path.size() == _k)
//        {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = index; i < _k; ++i)
//        {
//            for (int j = 1; j <= _n; ++j)
//            {
//                // 选这个
//                // 继续田间一个剪枝
//                if (flag[j] == false)
//                {
//                    path.push_back(j);
//                    flag[j] = true;
//                    BFS(i + 1);
//                    path.pop_back();
//                    flag[j] = false;
//                }
//            }
//          
//        }
//    }
//    vector<vector<int>> combine(int n, int k) {
//        _k = k;
//        _n = n;
//        BFS(0);
//        flag.resize(n + 1, false);
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    int _k = 0;
//    int _n = 0;
//    vector<bool> flag;
//    void BFS(int index)
//    {
//        if (path.size() == _k)
//        {
//            ret.push_back(path);
//            return;
//        }
//        for (int i = index; i <= _n; ++i)
//        {
//            path.push_back(i);
//            BFS(i+1);
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> combine(int n, int k) {
//        _k = k;
//        _n = n;
//        BFS(1);
//        return ret;
//    }
//};
//class Solution {
//public:
//    int ret = 0;
//    int sum = 0;
//    int target;
//    void BFS(vector<int>& nums, int index)
//    {
//        if (index == nums.size())
//        {
//            if (sum == target)
//                ret++;
//            return;
//        }
//        sum += nums[index];
//        BFS(nums, index + 1);
//        sum -= nums[index];
//
//        sum -= nums[index];
//        BFS(nums, index + 1);
//        sum += nums[index];
//    }
//    int findTargetSumWays(vector<int>& nums, int _target)
//    {
//        target = _target;
//
//        BFS(nums, 0);
//        return ret;
//    }
//};

//class Solution {
//public:
//    int ret = 0;
//    int target;
//    void BFS(vector<int>& nums, int index, int sum)
//    {
//        if (index == nums.size())
//        {
//            if (sum == target)
//                ret++;
//            return;
//        }
//        ;
//        BFS(nums, index + 1, sum + nums[index]);
//        BFS(nums, index + 1, sum - nums[index]);
//    }
//    int findTargetSumWays(vector<int>& nums, int _target)
//    {
//        target = _target;
//
//        BFS(nums, 0, 0);
//        return ret;
//    }
//};
//class Solution {
//public:
//    vector<vector<int>> ret;
//    vector<int> path;
//    int target = 0;
//    void BFS(vector<int>& candidates, int pos, int sum)
//    {
//        if (target == sum)
//        {
//            ret.push_back(path);
//            return;
//        }
//        if (sum > target || pos == candidates.size())
//        {
//            return;
//        }
//        for (int i = pos; i < candidates.size(); ++i)
//        {
//            path.push_back(candidates[i]);
//            BFS(candidates, i, sum + candidates[i]);
//            path.pop_back();
//        }
//    }
//    vector<vector<int>> combinationSum(vector<int>& candidates, int _target) {
//        //sort(candidates.begin(), candidates.end());
//        target = _target;
//        BFS(candidates, 0, 0);
//        return ret;
//    }
//};

//class Solution {
//public:
//    vector<string> ret;
//    string path;
//    void BFS(string& s, int pos)
//    {
//        if (pos == s.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//        char ch = s[pos];
//        path.push_back(ch);
//        BFS(s, pos + 1);
//        path.pop_back();
//
//        if (ch < '0' || ch >'9')
//        {
//            if (ch >= 'a' && ch <= 'z')
//            {
//                ch = ch - ('a' - 'A');
//            }
//            else
//            {
//                ch = ch + ('a' - 'A');
//            }
//
//            path.push_back(ch);
//            BFS(s, pos + 1);
//            path.pop_back();
//        }
//    }
//    vector<string> letterCasePermutation(string s) {
//        BFS(s, 0);
//        return ret;
//    }
//};

//class Solution {
//public:
//    int ret = 0;
//    int n = 0;
//    vector<bool> check;
//    void BFS(int pos)
//    {
//        // 下标是 1 开始
//        if (pos == n+1)
//        {
//            ret++;
//            return;
//        }
//        
//        for (int i = 1; i <= n; i++)
//        {
//            if (check[i] == false && pos % i == 0 || i % pos == 0)
//            {
//                check[i] = true;
//                BFS(i + 1);
//                check[i] = false;
//            }
//        }
//    }
//    int countArrangement(int _n) {
//        n = _n;
//        check.resize(_n+1, false);
//        BFS(1);
//        return ret;
//    }
//};


class Solution {
public:
    int ret = 0;
    int n = 0;
    vector<bool> check;
    void BFS(int pos)
    {
        // 下标是 1 开始
        if (pos == n + 1)
        {
            ret++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (check[i] == false && (pos % i == 0 || i % pos == 0))
            {
                check[i] = true;
                BFS(pos + 1);
                check[i] = false;
            }
        }
    }
    int countArrangement(int _n) {
        n = _n;
        check.resize(16, false);
        BFS(1);
        return ret;
    }
};