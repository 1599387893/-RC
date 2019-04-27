////#include<iostream>
////using namespace std;
////
////namespace RC
////{
////	template<class T, size_t N>
////	class Array
////	{
////	public:
////		T& operator[](size_t index)
////		{
////			assert(index < _size);
////			return _arr[index];
////		}
////		const T& operator[](size_t index)const
////		{
////			assert(index < _size);
////			return _arr[index];
////		}
////		size_t size()const
////		{
////			return _size;
////		}
////		bool empty()
////		{
////			return (_size == 0);
////		}
////	private:
////		T _arr[N];
////		size_t _size;
////	};
////} 
//
//
//////模板的特化
//////函数模板的特化
////#include<iostream>
////using namespace std;
////
////template<class T>
////bool IsEuqual(T& left, T& right)
////{
////	return (left == right);
////}
////
////template<>
////bool IsEuqual<char*>(char*& left, char*& right)
////{
////	if (strcmp(left, right) > 0)
////		return true;
////	return false;
////}
////void Test()
////{
////	char* p1 = "hello";
////	char* p2 = "world";
////
////	if (IsEuqual(p1, p2))
////		cout << p1 << endl;
////	else
////		cout << p2 << endl;
////}
////
////
////int main()
////{
////	Test();
////
////	return 0;
////}
//
//
////类模板的特化
//#include<iostream>
//using namespace std;
//
//template<class T1,class T2>
//class Data
//{
//public:
//	Data()
//	{
//		cout << "Data(T1,T2)" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////全特化
//template<>
//class Data<int,char>
//{
//public:
//	Data()
//	{
//		cout << "Data(int ,char)" << endl;
//	}
//private:
//	int  _d1;
//	char _d2;
//};
////偏特化
////1.
//template<class T1>
//class Data < T1, int >
//{
//public:
//	Data()
//	{
//		cout << "Data(T1,int)" << endl;
//	}
//private:
//	T1 _d1;
//	int _d2;
//};
////2.
//template<class T1,classT2>
//class Data<T1*,T2*>
//{
//public:
//	Data()
//	{
//		cout << "Data(T1*,T2*)" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//template<typename T1,typename T2>
//class Data<T1&,T2&>
//{
//public:
//	Data(const T1& d1, const T& d2) :_d1(d1), _d2(d2)
//	{
//		cout << "Data(T1&,T2&)" << endl;
//	}
//private:
//	T1 & _d1;
//	T2 & _d2;
//};

//#include<iostream>
//#include<string>
//using namespace std;
//
//template<class T>
//void Copy1(T* dst, T* rsc, size_t N)
//{
//	memcpy(dst, src, sizeof(T)*N);
//}
//template<class T>
//void Copy2(T* dst, T* rsc, size_t size)
//{
//	for (size_t i; i < size; ++i)
//		dst[i] = rsc[i];
//}
//bool IsPODType(const char* strType)
//{
//	const char* TypeArr[] = { "int", "char", "long", "double", "float" };
//	for (size_t i = 0; i < sizeof(TypeArr) / sizeof(TypeArr[0]); ++i)
//		if (0 == strcmp(strType, TypeArr[i]))
//			return true;
//	return false;
//}
//template<class T>
//void Copy3(T* dst, T* src, size_t N, bool IsPODType)
//{
//	if (IsPODType(typeid(T).name()))
//		memcpy(dst, src, sizeof(T)*N);
//	else
//		for (size_t i = 0; i < n; ++i)
//			dst[i] = src[i];
//}
//int main()
//{
//	string strarr1[3] = { "11", "22", "33" };
//	string strarr2[3];
//	Copy3(strarr1, strarr2,3,IsPODType);
//
//	return 0;
//}
//类型萃取
