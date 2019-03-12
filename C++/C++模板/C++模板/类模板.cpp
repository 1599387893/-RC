//#include<iostream>
//using namespace std;
//
//class A
//{
//private:
//	int a;
//public:
//	A(int x) :a(x){}
//	virtual void show()const{ cout << a ; }
//};
//
//template <class T>
//class B :public A
//{
//private:
//	T b;
//public:
//	B(int x, T y) :A(x), b(y){}
//		void show()const
//		{
//			A::show();
//			cout << b << endl;
//		}
//};
//
//int main()
//{
//	B<char*> obj(8, " is my happy digit!");
//	obj.show();
//	system("pause");
//	return 0;
//}