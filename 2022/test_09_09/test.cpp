#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <map>
using namespace std;



//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        if (nums.empty())
//            return -1;
//        int sum = 0;
//        for (int val : nums)
//            sum += val;
//        for (int i = 0; i <= nums.size(); i++)
//        {
//            sum -= i;
//        }
//        return -sum;
//    }
//};





//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        if (nums.empty())
//            return -1;
//        map<int, int> m;
//        for (const int& val : nums)
//        {
//            m[val]++;
//        }
//        auto it = m.find(target);
//        return it->second;
//    }
//};


//class Solution {
//public:
//    int findRepeatNumber(vector<int>& nums) {
//        if (nums.size() == 0)
//            return -1;
//        map<int, int> m;
//        for (const int& val : nums)
//        {
//            auto it = m.insert(make_pair(val, 0));
//            if (it.second == false)
//                return val;
//        }
//        return -1;
//    }
//};
//bool Erase(const K& key)
//{
//	size_t hashi = key;
//	hashi %= _tables.size();
//	Node* cur = _tables[hashi];
//	Node* prev = nullptr;
//	while (cur)
//	{
//		
//		if (cur->_kv.first == key)
//		{
//			// 首先 记录  当前节点  下一个的 位置
//			Node* next = cur->next;
//			if (prev == nullptr)
//			{
//				delete _tables[hashi];
//				_tables[hashi] = nullptr;
//			}
//			else
//			{
//				delete cur;
//				prev->next = next;
//			}
//			return true;
//		}
//
//		prev = cur;
//		cur = cur->_next;
//	}
//
//	return false;
//}

