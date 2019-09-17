#include<iostream>
using namespace std;

#if 0
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2（）" << endl;
	}
private:
	int _b = 1;
};

class Derived :public Base
{
public:
	virtual void Func3()
	{
		cout << "Derived::Func3()" << endl;
	}
private:
	int _d = 2;
};
class DD :public Derived
{
private:
	int _dd = 3;
};
int main()
{
	Base b1;
	Base b2;
	Derived d1;
	Derived d2;
	DD dd1;

	cout << sizeof(b1) << endl;
	system("pause");
	return 0;
}
#endif


//单继承中的虚函数表
#if 0
class Base
{
public:
	virtual void Func1(){ cout << "Base::Func1()" << endl; }
	virtual void Func2(){ cout << "Base::Func2()" << endl; }
private:
	int a;
};
class Derived :public Base
{
public:
	virtual void Func1(){ cout << "Derived::Func1()" << endl; }
	virtual void Func3(){ cout << "Derived::Func3()" << endl; }
	virtual void Func4(){ cout << "Derived::Func4()" << endl; }
private:
	int b;
};
typedef void(*VFPTR)();
void PrintVTable(VFPTR vTable[])
{
	cout << "虚表地址：" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个函数的地址：0X%x,->",i,vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derived d;
	VFPTR* vTabled1 = (VFPTR*)(*(int*)&b);
	PrintVTable(vTabled1);

	VFPTR* vTabled2 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled2);

	system("pause");
	return  0;
}
#endif


//多继承中的虚函数表
class Base1
{
public:
	virtual void func1(){ cout << "Base1::func1()" << endl; }
	virtual void func2(){ cout << "Base1::func2()" << endl; }
private:
	int b1;
};
class Base2
{
public:
	virtual void func1(){ cout << "Base2::func1()" << endl; }
	virtual void func2(){ cout << "Base2::func2()" << endl; }
private:
	int _b2;
};

class Derive :public Base1, public Base2
{
private:
	virtual void func1(){ cout << "Derive::func1()" << endl; }
	virtual void func3(){ cout << "Derive::func3()" << endl; }
private:
	int d1;
};

typedef void(*VFPTR)();
void PrintTable(VFPTR vTable[])
{
	cout << "虚函数地址：" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数的地址为：0X%x,->",i,vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main()
{
	Derive d;
	VFPTR* vTable1 = (VFPTR*)(*(int*)&d);
	PrintTable(vTable1);

	VFPTR* vTable2 = (VFPTR*)(*(int*)((char*)&d+sizeof(Base1)));
	PrintTable(vTable2);
	system("pause");
	return 0;
}