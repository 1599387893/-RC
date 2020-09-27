#include <iostream>
using namespace std;


class Base
{
private:
	int _a;
	virtual void Fun()
	{
		cout << "Base::Fun()" << endl;
	}
public:
	Base(int a)
		: _a(a)
	{}
	~Base()
	{}
};

class Derive : public Base
{
private:
	int _b;
	virtual void Fun()
	{
		cout << "Derive::Fun()" << endl;
	}
public:
	Derive(int a = 0)
		: Base(a)
	{}
};

class Demo
{
public:
	void A() { cout << "A()" << endl; }
	void A(int) { cout << "A(int)" << endl; }
	void A(double, double = 1.2) { cout << "A(double...)" << endl; }
};
int main()
{

	char a[20] = "You are so";
	char* p = a;
	char** ptr = &p;
	cout << **ptr << endl;
	ptr++;
	cout << **ptr << endl;
	Demo de;
	de.A(2.4);
	Base* b = new Derive();
}