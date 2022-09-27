#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person()" << endl;
	}
	Person operator=(const Person& p)
	{
		cout << "operator=(const Person& p)" << endl;
		return p;
	}
private:
	int _age;
};
class Student
{
public:
	Student(const Person& p = Person())
		:_per()
	{
		//_per = p;
	}
private:
	Person _per;
};

int main()
{
	Student s;
	return 0;
}
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person()" << endl;
//	}
//	Person operator=(const Person& p)
//	{
//		cout << "operator=(const Person& p)" << endl;
//		return p;
//	}
//private:
//	int _age;
//};
//class Student
//{
//public:
//	Student(const Person& p = Person())
//	{
//		_per = p;
//	}
//private:
//	Person _per;
//};
//
//int main()
//{
//	Student s;
//	return 0;
//}

//class Person
//{
//public:
//	/*Person()
//	{
//		_age = 10;
//	}*/
//private:
//	int _age;
//};
//class Student
//{
//public:
//
//private:
//	int a;
//	int* p;
//	/*Person per;
//	Person* pper;*/
//};
//
//int main()
//{
//	Student s;
//	return 0;
//}

//class Student
//{
//public:
//
//private:
//	int _age;
//	Person per;
//	Person* pper;
//	int* _p;
//};