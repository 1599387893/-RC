//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//
////class String
////{
////private:
////	char* _str;
////public:
////	String()
////		:_str(NULL)
////	{
////
////	}
////	String(char* str)
////		:_str((char*)malloc(strlen(str) + 1))
////	{
////		strcpy(_str, str);
////	}
////	String* operator=(String s)
////	{
////		if (this != &s)
////		{
////			String temp(s._str);
////			swap(_str, temp._str);
////		}
////		return this;
////	}
////	~String()
////	{
////		if (_str)
////		{
////			free(_str);
////			_str = NULL;
////		}
////	}
////};
////
////
//////函数模板
//////template<typename T1, class T2,class T3>
////template<class T>
////T Comp(T a, T b)
////{
////	return (a > b) ? a : b;
////}
////
////
////int main()
////{
////	//int a = 1;
////	//int b = 2;
////	//Comp<int>(a, b);
////	int a = 1;
////	cout << -a << endl;
////	return 0;
////}
//
//
//	int StrToInt(string str) {
//		int ret = 0;
//		int pos = 0;
//		int n = 0;
//		bool isNega = false;
//		//先找到第一个有效字符
//		while (str[pos] == ' ')
//			pos++;
//		if (str[pos] != '-' && !isdigit(str[pos]))
//			return 0;
//		if (str[pos] == '-')
//			isNega = true;
//		for (; pos < str.size(); ++pos)
//		{
//			if (isdigit(str[pos]))
//			{
//				n = str[pos] - '0';
//				if (ret > INT_MAX || (isNega && -ret < INT_MIN))
//					return isNega ? INT_MIN : INT_MAX;
//				else if ((ret == INT_MAX / 10 && n > INT_MAX % 10) || \
//					(isNega && -ret == INT_MIN / 10 && n > INT_MIN % 10))
//					return isNega ? INT_MIN : INT_MAX;
//				else
//					ret = ret * 10 + n;
//			}
//
//		}
//		return isNega ? -ret : ret;
//	}
//
//	int main()
//	{
//		string a{ "    -42" };
//		cout << StrToInt(a) << endl;
//	}



#include <iostream>
#include <string>
using namespace std;

int GetLastWord(string& s)
{
	int pos = s.rfind(' ');
	return s.size() - pos - 1;
}
#include <algorithm>
bool isPalindrome(string s) {
	string temp;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (int i = 0; i < s.size(); ++i)
		if (isalpha(s[i]))
			temp += s[i];
	s = temp;
	reverse(s.begin(), s.end());
	return s == temp;
}

int main()
{
	string s {"OP"};
	cout << (isPalindrome(s) ? "true" : "false") << endl;
	return 0;
}