#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class A
{
public:
	void foo()
	{
		cout << "A::foo()" << endl;
	}
	int _a;
	int _b;
	double _c;
};

void foo(const class A* pre)
{
	cout << "Gloabl foo()" << endl;
}

struct record{
	string name;
	int age;
	vector<int> grades;
} re;
int main()
{
	vector<bool> arr;
	vector<int> arr1;
	vector<double> arr2;
	vector<string> arr3;
	cout << sizeof(arr) << endl;
	cout << sizeof(arr1) << endl;
	cout << sizeof(arr2) << endl;
	cout << sizeof(arr3) << endl;

	string s{"123456789"};
	cout << sizeof(s) << endl;
	cout << sizeof(re) << endl;
	map<int, int> m;
	cout << sizeof(arr) << endl;
	cout << sizeof(m) << endl;

	A a,b;
	a._a = 1;
	a._b = 2;
	a._c = 3;
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	A* a1 = new A();
	a1->foo();
	foo(a1);
	cout << sizeof(a) << endl;
	return 0;
}