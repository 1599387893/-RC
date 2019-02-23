#include<iostream>
using namespace std;

class Base
{
public:
	virtual void f() {	cout << "调用Base::f()" << endl; }
};
class Derived :public Base
{
public:
	void f(){ cout << "调用Derived::f()" << endl; }
};

int main()
{
	Derived d1;
	d1.f();
	Base *p = &d1;
	p->f();
	system("pause");
	return 0;
}
