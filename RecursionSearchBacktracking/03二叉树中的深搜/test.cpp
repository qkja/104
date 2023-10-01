/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//class Solution {
//public:
//
//    bool evaluateTree(TreeNode* root) {
//        if (root->left == nullptr && root->right == nullptr)
//            return root->val;
//        // 记录做左孩子的值
//        evaluateTree(root->left);
//        evaluateTree(root->right);
//        int ret = 0;
//        switch (root->val)
//        {
//        case 2:
//            ret = root->left->val | root->right->val;
//            break;
//        case 3:
//            ret = root->left->val & root->right->val;
//            break;
//        }
//        root->val = ret;
//        return root->val;
//    }
//};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    int dfs(TreeNode* root, int presum)
//    {
//        presum = presum * 10 + root->val;
//        if (root->left == nullptr && root->right == nullptr)
//            return presum;
//        int ret = 0;
//        if (root->left)
//            ret += dfs(root->left, presum);
//        if (root->right)
//            ret += dfs(root->right, presum);
//        return ret;
//
//    }
//    int sumNumbers(TreeNode* root) {
//        return dfs(root, 0);
//    }
//};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    TreeNode* pruneTree(TreeNode* root) {
//        if (root == nullptr)
//            return root;
//        root->left = pruneTree(root->left);
//        root->right = pruneTree(root->right);
//        if (root->left == nullptr && root->right == nullptr && root->val == 0)
//        {
//            delete root;
//            return nullptr;
//        }
//        return root;
//    }
//};
//class Solution {
//public:
//    long prev = LONG_MIN;
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr)
//            return true;
//        bool left = isValidBST(root->left);
//        bool cur = false;
//        if (root->val > prev)
//            cur = true;
//        prev = root->val;
//        bool right = isValidBST(root->right);
//        return left && right && cur;
//    }
//};

//class Solution {
//public:
//    long prev = LONG_MIN;
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr)
//            return true;
//        bool left = isValidBST(root->left);
//        if (left == false) // 剪枝
//            return false;
//        bool cur = false;
//        if (root->val > prev)
//            cur = true;
//        if (cur == false) // 剪枝
//            return false;
//
//        prev = root->val;
//        bool right = isValidBST(root->right);
//        return left && right && cur;
//    }
//};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    int count = 0;
//    int ret = 0;
//    void dfs(TreeNode* root)
//    {
//        if (root == nullptr || count == 0)
//            return;
//        dfs(root->left);
//        count--;
//        if (0 == count)
//        {
//            ret = root->val;
//            return;
//        }
//        dfs(root->right);
//    }
//    int kthSmallest(TreeNode* root, int k) {
//        count = k;
//        dfs(root);
//        return ret;
//    }
//};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> result;
    void dfs(TreeNode* root, string path)
    {
        path += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {

            result.push_back(path);
            return;
        }
        path += "->";
        if (root->left)
            dfs(root->left, path);
        if (root->right)
            dfs(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        dfs(root, path);
        return result;
    }
};