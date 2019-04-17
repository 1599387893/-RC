#include<iostream>
using namespace std;


class Date
{
	friend ostream &operator<<(ostream &out, const Date &d);		// ������������
	friend istream &operator>>(istream &in, Date &d);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& d);

	void SetYear(int y){ _year = y; }
	void SetMonth(int m){ _month = m; }// ������ 
	void SetDay(int d){ _day = d; }		// ������
	int GetYear() const{ return _year; }	// ������ 
	int GetMonth() const{ return _month; }	// ������ 
	int GetDay() const{ return _day;  }	// ������
	static bool IsLeapyear(int y);			// �ж����y�Ƿ�Ϊ����
	static int GetYearDays(int y);			// ���y������
	static int GetMonthDays(const Date &d);	// ����d��ǰ�·ݵ�����
	static int DateToNum(const Date &d);		// ���شӹ�Ԫ1��1��1���������
	static Date NumToDate(int n);			// �ɴӹ�Ԫ1��1��1�����������������


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