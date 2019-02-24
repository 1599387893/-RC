//////#include<iostream>
//////using namespace std;
//////
//////class Base
//////{
//////public:
//////	virtual void f() {	cout << "调用Base::f()" << endl; }
//////};
//////class Derived :public Base
//////{
//////public:
//////	void f(){ cout << "调用Derived::f()" << endl; }
//////};
//////
//////int main()
//////{
//////	Derived d1;
//////	d1.f();
//////	Base *p = &d1;
//////	p->f();
//////	system("pause");
//////	return 0;
//////}
////
////
////#include<iostream>
////using namespace std;
////
////class Base
////{
////public:
////	virtual void Show()const { cout << "调用Base::Show" << endl; }
////};
////class Derived :public Base
////{
////public:
////	void Show()const { cout << "调用Derived::Show" << endl; }
////};
////
////void Refers(const Base& obj)
////{
////	obj.Show();
////	return;
////}
////int main()
////{
////	Base obj1;
////	Derived obj2;
////	Refers(obj1);
////	Refers(obj2);
////	system("pause");
////	return 0;
////}
//
//#include<iostream>
//using namespace std;
//
//class Base
//{
//private:
//	int m;
//public:
//	Base(int a) :m(a){}
//	virtual void Show()const { cout << m << endl; }
//};
//class Derived :public Base
//{
//private:
//	int n;
//public:
//	Derived(int a, int b) :Base(a), n(b){}
//	void Show() const
//	{
//		cout << n << ",";
//		Base::Show();
//	}
//};
//
//int main()
//{
//	Base obj1(168);
//	Derived obj2(158, 98);
//	Base* p;
//	p = &obj1;
//	p->Show();
//	p = &obj2;
//	p->Show();
//	p->Base::Show();
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;

class A
{
public:
	virtual void Show()const { cout << "基类A" << endl; }
};
class B :public A
{
public:
	void Show()const { cout << "派生类B" << endl; }
};

int main()
{
	B obj;
	A* p = &obj;
	p->Show();

	system("pause");
	return 0;
}