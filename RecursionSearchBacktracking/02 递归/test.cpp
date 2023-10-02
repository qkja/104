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

 // 1. 题目解释
 // 2. 算法原理
 //    2.1. 函数头
 //    2.2. 函数体
 // 递归出口
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

//class Solution {
//public:
//
//    ListNode* reverseList(ListNode* head) {
//        if (nullptr == head || head->next == nullptr)
//            return head;
//        ListNode* newHead = reverseList(head->next);
//        head->next->next = head;
//        head->next = nullptr;
//        return newHead;
//    }
//};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == nullptr || head->next == nullptr)
//            return head;
//        ListNode* ret = swapPairs(head->next->next);
//        ListNode* newHead = head->next;
//        head->next->next = head;
//
//        head->next = ret;
//        return newHead;
//    }
//};

class Solution {
public:
    double myPow(double x, int n) {
        return n < 0 ? 1.0 / Pow(x, -(long long)n) : Pow(x, (long long)n);
    }
    double Pow(double x, int n) {
        if (n == 0)
            return 1.0;
        double ret = Pow(x, n / 2);
        return n % 2 == 0 ? ret * ret : ret * ret * x;
    }
};