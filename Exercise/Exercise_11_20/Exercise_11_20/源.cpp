#include<iostream>
using namespace std;
//������������麯���������

//void (*PVFT)() ;���������PVFT�Ǻ���ָ�����
typedef void(*PVFT)(); //PVFT�Ǻ���ָ������
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
		(*pVft) (); //���������麯��ָ��ָ����麯������ӡ��ʾ��Ϣ��
		pVft++;
	}
	system("pause");
	return 0;
}