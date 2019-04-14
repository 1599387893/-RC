//#include<iostream>
//using namespace std;
//
//#if 0
//int main()
//{
//	char* p = "hello";
//	p[0] = 'H';
////	cout << p << endl;
////
////	return 0;
////}
////#endif
////
//
//#include<iostream>
//#include<string>
//using namespace std;
//
////1.0
//bool isPalindrome1(string s)
//{
//
//	if (s.empty())
//		return true;
//
//	int begin = 0;
//	int end = s.size() - 1;
//
//	while (begin < end)
//	{
//		if (s[begin]<30 || (s[begin]>57 && s[begin]<65) || (s[begin]<97 && s[begin]>90) || (s[begin]>122))
//			begin++;
//		if (s[end]<30 || (s[end]>57 && s[end]<65) || (s[end]<97 && s[end]>90) || (s[end]>122))
//			end--;
//
//		if (s[begin] != s[end])
//			return false;
//
//		begin++;
//		end--;
//	}
//	return true;
//}
////2.0
//bool isPalindrome2(string s)
//{
//	if (s.empty())
//		return true;
//
//	int begin = 0;
//	int end = s.size() - 1;
//
//	while (begin < end)
//	{
//		if (s[begin] + 32) % 32 == (s[end] + 32) % 32))
//
//		begin++;
//		end--;
//	}
//	return true;
//}
//
//int main()
//{
//	string s;
//	getline(cin, s);
//
//	cout<<isPalindrome1(s)<<endl;
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;


//传统方法
#if 0
namespace bit
{
	class string
	{
	public:
		string(const char* s = "")
		{
			if (s== nullptr)
				s = "";

			_size = strlen(s);
			_capacity = _size + 1;
			_str = new char[_capacity];
			strcpy(_str, s);
			_str[_size] = '\0';
		}
		//拷贝构造1
		//string(const string& s)
		//{
		//	if (s._str)
		//	{
		//		_size = s._size;
		//		_capacity = s._capacity;
		//		_str = new char[_capacity];
		//		strcpy(_str, s._str);
		//	}
		//}
		//拷贝构造2
		string(const string& s) :_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		string& operator=(const string& s)
		{
			if (&s != this)
			{
				char* ptr = new char[s._capacity];
				strcpy(ptr, s._str);

				delete[] _str;
				_str = ptr;
				_size = s._size;
				_capacity = s._capacity;
				
			}
			return *this;
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
void Teststring()
{
	bit::string s1;
	bit::string s2("hello");
	bit::string s3(nullptr);
	bit::string s4(s2);
	s1 = s4;

}

int main()
{
	Teststring();

	return 0;
}
#endif

//现代版（较为简洁）
namespace bit
{
	class string
	{
	public:
		string(const char* s = "")
		{
			if (s == nullptr)
				s = "";

			_size = strlen(s);
			_capacity = _size + 1;
			_str = new char[_capacity];
			strcpy(_str, s);
			_str[_size] = '\0';
		}
		string(const string& s) :_str(nullptr)
		{
			string strTemp(s._str);
			swap(_str, strTemp._str);
		}

		//1.0
		//string& operator=(const string& s)
		//{
		//	if (&s != this)
		//	{
		//		string strTemp(s._str);
		//		swap(_str, strTemp._str);
		//	}
		//	return *this;
		//}
		//2.0
		//string& operator=(const string& s)
		//{
		//	string strTemp(s);
		//	swap(_str, strTemp._str);
		//	return *this;
		//}
		//3.0
		string& operator=(string s)
		{
			swap(_str, s._str);
			return *this;
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}


