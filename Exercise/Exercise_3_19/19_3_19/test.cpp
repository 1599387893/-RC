#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
#include<malloc.h>
#include<string.h>
using namespace std;

//构造函数
//class Date
//{
//public:
//	Date(){ cout << "---" << endl; };
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	d.Print();
//
//	return 0;
//}


//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	d.Print();
//
//	return 0;
//}


//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 12;
//		_day = 30;
//	}
//	Date(int year = 1900, int month = 12, int day = 19)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d();
//	//d.Print();
//
//	return 0;
//}


//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_mintur = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _mintur;
//	int _second;
//
//};
//
//class Date
//{
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//	Date d;
//	return 0;
//}


//析构函数

//class SeqList
//{
//public:
//	SeqList(int capacity = 10)
//	{
//		_array = (int*)malloc(capacity * sizeof(int));
//		assert(_array);
//		_capacity = capacity;
//		_size = 0;
//	}
//	~SeqList()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	int* _array;
//	int _capacity;
//	int _size;
//};
//
//int main()
//{
//	SeqList s;
//
//	return 0;
//}


//class String
//{
//public:
//	String(const char* str = "RC")
//	{
//		if (str == NULL)
//			str = "";
//		_str = (char*)malloc(sizeof(char)* strlen(str));
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		if (_str)
//		{
//			cout << "~string()" << endl;
//			free(_str);
//			_str = NULL;
//		}
//	}
//private:
//	char* _str;
//};
//
//class Person
//{
//private:
//	String _name;
//	int _age;	
//};
//int main()
//{
//	Person p;
//
//	return 0;
//}

//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//int main()
//{
//	Person p;
//	return 0;
//}

