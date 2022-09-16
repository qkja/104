#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    bool _isSame(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr)
            return false;
        if (t1->val != t2->val)
            return false;
        return _isSame(t1->left, t2->left) && _isSame(t1->right, t2->right);
    }
    bool _isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        bool flg = _isSame(A, B);
        if (_isSame(A, B))
            return true;
        flg = _isSubStructure(A->left, B);
        if (flg)
            return true;
        flg = _isSubStructure(A->right, B);
        if (flg)
            return false;
        return false;
  

    }
public:
   
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return _isSubStructure(A, B);
    }
};