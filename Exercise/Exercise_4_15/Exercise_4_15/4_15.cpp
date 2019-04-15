#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
using namespace std;


//Éî¿½±´
namespace bit
{
	class string
	{
	public:
		string(const char* s = "") :_str(new char[strlen(s)+1])
		{
			if (s == nullptr)
				s = "";

			strcpy(_str, s);
			_size = strlen(s);
			_capacity = _size + 1;
		}
		string(const string& s) :_str(new char[s._capacity])
		{
			strcpy(_str, s._str);
			_capacity = s._capacity;
			_size = s._size;
		}
		string& operator=(const string& s)
		{
			if (&s != this)
			{
				//1.0
				//string strTemp(s._str);
				//strcpy(strTemp._str, s._str);

				//delete[] _str;
				//swap(_str, strTemp._str);
				//_capacity = s._capacity;
				//_size = s._size;

				//2.0
				char* temp = new char[s._capacity];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
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
	s1 = s3;

}
int main()
{
	Teststring();

	return 0;
}