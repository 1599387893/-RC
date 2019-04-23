#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;

//传统模式
namespace RC
{
	class string
	{
	public:
		string(char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s) :_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}

namespace RC1
{
	class string
	{
	public:
		string(char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s) :_str(nullptr)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			swap(_str, temp);
		}
		string& operator=(string s)
		{
			if (this != &s)
			{
				swap(_str, s._str);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;
	};
}
int main()
{
	RC1::string s1;
	RC1::string s2(nullptr);
	RC1::string s3("hello");
	RC1::string s4(s3);
	s1 = s4;

	return 0;
}