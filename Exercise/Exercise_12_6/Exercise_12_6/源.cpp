#include<iostream>
using namespace std;

#if 0
int main()
{
	int a = 1, b = 0, c = -1, d = 0;
	d = ++a || ++c && ++b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	system("pause");
	return 0;
}
#endif

#if 0
template<class T> class BigNumber{
	long n; 
public: 
	explicit BigNumber(T i) :n(i)
	{} 
	BigNumber operator+(BigNumber b) 
	{ 
		return BigNumber(n + b.n);
	}
};

int main()
{
	BigNumber<int> b1(1);
	BigNumber<int> b2(2);
	b1 + b2;
	//b1 + 1;
	//1 + b1;
	return  0;
}
#endif

class A
{
public:
	
	int b;int a;
public:
	A(int aa, int bb) :b(a*bb), a(aa--)
	{}
};
int main()
{
	A a(4, 5);
	cout << a.a << "  " << a.b << endl;
	system("pause");
	return 0;
}
#if 0
int main()
{
	int a = 10;
	int* ptr = &a;
	cout << ptr << endl;
	cout << *&ptr << endl;
	cout << &*ptr << endl;
	system("pause");
	return 0;
}


class A 
{ 
public: 
	A() :m_iVal(0){ test(); } 
	virtual void func() 
	{ 
		std::cout << m_iVal <<endl; 
	} 
	void test()
	{ 
		func(); 
	} 
public: 
	int m_iVal; 
}; 
class B : public A 
{ 
public: 
	B()
	{ 
		test(); 
	} 
	virtual void func() 
	{ 
		++m_iVal; 
		std::cout << m_iVal <<endl;
	} 
}; 
int main(int argc, char* argv[]) 
{ 
#if 0
	A*p = new B; 
	p->test();
#endif


	system("pause");
	return 0; 
}
#endif

#if 0
class A
{
public:
	A(int a)
	{
		cout << a << endl;
	}
};

int main()
{
	A a1(1), a2(2), a3(3), a4(4);
	system("pause");
	return 0;
}


class Test
{ 
public: 
	int a; 
	int b; 
	virtual void fun() 
	{} 
	Test(int temp1 = 0, int temp2 = 0) 
	{ 
		a = temp1; 
		b = temp2; 
	}
	int getA() 
	{ 
		return a; 
	}
	int getB() 
	{ 
		return b; 
	} 
};
int main() 
{
	Test obj(5, 10); 
	// Changing a and b 
	int* pInt = (int*)&obj; 
	*(pInt+0) = 100; 
	*(pInt+1) = 200; 
	cout << "a = " << obj.getA() << endl; 
	cout << "b = " << obj.getB() << endl; 
	system("pause");
	return 0; 
}
#endif