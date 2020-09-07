#include <iostream>
using namespace std;

class func
{
public:
	func()
	{
		cout << "func()" << endl;
	}
	~func()
	{
		cout << "~func()" << endl;
	}
};

class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	~Base()
	{
		cout << "~Base()" << endl;
	}
	func a;
};
class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}
	~Derived()
	{
		cout << "~Derived()" << endl;
	}
};

void GetDigit(string& s, int pos, bool PreIsDigit)
{
	if (pos >= (int)s.size())
		return;
	if (!isdigit(s[pos]))
	{
		if (PreIsDigit)
			cout << endl;
		PreIsDigit = false;
	}
	else
	{
		cout << s[pos];
		PreIsDigit = true;
	}
	GetDigit(s,pos+1, PreIsDigit);
}
int main()
{
	string s = "AA1234FF4567";
	GetDigit(s, 0, false);
	cout << endl;
	return 0;
}