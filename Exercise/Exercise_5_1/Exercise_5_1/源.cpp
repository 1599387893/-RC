#define  _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<assert.h>
#include<iostream>
using namespace std;

namespace RC
{
	class string
	{
	public:
		typedef char* iterator;
	public:
		//¹¹Ôì
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";

			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_size = strlen(str);
			_capacity = _size;

		}
		string(size_t n, char c)
		{
			_size = n;
			_capacity = n;
			_str = new char[n + 1];
			memset(_str, c, n);
			_str[_size] = '\0';
		}
		string(const string& s) :_str(nullptr)
		{
			_size = strlen(s._str);
			char* temp = new char[_size + 1];
			strcpy(temp, s._str);
			swap(_str, temp);
			_capacity = _size;
		}
		string& operator=(string s)
		{
			if (this != &s)
			{
				swap(_str, s._str);
				_size = s._size;
				_capacity = _size;
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				clear();
				_capacity = 0;
			}
		}
		//iterator
		iterator begin()
		{
			return &_str[0];
			//return _str;
		}
		iterator end()
		{
			//return _str + _size;
			return &_str[_size];
		}
		//capacity
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			return _size == 0;
		}
		void resize(size_t newSize, char c )
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
					reserve(newSize);
				size_t addsize = newSize - _size;
				for (size_t i = 0; i < addsize; ++i)
				{
					push_back(c);
				}
			}
			_size = newSize;
			_str[_size] = '\0';
		}
		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* temp = new char[newCapacity + 1];
				strcpy(temp, _str);

				delete[] _str;
				_str = temp;
				_capacity = newCapacity;
			}
		}
		void clear()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
				_size = 0;
			}
		}
		//access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}
		int find(char c, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
				if (_str[i] == c)
					return i;
			return -1;
		}
		int rfind(char c, size_t pos = -1)
		{
			if (pos == -1 || pos < 0)
				pos = _size;
			for (size_t i = pos; i >= 0; --i)
				if (_str[i] == c)
					return i;
			return -1;
		}
		char* c_str()
		{
			return _str;
		}
		string substr(size_t pos = 0, size_t n = -1) const
		{
			string retStr = new char[n + 1];
			retStr[n] = '\0';
			memcpy(retStr._str, _str + pos, n);
			return retStr;
		}
		//modefity
		void push_back(char c)
		{
			if (_size == _capacity)
				reserve(2 * _capacity);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		string& operator+=(const string& s)
		{
			for (size_t i = 0; i < s._size; ++i)
				push_back(s[i]);
			return *this;
		}
		string& operator+=(const char* str)
		{
			size_t size = strlen(str);
			for (size_t i = 0; i < size; ++i)
				push_back(str[i]);
			return *this;

		}
		string& operator+=(char c)
		{
			push_back(c);
			return *this;

		}
		string& append(const string& s)
		{
			for (size_t i = 0; i < s._size; ++i)
				push_back(s[i]);
			return *this;

		}
		string& append(const char* str)
		{
			size_t size = strlen(str);
			for (size_t i = 0; i < size; ++i)
				push_back(str[i]);
			return *this;

		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		//static size_t npos;
	};
	//size_t npos = -1;
}

void teststring()
{
	RC::string s(10, 'c');
	RC::string s1("hello");
	RC::string s2("world");
	RC::string s3(s1);
	RC::string s4;
	s4 = s1;
}
void teststring_iterator()
{
	RC::string s1("hello");
	auto it = s1.begin();
	while (it != s1.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}
void teststring_capacity()
{
	RC::string s1("hello");
	cout<<"size = "<<s1.size()<<endl;
	cout << "capacity = " << s1.capacity() << endl;
	cout << "empty = " << s1.empty() << endl;

	s1.reserve(1);
	cout << "size = " << s1.size() << endl;
	cout << "capacity = " << s1.capacity() << endl;
	cout << "empty = " << s1.empty() << endl;

	s1.reserve(10);
	cout << "size = " << s1.size() << endl;
	cout << "capacity = " << s1.capacity() << endl;
	cout << "empty = " << s1.empty() << endl;

	s1.resize(3, 'a');
	cout << "size = " << s1.size() << endl;
	cout << "capacity = " << s1.capacity() << endl;
	cout << "empty = " << s1.empty() << endl;

	s1.resize(10, 'c');
	cout << "size = " << s1.size() << endl;
	cout << "capacity = " << s1.capacity() << endl;
	cout << "empty = " << s1.empty() << endl;

	s1.clear();
	cout << "size = " << s1.size() << endl;
	cout << "capacity = " << s1.capacity() << endl;
	cout << "empty = " << s1.empty() << endl;
}
void teststring_modefity()
{
	RC::string s1("hello");
	//RC::string s2(" wprld");

	//s1 += s2;
	//s1.append(s2);

	s1.push_back('A');
	s1 += 'A';
	char* arr = "RC";
	s1 += arr;
	s1.append(arr);

}
void teststring_access()
{
	RC::string s1("hello");
	cout << s1[1] << endl;
	cout << s1.rfind('l')<<endl;
	cout << s1.find('l') << endl;
	cout << s1.c_str() << endl;

}

int main()
{
	//teststring();
	//teststring_iterator();
	//teststring_capacity();
	//teststring_modefity();
	teststring_access();
	return 0;
}