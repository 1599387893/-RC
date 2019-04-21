//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//using namespace std;
//
//
////第一种模拟方法：深拷贝(传统)
//namespace bit1
//{
//	class string
//	{
//	public:
//		//构造函数
//		string(const char* s = "") 
//		{
//			if (nullptr == s)
//				s = "";
//
//			_str = new char[strlen(s) + 1];
//			strcpy(_str, s);
//		}
//		//拷贝构造函数
//		string(const string& s)
//			:_str(new char[strlen(s._str)+1])
//		{
//			strcpy(_str, s._str);
//		}
//		//赋值运算符重载函数
//		string& operator=(const string& s)
//		{
//			if (&s != this)
//			{
//				char* ptr = new char[strlen(s._str)+1];
//				strcpy(ptr, s._str);
//
//				delete[] _str;
//				_str = ptr;
//			}
//			return *this;
//		}
//		//析构函数
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//			}
//		}
//	private:
//		char* _str;
//	};
//
//}
//void Teststring1()
//{
//	bit1::string s1;
//	bit1::string s2("hello");
//	bit1::string s3(s2);
//	s1 = s2;
//
//}
//
////第二种模拟方法：深拷贝（现代）
//namespace bit2
//{
//	class string
//	{
//	public:
//		string(const char* str = "")
//		{
//			if (str == nullptr)
//				str = "";
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		//拷贝构造函数
//		string(const string& s) :_str(nullptr)
//		{
//			string temp(s._str);
//			swap(_str, temp._str);
//		}
//		//赋值运算符重载
//		string& operator=(string s)// s对象此时为临时拷贝的一份资源，函数返回时会析构掉
//		{
//			if (this != &s)
//			{
//				swap(_str, s._str);
//			}
//			return *this;
//		}
//		~string()
//		{
//			if (_str)
//			{
//				delete[] _str;
//				_str = nullptr;
//			}
//		}
//
//	private:
//		char* _str;
//	};
//}
//void Teststring2()
//{
//	bit2::string s4(nullptr);
//	bit2::string s5("hello");
//	bit2::string s6(s5);
//	s4 = s5;
//}
//
////第三种模拟方法：写时拷贝 ==（浅拷贝+计数引用+修改对象时分离对象）
//
////需要特别考虑修改对象内容时的情况（s1[0] = 'A'）
//namespace bit3
//{
//	class string
//	{
//	public:
//		//构造函数
//		string(const char* str = "")
//		{
//			if (str == nullptr)
//				str = "";
//
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//			_pCount = new int(1);
//		}
//		//拷贝构造函数
//		string(const string& s)
//			:_str(s._str)
//			, _pCount(s._pCount)
//		{
//			strcpy(_str, s._str);
//			memcpy(_pCount, s._pCount, sizeof(_pCount));
//			++(*_pCount);
//		}
//		//赋值运算符的重载
//		string& operator=(const string& s)
//		{
//			if (this != &s)
//			{
//				Release();
//				_str = s._str;
//				_pCount = s._pCount;
//				++(*_pCount);
//			}
//			return *this;
//		}
//		//析构函数
//		~string()
//		{
//			Release();
//			//保证即使不是最后一个共用对象也指向空
//			_str = nullptr;
//			_pCount = nullptr;
//		}
//		char& operator[](size_t index)
//		{
//			//在修改对象内容时，要防止一改全改的情况，所以，此时要分离对象
//			if (*_pCount > 1)
//			{
//				string temp(_str);
//				Swap(temp);
//				//此时对象已被分离，temp替代对象的原位置，在函数返回时，会调用temp的析构函数，将计数器减1
//			}
//			return _str[index];
//		}
//		void Swap(string& temp)
//		{
//			swap(_str, temp._str);
//			swap(_str, temp._str);
//		}
//		const char& operator[](size_t index)const
//		{
//			return _str[index];
//		}
//		
//	private:
//		//判断是否为对象独占资源，若是销毁资源，若不是，不做处理
//		void Release()
//		{
//			//该方式会有线程安全问题
//			if (--(*_pCount) == 0)
//			{
//				delete[] _str;
//				delete _pCount;
//				_str = nullptr;
//				_pCount = nullptr;
//			}
//		}
//	private:
//		char* _str;
//		int* _pCount;
//	};
//}
//void Teststring3()
//{
//	bit3::string s1;
//	bit3::string s2(s1);
//	bit3::string s3("hello");
//	bit3::string s4(s3);
//	s1 = s3;
//}
//
//int main()
//{
//	Teststring1();
//	Teststring2();
//	Teststring3();
//
//	return 0;
//}