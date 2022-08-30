#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void test1()
{
	string s("hello");
	s += " word";
	cout << s << endl;
}

void test2()
{
	string s1("hello");
	string s2("word");
	s1.swap(s2);
	swap(s1, s2);
}

int main()
{
	test1();
	return 0;
}

/*
* 范围for
*/
//int main()
//{
//	string s1("hello word");
//	for (auto ch : s1)
//	{
//		cout << ch;
//	}
//	cout << endl;
//	return 0;
//}

/*
* 使用迭代器
*/
// 什么时迭代器   现在可以理解为指针
// 第一个位置 begin() end() 最后一个位置的下一个位置 左闭右开

//int main()
//{
//	string s1("h");
//	auto it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it;
//		if (*it == '\0')
//		{
//			break;
//		}
//		it++;
//	}
//	if (it == s1.end())
//	{
//		cout << " 和";
//	}
//	//string::iterator beg = s1.begin();
//	cout << endl;
//	return 0;
//}

/*
* 使用下标
*/
//int main()
//{
//	string s1("hello word");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i];
//	}
//	cout << endl;
//	return 0;
//}