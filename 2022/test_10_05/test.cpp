#define _CRT_SECURE_NO_WARNINGS 1
/*#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <string>
using namespace std;
template <class T>*/
//int PrintArg(const T& t)
//{
//	cout << t << " ";
//	return 0;
//}
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { PrintArg(args)... };
//	cout << endl;
//}
//
//int main()
//{
//	ShowList(1, 'x', 1.1, string("hello world"));
//	cout << endl;
//
//	ShowList(1, 2, 3, 4, 5);
//	return 0;
//}

//void ShowList()
//{
//}
//template <class ...Args>
//void ShowList(Args... args)
//{
//	int arr[] = { args... };
//}
//
//int main()
//{
//	ShowList(1, 2);
//	return 0;
//}



//template <class T>
//void ShowList(const T& val)
//{
//	cout << val <<"->"<<typeid(val).name()<<" end"<< endl;
//}
//void ShowList()
//{
//}
//template <class T, class ...Args>
//void ShowList(const T& val, Args... args)
//{
//	cout << sizeof...(args) << endl;
//	cout << val <<" -> "<< typeid(val).name() << endl;
//	ShowList(args...);
//}
//
//int main()
//{
//	ShowList(1, 2);
//	return 0;
//}

//int main()
//{
//	ShowList(1, 2, 3, 4, 5);
//	ShowList(1, 2, 3, 4, 5);
//	return 0;
//}


// Args是一个模板参数包，args是一个函数形参参数包
// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{
//	cout << sizeof...(args) << endl;
//}
//int main()
//{
//
//	ShowList(1, 2, 3, 4, 5);
//	return 0;
//}

//void Fun(int& x) 
//{ 
//	cout << "左值引用" << endl;
//}
//void Fun(const int& x) 
//{
//	cout << "const 左值引用" << endl; 
//}
//void Fun(int&& x) 
//{ 
//	cout << "右值引用" << endl; 
//}
//void Fun(const int&& x)
//{
//	cout << "const 右值引用" << endl; 
//}
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10); // 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b); // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}

//namespace bit
//{
//	class string
//	{
//
//	public:
//		
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			//cout << "string(char* str)" << endl;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		// 拷贝构造
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//			string tmp(s._str);
//			swap(tmp);
//		}
//		//// 赋值重载
//		//string& operator=(const string& s)
//		//{
//		//	cout << "string& operator=(string s) -- 深拷贝" << endl;
//		//	string tmp(s);
//		//	swap(tmp);
//		//	return *this;
//		//}
//		// 移动构造
//		string(string && s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 移动语义" << endl;
//			swap(s);
//		}
//		// 移动赋值
//		string& operator=(string && s)
//		{
//			cout << "string& operator=(string&& s) -- 移动语义" << endl;
//			swap(s);
//			return *this;
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//	
//
//	private:
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // 不包含最后做标识的\0
//	};
//	//这个实现是不对的
//	bit::string to_string(int val)
//	{
//		bit::string str;
//		while (val > 0)
//		{
//			int x = val % 10;
//			val /= 10;
//			str += ('0' + x);
//		}
//		return str;
//	}
//}
//int main()
//{
//	bit::string s1("hello");
//	bit::string s2;
//	s2 = move(s1);
//	return 0;
//}
//int main()
//{
//	bit::string s1 = "hello";
//	bit::string s2(s1);
//	bit::string s3 = "word";
//	bit::string s4(move(s3));
//
//
//	return 0;
//}

//int main()
//{
//	bit::string str = bit::to_string(123);
//
//	return 0;
//}

//int main()
//{
//	string s1("hello");
//	string s2 = move(s1);
//	return 0;
//}


//int main()
//{
//	int x = 111;
//	int&& y = move(x);
//	return 0;
//}

//int main()
//{
//	10;
//	int&& a = 10;
//	cout << &a << endl;
//	return 0;
//}


//int main()
//{
//	vector<int> v = { 1,2,3,4,5,6 };
//	for (int val : v)
//	{
//		cout << val << " ";
//	}
//	return 0;
//}
//int main()
//{
//	map<string, string> m;
//	m.insert(make_pair("left", "左边"));
//	map<string, string>::iterator it1 = m.begin();
//	auto it2 = m.begin(); // 简单点
//	return 0;
//}

