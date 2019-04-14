#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

namespace bit
{
	class string
	{
	public:
		string(const char* s = "")
		{
			if (nullptr == s)
				s = "";
			_size = strlen(s);
			_capacity = _size;
			_str = new char[_capacity+1];
			strcpy(_str, s);
		}
		string(const string& s)
			:_str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)	
		{
			strcpy(_str, s._str);
		}
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

void Teststring()
{
	bit::string s1;
	bit::string s2("hello");
	bit::string s3(s2);
	s1 = s2;
}

int main()
{
	Teststring();

	return 0;
}