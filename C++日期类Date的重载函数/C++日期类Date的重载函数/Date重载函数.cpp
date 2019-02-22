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
	static int GetMonthDays(const Date &d);
	static int DateToNum(const Date &d);
	static Date NumToDate(int n);
};

ostream &operator<<(ostream& out, const Date &d1);
istream &operator>>(istream& in, const Date &d2);

Date Date::operator+(int d1)
{
	int n = DateToNum(*this) + d1;
	return NumToDate(n);
}
Date Date::operator-(int d2)
{
	int n = DateToNum(*this) - d2;
	return NumToDate(n);
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
		return 366;
	else
		return 365;
}
int Date::GetMonthDays(const Date& d)
{
	int n = 0;
	switch ( d.GetMonth())
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
ostream &operator<<(ostream &out, const Date &d)
{
	out << d.GetYear() << "年" << d.GetMonth() << "月" << d.GetDay() << "日";
	return out;	
}
istream &operator>>(istream &in, Date &d)
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


#include<iostream>
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h = 1, int m = 1, int s = 1) :hour(h), minute(m), second(s){}
	void SetHour(int h){ hour = h; }
	void SetMintue(int m){ minute = m; }
	void SetSecond(int s){ second = s; }
	int GetHour()const{ return hour; }
	int GetMintue()const{ return minute; }
	int GetSecond()const { return second; }
	Time operator+(int s1);
	Time operator-(int s2);
	static int GetTime(const Time &t);
	
};

//ostream& operator<<(ostream& out, const Time& t);
//istream& operator>>(istream& in, Time& t);

ostream &operator<<(ostream &out, const Time &d);		// 重载输出运算符
istream &operator>>(istream &in, Time &d);				// 重载输入运算符>>

int Time::GetTime(const Time& t)
{
	int s = t.GetHour() * 3600 + t.GetMintue() * 60 + t.GetSecond();
	return s;
}

Time Time::operator+(int s1)
{
	int n = 0, h = 0, m = 0, s = 0;
	Time t1;
	int n1 = GetTime(*this);
	n = n1 + s1;
	h = n / 3600;
	m = (n - h * 3600) / 60;
	s = n % 60;
	t1.SetHour(h);
	t1.SetMintue(m);
	t1.SetSecond(s);
	return t1;
}
Time Time::operator-(int s2)
{
	int n = 0, h = 0, m = 0, s = 0;
	Time T1;
	int n1 = GetTime(*this);
	n = n1 - s2;
	h = n / 3600;
	m = (n - h * 3600) / 60;
	s = n % 60;
	T1.SetHour(h);
	T1.SetMintue(m);
	T1.SetSecond(s);
	return T1;
}

ostream &operator<<(ostream &out,const Time &t)
{
	out << t.GetHour() << "时" << t.GetMintue() << "分" << t.GetSecond() << "秒";
	return out;
}
istream &operator>>(istream &in, Time &t)
{
	int h = 0, m = 0, s = 0;
	cin >> h >> m >> s;
	t = Time(h, m, s);
	return in;
}

//ostream &operator<<(ostream &out, const Time &d)	// 重载输出运算符
//{
//	out << d.GetHour() << "年" << d.GetMintue() << "月" << d.GetSecond() << "日";
//	return out;										// 返回输出流
//}
//istream &operator>>(istream &in, Time &d)	// 重载输入运算符>>
//{
//	int year, month, day;					// 年月日
//	cin >> year >> month >> day;				// 输入年月日
//	d = Time(year, month, day);				// 转换成日期
//	return in;								// 返回输入流
//}
int main()
{
	Time t(12, 01, 10),t2;
	cout << t << endl;
	cout << t + 10 << endl;
	cout << t - 10 << endl;
	cin >> t2;
	cout<< t2 << endl;
	system("pause");
	return 0;
}



