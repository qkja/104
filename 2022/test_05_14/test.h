#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class Person
{

	void print();
    void set(const char* name, int age);
	
	int _age;
	char _name[20];
};
