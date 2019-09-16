#include<iostream>
using namespace std;

#if 0
//纯函数
class Car
{
public:
	virtual void Driver() = 0;
};
//抽象类的派生类中的纯虚函数必须实现
class Benz :public Car
{
public:
	virtual void Driver() override
	{
		cout << "Benz-舒适" << endl;
	}
};
//override 修饰派生类虚函数强制完成重写
class BMW :public Car
{
public:
	virtual void Driver()override
	{
		cout << "BMW-操控" << endl;
	}
};

void Test()
{
	Car* pBenz = new Benz;
	pBenz->Driver();
	Car* pBMW = new BMW;
	pBMW->Driver();
}
int main()
{
	Test();
	system("pause");
	return 0;
}
#endif

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	virtual  void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int  _a = 1;
};
class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	//int _d;
};
int main()
{
	Base b;
	Derive d;
	d.Func1();
	d.Base::Func1();
	cout << sizeof(b) << endl;
	cout << sizeof(d) << endl;
	system("pause");
	return 0;
}