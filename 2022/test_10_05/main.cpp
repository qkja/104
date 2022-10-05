#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        // 双指针
        ListNode* prev = head;
        while (k-- && prev)
        {
            prev = prev->next;
        }
        //cout << prev->val;
        //cout << k;
        if (k != 0)
            return nullptr;
        //cout <<  prev->val;

        ListNode* cur = head;
        while (prev)
        {
            prev = prev->next;
            cur = cur->next;
        }
        //cout << cur->val;

        return cur;
    }
};

int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    Solution().getKthFromEnd(n1, 2);
    return 0;
}


//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        //不考虑头结点(其实，考虑头结点简单，我们按照难的来)
//        //合并前，先判定
//        if (nullptr == l1) {
//            return l2;
//        }
//        if (nullptr == l2) {
//            return l1;
//        }
//        //合并中，找到第一个节点
//        ListNode* new_head = nullptr;
//        if (l1->val < l2->val) {
//            new_head = l1;
//            l1 = l1->next;
//        }
//        else {
//            new_head = l2;
//            l2 = l2->next;
//        }
//        //合并剩下的节点
//        new_head->next = mergeTwoLists(l1, l2);
//        return new_head;
//    }
//};
//class Solution {
//public:
    // 动态规划
    // f(i) 表示 下标为i的和
    // f(i) = max(f(i-1) + arr[i],arr[i]);
    // f(0) = arr[0] max = arr[0];
    // 使用那种容器

    /*int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxSum = nums[0];
        int result = nums[0];;
        for (int i = 1; i < nums.size(); i++)
        {
            int ret = max(result + nums[i], nums[i]);
            if (result > 0)
                result = ret;
            else
                

            if (ret > maxSum)
                maxSum = ret;

        }
        return maxSum;
    }*/
    /*int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxSum = nums[0];
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            int ret = max(result[i - 1] + nums[i], nums[i]);
            result.push_back(ret);
            if (ret > maxSum)
                maxSum = ret;

        }
        return maxSum;
    }*/
    /*bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (nullptr == left)
            return false;
        if (nullptr == right)
            return false;
        if (left->val != right->val)
            return false;
        return isSymmetricHelper(left->left, right->right)
            && isSymmetricHelper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSymmetricHelper(root->left, root->right);
    }*/
    //TreeNode* mirrorTree(TreeNode* root) {
    //    if (root == nullptr)
    //        return nullptr;
    //    // 交换左右子树
    //    TreeNode* left = root->left;
    //    root->left = root->right;
    //    root->right = left;
    //    // 继续交换
    //    mirrorTree(root->left);
    //    mirrorTree(root->right);
    //    return root;
    //}
//};
//class Solution {
//public:
//    bool isSubStructureHelper(TreeNode* A, TreeNode* B) {
//        if (B == nullptr)
//            return true;
//        if (A == nullptr)
//            return false;
//        if (A->val != B->val)
//            return false;
//        return isSubStructureHelper(A->left, B->left)
//            && isSubStructureHelper(A->right, B->right);
//    }
//    bool isSubStructure(TreeNode* A, TreeNode* B) {
//        if (A == nullptr || B == nullptr)
//            return false;
//        bool result = false;
//        if (A->val == B->val)
//        {
//            result = isSubStructureHelper(A, B);
//            // 判断子结构
//        }
//        if (result != true)
//        {
//            result = isSubStructure(A->left, B);
//
//        }
//        if (result != true)
//        {
//            result = isSubStructure(A->right, B);
//        }
//        return result;
//    }
//};