//namespace bit
//{
//	template<class T>
//	class vector {
//	public:
//		typedef T* iterator;
//		vector(initializer_list<T> l)
//		{
//			for (auto& data : l)
//				push_back(data);
//		}
//		vector<T>& operator=(initializer_list<T> l) {
//			vector<T> tmp(l);
//			std::swap(_start, tmp._start);
//			std::swap(_finish, tmp._finish);
//			std::swap(_endofstorage, tmp._endofstorage);
//			return *this;
//		}
//		void push_back(const T& data)
//		{
//
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _endofstorage;
//	};
//}

//int main()
//{
//	vector<int> v = { 1,2,3,4,5,6 };
//	
//	return 0;
//}

//int main()
//{
//	auto il = { 10, 20, 30 };
//	auto it = il.begin();
//	while (it != il.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	return 0;
//}


//class Date
//{
//public:
//	explicit Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1 = { 2000, 1, 2 };
//	return 0;
//}


//int main()
//{
//	Date d1{ 2000, 1, 2 };
//	Date d3 = { 2000, 1, 3 };
//	Date* p1 = new Date[3]{ { 2022, 1, 2 },{ 2022, 1, 2 },{ 2022, 1, 2 } };
//	delete p1;
//	return 0;
//}


//struct A
//{
//	A(int a = 1)
//		:_a(a)
//	{}
//	int _a;
//};
//int main()
//{
//	A* p = new A[3]{ 0 };
//	delete p;
//	return 0;
//}

//int main()
//{
//	int* p1 = new int[3]{ 0 };
//	int* p2 = new int[3]{ 1,2,3 };
//	delete[] p1;
//	delete[] p2;
//	return 0;
//}

//struct Person
//{
//	char name[20];
//	int age;
//	char sex[10];
//};
//int main()
//{
//	int arr[10]{ 1,2,3,4,5,6 };
//	struct Person per{ "张三",18,"男" };
//
//	return 0;
//}


//int main()
//{
//	int* p1 = new int(1);
//	delete p1;
//	return 0;
//}
//int main()
//{
//	int x = 10;
//	int y = { 10 };
//	int z{ 10 };
//	return 0;
//}


//struct Person
//{
//	char name[20];
//	int age;
//	char sex[10];
//};
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6 };
//	struct Person per = { "张三",18,"男" };
//
//	return 0;
//}


//struct ListNode
//{
//	ListNode* _next = nullptr;
//	ListNode* _prev = nullptr;
//	T _data;
//};
//template<class T>
//class List
//{
//	typedef ListNode<T> Node;
//public:
//	List()
//	{
//		_head = new Node;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	void PushBack(T&& xx)
//	{
//		Insert(_head, std::forward<T>(xx));
//		Insert(_head, xx);
//	}
//
//	void PushBack(T& x)
//	{
//		Insert(_head, x);
//	}
//
//	void Insert(Node* pos, T&& xx)
//	{
//		Node* prev = pos->_prev;
//		Node* newnode = new Node;
//		//newnode->_data = std::forward<T>(xx); // 关键位置
//		newnode->_data = xx; // 关键位置
//		// prev newnode pos
//		prev->_next = newnode;
//		newnode->_prev = prev;
//		newnode->_next = pos;
//		pos->_prev = newnode;
//	}
//	void Insert(Node* pos, const T& x)
//	{
//		Node* prev = pos->_prev;
//		Node* newnode = new Node;
//		newnode->_data = x; // 关键位置
//		// prev newnode pos
//		prev->_next = newnode;
//		newnode->_prev = prev;
//		newnode->_next = pos;
//		pos->_prev = newnode;
//	}
//private:
//	Node* _head;
//};
//
//int main()
//{
//	List<bit::string> lt;
//	lt.PushBack("1111");
//	return 0;
//}
//namespace bit
//{
//	class string
//	{
//
//	public:
//
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			//cout << "string(char* str)" << endl;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		// 拷贝构造
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//			string tmp(s._str);
//			swap(tmp);
//		}
//		//// 赋值重载
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- 深拷贝" << endl;
//			string tmp(s);
//			swap(tmp);
//			return *this;
//		}
//		// 移动构造
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 移动语义" << endl;
//			swap(s);
//		}
//		// 移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动语义" << endl;
//			swap(s);
//			return *this;
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//
//	private:
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // 不包含最后做标识的\0
//	};
//	//这个实现是不对的
//	bit::string to_string(int val)
//	{
//		bit::string str;
//		while (val > 0)
//		{
//			int x = val % 10;
//			val /= 10;
//			str += ('0' + x);
//		}
//		return str;
//	}
//}

