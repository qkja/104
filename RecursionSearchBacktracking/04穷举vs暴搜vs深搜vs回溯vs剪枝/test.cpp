//class Solution {
//public:
//    vector<vector<int>> result;
//    vector<int> path;
//    vector<bool> check;
//    void dfs(vector<int>& nums)
//    {
//        if (path.size() == nums.size())
//        {
//            result.push_back(path);
//            return;
//        }
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (!check[i])
//            {
//                path.push_back(nums[i]);
//                check[i] = true;
//                dfs(nums);
//                // 回溯 -> 恢复现场
//                path.pop_back();
//                check[i] = false;
//
//            }
//        }
//    }
//    vector<vector<int>> permute(vector<int>& nums) {
//        check.resize(7, false);
//        dfs(nums);
//        return result;
//    }
//};

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int pos)
    {
        ret.push_back(path);
        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back(); // 恢复现场
        }
    }
};