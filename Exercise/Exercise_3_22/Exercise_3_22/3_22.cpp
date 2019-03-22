#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstring>
using namespace std;

//¿½±´¹¹Ôìº¯Êý
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
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
//	Date d2(d1);
//
//	return 0;
//}

//class String
//{
//public:
//	String(const char* str = "")
//	{
//		if (str == nullptr)
//			str = "";
//		str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	String(const String& s)
//	{
//		strcpy(_str, s._str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//		_str = NULL;
//	}
//
//private:
//	char* _str;
//};
//
//int main()
//{
//	String s1("Hello");
//	string s2(s1);
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	/*bool operator== (const Date& d2)
//	{
//		return _year == d2._year && _month == d2._month && _day == d2._day;
//	}*/
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//bool operator== (const Date& d1,const Date& d2)
//{
//return d1._year == d2._year && d1._month == d2._month && d1._day == d2._day;
//}
//void Test()
//{
//	Date d1(2019, 3, 22);
//	Date d2(2019, 3, 22);
//	cout << (d1 == d2) << endl;
//
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		//_year = year;
		_month = month;
		_day = day;
	}
	/*Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}*/
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
//private:
	int _year;
	int _month;
	int _day;
};