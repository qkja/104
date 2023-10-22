#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

template<class T>
struct BSTreeNOde
{
public:
	BSTreeNOde(const T& x = T())
		:left(nullptr)
		, right(nullptr)
		, _key(x)
	{
	}

	BSTreeNOde* left;
	BSTreeNOde* right;
	T _key;
};


template<class T>
class BSTree
{
public:
	typedef BSTreeNOde<T> Node; // 名字有点 长
public:
	BSTree()
		:_root(nullptr)
	{}
public:
	~BSTree()
	{
		DestoryTree(_root);
		_root = nullptr;
	}
	// 给外部提供的节点
	void inorder()
	{
		_inorderR(_root);
	}
	// 插入数据
	Node* find(const T& key)
	{
		if (_root == nullptr)
			return nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->right;
			}
			else if (key < cur->_key)
			{
				cur = cur->left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}
	BSTree<T>& operator=(BSTree b)
	{
		swap(_root, b._root);
		return *this;
	}
	// 删除数据
	bool erase(const T& val)
	{
		// 1. 判断这个是不是在这个里面

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < val)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->_key > val)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				// 找到了,右树为空
				if (cur->right == nullptr)
				{
					// 1. 这里要判断我们的是不是root == cur
					if (_root == cur)
					{
						_root = cur->left;
						delete cur;
						return true;
					}
					// 这里要判断我们的cur是parent的左还是右
					if (cur == parent->left)
						parent->left = cur->left;
					else 
						parent->right = cur->left;
					delete cur;
					return true;
				}
				else if (cur->left == nullptr)
				{
					// 判断是不是头节点
					if (cur == _root)
					{
						_root = cur->right;
						delete cur;
						return true;
					}

					if (parent->right == cur)
						parent->right = cur->right;
					else
						parent->left = cur->right;
					delete cur;
					return true;
				}
				else
				{
					// 这里左右孩子都有
					// 1. 找到右子树里面的最小值
					Node*  minParent = cur;
					Node*  minRight = cur->right;
					while (minRight->left)
					{
						minParent = minRight;
						minRight = minRight->left;
					}
					// 交换 或者  直接覆盖
					std::swap(minRight->_key, cur->_key);

					if (minParent->left == minRight)
					{
						minParent->left = minRight->right;
					}
					else
					{
						// 这情况很重要是   
						// minp 
						//    minR
						//        val
						// 这个情况
						minParent->right = minRight->right;
					}
					delete minRight;
					return true;
				}
			}
			
		}
		return false;
	}

	// 插入数据

	bool insert(const T& val)
	{

		// 0. 看实现的功能,如果二叉树不允许插入相同的元素
		// 1. 首先new出来一个节点
		// 2. 插入数据
		// 2.1 第一个插入
		// 2.1 寻找插入的位置
		Node* node = new Node(val);

		if (_root == nullptr)
		{
			_root = node;
		}
		else
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (cur->_key > node->_key)
				{
					// 去左子树找
					parent = cur;
					cur = cur->left;
				}
				else if (cur->_key < node->_key)
				{
					parent = cur;
					cur = cur->right;
				}
				else 
				{
					return false;
				}
			}
			
			// 找到了,不过我们这里需要判断一下是左孩子,还是有孩子
			if (parent->_key > node->_key)
				// 去左孩子那
				parent->left = node;
			else
				parent->right = node;
		}
		return true;
	}
	bool insertR(const T& val)
	{
		return _insertR(_root, val);
	}
	bool eraseR(const T& val)
	{
		return _eraseR(_root, val);
	}
	BSTree(const BSTree<T>& b)
		:_root(nullptr)
	{
		_root = CopyTree(b._root);
	}
	Node* CopyTree(Node* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* copyNode = new Node(root->_key);

		copyNode->left = CopyTree(root->left);
		copyNode->right = CopyTree(root->right);
		return copyNode;
	}

private:
	void DestoryTree(Node* root)
	{
		if (root == nullptr)
			return;
		DestoryTree(root->left);
		DestoryTree(root->right);
		delete root;
	}
	bool _eraseR(Node*& root, const T& val)
	{
		if (root == nullptr)
		{
			return false;
		}
		// 先来找到这位置
		if (root->_key > val)
		{
			_eraseR(root->left, val);
		}
		else if (root->_key < val)
		{
			_eraseR(root->right, val);
		}
		else
		{
			// 找到了
			if (root->left == nullptr)
			{
				Node* cur = root;
				root = root->right;
				delete cur;
			}
			else if (root->right == nullptr)
			{
				Node* cur = root;
				root = root->left;
				delete cur;
			}
			else
			{
				Node* minRight = root->right;
				while (minRight->left != nullptr)
				{
					minRight = minRight->left;
				}
				// 这是一个好东西   
				swap(root->_key, minRight->_key);
				// 这里 递归  删除  要知道 现在 val所在的节点 一定是 没有左子树的
				return _eraseR(root->right, val);
			}
			return true;
		}
		return false;
	}
	// 中序遍历
	void _inorderR(Node* root)
	{
		if (root == nullptr)
			return;
		_inorderR(root->left);
		cout << root->_key << " ";
		_inorderR(root->right);
	}
	// 插入数据,递归版本
	bool _insertR(Node*& root, const T& val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return true;
		}

		if (root->_key > val)
		{
			_insertR(root->left, val);
		}
		else if (root->_key < val)
		{
			_insertR(root->right, val);
		}
		else
		{
			return false;
		}
		return true;
	}
private:
	Node* _root;
};
//int main()
//{
//	BSTree<int> b;
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	int sz = sizeof(a) / sizeof(int);
//
//	for (int i = 0; i < sz; i++)
//	{
//		b.insertR(a[i]);
//	}
//	b.inorder();
//	for (int e : a)
//	{
//		b.eraseR(e);
//		b.inorder();
//		cout << endl;
//	}
//
//	b.inorder();
//
//	return 0;
//}

//int main()
//{
//	BSTree<int> b;
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	int sz = sizeof(a) / sizeof(int);
//
//	for (int i = 0; i < sz; i++)
//	{
//		b.insertR(a[i]);
//	}
//
//	b.inorder();
//	cout << endl;
//	for (int e : a)
//	{
//		b.erase(e);
//		b.inorder();
//		cout << endl;
//	}
//
//	b.inorder();
//
//	return 0;
//}

//int main()
//{
//	BSTree<int> b;
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	int sz = sizeof(a) / sizeof(int);
//
//	for (int i = 0; i < sz; i++)
//	{
//		b.insert(a[i]);
//	}
//	b.inorder();
//	cout << endl;
//	// 插入个 相同的
//	b.insert(8);
//	b.inorder();
//
//	return 0;
//}
int main()
{
	BSTree<int> b1;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	int sz = sizeof(a) / sizeof(int);

	for (int i = 0; i < sz; i++)
	{
		b1.insertR(a[i]);
	}

	BSTree<int> b2(b1); // 拷贝构造
	BSTree<int> b3;
	b3 = b1; // operater = 

	b2.inorder();
	cout << endl;

	b3.inorder();
	cout << endl;

	return 0;
}