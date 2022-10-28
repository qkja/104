#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>                                                                                                                                                                
#include <string>            
#include<memory>             

#include "SmartPtr.h"  
using namespace std;
struct Node
{
	bit::shared_ptr<Node> _prev;
	bit::shared_ptr<Node> _next;
	int _data = 0;
	~Node()
	{
		cout << "~Node" << endl;
	}
};

//class A
//{
//public:
//	~A()
//	{
//		cout << "A" << endl;
//	}
//};
//
//class B
//{
//public:
//
//	~B()
//	{
//		cout << "B" << endl;
//	}
//	A _b;
//};
//
//int main()
//{
//	B b1;
//	B b2;
//	return 0;
//}

int main()
{
	bit::shared_ptr<Node> sp1(new Node);
	bit::shared_ptr<Node> sp2(new Node);

	sp1->_next = sp2;
	sp2->_prev = sp1;
	return 0;
}



//void func1()
//{
//    bit::SmartPtr<int> sp1(new int);
//    bit::SmartPtr<int> sp2(new int[3]);
//    bit::SmartPtr<int> sp4(sp1);
//
//    bit::SmartPtr<pair<string, int>> sp3(new pair<string, int>("sort", 1));
//
//    *sp1 = 1;
//    cout << *sp1 << endl;
//
//    sp3->second++;  // 注意 这里应该是省略的一个 ->
//    cout << (*sp3).first << "  " << (*sp3).second << endl;
//
//    cout << "===================" << endl;
//}
//
//int main()
//{
//    func1();
//}