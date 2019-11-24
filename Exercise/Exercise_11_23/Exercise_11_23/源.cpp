#include<iostream>
using namespace std;
#if 0
class Wideget
{
public:
	Wideget()
	{}
	Wideget(Wideget& w)
	{
		cout << "Wideget(Wideget&)" << endl;
	}
};
Wideget func(Wideget u)
{
	Wideget v(u);
	Wideget w;
	w = v;
	return w;
}
int main()
{
	Wideget x;
	Wideget y = func(func(x));
	system("pause");
	return 0;
}


void print(char* s)
{
	if (*s)
	{
		print(++s);
		printf("%c", *s);
	}
}
int main()
{
	char str[] = "Geneius";
	print(str);
	system("pause");
}


int main()
{
	char* p = "abc";
	char* q = "abc123";
	while (*p = *q)
		printf("%c,&c", *p, *q);
	system("pause");
	

}

int main()
{
	long long a = 1, b = 2, c = 3;
	printf("%d %d %d\n", a, b, c);
	system("pause");


}
#endif

class A
{
public:
	A(){ p(); }
	virtual void p(){ printf("A"); }
	virtual ~A(){ p(); }
};
class B :public A
{
public:
	B(){ p(); }
	void p(){ printf("B"); }
	~B(){ p(); }
};

int main()
{
	A* a = new B();
	delete a;
	system("pause");
	return 0;
}