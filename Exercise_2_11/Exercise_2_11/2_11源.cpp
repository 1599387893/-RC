//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(){ cout << "����A" << endl; }		// ���캯��
//	~A(){ cout << "����A" << endl; }		// ��������
//};
//
//class B : public A
//{
//public:
//	B(){ cout << "����B" << endl; }		// ���캯��
//	~B(){ cout << "����B" << endl; }		// ��������
//};
//
//class C : public B
//{
//public:
//	C(){ cout << "����C" << endl; }		// ���캯��
//	~C(){ cout << "����C" << endl; }		// ��������
//};
//
//int main()
//{
//	C obj;	// �������
//
//	return 0;                    			// ����ֵ0, ���ز���ϵͳ
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

//#include <iostream>						// Ԥ��������
//using namespace std;						// ʹ�ñ�׼�����ռ�std
//
//class A
//{
//protected:
//	int a;									// ���ݳ�Ա
//
//public:
//	A(int x) : a(x){ }							// ���캯��
//	void Show() const{ cout << a << endl; }	// ��ʾaֵ֮
//};
//
//class B
//{
//protected:
//	int b;								// ���ݳ�Ա
//
//public:
//	B(int x) : b(x){ }						// ���캯��
//	void Show() const{ cout << b << endl; }	// ��ʾa��bֵ֮
//};
//
//class C : public A, public B
//{
//public:
//	C(int x, int y) : A(x), B(y){ }				// ���캯��
//	void Show() const						// ��ʾbֵ֮
//	{
//		cout << a << "," << b << endl;
//	}
//};
//
//int main()
//{
//	C obj(1, 2);						// �������
//	obj.Show();							// ��ʾ�����Ϣ
//	obj.A::Show();						// ��ʾ�����Ϣ
//	obj.B::Show();						// ��ʾ�����Ϣ
//	system("pause");
//	return 0;                    			// ����ֵ0, ���ز���ϵͳ
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



//#include <iostream>					// Ԥ��������
//using namespace std;					// ʹ�ñ�׼�����ռ�std
//class A
//{
//private:
//	int a;							// ���ݳ�Ա
//
//public:
//	A(int x) :a(x)  { }				// ���캯��
//	void Show() const				// ��ʾaֵ֮
//	{
//		cout << "a:" << a << endl;
//	}
//};
//
//class B : public A
//{
//protected:
//	int b;							// ���ݳ�Ա
//
//public:
//	B(int x, int y) : A(x), b(y){ }		// ���캯��
//
//	void Show() const					// ��ʾ�����Ϣ
//	{
//		A::Show();				// ���û���A�ĳ�Ա����Show()
//		cout << "b:" << b << endl;	// ��ʾbֵ֮
//	}
//};
//
//int main()
//{
//	B obj(5, 18);					// �������
//	obj.Show();						// ��ʾ�����Ϣ
//
//	system("PAUSE");            		// ���ÿ⺯��system( )�����ϵͳ��ʾ��Ϣ
//	return 0;                    		// ����ֵ0, ���ز���ϵͳ
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