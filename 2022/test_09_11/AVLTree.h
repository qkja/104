#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <queue>
#include <assert.h>
using std::queue;
using std::cout;
using std::endl;
namespace bit
{
	template<class T>
	struct AVLTreeNode
	{
		AVLTreeNode(const T& data = T())
			: _parent(nullptr)
			, _left(nullptr)
			, _right(nullptr)
			, _data(data)
			, _bf(0)
		{}

		AVLTreeNode<T>* _parent;
		AVLTreeNode<T>* _left;
		AVLTreeNode<T>* _right;

		T _data;
		int _bf;

	};
	template<class K, class T>
	class AVLTree
	{
	public:
		typedef AVLTreeNode<T> Node;
		AVLTree()
			:_pRoot(nullptr)
		{}

		bool Insert(const T& data)
		{
			// 第一步 判断 第一次 插入
			if (_pRoot == nullptr)
			{
				_pRoot = new Node(data);
				_pRoot->_bf = 0;
				return true;
			}

			// 第二步 搜索二叉树 找位置
			Node* cur = _pRoot;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				if (cur->_data < data)
				{
					// 去 右树 查找
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_data > data)
				{
					// 左树 查找
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 我们这里不接受 重复值 ,你可以自己实现
					return false;
				}
			}

			// 第三步 new 出来一个节点
			Node* node = new Node(data);
			node->_bf = 0;               // 记住 不要相信构造函数,有可能不是你写的,不会自动默认0
			// 第四步 判断是插入左树还是 右树
			if (parent->_data > data)
			{
				parent->_left = node;
			}
			else
			{
				parent->_right = node;
			}
			// 这里需要链接
			node->_parent = parent;
			cur = node;
			// 更新平衡因子
			while (parent != nullptr)
			{
				// 如果 插入的是 右子树
				if (cur == parent->_right)
				{
					parent->_bf++;
				}
				else
				{
					parent->_bf--;
				}

				//  开始 检测
				if (parent->_bf == 0)
				{
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					// 这里 才是 大头
					if (cur->_bf == 1 && parent->_bf == 2)
					{
						// 左旋
						RotateL(parent);
						break;
					}
					else if (cur->_bf == -1 && parent->_bf == -2)
					{
						// 右旋
						RotateR(parent);
						break;
					}
					else if (cur->_bf == 1 && parent->_bf == -2)
					{
						RotateLR(parent);
						break;
					}
					else if (cur->_bf == -1 && parent->_bf == 2)
					{
						RotateRL(parent);
						break;
					}
					else 
					{
						assert(false);
					}
					// 等着
				}
				else
				{
					assert(false);
				}
			}

			return true;
		}

		// 层序遍历
		void levelOrder()
		{
			_levelOrder();
		}
		// 中序遍历
		void inorder()
		{
			_inorder(_pRoot);
		}
	private:
		void _inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_inorder(root->_left);
			cout << root->_data << " ";
			_inorder(root->_right);
		}
		void _levelOrder()
		{
			if (_pRoot == nullptr)
				return;

			// 层序遍历
			queue<Node*> q;
			q.push(_pRoot);
			int size = 1;
			while (size != 0)
			{
				Node* top = q.front();
				if (top->_left)
					q.push(top->_left);
				if (top->_right)
					q.push(top->_right);
				q.pop();
				--size;
				cout << top->_data << " ";
				if (size == 0)
				{
					cout << endl;
					size = q.size();
				}
			}
		}
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			RotateR(parent->_right);
			RotateL(parent);

			// 修改平衡因子

		}
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;
			RotateL(parent->_left);
			RotateR(parent);
			// 修改平衡因子
			if (bf == 0)
			{
				parent->_bf = 0;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else if (bf == 1)
			{
				parent->_bf = 0;
				subL->_bf = -1;
				subLR->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;
			Node* grandparent = parent->_parent;
			parent->_parent = subL;
			subL->_right = parent;

			if (grandparent == nullptr)
			{
				_pRoot = subL;
				_pRoot->_parent = nullptr;
			}
			else
			{
				subL->_parent = grandparent;
				if (grandparent->_left == parent)
				{
					grandparent->_left = subL;
				}
				else
				{
					grandparent->_right = subL;
				}
			}
			subL->_bf = parent->_bf = 0;
		}

		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;
			// 记录 祖父节点
			Node* grandparent = parent->_parent;

			parent->_parent = subR;
			subR->_left = parent;

			if (grandparent == nullptr)
			{
				// parent 就是 根节点
				_pRoot = subR;
				_pRoot->_parent = nullptr;
			}
			else
			{
				subR->_parent = grandparent;
				// 在判断  原本 的父节点 和 祖父的关系
				if (parent == grandparent->_left)
				{
					grandparent->_left = subR;
				}
				else
				{
					grandparent->_right = subR;
				}
			}

			// 修改 平衡因子
			subR->_bf = 0;
			parent->_bf = 0;
		}
	private:
		Node* _pRoot;
	};

	// 测试有序插入
	void test1()
	{
		//int arr[] = {  };
		AVLTree<int, int> a;
		for (int i = 0; i < 8; i++)
		{
			a.Insert(i+1);
		}
		cout << "层序遍历" << endl;
		a.levelOrder();
		cout << "中序遍历" << endl;
		a.inorder();
	}
}