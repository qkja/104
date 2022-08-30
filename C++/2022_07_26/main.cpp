#include <iostream>
#include <stdio.h>

using namespace std;

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};

class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFPTR) ();
void PrintVTable1(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; i< 3; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

void PrintVTable2(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; i < 2; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int  main()
{
	Derive d;

	PrintVTable1((VFPTR*)(*(long long*)&d));
	PrintVTable2((VFPTR*)(*((long long*)((char*)&d + sizeof(Base1)))));
	return 0;
}





/*

class A
{
public:
	virtual void func1()
	{
	}
	virtual void func2()
	{
	}
};

typedef void (*ViPointer)();

class B : public A
{
	virtual void func1()
	{
		cout << "func1()" << endl;
	}
	virtual void func2()
	{
		cout << "func2()" << endl;
	}
	virtual void func3()
	{
		cout << "func3()" << endl;
	}
};

void printViPointer(ViPointer* f)
{
	int i = 0;
  for(i=0;i<3;i++)
	{
		printf("第%d 的虚函数指针  : %p  ", i, f[i]);
		f[i]();
    cout << endl;
	}
}
int main()
{

  
	B b;
	printViPointer((ViPointer*) (*(long long*)(&b)));
	return 0;
}*/

