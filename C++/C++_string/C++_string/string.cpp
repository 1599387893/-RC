#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//��һ��ģ�ⷽ�������(��ͳ)
namespace bit1
{
	class string
	{
	public:
		//���캯��
		string(const char* s = "") 
		{
			if (nullptr == s)
				s = "";

			_str = new char[strlen(s) + 1];
			strcpy(_str, s);
			_size = strlen(s);
			_capacity = _size;
		}
		//�������캯��
		string(const string& s)
			:_str(new char[s._capacity])
			, _size(s._size)
			, _capacity(s._capacity)	
		{
			strcpy(_str, s._str);
		}
		//��ֵ��������غ���
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
		//��������
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
void Teststring1()
{
	bit1::string s1;
	bit1::string s2("hello");
	bit1::string s3(s2);
	s1 = s2;

}

//�ڶ���ģ�ⷽ����������ִ���
namespace bit2
{
	class string
	{
	public:
		//���캯��
		string(const char* s = "")
		{
			if (nullptr == s)
				s = "";

			_str = new char[strlen(s) + 1];
			strcpy(_str, s);
			_size = strlen(s);
			_capacity = _size + 1;
		}
		//�������캯��1.0
		string(const string& s) :_str(nullptr)
		{
			string temp(s._str);
			swap(_str, temp._str);//����֮����ʱ����temp����žɵ�_strִ����������
			_capacity = s._capacity;
			_size = s._size;
		}
		//��ֵ����������غ���
		string& operator=(string s)
		{
			swap(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}
		//��������
		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
void Teststring2()
{
	bit2::string s4(nullptr);
	bit2::string s5("hello");
	bit2::string s6(s5);
	s4 = s5;
}

#if 0
//������ģ�ⷽ����дʱ����
namespace bit3
{
	class string
	{
	public:
		string(const char* str = "") 
		{
			if (nullptr == str)
				str = "";

			_str = new char[strlen(str) + 1];
			_size = strlen(str);
			_capacity = _size + 1;
		}
		string(const string& s)
		{

		}
		string& operator=(const string& s)
		{

		}
		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}
void Teststring3()
{
	bit3::string s1(nullptr);
	bit3::string s2("hello");
	bit3::string s3(s2);
	s1 = s3;
}
#endif

//int main()
//{
//	//Teststring1();
//	Teststring2();
//
//	return 0;
//}