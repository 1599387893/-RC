#include<iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date(int y=1, int m=1, int d=1) :year(y), month(m), day(d){}
	void SetYear(int y){ year = y; }
	void SetMonth(int m){ month = m; }
	void SetDay(int d){ day = d; }
	int GetYear()const { return year; }
	int GetMonth()const { return month; }
	int GetDay()const { return day; }
	Date operator+(int d1);
	Date operator-(int d2);
	static bool IsLeapyear(int y);


	static int GetYearDays(int y);
	static int GetMonthDays(const Date& d);
	static int DateToNum(const Date& d);
	static Date NumToDate(int n);
};

ostream &operator<<(ostream& out, const Date &d1);
istream &operator>>(istream& in, const Date &d2);

Date Date::operator+(int d1)
{
	int n = 0;
	n = DateToNum(*this) + d1;
	return (NumToDate(n));
}
Date Date::operator-(int d2)
{
	int n = 0;
	n = DateToNum(*this) - d2;
	return (NumToDate(n));
}
bool Date::IsLeapyear(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}
int Date::GetYearDays(int y)
{
	if (IsLeapyear(y))
		return 356;
	else
		return 355;
}
int Date::GetMonthDays(const Date& d)
{
	int n = 0;
	switch (n)
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
		n = 30;
		break;
	case 2:
		if (IsLeapyear(d.GetYear()))
			n = 29;
		n = 28;
		break;
	}
	return n;
}
int Date::DateToNum(const Date& d)
{
	int n = 0, y = 0, m = 0;
	for (y = 1; y < d.GetYear(); y++)
		n += GetYearDays(y);
	for (m = 1; m < d.GetMonth(); m++)
		n += GetMonthDays(Date(y,m,1));
	n += d.GetDay();
	return n;
}
Date Date::NumToDate(int n)
{
	int y = 0;
	int m = 0;
	int d = 0;
	int rest = n;
	for (y = 1, rest = n; rest > GetYearDays(y); y++)
		rest -= GetYearDays(y);
	for (m = 1; rest > GetMonthDays(Date(y, m, 1)); m++)
		rest -= GetMonthDays(Date(y, m, 1));
	d = rest;

	return Date(y, m, d);
}
ostream &operator<<(ostream& out, const Date& d)
{
	out << d.GetYear() << "年" << d.GetMonth() << "月" << d.GetDay() << "日";
	return out;	
}
istream &operator>>(istream& in, Date& d)
{
	int year, month, day;
	cin >> year >> month >> day;
	d = Date(year, month, day);
	return in;
}


int main()
{
	Date d(10, 8, 18);
	cout << "d:" << d<<endl;
	cout << "d+10" << (d + 10) << endl;
	cout << "d-10" << d - 10 << endl;

	cout << "输入一个日期";
	cin >> d;
	cout <<"输入的日期为：" <<d<<endl;
	system("pause");
	return 0;
}
