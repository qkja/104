#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <time.h>
#include "RBTree.h"
using namespace std;

//int main()
//{
//	int N = 1024;
//
//	bit::RBTree<int, int> rb;
//	for (int i = 0; i < N; i++)
//	{
//		rb.Insert(make_pair(i, i));
//	}
//	cout << "ÊÇ·ñÆ½ºâ " << rb.IsValidRBTree() << endl;
//	return 0;
//}






//int main()
//{
//	int N = 1024;
//
//	bit::RBTree<int, int> rb;
//	for (int i = 0; i < N; i++)
//	{
//		rb.Insert(make_pair(i, i));
//	}
//	cout << rb.maxHeight() << endl;
//	cout << rb.minHeight() << endl;
//
//	return 0;
//}

//int main()
//{
//	int N = 1024;
//
//	bit::RBTree<int, int> rb;
//	for (int i = 0; i < N; i++)
//	{
//		rb.Insert(make_pair(i, i));
//	}
//	cout << rb.maxHeight() << endl;
//	cout << rb.minHeight() << endl;
//	//rb.inorder();
//	//rb.levelOrder();
//	return 0;
//}

//int main()
//{
//	int N = 10;
//	srand(time(0));
//
//	bit::RBTree<int, int> rb;
//	for (int i = 0; i < N; i++)
//	{
//		int ret = rand();
//		rb.Insert(make_pair(ret, ret));
//	}
//
//	rb.inorder();
//	//rb.levelOrder();
//	return 0;
//}

//int main()
//{
//	bit::RBTree<int, int> rb;
//	for (int i = 0; i < 10; i++)
//	{
//		rb.Insert(make_pair(i, i));
//	}
//
//	rb.inorder();
//	//rb.levelOrder();
//	return 0;
//}