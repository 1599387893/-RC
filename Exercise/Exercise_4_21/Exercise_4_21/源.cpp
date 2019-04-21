#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

namespace RC
{
	class string
	{
	public:
		typedef char* Iterator;
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_size = strlen(str);
			_capacity = _size + 1;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_size = strlen(s._str);
			_capacity = _size + 1;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);

				delete[] _str;
				_str = temp;
				_size = s._size;
				_capacity = s._capacity;
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
		///////////////////////////////////////////////////
		//Iterator
		Iterator begin()
		{
			return _str + 0;
		}
		Iterator end()
		{
			return _str + _size;
		}
		//////////////////////////////////////////////////
		//modify
		void Pushback(char c)
		{
			if (_size == _capacity)
				Reserve(2 * _capacity);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void append(size_t n, char c)
		{
			for (n; n > 0; n--)
				Pushback(c);
		}
		void Append(const char* str)
		{
			while (*str != '\0')
				Pushback(*str++);
		}
		string& operator+=(char c)
		{
			Pushback(c);

			return *this;
		}
		string& operator+=(const char* str)
		{
			Append(str);

			return *this;
		}
		void clear()
		{
			if (_str)
			{
				_str = nullptr;
				_size = 0;
			}
		}
		void Swap(string& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		const char* C_str()const
		{
			return _str;
		}
		//////////////////////////////////////////////////
		//capacity
		size_t capacity()const
		{
			return _capacity;
		}
		size_t size()const
		{
			return _size;
		}
		bool Empty()const
		{
			return _size == 0;
		}
		void Resize(size_t newSize, char c = char())
		{
			if (newSize > _size)
			{
				// 如果newSize大于底层空间大小，则需要重新开辟空间
				if (newSize > _capacity)
				{
					Reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[newSize] = '\0';
		}
		void Reserve(size_t newCapacity)
		{
			if (newCapacity>_capacity)
			{
				char* temp = new char[newCapacity];
				strcpy(temp, _str);

				delete[] _str;
				_str = temp;
				_capacity = newCapacity;
			}
		}
		/////////////////////////////////////////////////
		//access
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const
		{
			assert(index<_size);
			return _str[index];
		}
		bool operator>(const string& s)
		{
			if (_size > s._size)
				return true;
			if (_size < s._size)
				return false;
			char* temp1 = _str;
			char* temp2 = s._str;
			while (temp1 != '\0')
			{
				if ((*temp1) >(*temp2))
					return true;
				if ((*temp1) < (*temp2))
					return false;
				*temp1++;
				*temp2++;
			}
			return 0;
		}
		bool operator>=(const string& s)
		{

		}
		bool operator<(const string& s);
		bool operator<=(const string& s);
		bool operator==(const string& s);
		bool operator!=(const string& s);

		size_t Find(char c, size_t pos = 0)const;
		string substr(size_t pos, size_t n);
		string& Insert(size_t pos, char c);
		string& Insert(size_t pos, const char* str);
		string& Erase(size_t pos, size_t len);
	private:
		friend ostream& operator<<(ostream& _cout, const RC::string& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
ostream& RC::operator<<(ostream& _cout, const RC::string& s)
{
	_cout << s._str;
	return _cout;
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
void Teststring_Gz()
{
	RC::string s1;
	RC::string s2(nullptr);
	RC::string s3("hello");
	RC::string s4(s3);
	s1 = s4;
	cout << s1 << endl;
	Print(s1);
}
void Teststring_capacity()
{
	RC::string s1("Hello");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.Empty() << endl;
	Print(s1);
	cout << s1 << endl;

	s1.Resize(3, 'a');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	Print(s1);
	cout << s1 << endl;

	//s1.Resize(10, 'a');
	//cout << s1.size() << endl;
	//cout << s1.capacity() << endl;
	//Print(s1);

	RC::string s2("world");
	s2.Reserve(20);
	cout << s2.capacity() << endl;
	cout << s2 << endl;
}
void Teststring_modify()
{
	RC::string s1("hello");
	RC::string s2("world");

	s1.Swap(s2);
	cout << "s1:" << s1 << endl;
	cout << "s2:" << s2 << endl;
	s1.Pushback('A');
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	Print(s1);
	cout << s1 << endl;

	s1.append(1, 'B');
	//s1.Append(" CD");
	//s1 += 'E';
	//s1 += " FG";
	s1.clear();
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
}
int main()
{
	// Teststring_Gz();
	//Teststring_capacity();
	Teststring_modify();
	return 0;
}

