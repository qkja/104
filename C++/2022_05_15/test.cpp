#include "test.h"



void Date::Init(int year,int month,int day)
{
  this->_year = year;
  _month = month;
  _day = day;
}

void Date:: Print()
{
  cout << "this " << this << endl;
  cout << _year <<" "<< _month <<" " <<_day << endl;
}




void Student::Print()
{
  cout << "Print" << endl;
}


Student:: Student(int a,const char* array)
{
  cout<<"这是一个 半缺省的构造函数" <<endl;
}
Student:: Student(int a)
{
  cout<<"这是一个普通的函数，只有一个参数" <<endl;
}
