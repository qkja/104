/**
* User: Qkj
* Description: 继承
* Date: 2023-06-27
* Time: 21:12
*/
#include <iostream>
using namespace std;
#include <iostream>
#include <string>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public:
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
//int main()
//{
//	Student stu;
//	stu._name = "����";
//	stu._age = 20;
//	stu.Print();
//	return 0;
//}

//class Person
//{
//public:
//	void func()
//	{
//		cout << _name <<" "<< _sex <<" "<< _age << endl;
//	}
//protected:
//	string _name; // ����
//	string _sex;  // �Ա�
//	int _age;     // ����
//};
//class Student : public Person
//{
//public:
//	Student()
//	{
//		_name = "����";
//		_sex = "��";
//		_age = 18;
//	}
//};

//int main()
//{
//	Person per;
//	Student stu;
//	per = stu;
//	per.func();
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
//	// ��������
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:_num(num)
//		, Person(name)  //  �� ����  ����ȷ  �Ķ���
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		: _num(s._num)
//		//, Person(s) //  �Լ��� ���� ��Ƭ
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//protected:
//	int _num; //ѧ��
//};
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // ����
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:_num(num)
//		, Person(name)  //  �� ����  ����ȷ  �Ķ���
//	{
//		cout << "Student()" << endl;
//	}
//
//	~Student()
//	{
//		~Person();
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num; //ѧ��
//};
//
//int main()
//{
//	Student stu("jack", 18);
//
//	return 0;
//}
//int main()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//int main()
//{
//	Student s;
//	Teacher t;
//	s.Print();
//	t.Print();
//	return 0;
//}

//class Person
//{
//protected:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void Test()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	//2.��������ܸ�ֵ�����������
//	/*sobj = pobj;*/
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	//pp = &sobj;
//	//Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	//ps1->_No = 10;
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//}
//
// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ����֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ����֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//}

// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//void Test()
//{
//	B b;
//	b.fun(10);
//}
//int main()
//{
//	Test();
//	//cout << "--" << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	return 0;
//}

//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	int _b;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D
//{
//public:
//	int _d;
//};
//class D : public B, public C
//{
//public:
//	int _d;
//};

//int main()
//{
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;
//	cout << sizeof(int*) << endl;
//	/*D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//
//	d._b = 3;
//	d._c = 4;
//
//	d._d = 5;*/
//	return 0;
//}

// �������   ��̳еĻ�   ��ʱ  ���ǵ� �ռ���μ���,��Ҫ��    ����������ָ�� ������
//class A
//{
//public:
//	void func()
//	{}
//public:
//	long long _p;
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	cout << sizeof(B) << endl;
//	return 0;
//}

//class A
//{
//public:
//	int _a = 0x1122;
//};
//class B : virtual public A
//{
//public:
//	int _b = 0x3344;;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D
//{
//public:
//	int _d;
//};
//
//
//int main()
//{
//	cout << sizeof(B) << endl;
//	B b;
//	/*cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;*/
//	cout << sizeof(int*) << endl;
//
//	return 0;
//}
//class A
//{
//public:
//	int _a;
//};
//class B : virtual public A
//{
//public:
//	int _b;
//};
//class C : public A
//{
//public:
//	int _c;
//};
//
//class D
//{
//public:
//	int _d;
//};
//
//
//int main()
//{
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	cout << sizeof(D) << endl;
//	cout << sizeof(int*) << endl;
//
//	return 0;
//}
class A
{
  public:

  int f()
  {
    return a;
  }
  virtual void func()
  {
    cout << "A" << endl;
  }
  int a = 0;
};
class B: public A
{
  public:
    void func() override{
      cout << "B" << endl;
    }
  int a = 1;
};
int main()
{
  B b;
  cout << b.f() << endl;
  b.func();
  b.A::func();
  //B::A::func();
  return 0;
}
