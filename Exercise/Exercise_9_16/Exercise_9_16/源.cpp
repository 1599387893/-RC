#include<iostream>
using namespace std;

#if 0
//������
class Car
{
public:
	virtual void Driver() = 0;
};
//��������������еĴ��麯������ʵ��
class Benz :public Car
{
public:
	virtual void Driver() override
	{
		cout << "Benz-����" << endl;
	}
};
//override �����������麯��ǿ�������д
class BMW :public Car
{
public:
	virtual void Driver()override
	{
		cout << "BMW-�ٿ�" << endl;
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