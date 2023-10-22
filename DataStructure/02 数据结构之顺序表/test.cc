#include "SequenceTable.hpp"
#include <vector>
using namespace std;

//int main()
//{
//
//	return 0;
//}

//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        int fast = 0;
//        int end = 0;
//        while (fast < nums.size())
//        {
//            if (nums[fast] != val)
//            {
//                nums[end] = nums[fast];
//                ++end;
//            }
//            fast++;
//        }
//        return end;
//    }
//};

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int end = 0;
//        int fast = 1;
//        while (fast < nums.size())
//        {
//            if (nums[fast] != nums[end])
//            {
//                nums[++end] = nums[fast];
//            }
//            ++fast;
//        }
//        return ++end;
//    }
//};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end1 = m - 1;
        int end2 = n - 1;
        int index = nums1.size() - 1;
        while (end1 >=0 && end2 >= 0)
        {
            if (nums1[end1] > nums2[end2]) 
            {
                nums1[index--] = nums1[end1];
                --end1;
            }
            else
            {
                nums1[index--] = nums2[end2];
                --end2;
            }
        }
        while (end1 >=0)
        {
            nums1[index--] = nums1[end1];
            --end1;
        }
        while (end2 >= 0)
        {
            nums1[index--] = nums2[end2];
            --end2;
        }
    }
};