#include<iostream>
using namespace std;


class Date
{
	friend ostream &operator<<(ostream &out, const Date &d);		// 重载输出运算符
	friend istream &operator>>(istream &in, Date &d);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);

	void SetYear(int y){ _year = y; }
	void SetMonth(int m){ _month = m; }// 设置月 
	void SetDay(int d){ _day = d; }		// 设置日
	int GetYear() const{ return _year; }	// 返回年 
	int GetMonth() const{ return _month; }	// 返回月 
	int GetDay() const{ return _day;  }	// 返回日
	static bool IsLeapyear(int y);			// 判断年份y是否为润年
	static int GetYearDays(int y);			// 年份y的天数
	static int GetMonthDays(const Date &d);	// 日期d当前月份的天数
	static int DateToNum(const Date &d);		// 返回从公元1年1月1日起的天数
	static Date NumToDate(int n);			// 由从公元1年1月1日起的天数返回日期


	Date& operator=(const Date& d);
	Date operator+(int days);
	Date operator-(int days);
	int operator-(const Date& d);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
};