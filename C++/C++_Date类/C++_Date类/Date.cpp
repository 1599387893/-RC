#include"Date.h"

//���캯��
Date::Date(int year , int month, int day )
{
	_year = year;
	_month = month;
	_day = day;
}
//�������캯��
Date::Date(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	
}
// �ж����y�Ƿ�Ϊ����
static bool IsLeapyear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	return false;
}
// ���y������
static int GetYearDays(int y)
{
	if (IsLeapyear(y))
		return 366;
	return 365;
}
// ����d��ǰ�·ݵ�����
static int GetMonthDays(const Date &d)
{
	int n;						

	switch (d.GetMonth())
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		n = 31;		
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		n = 31;						
		break;
	case 2:
		if (IsLeapyear(d.GetYear())) n = 29;	
		else n = 28;							
	}

	return n;
}
// ���شӹ�Ԫ1��1��1���������
static int DateToNum(const Date &d)
{
	int y = 0;
	int m = 1;
	int n = 0;

	for (y = 0; y < d.GetYear(); y++)
		n += GetYearDays(y);
	for (m = 1; m < d.GetMonth();m++)
		n += GetMonthDays(Date(y,m,1));
	
	n += d.GetDay();
	return n;
}
// �ɴӹ�Ԫ1��1��1�����������������
static Date NumToDate(int n)
{
	int year = 0; 
	int month = 0;
	int rest = n;

	for (year = 1; rest > GetYearDays(year); year++)
		rest -= GetYearDays(year);

	for (month = 1; rest > GetMonthDays(Date(year, month, 1)); month++)
		rest -= GetMonthDays(Date(year, month, 1));

	 Date d(year, month, rest);
	return d;
}
ostream &operator<<(ostream &out, const Date &d)
{
	out << d.GetYear() << "/" << d.GetMonth() << "/" << d.GetDay();
	return out;
}
istream &operator>>(istream &in, Date &d)
{
	int year;
	int month;
	int day;
	cin >> year >> month >> day;
	d = Date(year, month, day);
	return in; 
}

//���غ���
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}
Date Date::operator+(int days)
{
	int day = DateToNum(*this) + days;
	return NumToDate(day);
}
Date Date::operator-(int days)
{
	int day = DateToNum(*this) - days;
	return NumToDate(day);
}
int Date::operator-(const Date& d)
{
	int day = DateToNum(*this) - DateToNum(d);
	return day;
}
Date& Date::operator++()
{
	int day = DateToNum(*this);
	return NumToDate(++day);
}
Date Date::operator++(int)
{
	Date temp(*this);
	int day = DateToNum(*this);
	*this = NumToDate(++day);
	return temp;
}
Date& Date::operator--()
{
	int day = DateToNum(*this);
	return NumToDate(--day);
}
Date Date::operator--(int)
{
	Date temp(*this);
	int day = DateToNum(*this);
	*this = NumToDate(--day);
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
