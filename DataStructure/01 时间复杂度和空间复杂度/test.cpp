//数据结构是对数据的一种存储与组织的一种方式
// 那么什么是算法: 就是良好的计算过程,将一个或者一组输入,经过一系列的转换,然后变为一个或者是一组的输出

//数据结构学习得差不多了，推荐大家都去把《剑指offer》和《程序员代码面试指南》上的题做一遍

//剑指offer: https://www.nowcoder.com/exam/oj/ta?page=1&tpId=13&type=13

// 如何衡量一个算法的优略:两个方面
// 1. 时间复杂度
// 2. 空间复杂度

// 注意,这里我们重点关注是时间复杂度,必要的时候可以使用空间来换取时间
#include <vector>
using namespace std;

//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//      if(nums.empty()) return 0;
//      int n = nums.size();
//      int result = 0;
//      for(int i = 0; i <= n; ++i)
//        result ^= i;
//      for(int i = 0; i < n; i++)
//        result ^= nums[i];
//      return result;
//    }
//};

class Solution {
public:
    void reverse(vector<int>& v, int left, int right)
    {
        while(left < right)
        swap(v[left++], v[right--]);
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
};

