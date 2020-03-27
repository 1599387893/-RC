//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A::构造函数()" << endl;
//	}
//	~A()
//	{
//		cout << "A::析构函数()" << endl;
//	}
//};
//
//int Fun(){
//	cout << "调用Fun()函数" << endl;
//	return 1;
//}
//typedef int(*Fptr)();
//A a;
//int n = 1;
//Fptr ptr = Fun;
//int h = ptr();
//
//
//
//int main()
//{
//	cout << "main()" << endl;
//	system("pause");
//	return 0;
//}

#if 0
#include<iostream>
#include<deque>
using namespace std;

class B
{
public:
	B(int xx) :x(xx)
	{
		++count;
		x += 1;
	}
	virtual void show()
	{
		cout << count<<x<<endl;
	}
protected:
	static int count;
private:
	int x;
};

class D :public B
{
public:
	virtual ~D(){};
	D(int xx, int yy) :B(xx), y(yy)
	{
		++count;
		y += 2;
	}
	void show()
	{
		cout << count << y << endl;
	}
private:
	int y;
};
int B::count = 0;

int main()
{
#if 0
	deque<int> D(5);
	deque<int>::iterator it;
	int i;
	for (int i = 0; i < 5; ++i)
		D[i] = i;
	D.pop_back();
	D.pop_front();
	for (it = D.begin(); it != D.end(); ++it)
		cout << *it <<" ";
#endif
	B* p = new D(1, 2);
	p->show();
	delete p;
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

template<class T1,class T2>
class R
{
	T1 w;
	T2 h;
public:
	R(T1 i, T2 j) :w(i), h(j)
	{}
	void show();
};

template<class T1,class T2>
void R<T1, T2>::show()
{
	cout << w*h << endl;
}
#endif

#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

class D
{
	int a, b;
public:
	D(int i = 0, int j = 0) : a(i), b(j){}
	D(D& p)
	{
		a = p.a;
		b = p.b;
	}
	void show()
	{
		cout << a << " " << b << endl;
	}
	static int count;
};

D f(D p)
{
	D d1(p);
	return d1;
}

#include<fstream>
int main()
{
	ofstream file2("text.txt", ios::binary);
	file2 << "一二三";
	file2.seekp(ios::beg);
	file2 << "四";
	file2.close();
	return 0;
}