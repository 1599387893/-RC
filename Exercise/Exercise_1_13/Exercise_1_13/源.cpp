#include<iostream>
using namespace std;
#if 0
int main()
{
#if 0
	char* p = "abc";
	char* q = "abc123";
	*p = 1;
	while (*p == *q) //因为p和q定义的变量都在代码段，而代码段的内容不可改
		cout << *p << *q << endl;
#endif
	long long a = 1, b = 2, c = 3;
	printf("%l %l %l\n",a,b,c);
	system("pause");
	return 0;
}
#endif 

#if 0
class A
{ 
public: 
	A()
	{ 
 		p(); 
	} 
	virtual void p()
	{ 
		printf("A");
	} 
	virtual ~A(){
		p(); 
	} 
}; 
class B :public A
{ 
public: 
	B()
	{
		p(); 
	} 
	void p()
	{
		printf("B");
	} 
	~B()
	{ 
		p(); 
	}
}; 
int main(int, char**)
{ 
	A* a = new B(); 
	delete a; 
}
#endif

class A
{
public:
	~A()
	{
		cout << "~A()" ;
	}
};
class B
{
public:
	virtual ~B()
	{
		cout << "~B()" ;
	}
};
class C :public A, public B
{
public:
	~C()
	{
		cout << "~C()";
	}
};
int main()
{
	C* c = new C;
	B* b1 = dynamic_cast<B*> (c);
	A* a2 = dynamic_cast<A*>(b1);
	delete a2;

	system("puase");
	return 0;
}

#if 0
#include<iostream>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n <= 2)
			cout << "-1" << endl;
		else if (n % 2 != 0)
			cout << "2" << endl;
		else
		{
			if (n % 4 == 0)
				cout << "3" << endl;
			else
				cout << "4" << endl;
		}
	}
	return 0;
}
#endif