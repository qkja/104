#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Derive d;
//
//	PrintVTable((VFPTR*)(*(int*)&d));
//	PrintVTable((VFPTR*)(*((int*)((char*)&d + sizeof(Base1)))));
//	return 0;
//}
//class A
//{
//public:
//	virtual void func()
//	{}
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	virtual void func()
//	{}
//
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void func()
//	{}
//public:
//	int _d;
//};
//int main()
//{
//	D d;
//	return 0;
//}
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Derive d;
//
//	PrintVTable((VFPTR*)(*(int*)&d));
//	PrintVTable((VFPTR*)(*((int*)((char*)&d + sizeof(Base1)))));
//	return 0;
//}


//class A
//{
//public:
//	virtual void func1()
//	{
//
//	}
//	virtual void func2()
//	{
//
//	}
//
//private:
//	int _a;
//
//};
//
//// 一个 函数指针
//typedef void (*ViPointer)();
//
//class B : public A
//{
//	virtual void func1()
//	{
//		cout << "func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "func2()" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "func3()" << endl;
//	}
//};
//
//
//void print(ViPointer* pf)
//{
//	int i = 0;
//	while (*(pf + i) != nullptr)
//	{
//		printf("%p\n", *(pf + i));
//		(*(pf + i))();
//		++i;
//	}
//}
//
//int main()
//{
//	B b;
//	print((ViPointer*)(*(int*)(&b)));
//	return 0;
//}


/*class A
{
public:
	virtual void func1()
	{

	}
	virtual void func2()
	{

	}
private:
	int _a;

};
class B : public A
{
	virtual void func1()
	{

	}
	virtual void func2()
	{

	}
	virtual void func3()
	{

	}
};

int main()
{

	B b;
	return 0;
}*/

//class A
//{
//public:
//	virtual void func1()
//	{
//
//	}
//	virtual void func2()
//	{
//
//	}
//private:
//	int _a;
//
//};
//class B : public A
//{
//	void func1()
//	{
//
//	}
//};
//
//int main()
//{
//
//	B b;
//	return 0;
//}
//

//class A
//{
//public:
//	virtual void func1()
//	{
//
//	}
//	virtual void func2()
//	{
//
//	}
//private:
//	int _a;
//
//};
//class B : public A
//{
//
//};
//int main()
//{
//	B b;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func()
//	{
//
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A a;
//	return 0;
//}
//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//
//	d._b = 3;
//	d._c = 4;
//
//	d._d = 5;
//	return 0;
//}



//int main()
//{
//	cout << sizeof(D) << endl;
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:_num(num)
//		, Person(name)  //  这 才是  最正确  的动作
//	{
//		cout << "Student()" << endl;
//	}
//
//	//Student& operator=(const Student& s)
//	//{
//	//	cout << "Student& operator= (const Student& s)" << endl;
//	//	if (this != &s)
//	//	{
//	//		Person::operator=(s);  // 会 发生 隐藏  这里突破类域
//	//		_num = s._num;
//	//	}
//	//	return *this;
//	//}
//
//protected:
//	int _num; //学号
//};
//
//int main()
//{
//	Student s1("jack", 18);
//	Student s2("joker", 18);
//
//	s2 = s1;
//
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//class B : public A
//{
//public:
//	int _b;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//
//	d._b = 3;
//	d._c = 4;
//
//	d._d = 5;
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main() 
//{ 
//	Assistant a;    
//	return 0; 
//}



//class A
//{
//public:
//	A()
//		//:p(new int)
//	{}
//	/*~A()
//	{
//		if (p)
//		{
//			delete p;
//			p = nullptr;
//		}
//	}*/
//private:
//	int* p;
//};


//int main()
//{
//	A* a = new A;
//	delete a;
//	delete a;
//	return 0;
//}
//class A
//{
//private:
//	static int a;
//};
//
//int A::a = 10;
//int main()
//{
//	cout << A::a << endl;
//	return 0;
//}
//int main()
//{
//	A a;
//	//a.Print();
//	return 0;
//}

//int main()
//{
//	int* p = new int[10];
//	delete[] p;
//	delete[] p;
//	return 0;
//}


//using namespace std;
//class A
//{
//public:
//	A()
//		:_p(new int)
//	{
//		cout << "A()" << endl;
//		*_p = 1;
//	}
//	A(const A& a)
//		:_p(new int)
//	{
//		*_p = *a._p;
//	}
//	A& operator=(const A& a)
//	{
//		*_p = *a._p;
//		cout << "A& operator=(const A& a)" << endl;
//
//		return *this;
//	}
//	~A()
//	{
//		if (_p)
//		{
//			delete _p;
//			_p = nullptr;
//		}
//		cout << "析构函数" << endl;
//	}
//private:
//	int* _p;
//};
//
//int main()
//{
//	vector<A> v;
//	A a1;
//	A a2;
//	A a3;
//	A a4;
//	v.push_back(a1);
//	cout << "===============" << endl;
//
//	v.push_back(a2);
//	cout << "===============" << endl;
//
//	v.push_back(a3);
//	cout << "===============" << endl;
//
//	v.push_back(a4);
//
//	cout << "===============" << endl;
//	return 0;
//}



//class A
//{
//public:
//	A(int a = 0, int b = 0)
//		:_a(a)
//		, _b(b)
//	{
//		cout << "构造函数" << endl;
//	}
//	~A()
//	{
//		cout << "析构函数" << endl;
//	}
//private:
//	int _a;
//	int _b;
//};



