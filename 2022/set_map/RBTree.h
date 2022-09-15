#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <queue>
using std::pair;
using std::cout;
using std::endl;
using std::queue;
namespace bit
{
	enum Colour
	{
		RED,
		BLACK
	};
	template<class K,class V>
	struct RBTreeNode
	{
		RBTreeNode(const pair<K,V>& kv)
			:_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_kv(kv)
			,_col(RED)
		{}

		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		Colour _col;
	};

	template<class K, class V>
	class RBTree
	{
	public:

		typedef RBTreeNode<K, V> Node;
		bool Insert(const pair<K, V>& data)
		{
			// 第一步 判断 第一次 插入
			if (_pRoot == nullptr)
			{
				_pRoot = new Node(data);
				_pRoot->_col = BLACK;
				return true;
			}

			// 第二步 搜索二叉树 找位置
			Node* cur = _pRoot;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				if (cur->_kv.first < data.first)
				{
					// 去 右树 查找
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_kv.first > data.first)
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

			// 知道 节点
			Node* node = new Node(data);
			node->_col = RED;           // 记住 不要相信构造函数,有可能不是你写的,不会自动默认0

			// 插入元素
			if (data.first > parent->_kv.first)
			{
				parent->_right = node;
			}
			else
			{
				parent->_left = node;
			}
			node->_parent = parent;
			cur = node;
			if (parent->_col == BLACK)
			{
				return true;
			}

			// 父节点 是 红色
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				if (parent->_left == parent)
				{
					// 判断  叔叔节点
					Node* uncle = grandfather->_right;
					if (uncle && uncle->_col == RED)
					{
						// 变色
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else  // 叔叔  不存在  或者  存在 是   黑色
					{
						if (cur == parent->_left)
						{
						 	//     g
						    //   p
						    // c
							// 右旋
							RotateR(grandfather);
							// 变色
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//   g
							// p
							//    c
							// 左旋 +  右旋
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
				else
				{
					Node* uncle = grandfather->_left;
					//  叔叔 存在  且  为 红
					if (uncle && uncle->_col == RED)
					{
						// 变色
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else
					{
						if (cur == parent->_right)
						{
							//     g
							//       p
							//         c
							// 左旋
							RotateL(grandfather);
							// 变色
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//   g
							//     p
							//   c
							// 右旋 +  左旋
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
			}

			_pRoot->_col = BLACK;
			return true;
		}

		void inorder()
		{
			_inorder(_pRoot);
		}
		void levelOrder()
		{
			_levelOrder();
		}
		int maxHeight()
		{
			return _maxHeight(_pRoot);
		}
		int minHeight()
		{
			return _minHeight(_pRoot);
		}

		bool IsValidRBTree()
		{
			Node* pRoot = _pRoot;
			// 空树也是红黑树
			if (nullptr == pRoot)
				return true;
			// 检测根节点是否满足情况
			if (BLACK != pRoot->_col)
			{
				cout << "违反红黑树性质二：根节点必须为黑色" << endl;
				return false;
			}

			// 获取任意一条路径中黑色节点的个数
			size_t blackCount = 0;
			Node* pCur = pRoot;
			while (pCur)
			{
				if (BLACK == pCur->_col)
					blackCount++;
				pCur = pCur->_left;
			}
			// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
			size_t k = 0;
			return _IsValidRBTree(pRoot, k, blackCount);
		}


	private:


		bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
		{
			//走到null之后，判断k和black是否相等
			if (nullptr == pRoot)
			{
				if (k != blackCount)
				{
					cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
					return false;
				}
				return true;
			}
			// 统计黑色节点的个数
			if (BLACK == pRoot->_col)
				k++;
			// 检测当前节点与其双亲是否都为红色 遇到 红色节点 检查 父亲
			Node* pParent = pRoot->_parent;
			if (pParent && RED == pParent->_col && RED == pRoot->_col)
			{
				cout << "违反性质三：没有连在一起的红色节点" << endl;
				return false;
			}
			return _IsValidRBTree(pRoot->_left, k, blackCount) &&
				_IsValidRBTree(pRoot->_right, k, blackCount);
		}


		int _maxHeight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int left = _maxHeight(root->_left);
			int right = _maxHeight(root->_right);
			return left > right ?  left + 1 : right + 1;
		}
		int _minHeight(Node* root)
		{
			if (root == nullptr)
				return 0;
			int left = _minHeight(root->_left);
			int right = _minHeight(root->_right);
			return left < right ?  left + 1 : right + 1;
		}
		void _levelOrder()
		{
			if (_pRoot == nullptr)
				return;

			// 层序遍历
			//queue<int*> q;
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
				cout << top->_kv.first << " ";
				if (size == 0)
				{
					cout << endl;
					size = q.size();
				}
			}
		}
		void _inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_inorder(root->_left);
			cout << root->_kv.first << " ";
			_inorder(root->_right);
		}
		// 旋转
		void RotateL(Node* parent)
		{
			Node* sub = parent->_right;
			Node* subR = sub->_left;
			parent->_right = subR;
			if (subR)
				subR->_parent = parent;
			Node* prev = parent->_parent;
			
			sub->_left = parent;
			parent->_parent = sub;
			if (prev == nullptr)
			{
				_pRoot = sub;
				_pRoot->_parent = nullptr;
			}
			else
			{
				if (prev->_left == parent)
					prev->_left = sub;
				else
					prev->_right = sub;
			
				sub->_parent = prev;
			}
	
		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;
			Node* prev = parent->_parent;
			
			parent->_parent = subL;
			subL->_right = parent;
					
			//pParent 有可能不是 根
			if (prev == nullptr)
			{
				_pRoot = subL;
				_pRoot->_parent = nullptr;
				return;
			}
			
			if (prev->_left == parent)
				prev->_left = subL;
			else
				prev->_right = subL;
					
			subL->_parent = prev;
		}
		
	private:
		Node* _pRoot = nullptr;
	};
}