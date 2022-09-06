#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Student
{
public:
	void print()
	{
		cout << "我叫" << _name << ",今年" << _age << "岁了";
		cout << endl;
	}

	void set(const char* name, int age)
	{
		_age = age;
		strcpy(_name, name);
	}
private:
	int _age;
	char _name[20];
};

//int main()
//{
//	Student stu1;
//	stu1.set("qkj", 18);
//
//	Student stu2;
//	stu2.set("qkj", 18);
//	return 0;
//}

int main()
{
	Student stu1;
	stu1.set("qkj", 18);
	return 0;
}