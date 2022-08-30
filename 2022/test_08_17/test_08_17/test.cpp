#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <list>
#include <time.h>

#include <algorithm>
#include <vector>

using namespace std;

//int main()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	l.push_back(7);
//	l.push_front(10);
//
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		list<int>::iterator prev = it;
//		it = l.erase(it);
//	}
//
//
//	cout << l.size() << endl;
//	return 0;
//
//}

//int main()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//	l.push_back(5);
//	l.push_back(6);
//	l.push_back(7);
//	l.push_front(10);
//	l.pop_front();
//
//	//list<int>::iterator it = l.begin();
//	//while (it != l.end())
//	//{
//	//	//it = l.erase(it);
//	//	l.pop_front();
//	//}
//	return 0;
//}
//#include <iostream>
//#include <list>
//
//using namespace std;

//int main()
//{
//	list<int> l;
//	for (int i = 0; i < 10; i++)
//	{
//		l.push_back(i);
//	}
//	l.reverse();
//	for (int& val : l)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	return 0;

//int main()
//{
//	srand((unsigned int)time(NULL));
//
//	list<int> l;
//	for (int i = 0; i < 20; i++)
//	{
//		int ret = rand() % 100;
//		l.push_back(ret);
//	}
//	for (int& val : l)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	l.sort();
//	for (int& val : l)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	srand((unsigned int)time(NULL));
//
//	list<int> l1;
//	list<int> l2;
//	for (int i = 0; i < 20; i++)
//	{
//		int ret = rand() % 100;
//		l1.push_back(ret);
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		int ret = rand() % 100;
//		l2.push_back(ret);
//	}
//	
//	l1.sort();
//	l2.sort();
//	l1.merge(l2);
//	for (int& val : l1)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	return 0;
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//
//	list<int> l1;
//	list<int> l2;
//	for (int i = 0; i < 20; i++)
//	{
//		int ret = rand() % 100;
//		l1.push_back(ret);
//	}
//	for (int i = 0; i < 20; i++)
//	{
//		int ret = rand() % 100;
//		l2.push_back(ret);
//	}
//
//	l1.sort();
//	l2.sort();
//	l1.merge(l2);
//	cout << l2.size() << endl;
//	return 0;
//}
//int main()
//{
//	
//	list<int> l;
//	l.push_back(1);
//	l.push_back(1);
//	l.push_back(2);
//
//	l.push_back(1);
//	l.push_back(3);
//    for (int& val : l)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	l.unique();
//	for (int& val : l)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <algorithm>
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//
//	list<int> l;
//	for (int i = 0; i < 20; i++)
//	{
//		int ret = rand() % 100;
//		l.push_back(ret);
//	}
//	for (int& val : l)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	std::sort(l.begin(),l.end());
//	for (int& val : l)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	srand((unsigned int)time(NULL));
//	const int N = 1024*1024;
//	list<int> l;
//	vector<int> v;
//	for (int i = 0; i < N; i++)
//	{
//		int val = rand();
//		l.push_back(val);
//		v.push_back(val);
//	}
//
//	int begin1 = clock();
//	l.sort();
//	int end1 = clock();
//
//	int begin2 = clock();
//	std::sort(v.begin(), v.end());
//	int end2 = clock();
//	cout << "list : " << (end1 - begin1) << endl;
//	cout << "sort: " << (end2 - begin2) << endl;
//	return 0;
//}

//int main()
//{
//	srand((unsigned int)time(NULL));
//	const int N = 1024 * 1024;
//	list<int> l1;
//	list<int> l2;
//	vector<int> v;
//	for (int i = 0; i < N; i++)
//	{
//		int val = rand();
//		l1.push_back(val);
//		l2.push_back(val);
//	}
//	// 排序 l1
//	int begin1 = clock();
//	l1.sort();
//	int end1 = clock();
//
//	// 先排序 再移动
//	int begin2 = clock();
//	v.reserve(N);
//	for (int& val : l2)
//	{
//		v.push_back(val);
//	}
//
//	std::sort(v.begin(), v.end());
//	// 重新填回去
//	l2.clear();
//	for (int& val : v)
//	{
//		l2.push_back(val);
//	}
//	int end2 = clock();
//	cout << "list   : " << (end1 - begin1) << endl;
//	cout << "vector : " << (end2 - begin2) << endl;
//	return 0;
//}


int main()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(10);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << &it << endl;
		it++;
	}
	cout << l.size() << endl;
	return 0;

}