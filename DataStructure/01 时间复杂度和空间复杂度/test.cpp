//���ݽṹ�Ƕ����ݵ�һ�ִ洢����֯��һ�ַ�ʽ
// ��ôʲô���㷨: �������õļ������,��һ������һ������,����һϵ�е�ת��,Ȼ���Ϊһ��������һ������

//���ݽṹѧϰ�ò���ˣ��Ƽ���Ҷ�ȥ�ѡ���ָoffer���͡�����Ա��������ָ�ϡ��ϵ�����һ��

//��ָoffer: https://www.nowcoder.com/exam/oj/ta?page=1&tpId=13&type=13

// ��κ���һ���㷨������:��������
// 1. ʱ�临�Ӷ�
// 2. �ռ临�Ӷ�

// ע��,���������ص��ע��ʱ�临�Ӷ�,��Ҫ��ʱ�����ʹ�ÿռ�����ȡʱ��
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

