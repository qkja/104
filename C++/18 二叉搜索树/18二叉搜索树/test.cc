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
	typedef BSTreeNOde<T> Node; // �����е� ��
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
	// ���ⲿ�ṩ�Ľڵ�
	void inorder()
	{
		_inorderR(_root);
	}
	// ��������
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
	// ɾ������
	bool erase(const T& val)
	{
		// 1. �ж�����ǲ������������

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
				// �ҵ���,����Ϊ��
				if (cur->right == nullptr)
				{
					// 1. ����Ҫ�ж����ǵ��ǲ���root == cur
					if (_root == cur)
					{
						_root = cur->left;
						delete cur;
						return true;
					}
					// ����Ҫ�ж����ǵ�cur��parent��������
					if (cur == parent->left)
						parent->left = cur->left;
					else 
						parent->right = cur->left;
					delete cur;
					return true;
				}
				else if (cur->left == nullptr)
				{
					// �ж��ǲ���ͷ�ڵ�
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
					// �������Һ��Ӷ���
					// 1. �ҵ��������������Сֵ
					Node*  minParent = cur;
					Node*  minRight = cur->right;
					while (minRight->left)
					{
						minParent = minRight;
						minRight = minRight->left;
					}
					// ���� ����  ֱ�Ӹ���
					std::swap(minRight->_key, cur->_key);

					if (minParent->left == minRight)
					{
						minParent->left = minRight->right;
					}
					else
					{
						// ���������Ҫ��   
						// minp 
						//    minR
						//        val
						// ������
						minParent->right = minRight->right;
					}
					delete minRight;
					return true;
				}
			}
			
		}
		return false;
	}

	// ��������

	bool insert(const T& val)
	{

		// 0. ��ʵ�ֵĹ���,��������������������ͬ��Ԫ��
		// 1. ����new����һ���ڵ�
		// 2. ��������
		// 2.1 ��һ������
		// 2.1 Ѱ�Ҳ����λ��
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
					// ȥ��������
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
			
			// �ҵ���,��������������Ҫ�ж�һ��������,�����к���
			if (parent->_key > node->_key)
				// ȥ������
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
		// �����ҵ���λ��
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
			// �ҵ���
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
				// ����һ���ö���   
				swap(root->_key, minRight->_key);
				// ���� �ݹ�  ɾ��  Ҫ֪�� ���� val���ڵĽڵ� һ���� û����������
				return _eraseR(root->right, val);
			}
			return true;
		}
		return false;
	}
	// �������
	void _inorderR(Node* root)
	{
		if (root == nullptr)
			return;
		_inorderR(root->left);
		cout << root->_key << " ";
		_inorderR(root->right);
	}
	// ��������,�ݹ�汾
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
//	// ����� ��ͬ��
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

	BSTree<int> b2(b1); // ��������
	BSTree<int> b3;
	b3 = b1; // operater = 

	b2.inorder();
	cout << endl;

	b3.inorder();
	cout << endl;

	return 0;
}