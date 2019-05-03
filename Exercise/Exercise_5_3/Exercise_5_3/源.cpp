//test_list
#include<iostream>
#include<list>
using namespace std;

template<class T>
void Print(list<T> l)
{
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it<<" ";
		++it;
	}
	cout << endl;
}
template<class T>
void Print1(list<T> l)
{
	auto it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
template<class T>
void Print2(list < T > l)
{
	for (auto& e : l)
		cout << e << " ";
	cout << endl;

}
template<class T>
void Print3(list<T> l)
{
	for (list<T>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it<<" ";
	cout << endl;
}
template<class T>
void reserve_iterator(list<T> l)
{
	for (list<T>::reverse_iterator it = l.rbegin(); it != rend(); ++it)
		cout << *it << " ";
	cout << endl;
}
int main()
{
	//list<int> l1;
	//list<int> l2(4, 100);
	//list<int> l3(l2.begin(), l2.end());
	//list<int> l4(l3);
	//Print(l1);
	//Print(l2);
	//Print(l3);
	//Print(l4);
	int array[] = { 15, 77, 2, 95 };
	list<int> l5(array, array + sizeof(array) / sizeof(array[0]));
	cout << l5.size() << endl;
	cout << l5.empty() << endl;
	cout << l5.front() << endl;
	cout << l5.back() << endl;
	//Print1(l5);
	//Print2(l5);
	//Print3(l5);
//	reserve_iterator(l5);
	//auto it = l5.cbegin();
	//cout << typeid(it).name() << endl;

	return 0;
}