#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        vector<int> v;
        if (root == nullptr)
            return vv;
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        int size = 1;
        while (size)
        {
            TreeNode* top = q.front();
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
            if (i % 2 == 0)
            {
                v.push_back(top->val);
            }
            else
            {
                v.insert(v.begin(), top->val);
            }
            q.pop();
            --size;
            if (size == 0)
            {
                size = q.size();
                vv.push_back(v);
                v.clear();
                ++i;
            }
        }
        return vv;
    }
};

//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vv;
//        vector<int> v;
//        if (root == nullptr)
//            return vv;
//        queue<TreeNode*> q;
//        q.push(root);
//        int size = 1;
//        while (size)
//        {
//            TreeNode* top = q.front();
//            if (top->left)
//                q.push(top->left);
//            if (top->right)
//                q.push(top->right);
//
//            v.push_back(top->val);
//            q.pop();
//            --size;
//            if (size == 0)
//            {
//                size = q.size();
//                vv.push_back(v);
//                v.clear();
//            }
//        }
//        return vv;
//    }
//};
 
//class Solution {
//public:
//    vector<int> levelOrder(TreeNode* root) {
//        vector<int> v;
//        if (root == nullptr)
//            return v;
//        queue<TreeNode*> q;
//        q.push(root);
//        int size = 1;
//        while (size)
//        {
//            TreeNode* top = q.front();
//            if (top->left)
//                q.push(top->left);
//            if(top->right)
//                q.push(top->right);
//
//            v.push_back(top->val);
//            q.pop();
//            --size;
//            if (size == 0)
//            {
//                size = q.size();
//            }
//        }
//        return v;
//    }
//};