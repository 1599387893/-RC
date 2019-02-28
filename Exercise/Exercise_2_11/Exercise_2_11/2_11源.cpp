//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(){ cout << "构造A" << endl; }		// 构造函数
//	~A(){ cout << "析构A" << endl; }		// 析构函数
//};
//
//class B : public A
//{
//public:
//	B(){ cout << "构造B" << endl; }		// 构造函数
//	~B(){ cout << "析构B" << endl; }		// 析构函数
//};
//
//class C : public B
//{
//public:
//	C(){ cout << "构造C" << endl; }		// 构造函数
//	~C(){ cout << "析构C" << endl; }		// 析构函数
//};
//
//int main()
//{
//	C obj;	// 定义对象
//
//	return 0;                    			// 返回值0, 返回操作系统
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//protected:
//	int a;
//public:
//	A(int x) :a(x){};
//	void show ()const{ cout << a << endl; }
//};
//
//class B 
//{
//protected:
//	int b;
//public:
//	B(int x):b(x){ }
//	void show()const { cout << b << endl; }
//};
//
//class C :public A, public B
//{
//public:
//	C(int x, int y) :A(x), B(y){};
//	void show()const { cout << a << "," << b << endl; }
//};
//
//int main()
//{
//	C obj(1,2);
//	obj.show();
//	obj.B::show();
//	obj.A::show();
//	system("pause");
//	return 0;
//}

//#include <iostream>						// 预处理命令
//using namespace std;						// 使用标准命名空间std
//
//class A
//{
//protected:
//	int a;									// 数据成员
//
//public:
//	A(int x) : a(x){ }							// 构造函数
//	void Show() const{ cout << a << endl; }	// 显示a之值
//};
//
//class B
//{
//protected:
//	int b;								// 数据成员
//
//public:
//	B(int x) : b(x){ }						// 构造函数
//	void Show() const{ cout << b << endl; }	// 显示a与b之值
//};
//
//class C : public A, public B
//{
//public:
//	C(int x, int y) : A(x), B(y){ }				// 构造函数
//	void Show() const						// 显示b之值
//	{
//		cout << a << "," << b << endl;
//	}
//};
//
//int main()
//{
//	C obj(1, 2);						// 定义对象
//	obj.Show();							// 显示相关信息
//	obj.A::Show();						// 显示相关信息
//	obj.B::Show();						// 显示相关信息
//	system("pause");
//	return 0;                    			// 返回值0, 返回操作系统
//}
//

//
//#include<iostream>
//using namespace std;
//class A
//{
//private:
//	int a;
//public:
//	A(int x) :a(x){}
//	void show() const { cout << "a:" << a << endl; };
//};
//
//class B:public A
//{
//protected:
//	int b;
//public:
//	B(int x, int y) :A(x), b(y){}
//	void show() const 
//	{ 
//		A::show(); 
//		cout << "b:" << b << endl;
//	}
//};
//
//int main()
//{
//	B obj(1, 2);
//	obj.show();
//
//	system("PAUSE");
//	return 0;
//}



//#include <iostream>					// 预处理命令
//using namespace std;					// 使用标准命名空间std
//class A
//{
//private:
//	int a;							// 数据成员
//
//public:
//	A(int x) :a(x)  { }				// 构造函数
//	void Show() const				// 显示a之值
//	{
//		cout << "a:" << a << endl;
//	}
//};
//
//class B : public A
//{
//protected:
//	int b;							// 数据成员
//
//public:
//	B(int x, int y) : A(x), b(y){ }		// 构造函数
//
//	void Show() const					// 显示相关信息
//	{
//		A::Show();				// 调用基类A的成员函数Show()
//		cout << "b:" << b << endl;	// 显示b之值
//	}
//};
//
//int main()
//{
//	B obj(5, 18);					// 定义对象
//	obj.Show();						// 显示相关信息
//
//	system("PAUSE");            		// 调用库函数system( )，输出系统提示信息
//	return 0;                    		// 返回值0, 返回操作系统
//}


//#include<iostream>
//using namespace std;
//
//class Base
//{
//private:
//	int m;
//public:
//	Base(int a) :m(a){ }
//	Base(const Base &copy) :m(copy.m){ }
//	void show() const
//	{
//		cout << "m:" << m << endl;
//	}
//};
//class Derived :private Base
//{
//protected:
//	int n;
//public:
//	Derived(int a, int b) :Base(a){ n = b; }
//	void show() const
//	{
//		Base::show();
//		cout << "n:" << n << endl;
//	}
//};
//
//int main()
//{
//	Derived obj(1,2);
//	obj.show();
//
//	system("PAUSE");
//	return 0;
//}