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
		//构造函数
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
			if (newSize > _size)
			{
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				Append((newSize - _size), c);
			}
			_size = newSize;

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
		char& operator[](const size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](const size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		char& at(const size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& at(const size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		////////////////////////////////////////////////////////////////////////////////////////
		//modifiers
		string& operator+=(const string& s)
		{
			Append(s._str);
			return *this;
		}
		string& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}
		void PushBack(char c)
		{
			if (_size == _capacity)
				Reserve(2 * _capacity);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		string& Append(const char* str)
		{
			while (*str != '\0')
			{
				PushBack(*str);
				++str;
			}	
			return *this;
		}
		string& Append(size_t n, char c)
		{
			for (n; n > 0; n--)
				PushBack(c);
			return *this;
		}
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
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
void Teststring_capacity()
{
	RC::string s1;
	RC::string s2("Hello");
	cout <<"s1:"<< s1.Empty() << endl;;
	cout << "s2:" << s2.Empty() << endl;
	Print(s2);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;
	
	/*s2.Resize(10,'A');
	Print(s2);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;*/
	
	s2.Reserve(10);
	Print(s2);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;

	s2.clear();
	Print(s2);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;
}
void Teststring_access()
{
	RC::string s1("hello");
	RC::string s2("world");
	cout << s1[0] << endl;
	s1[0] = 'H';
	cout << s1[0] << endl;
	cout << s2.at(0) << endl;
	s2.at(0) = 'H';
	cout << s2.at(0)<< endl;
}
void Teststring_modifiers()
{
	RC::string s1;
	RC::string s2(" world");
	s1.PushBack('A');
	//问题在扩容这里
	s1.Swap(s2);

}

int main()
{
	//Teststring_string();
	//Teststring_capacity();
	//Teststring_access();
	Teststring_modifiers();
	return 0;
}