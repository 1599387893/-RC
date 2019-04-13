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

			}
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

}