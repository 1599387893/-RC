#if 0
#include<iostream>
#include<list>
using namespace std;

void PrintList(list<int>& l)
{
	//auto it = l.begin();
	//while (it != l.end())
	//	cout << *it++ << " ";
	//cout << endl;

	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}


int main()
{
#if 0
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	list<int>l1;
	list<int>l2(5,100);
	list<int>l3(l2.begin(), l2.end());
	list<int>l4(arr, arr + (sizeof(arr) / sizeof(arr[1])));
	list<int>l5(l4);
	PrintList(l1);
	PrintList(l2);
	PrintList(l3);
	PrintList(l4);
	PrintList(l5);
	
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	list<int> l(arr, arr + 10);

	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
	cout << endl;

	for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
		cout << *it << " ";
	cout << endl;

	auto it = l.cbegin();
	cout << typeid(it).name() << endl;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + 10);

	cout << l.size() << endl;
	cout << l.empty() << endl;

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(arr, arr + 10);

	for (const auto&e : l)
		cout << e << " ";
	cout << endl;

	l.front() = 10;
	l.back() = 10;

	for (const auto&e : l)
		cout << e << " ";
	cout << endl;
#endif




	system("pause");
	return 0;
}
#endif

#include<iostream>
#include<assert.h>
#include<list>
#include<vector>
using namespace std;


class Date
{
public:
	Date(int year = 1900, int month = 1,int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int,int,int)" << endl;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date& d)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void PrintList(list<int>& l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;
}
void TestList1()
{
	int arr[] = { 1, 2, 3 };
	list<int> l(arr,arr+3);
	l.push_back(4);
	l.push_back(5);
	PrintList(l);
	
	l.pop_back();
	PrintList(l);

	l.push_front(0);
	l.push_front(-1);
	PrintList(l);

	l.pop_front();
	PrintList(l);

}
void TestList2()
{
	int arr[] = { 1, 2, 3 };
	list<int> l(arr, arr + 3);
	auto pos = ++l.begin();
	cout << *pos << endl;

	l.insert(pos,4);
	PrintList(l);

	l.insert(pos, 5, 5);
	PrintList(l);

	vector<int> v{ 7, 8, 9 };
	l.insert(pos,v.begin(),v.end());
	PrintList(l);

	l.erase(pos);
	PrintList(l);

	l.erase(l.begin(),l.end());
	PrintList(l);
}
void TestIterator()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	list<int> l(arr, arr + 7);

	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++);
	}
	PrintList(l);
}

int main()
{
	//TestList1();
	//TestList2();
	TestIterator();
	system("pause");
	return 0;
}