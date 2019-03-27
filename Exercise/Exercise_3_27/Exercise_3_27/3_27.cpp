#include<iostream>
using namespace std;

//class Date
//{
//public:
//	explicit Date(int year) :_year(year)
//	{
//		cout << "Date(int)" << this << endl;
//	}
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2019);
//	d1 = 2020;
//
//	return 0;
//}

//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestDate()
//{
//	Date d1(2018);
//	// 用一个整形变量给日期类型对象赋值
//	// 实际编译器背后会用2019构造一个无名对象，最后用无名对象给d1对象进行赋值
//	d1 = 2019;
//}
//int main()
//{
//	TestDate();
//
//	return 0;
//}

//class Test
//{
//public:
//	Test() :_a(0)
//	{
//		_count++;
//	}
//	Test(const Test& d)
//	{
//		_count++;
//	}
//	static int GetCount()
//	{
//		return _count;
//	}
//	~Test()
//	{
//		_count--;
//	}
//private:
//	int _a;
//	static int _count;
//};
//int Test::_count = 0;
//void TestFun()
//{
//	Test t1;
//	cout << Test::GetCount() << endl;
//	Test t2;
//	Test t3(t2);
//	cout << t1.GetCount() << endl;
//	cout << t1.GetCount() << endl;
//}
//int main()
//{
//	TestFun();
//	cout << Test::GetCount() << endl;
//	return 0;
//}
//
//class Test
//{
//public:
//	Test() :_a(0)
//	{
//		_count++;
//	}
//	Test(Test& t)
//	{
//		_count++;
//	}
//	int GetB()
//	{
//		GetCount();
//		cout << this << endl;
//		return this->_a;
//	}
//	static int GetCount()
//	{
//		//cout << this << endl;
//		//cout << _a << endl;
//		return _count;
//	}
//	~Test()
//	{
//		_count--;
//	}
//private:
//	int _a;
//	static int _count;
//};
//
//int Test::_count = 0;
//
//int main()
//{
//	Test t;
//	t.GetB();
//	Test::GetCount();
//
//	return 0;
//}
//
//class Time
//{
//public:
//	Time(int hour = 12, int minute = 1, int second = 1) :_hour(hour), _minute(minute), _second(second)
//	{
//		cout << this->_hour << endl;
//	}
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//	}
//	friend void TestFriend();
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1) :_year(year), _month(month), _day(day){}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void PrintDate()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	friend void TestFriend();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestFriend()
//{
//	//Time t;
//	Time t;
//	t._hour = 16;
//
//	Date d;
//	d._year = 2019;
//}
//int main()
//{
//	TestFriend();
//
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, const Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1) :_year(year), _month(month), _day(day){}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void PrintDate()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day;
//	return out;
//}
////istream& operator>>(istream& in, const Date& d)
////{
////	
////	return in;
////}
//int main()
//{
//	Date d1(2019, 3, 26);
//	cout << d1 << endl;
//
//	Date d2(d1);
//	cout << d2 << endl;
//
//	return 0;
//}

class Time
{
public:
	Time(int hour = 12, int minute = 1, int second = 1) :_hour(hour), _minute(minute), _second(second){}
	Time(const Time& t)
	{
		_hour = t._hour;
		_minute = t._minute;
		_second = t._second;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
	friend class Time;
	friend Time;
public:
	Date(int year = 1900, int month = 1, int day = 1 ) 
		:_year(year), _month(month), _day(day){}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{

	return 0;
}