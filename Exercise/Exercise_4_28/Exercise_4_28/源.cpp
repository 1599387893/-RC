////////#include<iostream>
////////using namespace std;
////////
////////namespace RC
////////{
////////	template<class T, size_t N>
////////	class Array
////////	{
////////	public:
////////		T& operator[](size_t index)
////////		{
////////			assert(index < _size);
////////			return _arr[index];
////////		}
////////		const T& operator[](size_t index)const
////////		{
////////			assert(index < _size);
////////			return _arr[index];
////////		}
////////		size_t size()const
////////		{
////////			return _size;
////////		}
////////		bool empty()
////////		{
////////			return (_size == 0);
////////		}
////////	private:
////////		T _arr[N];
////////		size_t _size;
////////	};
////////} 
//////
//////
//////////模板的特化
//////////函数模板的特化
//////#include<iostream>
//////using namespace std;
//////
//////template<class T>
//////bool IsEuqual(T& left, T& right)
//////{
//////	return (left == right);
//////}
//////
//////template<>
//////bool IsEuqual<char*>(char*& left, char*& right)
//////{
//////	if (strcmp(left, right) > 0)
//////		return true;
//////	return false;
//////}
//////void Test()
//////{
//////	char* p1 = "hello";
//////	char* p2 = "world";
//////
//////	if (IsEuqual(p1, p2))
//////		cout << p1 << endl;
//////	else
//////		cout << p2 << endl;
//////}
//////
//////
//////int main()
//////{
//////	Test();
//////
//////	return 0;
//////}
//////
//////
////////类模板的特化
//////#include<iostream>
//////using namespace std;
//////
//////template<class T1,class T2>
//////class Data
//////{
//////public:
//////	Data()
//////	{
//////		cout << "Data(T1,T2)" << endl;
//////	}
//////private:
//////	T1 _d1;
//////	T2 _d2;
//////};
//////
////////全特化
//////template<>
//////class Data<int,char>
//////{
//////public:
//////	Data()
//////	{
//////		cout << "Data(int ,char)" << endl;
//////	}
//////private:
//////	int  _d1;
//////	char _d2;
//////};
////////偏特化
////////1.
//////template<class T1>
//////class Data < T1, int >
//////{
//////public:
//////	Data()
//////	{
//////		cout << "Data(T1,int)" << endl;
//////	}
//////private:
//////	T1 _d1;
//////	int _d2;
//////};
////////2.
//////template<class T1,classT2>
//////class Data<T1*,T2*>
//////{
//////public:
//////	Data()
//////	{
//////		cout << "Data(T1*,T2*)" << endl;
//////	}
//////private:
//////	T1 _d1;
//////	T2 _d2;
//////};
//////template<typename T1,typename T2>
//////class Data<T1&,T2&>
//////{
//////public:
//////	Data(const T1& d1, const T& d2) :_d1(d1), _d2(d2)
//////	{
//////		cout << "Data(T1&,T2&)" << endl;
//////	}
//////private:
//////	T1 & _d1;
//////	T2 & _d2;
//////};
////
//////#include<iostream>
//////#include<string>
//////using namespace std;
//////
////////针对内置类型的函数模板
//////template<class T>
//////void Copy1(T* dst, T* src, size_t N)
//////{
//////	memcpy(dst, src, sizeof(T)*N);
//////}
//////
////////针对自定义类型的函数模板
//////template<class T>
//////void Copy2(T* dst, T* rsc, size_t size)
//////{
//////	for (size_t i = 0; i < size; ++i)
//////		dst[i] = rsc[i];
//////}
//////
////////将拷贝和赋值的优点结合起来的函数模板
//////bool IsPODType(const char* strType)
//////{
//////	const char* TypeArr[] = { "int", "char", "long", "double", "float" };
//////	for (size_t i = 0; i < sizeof(TypeArr) / sizeof(TypeArr[0]); ++i)
//////		if (0 == strcmp(strType, TypeArr[i]))
//////			return true;
//////	return false;
//////}
//////template<class T>
//////void Copy3(T* dst, T* src, size_t N, bool IsPODType)
//////{
//////	if (IsPODType(typeid(T).name()))
//////		memcpy(dst, src, sizeof(T)*N);
//////	else
//////		for (size_t i = 0; i < N; ++i)
//////			dst[i] = src[i];
//////}
//////int main()
//////{
//////	string strarr1[3] = { "11", "22", "33" };
//////	string strarr2[3];
//////	//Copy1(strarr2, strarr1, 3);
//////	Copy2(strarr2, strarr1, 3);
//////	//Copy3(strarr1, strarr2, 3, IsPODType(typeid(strarr1).name()));
//////
//////	return 0;
//////}
//////类型萃取
////#include<iostream>
////#include<string>
////using namespace std;
////
////struct TrueType//代表内置类型
////{
////	static bool Get()
////	{
////		return true;
////	}
////};
////struct FalseType//代表自定义类型
////{
////	static bool Get()
////	{
////		return false;
////	}
////};
////
////template<class T>
////struct TypeTraits
////{
////	typedef FalseType IsPODType;
////};
////
//////模板特化
////template<>
////struct TypeTraits<char>
////{
////	typedef TrueType IsPODType;
////};
////template<>
////struct TypeTraits<short>
////{
////	typedef TrueType IsPODType;
////};
////template<>
////struct TypeTraits<int>
////{
////	typedef TrueType IsPODType;
////};
////template<>
////struct TypeTraits<long>
////{
////	typedef TrueType IsPODType;
////};
////template<>
////struct TypeTraits<double>
////{
////	typedef TrueType IsPODType;
////};
////template<>
////struct TypeTraits<float>
////{
////	typedef TrueType IsPODType;
////};
////
//////拷贝函数
////template<class T>
////void Copy(T* dst, T* src, size_t size)
////{
////	if (TypeTraits<T>::IsPODType::Get())
////		memcpy(dst, src, sizeof(T)*size);
////	else
////		for (size_t i = 0; i < size; ++i)
////			dst[i] = src[i];
////}
////
////int main()
////{
////	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
////	int a2[10];
////	Copy(a2, a1, 10);
////
////	string s1[] = { "1111", "2222", "3333", "4444" };
////	string s2[4];
////	Copy(s2, s1, 4);
////	return 0;
////}
//
////--------------------------------------------------------------------
//#include<iostream>
//#include<string>
//using namespace std;
//
////STL中的类型萃取例子
////代表内置类型
//struct _true_type{};
////代表自定义类型
//struct _false_type{};
//
////模板类
//template<class T>
//struct _type_traits
//{
//	typedef _false_type is_pod_type;
//};
//
////模板类的特化
//template< >
//struct _type_traits<char>
//{
//	typedef _true_type is_pod_type;
//};
//template< >
//struct _type_traits < short >
//{
//	typedef _true_type is_pod_type;
//};
//template< >
//struct _type_traits < int >
//{
//	typedef _true_type is_pod_type;
//};
//template< >
//struct _type_traits < float >
//{
//	typedef _true_type is_pod_type;
//};
//template< >
//struct _type_traits < double >
//{
//	typedef _true_type is_pod_type;
//};
//
////针对内置类型的拷贝函数
//template<class T>
//void _copy(T* dst, T* src, size_t size, _true_type)
//{
//	memcpy(dst, src, sizeof(T)*size);
//}
////针对自定义类型的拷贝函数
//template<class T>
//void _copy(T* dst, T* src, size_t size, _false_type)
//{
//	for (size_t i = 0; i < size; ++i)
//		dst[i] = src[i];
//}
//
//template<class T>
//void Copy(T* dst, T* src, size_t size)
//{
//		_copy(dst, src, size, _type_traits<T>::is_pod_type());
//}
//
//
//int main()
//{
//	int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int a2[10];
//	Copy(a2, a1, 10);
//	
//	string s1[] = { "1111", "2222", "3333", "4444" };
//	string s2[4];
//	Copy(s2, s1, 4);
//
//	return 0;
//}
////--------------------------------------------------------------------------
