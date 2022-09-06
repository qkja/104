#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"
void Person::print()
{
	cout << "我叫" << _name << ",今年" << _age << "岁了";
	cout << endl;
}

void Person::set(const char* name, int age)
{
	_age = age;
	strcpy(_name, name);
}


//struct Person
//{
//	void print()
//	{
//		cout << "我叫" << _name << ",今年" << _age << "岁了";
//		cout << endl;
//	}
//
//	void set(const char* name, int age)
//	{
//		_age = age;
//		strcpy(_name, name);
//	}
//
//	int _age;
//	char _name[20];
//};

//class Person
//{
//
//};

//int main()
//{
//	struct Person person1;
//	Person person2;       // 可以把  struct 去掉
//	
//	return 0;
//}
//class Person
//{
//	void print()
//	{
//		cout << "我叫" << _name << ",今年" << _age << "岁了";
//		cout << endl;
//	}
//
//	void set(const char* name, int age)
//	{
//		_age = age;
//		strcpy(_name, name);
//	}
//private:
//	int _age;
//	char _name[20];
//};
//
//struct Student
//{
//	void print()
//	{
//		cout << "我叫" << _name << ",今年" << _age << "岁了";
//		cout << endl;
//	}
//
//	void set(const char* name, int age)
//	{
//		_age = age;
//		strcpy(_name, name);
//	}
//private:
//	int _age;
//	char _name[20];
//};

//int main()
//{
//	//  class  创建
//	Person person;
//	person.set("qkj", 18);
//	person.print();
//
//	//  struct  创建
//	Student student;
//	student.set("zhansan", 19);
//	student.print();
//	return 0;
//}

//int main()
//{
//	return 0;
//}

//int main()
//{
//	struct Person person1;
//	//Person person2;       // 可以把  struct 去掉
//	person1.set("qkj", 18);
//	person1.print();
//	return 0;
//}























//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//	
//	//typeid 可以测试 变量的类型
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto x = 1;
//	auto ch = 'c';
//	return 0;
//}


//int main()
//{
//	std::map<std::string, std::string> dict;
//	dict["sort"] = "排序";
//	dict["string"] = "字符串";
//
//	//std::map<std::string, std::string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	return 0;
//}

//int main()
//{
//	auto a = 1,b = 2;
//	auto c = 1.0,b = 'c';  // 报错
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	auto pa = &a;
//	cout << typeid(pa).name() << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	auto* pa = &a;    //加了一个  *
//	cout << typeid(pa).name() << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	auto& pa = a;    
//
//	cout << "&a:  " << &a << endl;
//	cout << "&pa: " << &pa << endl;
//	return 0;
//}

//int main()
//{
//	//cout << sizeof(auto x) << endl;
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}
//void func(int* arr)
//{
//	for (int* val : arr)
//	{
//		cout << *val << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	func();
//	return 0;
//}

//void func(int* p)
//{
//	cout << "p是指针" << endl;
//}
//
//void func(int p)
//{
//	cout << "p是整型" << endl;
//}
//
//int main()
//{
//	func(nullptr);
//	return 0;
//}

//#ifndef NULL
//	#ifdef __cplusplus
//		#define NULL 0
//	#else
//		#define NULL ((void *)0)
//	#endif
//#endif