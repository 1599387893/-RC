#include<iostream>
using namespace std;
//
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << this->_a << endl;
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a =0;
//};
//int main()
//{
//	A p;
//	p.PrintA();
//	p.Show();
//	//p->PrintA();
////	p->Show();
//
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1):_year(year),_month(month),_day(day){}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
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
//	Date d1;
//	Date d2(2019, 3, 26);
//	Date d3(d2);
//	d3 = d1;
//	return 0;
//}

//class Test
//{
//public:
//	void TestFun()
//	{
//		Test* const& p = this;
//		cout << &p << endl;
//	}
//
//int _t;
//};
//int main()
//{
//	int* p = nullptr;
//	int*& q = p;
//	cout << &q << endl;
//	cout << &p << endl;
//
//	Test t;
//	t.TestFun();
//	 
//	return 0;
//}

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
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	Date operator+(int days)
//	{
//		Date temp(*this);
//		temp._day += days;
//		return temp;
//	}
//	bool operator==(const Date& d)
//	{
//		return this->_year == d._year
//			&& this->_month == d._month
//			&& this->_day == d._day;
//	}
//	//前置++
//	Date& operator++()
//	{
//		_day++;
//		return *this;
//	}
//	//后置++
//	Date operator++(int)
//	{
//		Date temp(*this);
//		this->_day++;
//		return temp;
//	}	
//	//前置--
//	Date& operator--()
//	{
//		_day--;
//		return *this;
//	}
//	//后置--
//	Date operator--(int)
//	{
//		Date temp(*this);
//		this->_day--;
//		return temp;
//	}
//private:
//	int _year;
//	int  _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2019, 3, 26);
//	Date d3;
//	Date d4;
//	d4 = d3 = d2;
//	d4 = d4 + 10;
//	cout << (d2 == d3) << endl;
//	d1++;
//	++d1;
//	d1--;
//	--d1;
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 1;
//	int c = -1;
//	c = a + b;
//
//	return 0;
//}
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
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	Date* operator&()
//	{
//		cout<<"this   " << this << endl;
//		return this;
//	}
//
//private:
//	int _year;
//	int  _month;
//	int _day;
//};
//
//int main()
//{
//	Date d;
//	cout << &d << endl;
//	const Date d2;
//	cout << &d2 << endl;
//	return 0;
//}

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
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	Date* operator&()
//	{
//		cout << "this   " << this << endl;
//		return this;
//	}
//	//Date* const  <==> this
//	void TestFun1()
//	{
//		this->_day++;
//	}
//	//const Date* const  this
//	void TestFun2()const
//	{
//		//this->_day++;
//	}
//private:
//	int _year;
//	int  _month;
//	int _day;
//};

//int main()
//{
//	Date d;
//	cout << &d << endl;
//	const Date d2;
//	cout << &d2 << endl;
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(Date&):" << this << endl;
	}

	// d1 = d2 = d3;
	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	~Date()
	{
		cout << "~Date():" << this << endl;
	}


	int _year;
	int _month;
	int _day;
};

Date& TestDate(Date& d)
{
	Date temp(d);
	temp._day += 1;
	return d;
}

void TestDate()
{
	Date d1(2019, 3, 24);
	Date d2(d1);
	d1 = TestDate(d2);
}
int main()
{
	Date d1(2019, 3, 2);
	Date d2(d1);
	TestDate();
	return 0;
}