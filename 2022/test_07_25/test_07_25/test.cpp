#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//class Person {
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//		delete[] _name;
//	}
//
//private:
//	char* _name = new char[10]{'j', 'a', 'c', 'k'};
//};
//
//int main()
//{
//
//	Person* ptr = new Person;
//	delete ptr; // ptr->destructor() + operator delete(ptr)
//
//	ptr = new Student;
//	delete ptr;  // ptr->destructor() + operator delete(ptr)
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void func()
//	{
//		cout << "B:: func()" << endl;
//	}
//
//	void func(int i)
//	{
//		cout << "B:: func(int i)" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	A& a = b;
//	a.func();
//	b.func(2);
//	return 0;
//}

//class A
//{
//public:
//	virtual void func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void func()
//	{
//		cout << "B:: func()" << endl;
//	}
//
//	void func(int i)
//	{
//		cout << "B:: func(int i)" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	A& a = b;
//	a.func();
//	b.func(2);
//	return 0;
//}

//class A
//{
//public:
//	virtual void func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void func()
//	{
//		cout << "B:: func()" << endl;
//	}
//};

//int main()
//{
//	B b;
//	A& a = b;
//	A* p = &b;
//	p->func();
//	a.func();
//	return 0;
//}
//class A
//{
//public:
//	virtual void func() final
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void func()
//	{
//		cout << "B:: func()" << endl;
//	}
//};
//int main()
//{
//	B b;
//	A a = b;  // 简单的切片
//	a.func();
//	return 0;
//}

//class A 
//{
//public:
//	void func() 
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void func() override
//	{
//		cout << "B:: func()" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	A a = b;  // 简单的切片
//	a.func();
//	return 0;
//}

//class C
//{
//};
//class D : public C
//{
//};
//
//
//class A
//{
//public:
//    virtual	void func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void func() override
//	{
//		cout << "B:: func()" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	A a = b;  // 简单的切片
//	a.func();
//	return 0;
//}

//class A
//{
//};
//class B : public A
//{
//};
//
//
//class C
//{
//public:
//	virtual	A* func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class D : public C
//{
//public:
//	virtual B* func() 
//	{
//		cout << "B:: func()" << endl;
//	}
//};
//
//int main()
//{
//	return 0;
//}

//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//	void func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	~B()
//	{
//		cout << "~B()" << endl;
//		delete[] arr;
//	}
//	void func()
//	{
//		cout << "B:: func()" << endl;
//	}
//protected:
//	int* arr = new int[10]; // 这里已经说过了
//};
//
//int main()
//{
//	B* b = new B;
//	A* a = b;
//	delete a; //   析构  &  operator delete
//	return 0;
//}

//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	~B()
//	{
//		cout << "~B()" << endl;
//		delete[] arr;
//	}
//protected:
//	int* arr = new int[10]; // 这里已经说过了
//};
//
//int main()
//{
//	A* a = new A;
//	delete a;
//
//	a = new B;
//	delete a; //   析构  &  operator delete
//	return 0;
//}

//class Person {
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//		delete[] _name;
//	}
//
//private:
//	char* _name = new char[10]{'j', 'a', 'c', 'k'};
//};
//
//int main()
//{
//
//	Person* ptr = new Person;
//	delete ptr; // ptr->destructor() + operator delete(ptr)
//
//	ptr = new Student;
//	delete ptr;  // ptr->destructor() + operator delete(ptr)
//
//	return 0;
//}

//class A
//{
//public:
//	void func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//    void func()
//	{
//		cout << "B:: func()" << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	A& a = b;
//	A* p = &b;
//	A aa = b;
//
//	a.func();
//	p->func();
//	aa.func();
//	return 0;
//}
//class Person
//{
//public:
//	virtual	void  func() = 0;
//private:
//
//};
//class Student : public Person
//{
//public:
//	void  func()
//	{
//
//	}
//
//private:
//
//};
//
//int main()
//{
//	Student stu;
//	Person& per = stu; // 允许
//	return 0;
//}

//class A
//{
//public:
//    virtual	void func(int a = 10)
//	{
//		cout << "A:: func()" << endl;
//		cout << "a = " << a << endl;
//	}
//};
//
//class B : public A
//{
//	void func(int a) override
//	{
//		cout << "B:: func()" << endl;
//		cout << "a = " << a << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	A& a = b;
//	a.func();
//	return 0;
//}

class Person
{
public:

	virtual void func()
	{
		cout << "Person:: func" << endl;
	}
private:
	int _a;
};

