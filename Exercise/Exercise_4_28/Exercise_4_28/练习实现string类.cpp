#include<iostream>
using namespace std;

namespace RC
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		//¹¹Ôìº¯Êý
		string(const char* str = "")
		{
			if (nullptr == str)
				str = "";
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		string(size_t n, const char c)
		{
			_str = new char[n + 1];
			memset(_str, c, n);
			_size = n;
			_capacity = _size;
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* temp = new char[s._size + 1];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
				_size = s._size;
				_capacity = s._capacity;
			}
		}
		//access
		char* operator[](size_t index);
		const char* operator[](size_t index)const;
		char* at(size_t index);
		const char* at(size_t index)const;
		//capacity
		size_t size();
		size_t capacity();
		bool empty();
		void resize(size_t newSize, char c);
		void reserve(size_t newCapacity);
		//modeify
		void PushBack(char c);
		void append(size_t n,char c);
		void append(char* str);
		char* c_str();
		//iterator
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}