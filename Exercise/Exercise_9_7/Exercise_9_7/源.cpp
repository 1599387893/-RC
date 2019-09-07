#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

void PrintDeque(deque<int> d)
{
	for (auto& e : d)
		cout << e << " ";
	cout << endl;
}

void Test()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	deque<int> d1;
	deque<int> d2(5, 100);
	deque<int> d3(arr, arr + 5);
	deque<int> d4(d2);

	PrintDeque(d1);
	PrintDeque(d2);
	PrintDeque(d3);
	PrintDeque(d4);
}

void TestIterator()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	deque<int> d1(arr, arr + 9);

	for (auto it = d1.cbegin(); it != d1.cend(); ++it)
		cout << *it << " ";
	cout << endl;

	for (auto it = d1.crbegin(); it != d1.crend(); ++it)
		cout << *it << " ";
	cout << endl;
}

void TestDeque3()
{
	deque<int> d1{3,4,5};
	d1.push_back(6);
	d1.push_front(2);
	PrintDeque(d1);

	cout << "size() = "<< d1.size() << endl;
	cout << "Front = " << d1.front() << endl;
	cout << "back = " << d1.back() << endl;

	d1.emplace_back(7);
	d1.emplace_front(1);
	PrintDeque(d1);

	d1.insert(d1.begin(), 0);
	PrintDeque(d1);

	d1.pop_back();
	d1.pop_front();
	d1.erase(d1.begin());
	PrintDeque(d1);
	
	d1.clear();
	cout << "size() = " << d1.size() << endl;

}

void TestDequeSort()
{
	int arr[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
	deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PrintDeque(d);

	sort(d.begin(), d.end());
	PrintDeque(d);
}
int main()
{
	//Test();
	//TestIterator();
	//TestDeque3();
	TestDequeSort();
	system("pause");
	return 0;
}