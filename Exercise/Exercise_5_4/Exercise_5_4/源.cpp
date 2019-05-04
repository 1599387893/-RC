#include<vector>
#include<iostream>
#include<list>
using namespace std;


#if 0
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));

	for (auto& e : l1)
		cout << e << " ";
	cout << endl;

	cout << "l1.front = " << l1.front() << endl;
	cout << "l1.back = " << l1.back() << endl;
	l1.front() = 10;
	l1.back() = 10;

	for (auto& e : l1)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif

void PrintList(list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;

}
//int main()
//{
//	int array[] = { 1, 2, 3 };
//	list<int> l1(array, array + (sizeof(array) / sizeof(array[0])));
//	
//	PrintList(l1);
//	l1.push_back(4);
//	l1.push_front(0);
//	PrintList(l1);
//
//	l1.pop_back();
//	l1.pop_front();
//	PrintList(l1);
//
//	return 0;
//}

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&)" << this << endl;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestList1()
{
	list<Date> l;
	Date d(2019, 5, 4);
	l.push_back(d);
	l.emplace_back(2019,5,5);
	l.emplace_front(2019, 5, 3);

}
void TestList2()
{
	int array[] = { 1, 2, 3 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto pos = ++l.begin();
	cout << *pos << endl;
	l.insert(pos, 4);
	PrintList(l);
	l.insert(pos, 5, 5);
	PrintList(l);

	vector<int> v{ 7, 8, 9 };
	l.insert(pos, v.begin(), v.end());
	PrintList(l);

	l.erase(pos);
	PrintList(l);
	
	l.erase(l.begin(), l.end());
	PrintList(l);
}
void TestList3()
{
	int array[] = { 1, 2, 3 };
	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l1);

	l1.resize(10);
	PrintList(l1);
	 
	l1.resize(20, 4);
	PrintList(l1);

	l1.resize(5);
	PrintList(l1);

	vector<int> v{ 4, 5, 6 };
	list<int> l2(v.begin(), v.end());
	PrintList(l2);

	l1.swap(l2);
	PrintList(l1);
	PrintList(l2);

	l2.clear();
	cout << l2.size() << endl;
}
void TestlistIterator()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = l.begin();
	while (it != l.end())
	{
		//l.erase(it++);
		it = l.erase(it);
	}

}


int main()
{
	//TestList1();
	//TestList2();
	//TestList3();
	TestlistIterator();
	
	return 0;
}