//template<class T>
//struct ListNode
//{
//	ListNode* _next = nullptr;
//	ListNode* _prev = nullptr;
//	T _data;
//};
//template<class T>
//class List
//{
//	typedef ListNode<T> Node;
//public:
//	List()
//	{
//		_head = new Node;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	void PushBack(const T& x)
//	{
//		Insert(_head, x);
//	}
//	void PushBack(T&& xx)
//	{
//		Insert(_head, std::forward<T>(xx));
//	}
//	void Insert(Node* pos, T&& xx)
//	{
//		Node* prev = pos->_prev;
//		Node* newnode = new Node;
//
//		newnode->_data = std::forward<T>(xx); // 关键位置
//		// prev newnode pos
//		prev->_next = newnode;
//		newnode->_prev = prev;
//		newnode->_next = pos;
//		pos->_prev = newnode;
//	}
//	void Insert(Node* pos, const T& x)
//	{
//		Node* prev = pos->_prev;
//		Node* newnode = new Node;
//		newnode->_data = x; // 关键位置
//		// prev newnode pos
//		prev->_next = newnode;
//		newnode->_prev = prev;
//		newnode->_next = pos;
//		pos->_prev = newnode;
//	}
//private:
//	Node* _head;
//};
//
//int main()
//{
//	List<bit::string> lt;
//	bit::string s1 = "hello";
//	lt.PushBack("1111");
//	lt.PushBack(s1);
//	return 0;
//}

