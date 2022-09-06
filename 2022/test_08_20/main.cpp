#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
using namespace std;

//template<class T>
//void list_print(list<T>& l)
//{
//	typename list<T>::const_iterator cit = l.cbegin();
//	while (cit != l.cend())
//	{
//		cout << *cit << " ";
//		++cit;
//	}
//}
//
//int main()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(1);
//	l.push_back(1);
//	l.push_back(1);
//	l.push_back(1);
//	l.push_back(1);
//	list_print(l);
//
//	list<string> lstr;
//	lstr.push_back("qqqq");
//	lstr.push_back("qqqq");
//	lstr.push_back("qqqq");
//	lstr.push_back("qqqq");
//	lstr.push_back("qqqq");
//
//	list_print(lstr);
//	return 0;
//}
//namespace bit
//{
//	// 适配器 -- 复用
//	template<class Iterator, class Ref, class Ptr>
//	struct Reverse_iterator
//	{
//		Iterator _it;
//		typedef Reverse_iterator<Iterator, Ref, Ptr> Self;
//
//		Reverse_iterator(Iterator it)
//			:_it(it)
//		{}
//
//		Ref operator*()
//		{
//			Iterator tmp = _it;
//			return *(--tmp);
//		}
//
//		Ptr operator->()
//		{
//			return &(operator*());
//		}
//
//		Self& operator++()
//		{
//			--_it;
//			return *this;
//		}
//
//		Self& operator--()
//		{
//			++_it;
//			return *this;
//		}
//
//		bool operator!=(const Self& s)
//		{
//			return _it != s._it;
//		}
//	};
//	template<class T>
//	struct _list_node
//	{
//		_list_node<T>* _prev;
//		_list_node<T>* _next;
//		T _data;
//		_list_node(const T data = T())
//			:_prev(nullptr)
//			, _next(nullptr)
//			, _data(data)
//		{
//		}
//	};
//	template<class T, class Ref, class Ptr>
//	class _vector_iterator
//	{
//	public:
//		typedef _vector_iterator<T, Ref, Ptr> self;
//
//		_vector_iterator(const T*& node)
//			:_node(node)
//		{}
//
//		// ... ++ -- -> *
//	private:
//		T* _node;
//	};
//	template<class T>
//	class vector
//	{
//		typedef _vector_iterator<T, T&, T*> iterator;
//		typedef _vector_iterator<T, const T&, const T*> const_iterator;
//
//		typedef _vector_iterator<iterator, T&, T*> 
//			reverse_iterator;
//		typedef _vector_iterator<iterator, const T&, const T*> 
//			reverse_const_iterator;
//	public:
//
//		reverse_iterator rbegin()
//		{
//			return reverse_iterator(end());
//		}
//
//		reverse_iterator rend()
//		{
//			return reverse_iterator(begin());
//		}
//
//		iterator begin()
//		{
//			return iterator(_start);
//		}
//
//		const_iterator cbegin() const
//		{
//			return const_iterator(_start);
//		}
//
//		iterator end()
//		{
//			return iterator(_finish);
//		}
//
//		const_iterator cend() const
//		{
//			return const_iterator(_finish);
//		}
//
//	private:
//		T* _start;
//		T* _finish;
//		T* _endOfStoage;
//	};
//
//	
//
//
//
//	template<class T,class Ref,class Ptr>
//	class _list_iterator
//	{
//	public:
//		typedef _list_node<T> Node;
//		typedef _list_iterator<T,Ref,Ptr> self;
//
//		_list_iterator(Node* node)
//			:_node(node)
//		{}
//		_list_iterator(const _list_iterator<T, Ref, Ptr>& l)
//			:_node(l._node)
//		{}
//		// 前置
//		self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//		self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//		//后置
//		self operator++(int)
//		{
//			self cur = *this; // 调用  的 是拷贝构造
//			_node = _node->_next;
//			return cur;
//		}
//		self operator--(int)
//		{
//			self cur(*this);
//			_node = _node->_prev;
//			return cur;
//		}
//
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//		Ptr operator->()
//		{
//			return &(_node->_data);
//		}
//
//		bool operator!=(const self& t) const
//		{
//			return _node != t._node;
//		}
//		bool operator==(const self& t) const
//		{
//			return !(*this != t);
//		}
//	private:
//		Node* _node;
//	};
//
//	
//	template<class T>
//	class list
//	{
//	public:
//		typedef _list_node<T> Node;
//
//		typedef _list_iterator<T, T&, T*> iterator;
//		typedef _list_iterator<T, const T&, const T*> const_iterator;
//
//		typedef Reverse_iterator<iterator, const T&, const T*> 
//			reverse_iterator;
//		typedef Reverse_iterator<const_iterator, const T&, const T*> 
//			reverse_const_iterator;
//
//	public:
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//		iterator end()
//		{
//			return iterator(_head);
//		}
//
//		reverse_iterator rbegin()
//		{
//			return reverse_iterator(end());
//		}
//		iterator rend()
//		{
//			return reverse_iterator(begin());
//		}
//		const_iterator cbegin() const
//		{
//			return const_iterator(_head->_next);
//		}
//		const_iterator cend() const
//		{
//			return const_iterator(_head);
//		}
//
//		list()
//		{
//			_head = new Node;
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//	private:
//		Node* _head;
//	};
//}
//class MyClass
//{
//public:
//	MyClass(const MyClass& a)
//	{
//		_a = 1;
//	}
//	int _a;
//private:
//
//};
//
//int main()
//{
//	MyClass m1;
//	cout << m1._a << endl;
//	MyClass m1();
//	cout << m1._a << endl;
//
//
//	return 0;
//}