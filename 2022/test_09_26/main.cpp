#define _CRT_SECURE_NO_WARNINGS 1
// 类和对象
// 先来看 构造函数
class Person
{
public:
	Person()
	{
		_age = 10;
	}
private:
	int _age;
};
class Student
{
public:

private:
	//Person per;
	Person* pper;
};

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

int main()
{
	Student s;
	return 0;
}