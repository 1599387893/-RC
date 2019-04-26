#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

namespace RC
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		//构造函数
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = _size+1;
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
		string(const char* pstr, size_t n)
		{
			size_t length = strlen(pstr);
			_size = length > n ? n : length;
			_capacity = _size + 1;
			_str = new char[_capacity];
			memcpy(_str, pstr, n);
			_str[_size] = '\0';
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
		void Resize(size_t newSize, char c = char())//将有效元素个数修改到newSize;
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[_size] = '\0';
		}
		void Reserve(size_t newCapacity = 0)//预留空间，当新容量大于原容量时才会扩容
		{
			if (newCapacity > _capacity)
			{
				char* temp = new char[newCapacity+1];
				strcpy(temp, _str);
				delete[] _str;
				_str = temp;
				_capacity = newCapacity;
			}
		}
		void clear()
		{
				_str[_size] = '\0';
				_size = 0;
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
		void insert();
		void erase();
		///////////////////////////////////////////////////////////////////////////////////////////
		//String operations
		const char* C_str()const
		{
			return _str;
		}
		size_t find(char c, size_t pos = 0)
		{
			if (pos > _size || pos < 0)
				return -1;

			for (size_t i = pos; i < _size; i++)
				if (c == _str[i])
					return i;
			return -1;
		}
		size_t rfind(char c, size_t pos = npos)
		{
			if (pos == npos || pos > _size)
				pos = _size - 1;

			for (int i = pos; i >= 0; --i)
				if (c == _str[i])
					return i;

			return -1;
		}
		string strsub(size_t pos = 0, size_t n = npos) const 
		{
			return string(_str + pos, n);
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static const size_t npos;
	};
	const size_t string::npos = 1;
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
	RC::string s5("world", 3);
	Print(s5);
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
	
	s2.Resize(3,'A');
	Print(s2);
	cout << s2.Size() << endl;
	cout << s2.Capacity() << endl;
	
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
	Print(s1);
	char* str = "Hello";
	s1 += (str);
	Print(s1);
	s1 += s2;
	Print(s1);

	s1.Append(str);
	Print(s1);
	s1.Append(10,'A');
	Print(s1);

	s1.Swap(s2);
	Print(s1);

}





//扩容时，删除原空间会出错





int main()
{
	//Teststring_string();
	//Teststring_capacity();
	//Teststring_access();
	Teststring_modifiers();
	return 0;
}