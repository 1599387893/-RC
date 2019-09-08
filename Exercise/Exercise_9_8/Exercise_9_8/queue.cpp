#include<iostream>
#include<queue>
#include<functional>
using namespace std;

void TestPriorityQueue1()
{
	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
	priority_queue<int> q1;
	for (auto& e : v)
		q1.push(e);
	cout << q1.top() << endl;

	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;
}

class Date
{
public:
	Date(int year=1900,int month=1,int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
	friend ostream& operator<<(ostream& out, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day;
	return out;
}

class Less
{
public:
	bool operator()(const Date* pleft, const Date* pright)
	{
		return *pleft < *pright;
	}
};

void TestPriorityQueue2()
{
	//大堆
	priority_queue<Date> q1;
	q1.push(Date(2018, 10, 29));
	q1.push(Date(2018, 10, 28));
	q1.push(Date(2018, 10, 30));
	cout << "大堆(默认)Top=" << q1.top() << endl;

	//小堆
	priority_queue<Date, vector<Date>, greater<Date>> q2;
	q2.push(Date(2018, 10, 29));
	q2.push(Date(2018, 10, 28));
	q2.push(Date(2018, 10, 30));
	cout << "小堆Top=" << q2.top() << endl;

	//大堆
	priority_queue<Date,vector<Date*> ,Less> q3;
	q3.push(&Date(2019, 10, 29));
	q3.push(&Date(2019, 10, 28));
	q3.push(&Date(2019, 10, 30));
	cout << "自定义Top=" << *q3.top() << endl;
}
int main()
{
	//TestPriorityQueue1();
	TestPriorityQueue2();
	system("pause");
	return 0;
}