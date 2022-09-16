#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

namespace bit
{
	enum Colour
	{
		RED,
		BLACK
	};
	template<class T>
	struct RBTreeNode
	{
		RBTreeNode(const T& data)
			:_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_data(data)
			,_col(RED)
		{}

		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;
		Colour _col;
	};


	template<class T,class Ref,class Ptr>
	struct __RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef  __RBTreeIterator<T, Ref, Ptr> Self;
		Node* _node;
		__RBTreeIterator(Node* node)
			:_node(node)
		{}
		__RBTreeIterator(const Self& self)
		{
			_node = self._node;
		}
		Ref operator*()
		{
			return _node->_data;
		}
		Ptr operator->()
		{
			return &_node->_data;
		}

		Self operator++()
		{
			// 右 为空 找孩子事父亲得左
			if (_node->_right == nullptr)
			{
				// 
				Node* child = _node;
				Node* parent = child->_parent;
				while (parent && parent->_left != child)
				{
					child = parent;
					parent = child->_parent;
				}
				_node = parent;
			}
			else
			{
				//右子树 最左
				Node* subLeft = _node->_right;
				while (subLeft->_left)
				{
					subLeft = subLeft->_left;
				}
				_node = subLeft;
			}
			// 右 不为空
			return *this;
		}
		Self operator++(int)
		{
			Self ret(*this);
			++(*this);
			return ret;
		}

		Self operator--()
		{
			// 问题  尾节点
			//if (_node == nullptr)
			//{
			//	// 找最右
			//	//Node* subRight = ;
			//}
			
			// 左为空 找 找 最右
			if (_node->_left == nullptr)
			{
				Node* child = _node;
				Node* parent = child->_parent;
				while (parent && parent->_right != child)
				{
					child = parent;
					parent = child->_parent;
				}
				_node = parent;
			}
			else
			{
				Node* subRight = _node->_left;
				while (subRight->_right)
				{
					subRight = subRight->_right;
				}
				_node = subRight;
			}
			return *this;
		}
		Self operator--(int)
		{
			Self ret(*this);
			--(*this);
			return ret;
		}

		bool operator==(const Self& s)
		{
			return _node == s._node;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}
	};
	// 对于 set 就是 <K, K>
	// 对于 map 就是 <K, pair<K, V>>
	template<class K, class T, class KeyOfT>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		// 迭代器的实现
		typedef __RBTreeIterator<T, T&, T*> iterator;
		typedef __RBTreeIterator<T, const T&, const T*> const_iterator;


		const_iterator Begin() const
		{
			// 最左
			Node* subLeft = _pRoot;
			while (subLeft && subLeft->_left != nullptr)
			{
				subLeft = subLeft->_left;
			}
			return const_iterator(subLeft);
		}
		const_iterator End() const
		{
			return const_iterator(nullptr);
		}

		iterator Begin()
		{
			// 最左
			Node* subLeft = _pRoot;
			while (subLeft && subLeft->_left != nullptr)
			{
				subLeft = subLeft->_left;
			}
			return iterator(subLeft);
		}
		iterator End()
		{
			return iterator(nullptr);
		}

	public:
		const_iterator Find(const K& key) const
		{
			Node* cur = _pRoot;
			KeyOfT keyOfT;
			while (cur)
			{
				if (key > keyOfT(cur->_data))
				{
					cur = cur->_right;
				}
				else if (key < keyOfT(cur->_data))
				{
					cur = cur->_left;
				}
				else
				{
					return const_iterator(cur);
				}
			}
			return const_iterator(nullptr);
		}
		iterator Find(const K& key)
		{
			Node* cur = _pRoot;
			KeyOfT keyOfT;
			while (cur)
			{
				if (key > keyOfT(cur->_data))
				{
					cur = cur->_right;
				}
				else if (key < keyOfT(cur->_data))
				{
					cur = cur->_left;
				}
				else
				{
					return iterator(cur);
				}
			}
			return iterator(nullptr);
		}
	
		pair<iterator,bool> Insert(const T& data)
		{
			// 第一步 判断 第一次 插入
			if (_pRoot == nullptr)
			{
				_pRoot = new Node(data);
				_pRoot->_col = BLACK;
				return make_pair(iterator(_pRoot), true);
			}

			// 得到 key
			KeyOfT keyOfT;

			// 第二步 搜索二叉树 找位置
			Node* cur = _pRoot;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				/*int ret1 = keyOfT(cur->_data);
				int ret2 = keyOfT(data);*/
				if (keyOfT(cur->_data) < keyOfT(data))
				{
					// 去 右树 查找
					parent = cur;
					cur = cur->_right;
				}
				else if (keyOfT(cur->_data) > keyOfT(data))
				{
					// 左树 查找
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// 我们这里不接受 重复值 ,你可以自己实现
					return make_pair(iterator(cur), false);
				}
			}

			// 知道 节点
			Node* node = new Node(data);
			node->_col = RED;           // 记住 不要相信构造函数,有可能不是你写的,不会自动默认0

			// 插入元素
			if (keyOfT(data) > keyOfT(parent->_data))
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
				return make_pair(iterator(node), true);
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
			return make_pair(iterator(node), true);

		}
	private:
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