//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//////深拷贝------现代方法
////namespace bit
////{
////	class string
////	{
////	public:
////		string(const char* str = "")
////		{
////			if (str == nullptr)
////				str = "";
////
////			_str = new char[strlen(str) + 1];
////			strcpy(_str, str);
////		}
////		//拷贝构造函数
////		string(const string& s) :_str(nullptr)
////		{
////			string temp(s._str);
////			swap(_str, temp._str);
////		}
////		//赋值运算符重载
////		string& operator=(string s)
////		{
////			if (this != &s)
////			{
////				swap(_str, s._str);
////			}
////			return *this;
////		}
////		~string()
////		{
////			if (_str)
////			{
////				delete[] _str;
////				_str = nullptr;
////			}
////		}
////
////	private:
////		char* _str;
////	};
////}
////
////void Teststring()
////{
////	bit::string s1("hello");
////	bit::string s2(s1);
////	bit::string s3("world");
////	bit::string s4(s3);
////	s1 = s3;
////}
////int main()
////{
////	Teststring();
////
////	return 0;
////}
//
//
//
//////深拷贝----传统方法
////namespace bit1
////{
////	class string
////	{
////	public:
////		string(const char* str = "")
////		{
////			if (nullptr == str)
////				str = "";
////			_str = new char[strlen(str) + 1];
////			strcpy(_str, str);
////		}
////		//拷贝
////		string(const string& s)
////		{
////			_str = new char[strlen(s._str) + 1];
////			strcpy(_str, s._str);
////		}
////		string& operator=(const string& s)
////		{
////			if (this != &s)
////			{
////				char* ptr = new char[strlen(s._str) + 1];
////				strcpy(_str, s._str);
////
////				delete[] _str;
////				_str = _str;
////			}
////			return *this;
////		}
////		//赋值运算符重载
////		~string()
////		{
////			delete[] _str;
////			_str = nullptr;
////		}
////	private:
////		char* _str;
////	};
////}
////
////void Teststring()
////{
////	bit1::string s1("hello");
////	bit1::string s2(s1);
////	bit1::string s3("world");
////	bit1::string s4(s3);
////	s1 = s3;
////}
////int main()
////{
////	Teststring();
////
////	return 0;
////}
//
//
//
////写时拷贝
////namespace bit
////{
////	class string
////	{
////	public:
////		//构造函数
////		string(const char* str = "")
////		{
////			if (str == nullptr)
////				str = "";
////
////			_str = new char[strlen(str) + 1];
////			strcpy(_str, str);
////			_pCount = new int(1);
////		}
////		//拷贝构造函数
////		string(const string& s)
////			:_str(s._str)
////			, _pCount(s._pCount)
////		{
////			strcpy(_str, s._str);
////			memcpy(_pCount, s._pCount,sizeof(_pCount));
////			++(*_pCount);
////		}
////		//赋值运算符的重载
////		string& operator=(const string& s)
////		{
////			if (this != &s)
////			{
////				Release();
////				_str = s._str;
////				_pCount = s._pCount;
////				++(*_pCount);
////			}
////			return *this;
////		}
////		//析构函数
////		~string()
////		{
////			Release();
////			_str = nullptr;
////			_pCount = nullptr;
////		}
////		char& operator[](size_t index)
////		{
////			if ((*_pCount) > 1)
////			{
////				string temp(_str);
////				Swap(temp);
////			}
////			return _str[index];
////		}
////		const char& operator[](size_t index)const
////		{
////			return _str[index];
////		}
////		void Swap(string& temp)
////		{
////			swap(_str, temp._str);
////			swap(_pCount, temp._pCount);
////		}
////	private:
////		void Release()
////		{
////			if (--(*_pCount) == 0)
////			{
////				delete[] _str;
////				delete _pCount;
////				_str = nullptr;
////				_pCount = nullptr;
////			}
////		}
////	private:
////		char* _str;
////		int* _pCount;
////	};
////}
////
////void Teststring()
////{
////	bit::string s1;
////	bit::string s2(s1);
////	bit::string s3("hello");
////	bit::string s4(s3);
////	s1 = s3;
////
////	s1[0] = 'W';
////}
////int main()
////{
////	Teststring();
////
////	return 0;
////}
//
//
//
//int main()
//{
//	 
//}
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//
//void PrintVector(const vector<int>& v)
//{
//	vector<int>::const_iterator it = v.cbegin();
//	while (it != v.cend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	it = v.begin();
//	while (it != v.end())
//	{
//		*it *= 2;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	vector<int>::reverse_iterator rit = v.rbegin();
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//
//	PrintVector(v);
//	
//	return 0;
//}

//空间增长问题
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	size_t sz;
//	vector<int> foo;
//	sz = foo.capacity();
//	cout << "making foo grow:\n";
//
//	for (int i = 0; i < 10; i++)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity())
//		{
//			sz = foo.capacity();
//			cout << "capacity changed:" << sz << '\n';
//		}
//	}
//}

//#include<iostream>
//#include<vector>
//using namespace std;

//int main()
//{
//	size_t sz;
//	vector<int> foo;
//	sz = foo.capacity();
//	cout << "make capacity grow:\n";
//	for (int i = 0; i < 100; ++i)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity())
//			cout << "capacity chagned" << endl;
//	}
//	
//	vector<int> bar;
//	bar.reserve(100);
//	for (int i = 0; i < 100; ++i)
//	{
//		bar.push_back(i);
//		if (sz != bar.capacity())
//			cout << "capacity chagned" << endl;
//	}
//
//
//	return 0;
//}

//int main()
//{
//	vector<int> my;
//	for (int i = 1; i < 10; ++i)
//		my.push_back(i);
//	my.resize(5);
//	my.resize(8, 100);
//	my.resize(12);
//
//}


//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//}