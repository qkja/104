//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//// void test_a()
////{
////	int *p = new int[10];
////	test_b();
////	delete[] p;
//// }
//// void test_b()
////{
////	throw "锟届常";
//// }
//// int main()
////{
////	try{
////		test_a();
////	}
////	catch (...)
////	{
////
////	}
////	return 0;
//// }
//// class MyClass
////{
//// private:
////	void fun1();
//// public:
////	void fun2();
//// };
////
//// void MyClass::fun1()
////{
////	cout << "void MyClass::fun1()" << endl;
//// }
//// void MyClass::fun2()
////{
////	cout << "void MyClass::fun1()" << endl;
//// }
//// int main()
////{
////
////	return 0;
//// }
//
//#pragma once
//#include <mutex>
//#include <iostream>
//#include <thread>
//namespace wbx
//{
//	template <class T>
//	struct DFdelete
//	{
//		void operator()(T *ptr)
//		{
//			if (ptr)
//			{
//				delete ptr;
//				ptr = nullptr;
//			}
//		}
//	};
//
//	template <class T>
//	struct DFfree
//	{
//		void operator()(T *ptr)
//		{
//			if (ptr)
//			{
//				free(ptr);
//				ptr = nullptr;
//			}
//		}
//	};
//	struct DFclose
//	{
//		void operator()(FILE *fp)
//		{
//			if (fp)
//			{
//				fclose(fp);
//				fp = nullptr;
//			}
//		}
//	};
//
//	template <class T>
//	struct DFarr
//	{
//		void operator()(T *ptr)
//		{
//			if (ptr)
//			{
//				delete[] ptr;
//				ptr = nullptr;
//			}
//		}
//	};
//	template <class T, class DF = DFdelete<T>>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T *p = nullptr)
//			:ptr(p), pcount(nullptr), pmutex(nullptr)
//		{
//			if (ptr)
//			{
//				pcount = new size_t(0);
//				pmutex = new std::mutex;
//				add_mutex();
//			}
//		}
//		T &operator*() { return *ptr; }
//		T *operator->() { return ptr; }
//		~shared_ptr()
//		{
//			if (ptr)
//			{
//				relese();
//			}
//		}
//		shared_ptr(const shared_ptr<T, DF> &sp) : ptr(sp.ptr), pcount(sp.pcount), pmutex(sp.pmutex) { add_mutex(); }
//		shared_ptr<T, DF> &operator=(const shared_ptr<T, DF> &sp)
//		{
//			if (ptr != sp.ptr)
//			{
//				if (ptr)
//				{
//					relese();
//				}
//				ptr = sp.ptr;
//				pcount = sp.pcount;
//				pmutex = sp.pmutex;
//				add_mutex();
//			}
//			return *this;
//		}
//
//	private:
//		void relese()
//		{
//			pmutex->lock();
//			if (pcount)
//			{
//				--(*pcount);
//			}
//			pmutex->unlock();
//			if (ptr && (*pcount) == 0)
//			{
//				DF()
//				(ptr);
//				ptr = nullptr;
//				delete pcount;
//				delete pmutex;
//				pcount = nullptr;
//				pmutex = nullptr;
//			}
//		}
//		void add_mutex()
//		{
//			if (ptr && pcount)
//			{
//				pmutex->lock();
//				++(*pcount);
//				pmutex->unlock();
//			}
//		}
//		size_t *pcount;
//		T *ptr;
//		std::mutex *pmutex;
//	};
//};


