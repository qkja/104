#define _CRT_SECURE_NO_WARNINGS 1

//void int binaryTree(Tree* root)
//{
//	if (root == NULL) 
//	{
//		return 0;
//	}
//	return 1 + binaryTree(root->left) + binaryTree(root->right);
//}
//
//// 第k层的节点的个数，k >= 1
//int BTreeKLevelSize(BTNode* root, int k)
//{
//	assert(k >= 1);
//	if (root == NULL) 
//	{
//		return 0;
//	}
//	if (1 == k)
//	{
//		return 1;
//	}
//	return BTreeKLevelSize(root->left, k - 1) + BTreeKLevelSize(root->right, k - 1);
//}

//int 