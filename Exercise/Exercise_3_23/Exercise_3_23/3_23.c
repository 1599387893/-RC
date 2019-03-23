//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//
////class Date
////{
////public:
////	Date(int year = 1900, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	Date(const Date& d)
////	{
////		_year = d._year;
////		_month = d._month;
////		_day = d._day;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////
////int main()
////{
////	Date d1;
////	Date d2(2019, 3, 23);
////	Date d3(d2);
////
////	return 0;
////}
//
////class String
////{
////public:
////	String(const char* str = "")
////	{
////		if (nullptr == str)
////			str = "";
////		_str = (char*)malloc(strlen(str) + 1);
////		strcpy(_str, str);
////	}
////	//String(const String& s)
////	//{
////	//	strcpy(_str, s._str);
////	//}
////	~String()
////	{
////		free(_str);
////		_str = nullptr;
////	}
//////private:
////	char* _str;
////};
////
////int main()
////{
////	String s1;
////	String s2("RC");
////	String s3(s2);
////
////	return 0;
////}
//
////class String
////{
////public:
////	String(const char* str = "jack")
////	{
////		if (str == nullptr)
////			str = "";
////		_str = (char*)malloc(strlen(str) + 1);
////		strcpy(_str, str);
////	}
////	~String()
////	{
////		cout << "~String()" << endl;
////		free(_str);
////		_str = nullptr;
////	}
////	void GetStr()
////	{
////		cout << _str << endl;
////	}
////private:
////	char* _str;
////};
////
////int main()
////{
////	String s1;
////	s1.GetStr();
////	String s2("RC");
////	s2.GetStr();
////
////	String s3(s2);
////	s3.GetStr();
////
////
////	return 0;
////}
//
//
////class Date
////{
////public:
////	Date(int year = 1900, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	Date(const Date& d)
////	{
////		_year = d._year;
////		_month = d._month;
////		_day = d._day;
////	}
////	/*bool operator== (const Date& d)
////	{
////		return _year == d._year &&
////			_month == d._month &&
////			_day == d._day;
////	}*/
//////private:
////	int _year;
////	int _month;
////	int _day;
////};
////bool operator== (const Date d1,const Date& d2)
////{
////	return d1._year == d2._year &&
////		d1._month == d2._month &&
////		d1._day == d2._day;
////}
////int main()
////{
////	Date d1;
////	Date d2(2019, 3, 23);
////	Date d3(d2);
////	cout << (d3 == d2) << endl;
////	cout << (d1 == d2) << endl;
////	return 0;
////}
//
////class Date
////{
////public:
////	Date(int year = 1900, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	Date(const Date& d)
////	{
////		_year = d._year;
////		_month = d._month;
////		_day = d._day;
////	}
////	bool operator== (const Date& d)
////	{
////	return _year == d._year &&
////	_month == d._month &&
////	_day == d._day;
////	}
////	Date& operator=(const Date& d)
////	{
////		if (this != &d)
////		{
////			_year = d._year;
////			_month = d._month;
////			_day = d._day;
////		}
////		return *this;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////int main()
////{
////	Date d1;
////	Date d2(2019, 3, 23);
////	//Date d3(d2);
////	Date d3;
////	d3 = d2;
////
////	return 0;
////}
//
//
////class String
////{
////public:
////	String(const char* str = "jack")
////	{
////		_str = (char*)malloc(strlen(str) + 1);
////		strcpy(_str, str);
////	}
////	~String()
////	{
////		cout << "~String()" << endl;
////		free(_str);
////	}
////private:
////	char* _str;
////};
////int main()
////{
////	String s1("hello");
////	String s2("world");
////
////	s1 = s2;
////
////	return 0;
////}
//
//
////class Date
////{
////public:
////	Date(int year = 1900, int month = 1, int day = 1)
////	{
////		_year = year;
////		_month = month;
////		_day = day;
////	}
////	Date(const Date& d)
////	{
////		_year = d._year;
////		_month = d._month;
////		_day = d._day;
////	}
////	bool operator== (const Date& d)
////	{
////	return _year == d._year &&
////	_month == d._month &&
////	_day == d._day;
////	}
////	Date& operator=(const Date& d)
////	{
////		if (this != &d)
////		{
////			_year = d._year;
////			_month = d._month;
////			_day = d._day;
////		}
////		return *this;
////	}
////	//前置++
////	Date& operator++()
////	{
////		_day++;
////		return *this;
////	}
////	//后置++
////	Date operator++(int)
////	{
////		Date temp(*this);
////		_day++;
////		return temp;
////	}
////private:
////	int _year;
////	int _month;
////	int _day;
////};
////int main()
////{
////	Date d1;
////	Date d2(2019, 3, 23);
////	//Date d3(d2);
////	Date d3(2000,1,1);
////	//d3 = d2 = d1;
////	d3++;
////	++d3;
////	return 0;
////}
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	bool operator== (const Date& d)
//	{
//		return _year == d._year &&
//			_month == d._month &&
//			_day == d._day;
//	}
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	//前置++
//	Date& operator++()
//	{
//		_day++;
//		return *this;
//	}
//	//后置++
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day++;
//		return temp;
//	}
//	//void Display()
//	//{
//	//	cout << "Display ()" << endl;
//	//	cout << "year:" << _year << endl;
//	//	cout << "month:" << _month << endl;
//	//	cout << "day:" << _day << endl;
//	//}
//	void Display() const
//	{
//		cout << "Display ()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl;
//	}
//	void D1() 
//	{
//		Display();
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	Date d2(2019, 3, 23);
//	Date d3(2000, 1, 1);
//	d3.D1();
//	return 0;
//}
//
//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
////快速排序
//int Partion(int* array, int left, int right)
//{
//	int begin = left;
//	int end = right-1;
//	int key = array[right - 1];//基准值
//	while (begin < end)
//	{
//		while (begin < end && array[begin] < key)
//			begin++;
//		while (begin < end && array[end] > key)
//			end--;
//		if (begin < end)
//			Swap(&array[begin], &array[end]);
//	}
//	if (array[begin] != array[right-1])
//	{
//		Swap(&array[begin], &key);
//	}
//	return begin;
//}
//void Qsort(int* array, int left, int right)
//{
//	int mid = 0;
//	if (left < right)
//	{
//		mid = Partion(array, left, right);
//		Qsort(array, 0, mid - 1);
//		Qsort(array, mid + 1, right);
//	}
//}
//
////int Partition(int* array, int left, int right)
////{
////	int key = array[right - 1];
////	int begin = left;
////	int end = right - 1;
////	while (begin < end)
////	{
////		//先从左向右找出比基准值大的元素
////		while (array[begin] < key)
////			begin++;
////		//从右向左找出比基准值小的元素
////		while (array[end]>key)
////			end--;
////		if (begin < end)
////			Swap(&(array[begin]), &(array[end]));
////	}
////	if (array[begin] != key)
////		Swap(&(array[begin]), &(array[right - 1]));
////		//Swap(&(array[begin]), &key);
////	return begin;
////
////}
////void QuickSort(int* array, int left, int right)
////{
////	int mid = 0;
////	if (left < right)
////	{
////		mid = Partition(array, left, right);
////		QuickSort(array, 0, mid - 1);
////		QuickSort(array, mid + 1, right);
////	}
////}
//int main()
//{
//	int array[] = { 0, 6, 8, 9, 1, 3, 4, 7, 2, 5 };
//	Qsort(array, 0, 10);
//
//	return 0;
//}

//二叉树创建
BTNode* CreaterBT(DataType* array, int size, int* index)
{
}
BTNode* CreaterBinTree(DataType* array,int size)
{
	int index = 0;
	BTNode* pRo0t = nullptr;
	pRoot = CreaterBT(array, size,&index);
}
//二叉树内容
//归并排序
