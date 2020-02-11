#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
#if 0
	string s{ "leetcode" };
	vector<int> count(256, 0);
	for (int i = 0; i < s.size(); ++i)
		count[s[i]] += 1;
	for (int i = 0; i < s.size(); ++i)
		if (count[s[i]] == 1)
			cout<< i<<endl;
	cout << -1<<endl;
#endif
	string num1 = "10";
	string num2 = "11";
	string res;
	if (num1.size()>num2.size())
		num1.swap(num2);
	while (num1.size()<num2.size())
		num1.insert(num1.begin(), '0');
	res.resize(num1.size(), 0);
	int flag = 0; //进位
	int temp = 0;
	for (int i = num1.size() - 1; i >= 0; --i)
	{
		temp = num1[i] - '0' + num2[i] - '0' + flag;
		flag = temp / 10;
		res[i] = temp % 10 + '0';
	}
	if (flag != 0)
		res.insert(res.begin(), flag + '0');
	cout<< res<<endl;
}
#include<algorithm>

namespace RC
{
//深拷贝--传统写法
	class string1
	{
	public:
		string1(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str,str);
		}
		string1(const string1& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str,s._str);
		}
		string1& operator=(const string1& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp,s._str);
				delete[] _str;
				_str = temp;
			}
			return *this;
		}
		~string1()
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
	//现代写法
	class string2
	{
	public:
		string2(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str,str);
		}
		string2(const string2& s)
			:_str(nullptr)
		{
			string2 temp(s._str);
			swap(_str, s._str);
		}
		string2& operator=(string2 s)
		{
			if (this != &s)
			{
				swap(_str,s._str);
			}
			return *this;
		}
	private:
		char* _str;
	};
	//写时拷贝
	class string
	{
	public:
		string(const char* str = "")
		{
			if (str == nullptr)
				str = "";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_count = new int(1);
		}
		string(const string& s)
			:_str(s._str)
			, _count(s._count)
		{
			++(*_count);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				if (_str)
				{
					--(*_count);
					if (*_count == 0)
					{
						delete[] _str;
						delete _count; 
					}
				}
				_str = s._str;
				_count = s._count;
				++(*_count);
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				--(*_count);
				if ((*_count) == 0)
				{
					delete[] _str;
					delete _count;
				}
			}
		}
	private:
		int* _count;
		char* _str;
	};
}


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
	Singleton(const Singleton&) = delete;
	static Singleton m_instance;
};
Singleton Singleton::m_instance;


//懒汉模式
#include<mutex>
#include<thread>
class singleton
{
public:
	static singleton* Instance()
	{
		if (m_instance == nullptr)
		{
			m_mtx.lock();
			if (nullptr == m_instance)
			{
				m_instance = new singleton;
			}
			m_mtx.unlock();
		}
		return m_instance;
	}
	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (m_instance)
			{
				delete m_instance;
			}
		}
	};
	static CGarbo cg;
private:
	singleton() = delete;
	singleton(const singleton&) = delete;
	static singleton* m_instance;
	static mutex m_mtx;
};
singleton* singleton::m_instance = nullptr;
mutex singleton::m_mtx;
singleton::CGarbo singleton::cg;