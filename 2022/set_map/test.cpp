#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include "Set.h"
#include "Map.h"




int main()
{
	bit::test_set2();
	//bit::test_map2();
	return 0;
}




//template<class A>
//class B
//{
//public:
//	B& operator=(const B& b)
//	{
//		a = b.a;
//		return *this;
//	}
//	int a;
//};
//int main()
//{
//	B<const int> b1;
//	B<int> b2;
//	B<int> b3;
//	b2 = b3;
//	return 0;
//}
//int main()
//{
//	int a = 1;
//	const int B = a;
//	return 0;
//}

//int main()
//{
//	//bit::test_set1();
//	//bit::test_map1();
//	return 0;
//}


//const int& func(int a)
//{
//	return a;
//}
//int main()
//{
//	/*int ret1 = func(1);
//	int ret2 = func(2);*/
//	if (func(2) > func(1))
//	{
//		cout << "aaaa" << endl;
//	}
//	return 0;
//}

//int main()
//{
//	//bit::test_set1();
//	bit::test_map1();
//	return 0;
//}

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	sort(v.begin(), v.end());
//	return 0;
//}