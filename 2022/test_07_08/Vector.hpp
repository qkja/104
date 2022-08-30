#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>

//  vector 的底层模板实现   
//  迭代器的失效

namespace bit
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		Vector();
		~Vector();

		// 


	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStoage;
	};

	template<class T>
	Vector<T>::Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStoage(nullptr)
	{

	}

	template<class T>
	Vector<T>::~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = nullptr;
			_finish = nullptr;
			_endOfStoage = nullptr;
		}
	}
}