#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;

#if 0
class Test
{
private:
	int _year;
	int _month;
public:
	Test(int year,int month)
		:_year(year)
		, _month(month)
	{}
	Test(const Test& tt)
	{
		_year = tt._year;
		_month = tt._month;
	}
	//赋值运算符重载
	Test& operator=(const Test& tt)
	{
		if (this != &tt)
		{
			_year = tt._year;
			_month = tt._month;
		}
		return *this;
	}
	Test* operator&()
	{
		return this;
	}
	const Test* operator&()const
	{
		return this;
	}
	~Test()
	{}
};

#endif

//深浅拷贝
//传统写法
class String
{
public:
	String(const char* s = "")
	{
		if (s == nullptr)
			s = "";
		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}
	String(const String& s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete _str;
			_str = temp;
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};
#if 0
//现代写法
class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		str_ = new char[strlen(str) + 1];
		strcpy(str_, str);
	}
	String(const String& s)
		:str_(nullptr)
	{
		String temp(s.str_);
		swap(str_, temp.str_);
	}
	String& operator=(String s)
	{
		if (this != &s)
		{
			swap(str_, s.str_);
		}
		return *this;
	}
	~String()
	{
		if (str_)
		{
			delete[] str_;
			str_ = nullptr;
		}
	}
private:
	char* str_;
};
#endif
//写时拷贝
namespace RC
{
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			_count = new int(1);
			strcpy(_str, str);
		}
		string(const string& s)
		{
			_str = s._str;
			_count = s._count;
			(*_count)++;
		}
		string& operator=(string& s)
		{
			if (this != &s)
			{
				if (_str)
				{
					(*_count)--;
					if (*_count == 0)
					{
						delete[] _str;
						delete _count;
						_str = nullptr;
						_count = nullptr;
					}
				}
				_str = s._str;
				_count = s._count;
				(*_count)++;
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				*_count--;
				if (*_count == 0)
				{
					delete[] _str;
					delete _count;
				}
			}
		}
	private:
		char* _str;
		int* _count;
		friend ostream& operator<<(ostream& out,const string& s);
	};
	ostream& operator<<(ostream& out,const  string& s)
	{
		cout << s._str << " " << s._count;
		return out;
	}
}
#if 0
using namespace RC;

int main()
{
	RC::string s1("abcde");
	RC::string s2("ghjkl");
	RC::string s3(s1);
	s3 = s2;
	return 0;
}

#endif


//只能在堆上申请空间
class HeapOnly
{
public:
	static HeapOnly* Instance()
	{
		return new HeapOnly;
	}
private:
	HeapOnly() = delete;
	HeapOnly(const HeapOnly& ho) = delete;
};


//只能在栈上申请空间
class StackOnly
{
public:
	static StackOnly Instance()
	{
		return StackOnly();
	}
private:
	StackOnly(){};
};
class StackOnly1
{
public:
	StackOnly1(){}
private:
	void* operator new (size_t size);
	void operator delete(void* p);
};

//单例模式
//饿汉模式
class Singleton
{
public:
	static Singleton* Instance()
	{
		return &m_instance;
	}
private:
	Singleton() = delete;
	Singleton(const Singleton& s) = delete;
	static Singleton m_instance;
};
Singleton Singleton::m_instance;

//懒汉模式
#include<mutex>
#include<thread>
class Singleton2
{
public:
	static Singleton2* Instance()
	{
		if (m_instance == nullptr)
		{
			m_mtx.lock();
			if (m_instance == nullptr)
				m_instance = new Singleton2;
			m_mtx.unlock();
		}
	}

	//实现一个垃圾回收机制：使用这个类在Singleton2对象结束时，调用这个类的析构函数，而回收内存
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (m_instance)
				delete m_instance;
		}
	};
	static CGarbo cg;
private:
	Singleton2() = delete;
	Singleton2(const Singleton2&) = delete;
	static Singleton2* m_instance;
	static mutex m_mtx;
};
Singleton2* Singleton2::m_instance = nullptr;
mutex Singleton2::m_mtx;
Singleton2::CGarbo Singleton2::cg;