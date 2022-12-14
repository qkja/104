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
			// ?? Ϊ?? ?Һ????¸??׵???
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
				//?????? ????
				Node* subLeft = _node->_right;
				while (subLeft->_left)
				{
					subLeft = subLeft->_left;
				}
				_node = subLeft;
			}
			// ?? ??Ϊ??
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
			// ????  β?ڵ?
			//if (_node == nullptr)
			//{
			//	// ??????
			//	//Node* subRight = ;
			//}
			
			// ??Ϊ?? ?? ?? ????
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
	// ???? set ???? <K, K>
	// ???? map ???? <K, pair<K, V>>
	template<class K, class T, class KeyOfT>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		// ????????ʵ??
		typedef __RBTreeIterator<T, T&, T*> iterator;
		typedef __RBTreeIterator<T, const T&, const T*> const_iterator;


		const_iterator Begin() const
		{
			// ????
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
			// ????
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
			// ??һ?? ?ж? ??һ?? ????
			if (_pRoot == nullptr)
			{
				_pRoot = new Node(data);
				_pRoot->_col = BLACK;
				return make_pair(iterator(_pRoot), true);
			}

			// ?õ? key
			KeyOfT keyOfT;

			// ?ڶ??? ?????????? ??λ??
			Node* cur = _pRoot;
			Node* parent = nullptr;
			while (cur != nullptr)
			{
				/*int ret1 = keyOfT(cur->_data);
				int ret2 = keyOfT(data);*/
				if (keyOfT(cur->_data) < keyOfT(data))
				{
					// ȥ ???? ????
					parent = cur;
					cur = cur->_right;
				}
				else if (keyOfT(cur->_data) > keyOfT(data))
				{
					// ???? ????
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// ???????ﲻ???? ?ظ?ֵ ,???????Լ?ʵ??
					return make_pair(iterator(cur), false);
				}
			}

			// ֪?? ?ڵ?
			Node* node = new Node(data);
			node->_col = RED;           // ??ס ??Ҫ???Ź??캯??,?п??ܲ?????д??,?????Զ?Ĭ??0

			// ????Ԫ??
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

			// ???ڵ? ?? ??ɫ
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				if (parent->_left == parent)
				{
					// ?ж?  ?????ڵ?
					Node* uncle = grandfather->_right;
					if (uncle && uncle->_col == RED)
					{
						// ??ɫ
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;
						cur = grandfather;
						parent = cur->_parent;
					}
					else  // ????  ??????  ????  ???? ??   ??ɫ
					{
						if (cur == parent->_left)
						{
						 	//     g
						    //   p
						    // c
							// ????
							RotateR(grandfather);
							// ??ɫ
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//   g
							// p
							//    c
							// ???? +  ????
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
					//  ???? ????  ??  Ϊ ??
					if (uncle && uncle->_col == RED)
					{
						// ??ɫ
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
							// ????
							RotateL(grandfather);
							// ??ɫ
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							//   g
							//     p
							//   c
							// ???? +  ????
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
		// ??ת
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
					
			//pParent ?п??ܲ??? ??
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