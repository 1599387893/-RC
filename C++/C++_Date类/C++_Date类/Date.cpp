#include"Date.h"

//构造函数
Date::Date(int year , int month, int day )
{
	_year = year;
	_month = month;
	_day = day;
}
//拷贝构造函数
Date::Date(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	
}


//重载函数
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
Date Date::operator+(int days)
{
	_day += days;
	return *this;
}
Date Date::operator-(int days)
{
	_day -= days;
	return *this;
}
int Date::operator-(const Date& d)
{

}
Date& Date::operator++()
{
	_day++;
	return *this;
}
Date Date::operator++(int)
{
	Date temp(*this);
	_day++;
	return temp;
}
Date& Date::operator--()
{
	_day--;
	return *this;
}
Date Date::operator--(int)
{
	Date temp(*this);
	_day--;
	return temp;

}
bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
		return true;
	if (_month > d._month)
		return true;
	if (_day > d._day)
		return true;
	return false;
}
bool Date::operator>=(const Date& d)const
{
	if (_year >= d._year)
		return true;
	if (_month >= d._month)
		return true;
	if (_day >= d._day)
		return true;
	return false;
}
bool Date::operator<(const Date& d)const
{
	if (_year < d._year)
		return true;
	if (_month < d._month)
		return true;
	if (_day < d._day)
		return true;
	return false;
}
bool Date::operator<=(const Date& d)const
{
	if (_year <= d._year)
		return true;
	if (_month <= d._month)
		return true;
	if (_day <= d._day)
		return true;
	return false;
}
bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}
bool Date::operator!=(const Date& d)const
{
	return _year != d._year || _month != d._month || _day != d._day;
}