//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//namespace bit
//{
//	template<class T>
//	class SmartPtr
//	{
//	public:
//		SmartPtr(T* ptr)
//			:_ptr(ptr)
//		{
//			// 这里我们给一个 打印函数
//			//std::cout << "SmartPtr()" << std::endl;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		// 有些指针还会重载 []  这里等会再说
//		~SmartPtr()
//		{
//			//std::cout << "~SmartPtr()" << std::endl;
//			//if(_ptr)
//			delete _ptr; // 对于 多个自定义对象   等会在谈
//			//_ptr = nullptr;
//		}
//
//	private:
//		T* _ptr;
//	};
//
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//
//		// 拷贝构造 悬空
//		auto_ptr(auto_ptr<T>& a)
//		{
//			_ptr = a._ptr;
//			// 他给我悬空了
//			a._ptr = nullptr;
//		}
//
//		// 赋值重载
//		// 这里也有问题
//		// 这里就不仔细谈
//		auto_ptr<T>& operator=(auto_ptr<T>& a)
//		{
//			if (&a == this)
//				return *this;
//			free(_ptr);
//
//			_ptr = a._ptr;
//			// 他给我悬空了
//			a._ptr = nullptr;
//
//			// 注意放回置
//			return *this;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		~auto_ptr()
//		{
//			delete _ptr; // 对于 多个自定义对象   等会在谈
//		}
//
//	private:
//		T* _ptr;
//	};
//
//
//	// 下面是 C++ 11 更新出来的
//	// 我们重点看三个
//
//	// 我们谈一下  boost
//	// 这是一个 准标准库   里面可以看作一个使用
//	// 现在不太谈了
//
//	// boost scoped_ptr shared_ptr weak_ptr
//	// c++11 unique_ptr shared_ptr weak_ptr
//
//
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//		{}
//
//		// 1 只声明 不实现  有老刘自己实现  这里 声明成 私有
//
//		// 2 c++11 可以 使用 delete 
//		unique_ptr(const unique_ptr<T>& u) = delete;
//		unique_ptr operator=(const unique_ptr<T>& u) = delete;
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		~unique_ptr()
//		{
//			delete _ptr; // 对于 多个自定义对象   等会在谈
//		}
//	private:
//		T* _ptr;
//	};
//
//
//	// shared_ptr 
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			, _pCount(new int)
//		{
//			std::cout << "构造" << std::endl;
//
//			//std::cout << "11111111111" << std::endl;
//			*_pCount = 1;
//		}
//
//		shared_ptr(shared_ptr<T>& s)
//		{
//			_ptr = s._ptr;
//			_pCount = s._pCount;
//			(*_pCount)++;
//		}
//
//		shared_ptr<T>& operator=(shared_ptr<T>& s)
//		{
//			std::cout << "operator=" << s._ptr << std::endl;
//
//			if (this == &s)
//				return *this;
//			if (_ptr == s._ptr)
//				return *this;
//			// 这个很 麻烦
//			//我们要考虑情况
//
//			if (*_pCount == 1)
//			{
//				delete _ptr;
//				delete _pCount;
//			}
//			else
//			{
//				(*_pCount)--;
//			}
//
//			_ptr = s._ptr;
//			_pCount = s._pCount;
//			(*_pCount)++;
//
//			return *this;
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//		void Release()
//		{
//			//if (--(*_pCount) == 0)
//			if (--(*_pCount) == 0 && _ptr)
//			{
//				std::cout << "析构" << this->_ptr << std::endl;
//
//				//std::cout << "delete" << _ptr << std::endl;
//				delete _ptr;
//				_ptr = nullptr;
//
//				delete _pCount;
//				_pCount = nullptr;
//			}
//		}
//		~shared_ptr()
//		{
//			Release();
//		}
//
//		/*~shared_ptr()
//		{
//		// 等到 剩下一个
//		if(--(*_pCount) == 0 && _ptr)
//		{
//		delete _ptr; // 对于 多个自定义对象   等会在谈
//		delete _pCount;
//		}
//		}*/
//
//	private:
//		T* _ptr;
//		int* _pCount;
//	};
//
//}
//namespace bit
//{
//    template<class T>
//    class SmartPtr
//    {
//    public:
//        SmartPtr(T* ptr)
//            :_ptr(ptr)
//        {
//            // 这里我们给一个 打印函数
//            //std::cout << "SmartPtr()" << std::endl;
//        }
//
//        T& operator*()
//        {
//            return *_ptr;
//        }
//
//        T* operator->()
//        {
//            return _ptr;
//        }
//
//        ~SmartPtr()
//        {
//            //std::cout << "~SmartPtr()" << std::endl;
//            if (_ptr)
//                delete _ptr; // 这里存在点问题 
//            //delete[] _ptr;
//            _ptr = nullptr;
//        }
//    private:
//        T* _ptr;
//    };
//}