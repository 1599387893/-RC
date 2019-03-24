#include<iostream>
using namespace std;


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1):_year(year),_month(month),_day(day){}
//
//	void Display()const 
//	{
//		cout << _year << "-" << _month << "-" << _day << "-" << endl;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2019, 3, 24);
//	Date d3(d2);
//	d2.Display();
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1) :_year(year), _month(month), _day(day){}
//
//	Date* operator&()
//	{
//		return this;
//	}
//	const Date* operator&()const
//	{
//		return this;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2019, 3, 24);
//	Date d3(d2);
//
//	return 0;
//}

class A
{
public:
	A(int a = 0,int b = 0) :_a(a),_b(b){}
private:
	int _a;
	int _b;
};

class B
{
public:
	B(int ref) :_ref(ref), _n(10){}
private:
	A _aobj;
	int& _ref;
	const int _n;
};

int main()
{
	B obj(2);

	return 0;
}

//class Time
//{
//public:
//	Time(int hour = 0) :_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int d){}
//private:
//	int _day;
//	Time _t;
//};
