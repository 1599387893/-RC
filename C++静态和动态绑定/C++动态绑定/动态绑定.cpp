//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void display()const { cout << "基类Base" << endl; }
//};
//
//class FristA:public Base
//{
//public:
//	void display() const { cout << "派生类FristA" << endl; }
//};
//
//class SceondB :public Base
//{
//public:
//	void display()const { cout << "派生类SceondB" << endl; }
//};
//
//int main()
//{
//	Base obj1;
//	FristA obj2;
//	SceondB obj3;
//
//	Base* ptr;
//	ptr = &obj1;
//	ptr->display();
//
//	ptr = &obj2;
//	ptr->display();
//	
//	ptr = &obj3;
//	ptr->display();
//	system("pause");
//	return 0;
//}