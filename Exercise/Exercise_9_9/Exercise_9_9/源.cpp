#include<iostream>
using namespace std;

template<class T>
bool isEqual(const T& left, const T& right)
{
	return (left == right);
}
template<class T>
bool isEqual(char*& left, char*& right)
{
	if (strcmp(left, right) > 0)
		return true;
	return false;
}
void Test()
{
	char* p1 = "hello";
	char* p2 = "world";

	if (isEqual(p1, p2))
		cout << p1 << endl;
	else
		cout << p2 << endl;
}


template<class T>
class Data
{
public:
	Data(){ cout << "Date<T1,T2>"; }
private:
	T1 _d1;
	T2 _d2;
};

////全特化
//template<>
//class Data<int,char>
//{
//public:
//	Data(){ cout << "Date<int,char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//}

//偏特化
template <class T1>
class Data<T1, int> {
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1 & _d1;
	const T2 & _d2;
};


//void test2()
//{
//	Data<double, int> d1; // 调用特化的int版本
//	Data<int, double> d2; // 调用基础的模板
//	Data<int *, int*> d3; // 调用特化的指针版本
//	Data<int&, int&> d4(); // 调用特化的指针版本
//}

int main()
{
	//Test();
	//TestVector();
	system("pause");
	return 0;
}