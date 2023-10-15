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
class Solution {
public:
    vector<string> v = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> ret;
    string path;
    void dfs(string& digits, int pos)
    {
        if (pos == digits.size())
        {
            ret.push_back(path);
            return;
        }
        // 只关注这一个字符, 我们必须要
        for (int j = 0; j < v[digits[pos] - '0'].size(); ++j)
        {
            path.push_back(v[digits[pos] - '0'][j]);
            dfs(digits, pos + 1);
            path.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return ret;
        dfs(digits, 0);
        return ret;
    }
};