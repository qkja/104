#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using std::pair;
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

		RBTreeNode<K, V> _left;
		RBTreeNode<K, V> _right;
		RBTreeNode<K, V> _parent;
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
			if (data->first > parent->_kv->first)
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
						uncle->_col = BALCK;
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
							RotateR(grandfater);
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
							RotateR(grandfater);
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
							RotateL(grandfater);
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

	private:
		// 旋转
		void RotateL(Node* parent)
		{

		}
		void RotateR(Node* parent)
		{

		}
	private:
		Node* _pRoot = nullptr;
	};
}