#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};

//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (head == nullptr)
//            return nullptr;
//        unordered_map<Node*, Node*> m;
//        Node* cur = head;
//        while (cur != nullptr)
//        {
//            m.insert(make_pair(cur, new Node(cur->val)));
//            cur = cur->next;
//        }
//        // 这里 开始 修改
//        auto it = m.begin();
//        while (it != m.end())
//        {
//            if (it->first->next)
//            {
//                it->second->next = m.find(it->first->next)->second;
//            }
//            if (it->first->random)
//            {
//                it->second->random = m.find(it->first->random)->second;
//            }
//            else
//            {
//                it->second->random = nullptr;
//            }
//            ++it;
//        }
//        return m.find(head)->second;
//    }
//};

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//        if (head == nullptr)
//            return nullptr;
//        ListNode* newHead = nullptr;
//        ListNode* cur = head;
//        while (cur != nullptr)
//        {
//            ListNode* next = cur->next;
//            if (newHead == nullptr)
//            {
//                newHead = cur;
//                newHead->next = nullptr;
//            }
//            else
//            {
//                cur->next = newHead;
//                newHead = cur;
//            }
//            cur = next;
//        }
//        return newHead;
//    }
//};
 
//class Solution {
//public:
//    vector<int> reversePrint(ListNode* head) {
//        vector<int> v;
//        if (head == nullptr)
//            return v;
//        ListNode* cur = head;
//        while (cur != nullptr)
//        {
//            v.insert(v.begin(), cur->val);
//            cur = cur->next;
//        }
//        return v;
//    }
//};


//class Solution {
//public:
//    void sentenceToWords(const string& str,vector<string>& v)
//    {
//        int ret = str.find(' ');
//        int begin = 0;
//        string s;
//        while (ret != string::npos)
//        {
//            s = str.substr(begin, ret - begin);
//            begin = ret + 1;
//            
//            ret = str.find(' ',begin);
//            v.push_back(s);
//        }
//        if (ret == string::npos)
//        {
//            s = str.substr(begin);
//            v.push_back(s);
//        }
//        /*if (v.empty())
//        {
//            v.push_back(str);
//        }*/
//
//    }
//    vector<string> uncommonFromSentences(string s1, string s2) {
//        vector<string> v;
//        vector<string> v1;
//        vector<string> v2;
//        sentenceToWords(s1, v1);
//        sentenceToWords(s2, v2);
//        unordered_map<string, int> m;
//        for (string& val : v1)
//        {
//            m[val]++;
//        }
//        for (string& val : v2)
//        {
//            m[val]++;
//        }
//        auto it = m.begin();
//        while (it != m.end())
//        {
//            if (it->second == 1)
//            {
//                v.push_back(it->first);
//            }
//            ++it;
//        }
//        return v;
//    }
//};
//
//int main()
//{
//    vector<string> v;
//    string str1 = "this";
//    Solution().sentenceToWords(str1, v);
//    for (string& val : v)
//    {
//        cout << val << endl;
//    }
//    //string str2 = "banana";
//    //Solution().uncommonFromSentences(str1, str2);
//    return 0;
//}
//int main()
//{
//    vector<string> v;
//    string str = "this";
//    Solution().sentenceToWords(str, v);
//    for (string& val : v)
//    {
//        cout << val << endl;
//    }
//    return 0;
//}

//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> v;
//        if (nums1.empty() || nums2.empty())
//            return v;
//        unordered_map<int, int> m;
//        for (auto& e : nums1)
//        {
//            m[e]++;
//        }
//        for (auto& e : nums2)
//        {
//            auto it = m.find(e);
//            if (it != m.end() && it->second != 0)
//            {
//                v.push_back(e);
//                it->second--;
//            }
//        }
//        return v;
//    }
//};
//class Solution {
//public:
//    int repeatedNTimes(vector<int>& nums) {
//        unordered_map<int, int> m;
//        for (auto& e : nums)
//        {
//            m[e]++;
//        }
//        auto it = m.begin();
//        while (it != m.end())
//        {
//            if (it->second == nums.size() / 2)
//                return it->first;
//            ++it;
//        }
//        return 0;
//    }
//};
//#include "HashTable.h"
//int main()
//{
//
//	return 0;
//}