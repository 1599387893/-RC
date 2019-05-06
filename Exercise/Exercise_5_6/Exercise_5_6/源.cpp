////#include<iostream>
////#include<deque>
////using namespace std;
////
////template<class T>
////void PrintDeque(const deque<T>& d)
////{
////	for (const auto& e : d)
////		cout << e << " ";
////	cout << endl;
////}
////
////void TestDeque1()
////{
////	deque<int> d1;
////	deque<int> d2(10, 5);
////	PrintDeque(d1);
////	PrintDeque(d2);
////
////	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
////	deque<int> d3(array, array + sizeof(array) / sizeof(array[0]));
////	PrintDeque(d3);
////
////	deque<int> d4(d3);
////	PrintDeque(d4);
////
////	d1 = d4;
////	PrintDeque(d1);
////
////}
////void TestDeque2()
////{
////	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
////	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
////
////	for (auto it = d.begin(); it != d.end(); ++it)
////		cout << *it << " ";
////	cout << endl;
////
////	auto cit = d.cbegin();
////	while (cit != d.cend())
////	{
////		cout << *cit << " ";
////		cit++;
////	}
////	cout << endl;
////
////	auto rit = d.rbegin();
////	while (rit != d.rend())
////	{
////		cout << *rit << " ";
////		rit++;
////	}
////	cout << endl;
////
////}
////void TestDeque3()
////{
////	deque<int> d{ 3, 4, 5 };
////	PrintDeque(d);
////
////	d.push_back(6);
////	d.push_front(2);
////	PrintDeque(d);
////
////	cout << d.size() << endl;
////	cout << d.front() << endl;
////	cout << d.back() << endl;
////
////	d.emplace_back(7);
////	d.emplace_front(1);
////	PrintDeque(d);
////
////	d.insert(d.begin(), 0);
////	d.insert(d.end(), 8);
////	PrintDeque(d);
////
////	d.erase(d.end()-1);
////	PrintDeque(d);
////
////
////	d.clear();
////	cout << d.size() << endl;
////
////}
////int main()
////{
////	//TestDeque1();
////	//TestDeque2();
////	TestDeque3();
////	return 0;
////}
////
////#include<iostream>
////#include<deque>
////#include<algorithm>
////using namespace std;
////
////
////template<class T>
////void PrintDeque(const deque<T>& d)
////{
////	for (const auto& e : d)
////		cout << e << " ";
////	cout << endl;
////}
////void TestDequeSort()
////{
////	int array[] = { 0, 9, 4, 3, 5, 1, 8, 2, 6, 7 };
////	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
////	PrintDeque(d);
////	sort(d.begin(), d.end());
////	PrintDeque(d);
////	
////}
////
////int main()
////{
////	TestDequeSort();
////
////	return 0;
////}
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<functional>
//
//
//void TestPriorityQueue()
//{
//	vector<int> v{ 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
//	priority_queue<int> q;
//	for ()
//}


////¿‡–Õ›Õ»°
//#include<iostream>
//using namespace std;
//
//struct TrueType
//{
//	static bool Get()
//	{
//		return true;
//	}
//};
//struct FalseType
//{
//	static bool Get()
//	{
//		return false;
//	}
//};
//
//template<class T>
//struct TypeTraits
//{
//	typedef FalseType IsPODType;
//};
//
//template<>
//struct TypeTraits < char >
//{
//	typedef TrueType IsPOFType;
//};
//template<>
//struct TypeTraits < short >
//{
//	typedef TrueType IsPODType;
//};
//template<>
//struct TypeTraits < int >
//{
//	typedef TrueType IsPODType;
//};
//
//template<class T>
//void Copy(T* dst, T* rst, size_t size)
//{
//	if (TypeTraits<T>::IsPODType::Get())
//		memcpy(dst, src, sizeof(T)*size);
//	else
//		for (size_t i = 0; i < size; ++i)
//			dst[i] = src[i];
//}

#include<iostream>
using namespace std;

int globalVar = 1;
static int staticGlobalVar = 1;

void Test()
{
	static int staticVar = 1;
	
	int localVar = 1;
	int num[10] = { 0 };
	char array[] = "abcd";
	char* parr = "efgh";

	int* ptr1 = (int*)malloc(sizeof(int) * 10);
	int* ptr2 = (int*)calloc(sizeof(int) * 10);
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 10);

	free(ptr3);
	free(ptr1);
}