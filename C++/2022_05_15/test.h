#include <iostream>

using namespace std;
class A
{
 public :
  void Print()
  {
    cout << "Show()"<<endl;
  }
};

class Date
{

public:
  void Print();
  void Init(int year,int month,int day);

private:    
  int _year;
  int _month;
  int _day;
};

class Student
{
 public:
   void Print();
   void Set(char* _name,int _age);
   Student(int a,const char* array = "Qkj");
   Student(int a);

private:
   char _name[20];
   int _age;
};