//namespace bit
//{
//	class string
//	{
//
//	public:
//
//		string(const char* str = "")
//			:_size(strlen(str))
//			, _capacity(_size)
//		{
//			//cout << "string(char* str)" << endl;
//			_str = new char[_capacity + 1];
//			strcpy(_str, str);
//		}
//		// 拷贝构造
//		string(const string& s)
//			:_str(nullptr)
//		{
//			cout << "string(const string& s) -- 深拷贝" << endl;
//			string tmp(s._str);
//			swap(tmp);
//		}
//		//// 赋值重载
//		string& operator=(const string& s)
//		{
//			cout << "string& operator=(string s) -- 深拷贝" << endl;
//			string tmp(s);
//			swap(tmp);
//			return *this;
//		}
//		// 移动构造
//		string(string&& s)
//			:_str(nullptr)
//			, _size(0)
//			, _capacity(0)
//		{
//			cout << "string(string&& s) -- 移动语义" << endl;
//			swap(s);
//		}
//		// 移动赋值
//		string& operator=(string&& s)
//		{
//			cout << "string& operator=(string&& s) -- 移动语义" << endl;
//			swap(s);
//			return *this;
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//
//		void reserve(size_t n)
//		{
//			if (n > _capacity)
//			{
//				char* tmp = new char[n + 1];
//				strcpy(tmp, _str);
//				delete[] _str;
//				_str = tmp;
//				_capacity = n;
//			}
//		}
//		void push_back(char ch)
//		{
//			if (_size >= _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//				reserve(newcapacity);
//			}
//			_str[_size] = ch;
//			++_size;
//			_str[_size] = '\0';
//		}
//		string& operator+=(char ch)
//		{
//			push_back(ch);
//			return *this;
//		}
//
//
//	private:
//		void swap(string& s)
//		{
//			::swap(_str, s._str);
//			::swap(_size, s._size);
//			::swap(_capacity, s._capacity);
//		}
//	private:
//		char* _str;
//		size_t _size;
//		size_t _capacity; // 不包含最后做标识的\0
//	};
//	//这个实现是不对的
//	bit::string to_string(int val)
//	{
//		bit::string str;
//		while (val > 0)
//		{
//			int x = val % 10;
//			val /= 10;
//			str += ('0' + x);
//		}
//		return str;
//	}
//
//	template<class T>
//	struct list_node
//	{
//		list_node<T>* _next;
//		list_node<T>* _prev;
//		T _data;
//
//		list_node(const T& val = T())
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(val)
//		{}
//
//		list_node(T&& val)
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(std::forward<T>(val))
//		{}
//	};
//
//	
//	template<class T, class Ref, class Ptr>
//	struct __list_iterator
//	{
//		typedef list_node<T> Node;
//		typedef __list_iterator<T, Ref, Ptr> self;
//
//		typedef Ptr pointer;
//		typedef Ref reference;
//
//		Node* _node;
//
//		__list_iterator(Node* node)
//			:_node(node)
//		{}
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//
//		Ptr operator->()
//		{
//			//return &(operator*());
//			return &_node->_data;
//		}
//
//		self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//		self operator++(int)
//		{
//			self tmp(*this);
//			_node = _node->_next;
//			return tmp;
//		}
//
//		self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//
//		self operator--(int)
//		{
//			self tmp(*this);
//			_node = _node->_prev;
//			return tmp;
//		}
//
//
//		bool operator!=(const self& it)
//		{
//			return _node != it._node;
//		}
//
//		bool operator==(const self& it)
//		{
//			return _node == it._node;
//		}
//
//	};
//
//	template<class T>
//	class list
//	{
//		typedef list_node<T> Node;
//	public:
//
//		typedef __list_iterator<T, T&, T*> iterator;
//		typedef __list_iterator<T, const T&, const T*> const_iterator;
//
//		const_iterator begin() const
//		{
//			return const_iterator(_head->_next);
//		}
//
//		const_iterator end() const
//		{
//			return const_iterator(_head);
//		}
//
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//
//		iterator end()
//		{
//			return iterator(_head);
//		}
//
//		list()
//		{
//			_head = new Node();
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		void empty_init()
//		{
//			_head = new Node();
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//
//		void swap(list<T>& lt)
//		{
//			std::swap(_head, lt._head);
//		}
//
//
//
//		void push_back(const T& x)
//		{
//			insert(end(), x);
//		}
//
//		void push_back(T&& xx)
//		{
//			insert(end(), std::forward<T>(xx));
//			//insert(end(), xx);
//		}
//
//
//	
//		// 插入在pos位置之前
//		iterator insert(iterator pos, const T& x)
//		{
//			Node* newNode = new Node(x);
//			Node* cur = pos._node;
//			Node* prev = cur->_prev;
//
//			// prev  newnode  cur
//			prev->_next = newNode;
//			newNode->_prev = prev;
//			newNode->_next = cur;
//			cur->_prev = newNode;
//
//			return iterator(newNode);
//		}
//
//		iterator insert(iterator pos, T&& xx)
//		{
//			Node* newNode = new Node(std::forward<T>(xx));
//			//Node* newNode = new Node(xx);
//			Node* cur = pos._node;
//			Node* prev = cur->_prev;
//
//			// prev  newnode  cur
//			prev->_next = newNode;
//			newNode->_prev = prev;
//			newNode->_next = cur;
//			cur->_prev = newNode;
//
//			return iterator(newNode);
//		}
//
//		
//
//	private:
//		Node* _head;
//	};
//}
//
//int main()
//{
//	bit::list<bit::string> lt;
//	bit::string s1("1111");
//	// 这里调用的是拷贝构造
//	lt.push_back(s1);
//
//	// 下面调用都是移动构造
//	lt.push_back("2222");
//	lt.push_back(std::move(s1));
//
//	return 0;
//}

//int main()
//{
//	decltype(1) a = 10;
//	decltype(1.0*a) b = 1.00;
//	return 0;
//}




