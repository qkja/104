#include <vector>
using std::vector;

//class Solution {
//public:
//    void dfs(vector<int>& a, vector<int>& b, vector<int>& c, int n)
//    {
//        if (1 == n)
//        {
//            c.push_back(a.back());
//            a.pop_back();
//            return;
//        }
//        dfs(a, c, b, n - 1);
//        c.push_back(a.back());
//        a.pop_back();
//        dfs(b, a, c, n - 1);
//    }
//    void hanota(vector<int>& a, vector<int>& b, vector<int>& c) {
//        dfs(a, b, c, a.size());
//    }
//};

 // 1. ��Ŀ����
 // 2. �㷨ԭ��
 //    2.1. ����ͷ
 //    2.2. ������
 // �ݹ����
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr)
//            return list2;
//        if (nullptr == list2)
//            return list1;
//        if (list1->val <= list2->val)
//        {
//            list1->next = mergeTwoLists(list1->next, list2);
//            return list1;
//        }
//        else
//        {
//            list2->next = mergeTwoLists(list1, list2->next);
//            return list2;
//        }
//    }
//};

