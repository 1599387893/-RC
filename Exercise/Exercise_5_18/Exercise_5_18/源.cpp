#include<iostream>
using namespace std;

#if 0
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
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derived :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derived::Func1()" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derived d;

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
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derived :public Base
{
public:
	virtual void Func1()
	{
		cout << "Derived::Func1()" << endl;
	}
	virtual void Func4()
	{
		cout << "Derived::Func4()" << endl;
	}
private:
	int _d = 2;
};
typedef void(*VFP)();
void PrintVTable(VFP vTable[])
{
	cout << "虚标地址：" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf("第%d个虚函数地址：0X%x,->", i+1, vTable[i]);
		VFP f = vTable[i];
		f();
	}
	cout << endl;	
}
typedef void(*PVF)();
void PrintVFun(Base& b)
{
	PVF* pVF = (PVF*)(*(int*)&b);
	while (pVF)
	{
		(*pVF)();
		pVF++;
	}
}
int main()
{
	Base b;
	Derived d;
	/*VFP* vTableb = (VFP*)(*(int*)&b);
	PrintVTable(vTableb);
	VFP* vTabled = (VFP*)(*(int*)&d);
	PrintVTable(vTabled);*/
	PrintVFun(b);
	PrintVFun(d);
	system("pause");
	return 0;
}