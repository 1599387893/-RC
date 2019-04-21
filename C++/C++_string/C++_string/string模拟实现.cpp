#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

namespace RC
{
	class string
	{
		typedef char* iterator;
	public:
		//¹¹Ôìº¯Êý
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = _size + 1;
			_str = new char[_capacity];
			strcpy(_str, str);
		}
		string(const string& s)
			:_str(new char[s._capacity])
			, _capacity(s._capacity)
			, _size(s._size)
		{
			strcpy(_str, s._str);
		}
		string(size_t n, char c)
		{
			_size = n;
			_capacity = _size + 1;
			_str = new char[_capacity];
			memset(_str, c, n);
			_str[_size] = '\0';
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				_size = s._size;
				_capacity = s._capacity;
				_str = new char[_capacity];
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
				_size = 0;
				_capacity = 0;
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////
		//iterator
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		iterator rbegin()
		{
			return end();
		}
		iterator rend()
		{
			return begin();
		}
	    ///////////////////////////////////////////////////////////////////////////////////////
		//Capacity
		size_t Size()const
		{
			return _size;
		}
		size_t Capacity()const
		{
			return _capacity;
		}
		bool Empty()const
		{
			return (_size == 0);
		}
		void Resize(size_t newSize, char c = char())
		{
			if (newSize > _capacity)
			{

			}

		}
		void Reserve(size_t n = 0)
		{
			if (n > _capacity)
			{
				char* temp = new char[n];
				strcpy(temp, _str);

				delete[] _str;
				_str = temp;
				_capacity = n;
			}
		}
		void clear()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = 0;
				_capacity = 0;
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////
		//access
		const char& operator[](const size_t index)const
		{
			assert(index > _size);
			return _str[index];
		}
		const char& at(const size_t index)const
		{
			assert(index > _size);
			return _str[index];
		}
		////////////////////////////////////////////////////////////////////////////////////////
		//modify
		string& operator+=(const string& s);
		string& operator+=(const char* str);
		void PushBack(char c);
		string& Append(char c );
		string& Append(char* str);
		string& Append(size_t n, char c);
		void Swap(string& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
void Print(RC::string& s)
{
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}
void Teststring_string()
{
	RC::string s1;
	RC::string s2("Hello");
	RC::string s3(s2);
	RC::string s4(10, 'a');
	s1 = s4;
	Print(s1);
	s1 = s3;
	Print(s1);
}

int main()
{
	Teststring_string();

	return 0;
}