//
//int main()
//{
//	A* pa1 = new A;
//	cout << "============" << endl;
//	A* pa2 = new A[4];
//
//	delete pa1;
//	delete[] pa2;
//	return 0;
//}


//class B
//{
//public:
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//class A
//{
//public:
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	B _b;
//};
//int main()
//{
//	A a;
//	return 0;
//}


//class B
//{
//public:
//	B(int a = 0)
//	{
//		cout << "B(int a = 0)  " << a << endl;
//	}
//};
//class A
//{
//public:
//	A()
//		:_v(4)
//		,_b()
//	{
//
//	}
//
//private:
//	vector<int> _v;
//	B _b;
//};
//class A
//{
//public:
//	A()
//		:_v(4)
//	{
//
//	}
//
//private:
//	vector<int> _v;
//};
//int main()
//{
//	A a;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	A(const A& a)
//		:_a(a._a)
//		//,_v(a._v)
//	{
//		// 这里 完成深拷贝
//	}
//	int _a;
//	int* _parr; // 这里假设 需要深拷贝
//	vector<int> _v;
//};
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	/*A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//	}*/
//	int _a;
//	vector<int> _v;
//};

//int main()
//{
//	A a1;
//	a1._v.push_back(1);
//	a1._v.push_back(1);
//	a1._v.push_back(1);
//	a1._v.push_back(1);
//	A a2(a1);
//	a2._v.push_back(2);
//
//	return 0;
//}
//class B
//{
//public:
//	B()
//	{
//	}
//	//B(const B& b)
//	//{
//	//	cout << "B(const B& b)" << endl;
//	//}
//	A _aa;
//};
//int main()
//{
//	B b1;
//	b1._aa._v.push_back(1);
//	b1._aa._v.push_back(1);
//	B b2(b1);
//	b2._aa._v.push_back(1);
//
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//	}
//	int _a;
//	vector<int> _v;
//};
//class B
//{
//public:
//	B()
//	{
//	}
//	//B(const B& b)
//	//{
//	//	cout << "B(const B& b)" << endl;
//	//}
//	A _aa;
//};
//int main()
//{
//	B b1;
//	b1._aa._v.push_back(1);
//	b1._aa._v.push_back(1);
//	B b2(b1);
//	b2._aa._v.push_back(1);
//
//	return 0;
//}



//class P {
//public:
//    int id;
//    string name;
//
//public:
//    P() { cout << "wu can p gou zao " << endl; }
//
//    P(int id, string name) { cout << "you can p gou zao" << endl; }
//    P(const P& p) { cout << "p de 拷贝构造函数" << endl; }
//};
//
//class Person {
//public:
//    int id2 = 202;
//    int id1 = 201;
//    P p;
//
//public:
//    Person() { cout << "person gou zao " << endl; }
//};
//
//int main(int argc, char const* argv[]) {
//    Person p1;
//    // 默认情况下，会调用自定义类型属性的拷贝构造函数
//    Person p2 = p1;
//    return 0;
//}
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 10;
//	}
//	int _a;
//	vector<int> _v;
//};
//class B
//{
//public:
//	B()
//	{
//		_b = 10;
//	}
//	int _b;
//	A _aa;
//};
//
//int main()
//{
//	B b1;
//	b1._aa._v.push_back(1);
//	b1._aa._v.push_back(2);
//	b1._aa._v.push_back(3);
//	b1._aa._v.push_back(4);
//	B b2(b1);
//	b2._aa._v.push_back(5);
//	return 0;
//}
//class A
//{
//public:
//	A()
//	{
//		_a = 0;
//	}
//	A(const A& a)
//	{
//		_a = a._a;
//	}
//	int _a;
//};
//class B
//{
//public:
//	B()
//	{
//		_b = 10;
//	}
//
//private:
//	int _b;
//	A _aa;
//};
//
//int main()
//{
//	B b1;
//	B b2(b1);
//	return 0;
//}
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:_num(num)
//		, Person(name)  //  这 才是  最正确  的动作
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		: _num(s._num)
//		//, Person(s) //  自己会 发生 切片
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//protected:
//	int _num; //学号
//};
//
//int main()
//{
//	Student s1("jack", 18);
//	cout << "==========" << endl;
//	Student s2(s1);
//
//	return 0;
//}


//class A
//{
//public:
//	virtual	void func(int a = 10)
//	{
//		cout << "A:: func()" << endl;
//		cout << "a = " << a << endl;
//	}
//};
//
//class B : public A
//{
//	void func(int a = 20)
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

//class A
//{
//};
//class B : public A
//{
//};
//
//class C
//{
//public:
//	virtual	A func()
//	{
//		cout << "A:: func()" << endl;
//	}
//};
//
//class D : public C
//{
//public:
//	B func()
//	{
//		cout << "B:: func()" << endl;
//	}
//};

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
//class Person
//{
//public:
//	Person(string& name)
//		:_name(name)
//	{
//
//	}
//	void buyTicket()
//	{
//		cout << _name << " 普通人 票价 100 ￥" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Soldier : public Person
//{
//public:
//	Soldier(string& name)
//		:Person(name)
//	{
//
//	}
//	void buyTicket()
//	{
//		cout << _name << " 军人 优先购买 票价 100 ￥" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	Student(string& name)
//		:Person(name)
//	{
//
//	}
//	void buyTicket()
//	{
//		cout << _name << " 学生 半价 50 ￥" << endl;
//	}
//};
//
//int main()
//{
//	string str = "qkj";
//	Student s(str);
//	s.buyTicket();
//	Person& p = s;
//	p.buyTicket();
//
//	/*s.buyTicket();
//	s.buyTicket();*/
//	return 0;
//}