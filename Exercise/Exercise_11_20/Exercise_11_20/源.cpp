#include<iostream>
using namespace std;
//测试派生类的虚函数表的内容

//void (*PVFT)() ;这种情况，PVFT是函数指针变量
typedef void(*PVFT)(); //PVFT是函数指针类型
class Base
{
public:
	int _b;
public:
	virtual void TestFunc1()
	{
		cout << "Base::TestFunc1()" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "Base::TestFunc2()" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "Base::TestFunc3()" << endl;
	}
};
class Derived :  public Base
{
public:
	int _d;
public:
	virtual void TestFunc1()
	{
		cout << "Derived::TestFunc1()" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "Derived::TestFunc4()" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "Derived::TestFunc5()" << endl;
	}

};

void Test(Base& b)
{
	b.TestFunc1();
	b.TestFunc2();
	b.TestFunc3();
}
int main()
{
	Base b;
	b._b = 1;
	Derived d;
	cout << sizeof(d) << endl;
	d._b = 2;
	d._d = 3;
	Test(d);
	PVFT* pVft = (PVFT*)(*((int*)&d));
	while (*pVft)
	{
		(*pVft) (); //调用现在虚函数指针指向的虚函数，打印提示信息；
		pVft++;
	}
	system("pause");
	return 0;
}