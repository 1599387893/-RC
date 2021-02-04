#include <iostream>
#include <algorithm>
using namespace std;

class Base
{
public:
	virtual void Func()
	{
		cout << "Base::Func()" << endl;
	}
	int _b;
};

class Derived : public Base
{
public:
	virtual void Func()
	{
		cout << "Derived::Func()" << endl;
	}
	int _d;
};

template<class T>
auto Add(const T& left, const T& right)->decltype(left+ right)
{
	return left + right;
}
int main()
{
	//Derived a;
	int a = 1;
	int b = 2;
	cout << typeid(Add(a, b)).name() << endl;
	return 0;
}