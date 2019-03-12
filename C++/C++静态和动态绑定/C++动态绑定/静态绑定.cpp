#include<iostream>
using namespace std;

class Base
{
public:
	void display()const { cout << "基类Base" << endl; }
};

class FristA :public Base
{
public:
	void display()const { cout << "派生类FristA" << endl; }
};

class SceondB :public Base
{
public:
	void display()const { cout << "派生类SceondB" << endl; }
};

int main()
{
	Base obj1;
	FristA obj2;
	SceondB obj3;
	obj1.display();
	obj2.display();
	obj3.display();
	system("pause");
	return 0;
}