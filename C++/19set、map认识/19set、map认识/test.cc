#define _CRT_SECURE_NO_WARNINGS 1
#include <set>
#include <iostream>
using namespace std;

//template < class T,             // set::key_type/value_type
//class Compare = less<T>,        // set::key_compare/value_compare
//class Alloc = allocator<T>      // set::allocator_type
//> class set;
//struct Compare
//{
//	bool operator()(int x, int y)
//	{
//		return x < y;
//	}
//}
//;
//int main()
//{
//	//set<int, Compare> s;
//	set<int, Compare> s;
//
//	s.insert(1);
//	s.insert(12);
//	s.insert(-11);
//	s.insert(10);
//	auto iter = s.begin();
//	while (iter != s.end())
//	{
//		cout << *iter << " ";
//		++iter;
//	}
//	cout << endl;
//
//	return 0;
//}