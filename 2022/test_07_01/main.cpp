#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//#include <string>
#include "string.h"

using namespace std;
using namespace bit;

void test1()
{
	bit::string str;
	cout << str.string_char() << endl;
}

void test2()
{
	bit::string str1("hello word");
	bit::string str2(str1);
	cout << str1.string_char() << endl;
	cout << str2.string_char() << endl;


	/*cout << str1.string_char() << endl;
	cout << str2.string_char() << endl;*/
}
void test3()
{
	//bit::string str0;
	bit::string str1("hello word");
	bit::string str2 = str1;
	cout << str2.string_char() << endl;
}
int main()
{
	test1();
	//test2();
	//test3();
	return 0;
}