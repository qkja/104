#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

Date::Date(int year , int month, int day)
{
	assert(year > 0);
	assert(month > 0 && month < 13);
	if (day > 0 && day <= MonthDays(year,month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "数据不合法" << endl;
	}
	
}

Date Date::operator+(const int day)
{
	if (day < 0)
	{
		return *this - (-day);
	}

	Date d(*this);
	d += day;
	return d;
}

Date& Date::operator+=(const int day)
{
	//现在开始了
	if (day < 0)
	{
		return *this -= (-day);
	}

	_day += day;

	while (_day > MonthDays(_year, _month))
	{
		_day -= MonthDays(_year, _month);
		_month += 1;
		if (_month == 13)
		{
			_year += 1;
			_month = 1;
		}
	}

	return *this;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator>(const Date& d)
{
	return (_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day);
	return false;
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date& Date::operator-=(const int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}

	_day -= day;
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_year -= 1;
			_month = 12;
			_day += MonthDays(_year, _month);
		}
		else
		{
			_month -= 1;
			_day += MonthDays(_year, _month);
		}
	}

	return* this;
}

Date Date::operator-(const int day)
{
	if (day < 0)
	{
		return *this + (-day);
	}

	Date d(*this);
	d -= day;
	return d;
}
//前置 ++
Date& Date::operator++()
{
    *this += 1;
	return *this;
}

Date Date::operator++(int day)
{
	Date d(*this);
    *this += 1;
	return d;
}

//前置 --

Date& Date::operator--()
{
	
	return *this-=1;
}

Date Date::operator--(int day)
{
	Date d(*this);
	*this -= 1;
	return d;
}

int Date::operator-(const Date d)
{
	if (&d == this)
	{
		return 0;
	}
	//假设   max 是 *this 
	Date max = *this;
	Date min = d;
	int flg = 1;
	if (max < min)
	{
		Date ret = max;
		max = min;
		min = ret;
		flg = -1;
	}
	// 小追大
	int n = 0;
	while (max != min)
	{
		min++;
		n++;
	}
	return n*flg;
}

//Date* Date::operator&()
//{
//	return this;
//}

const Date* Date::operator&() const 
{
	return this;
}