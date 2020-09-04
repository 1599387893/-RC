
#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <string.h>

char *GetMemory(void)
{
	char p[] = "hello world";
	return p;
}
void Test(void)
{
	char *str = NULL;
	str = GetMemory();
	printf(str);
}

int main()
{

	const int a11 = 10;
	int ar[a11];
	ar[1] = 1;
	Test();
	struct S3
	{
		double d;
		char c;
		int i;
	};
	struct A
	{
		int _a : 2;
		int _b : 5;
		int _c : 10;
		int _d : 30;
	};
	printf("%d\n", sizeof(struct A));


	char str1[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str1);
	pch = strtok(str1, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}

	char str[] = "abc";
	strcat(str, str);
	printf("%s\n", str);

	int a = 10;
	int b = 20;
	b = a^b;
	a = a^b;
	b = a^b;
	printf("a = %d b = %d\n", a, b);


	const int count = 10;
	int arr2[count];

	char arr[20] = "hello";
	int ret = strlen(strcat(arr, "bit"));//这里介绍一下strlen函数
	printf("%d\n", ret);


	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
		k++;
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(long double));
	printf("%d\n", sizeof(wchar_t));

	printf("%d\n", strlen("abcedf"));
	printf("%d\n", strlen("c:\test\32\test.c"));
	return 0;
}
#endif

template<class T1, class T2>
T1 add(const T2& a, const T1&  b)
{
	return a + b;
}

#if 0
#include <iostream>
using namespace std;
class Base
{
public:
	void GetStaticAddr()
	{
		cout << &b << endl;
	}
	void Func()
	{
		cout << "Base::Func()" << endl;
	}
protected:
	int a;
	static int b;
};

class Dervied : public Base
{
public:
	void GetStaticAddr()
	{
		cout << &b << endl;
	}
	virtual void Func()
	{
		cout << "Derived::Func()" << endl;
	}
private:
	int _d;
};

int Base::b = 1;

#endif
#include <iostream>
using namespace std;
	class Base
	{
	public:
		Base()
		{
			std::memset((((char*)this) + 4), 0, sizeof(this));
		}
		virtual void Show()
		{
			std::cout << "Base's show = " << std::endl;
		}
	};


	int main()
	{
		Base* pb = new Base;
		pb->Show();
		return 0;
	}

namespace Test
{
#include <cstring>
#include <algorithm>
	class String
	{
	public:
		//构造函数
		String(const char* str = "")
		{
			if (str == nullptr)
			{
				return ;
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		//析构函数
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
		//拷贝构造函数
		String(const String& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
		//赋值运算符重载函数
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char* temp = new char[strlen(s._str) + 1];
				strcpy(temp, s._str);
				delete[] _str;
				swap(_str, temp);
			}
			return *this;
		}
		//取地址函数
		//const取地址函数
	private:
		char* _str;
	};
}


