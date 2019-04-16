#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//第一种模拟方法：深拷贝(传统)
namespace bit1
{
	class string
	{
	public:
		//构造函数
		string(const char* s = "") 
		{
			if (nullptr == s)
				s = "";

			_str = new char[strlen(s) + 1];
			strcpy(_str, s);
			_size = strlen(s);
			_capacity = _size;
		}
		//拷贝构造函数
		string(const string& s)
			:_str(new char[s._capacity])
			, _size(s._size)
			, _capacity(s._capacity)	
		{
			strcpy(_str, s._str);
		}
		//赋值运算符重载函数
		string& operator=(const string& s)
		{
			if (&s != this)
			{
				char* ptr = new char[s._capacity];
				strcpy(ptr, s._str);

				delete[] _str;
				_str = ptr;
				_capacity = s._capacity;
				_size = s._size;
			}
			return *this;
		}
		//析构函数
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_capacity = 0;
				_size = 0;
			}
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

}
void Teststring1()
{
	bit1::string s1;
	bit1::string s2("hello");
	bit1::string s3(s2);
	s1 = s2;

}

//第二种模拟方法：深拷贝（现代）
namespace bit2
{
	class string
	{
	public:
		//构造函数
		string(const char* s = "")
		{
			if (nullptr == s)
				s = "";

			_str = new char[strlen(s) + 1];
			strcpy(_str, s);
			_size = strlen(s);
			_capacity = _size + 1;
		}
		//拷贝构造函数1.0
		string(const string& s) :_str(nullptr)
		{
			string temp(s._str);
			swap(_str, temp._str);//交换之后临时变量temp会带着旧的_str执行析构函数
			_capacity = s._capacity;
			_size = s._size;
		}
		//赋值运算符的重载函数
		string& operator=(string s)
		{
			swap(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}
		//析构函数
		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
void Teststring2()
{
	bit2::string s4(nullptr);
	bit2::string s5("hello");
	bit2::string s6(s5);
	s4 = s5;
}

#if 0
//第三种模拟方法：写时拷贝
namespace bit3
{
	class string
	{
	public:
		string(const char* str = "") 
		{
			if (nullptr == str)
				str = "";

			_str = new char[strlen(str) + 1];
			_size = strlen(str);
			_capacity = _size + 1;
		}
		string(const string& s)
		{

		}
		string& operator=(const string& s)
		{

		}
		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
void Teststring3()
{
	bit3::string s1(nullptr);
	bit3::string s2("hello");
	bit3::string s3(s2);
	s1 = s3;
}
#endif

//int main()
//{
//	//Teststring1();
//	Teststring2();
//
//	return 0;
//}