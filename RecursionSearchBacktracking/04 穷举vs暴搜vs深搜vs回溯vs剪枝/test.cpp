#include <vector>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> result;
//     vector<int> path;
//     vector<bool> check;
//     void dfs(vector<int>& nums)
//     {
//         if (path.size() == nums.size())
//         {
//             result.push_back(path);
//             return;
//         }
//
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (!check[i])
//             {
//                 path.push_back(nums[i]);
//                 check[i] = true;
//                 dfs(nums);
//                 // ���� -> �ָ��ֳ�
//                 path.pop_back();
//                 check[i] = false;
//
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         check.resize(7, false);
//         dfs(nums);
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> ret;
//     vector<int> path;
// public:
//     vector<vector<int>> subsets(vector<int>& nums)
//     {
//         dfs(nums, 0);
//         return ret;
//     }
//     void dfs(vector<int>& nums, int pos)
//     {
//         ret.push_back(path);
//         for (int i = pos; i < nums.size(); i++)
//         {
//             path.push_back(nums[i]);
//             dfs(nums, i + 1);
//             path.pop_back(); // �ָ��ֳ�
//         }
//     }
// };

// https://leetcode.cn/problems/permutations/
// class Solution
// {
// public:
//     vector<vector<int>> ret;
//     vector<int> path;
//     vector<bool> check;

//     void dfs(vector<int> &nums)
//     {
//         if (nums.size() == path.size())
//         {
//             ret.push_back(path);
//             return;
//         }
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             // 选择,
//             if (check[i] == false)
//             {
//                 // 这里是没有选的
//                 path.push_back(nums[i]);
//                 check[i] = true;
//                 dfs(nums);
//                 check[i] = false;
//                 path.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         check.resize(nums.size(), false);
//         dfs(nums);
//         return ret;
//     }
// };

// https://leetcode.cn/problems/subsets/submissions/

// class Solution
// {
// public:
//     vector<vector<int>> result;
//     vector<int> path;
//     void dfs(vector<int> &nums, int pos)
//     {
//         if (pos == nums.size())
//         {
//             result.push_back(path);
//             return;
//         }
//         // 选
//         path.push_back(nums[pos]);
//         dfs(nums, pos + 1);
//         path.pop_back();

//         // 不选
//         dfs(nums, pos + 1);
//     }
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         dfs(nums, 0);
//         return result;
//     }
// };

// class Solution
// {
// public:
//     vector<vector<int>> result;
//     vector<int> path;
//     void dfs(vector<int> &nums, int pos)
//     {
//         // pos 是从那里开始
//         result.push_back(path);

//         for (int i = pos; i < nums.size(); ++i)
//         {
//             path.push_back(nums[i]);
//             dfs(nums, i + 1);
//             // 恢复状态
//             path.pop_back();
//         }
//     }
//     vector<vector<int>> subsets(vector<int> &nums)
//     {
//         dfs(nums, 0);
//         return result;
//     }
// };
