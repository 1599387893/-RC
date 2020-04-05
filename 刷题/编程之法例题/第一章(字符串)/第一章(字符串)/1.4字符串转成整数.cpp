#if 0

#include<iostream>
#include<string>
using namespace std;

int StrToInt(const char* str)
{
	static const int MAX_INT = (int)((unsigned)~0 >> 1);
	static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;
	unsigned int n = 0; //返回值

	//判空
	if (str == nullptr) return 0;
	//消除空格
	while (isspace(*str)) str++;
	//判断正负
	bool minus = false;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = true;
		++str;
	}

	//循环得结果
	while (isdigit(*str))
	{
		//处理溢出
		int c = *str - '0';//当前位上的数值
		if (!minus && ((n>MAX_INT/10) || (n==MAX_INT/10 && c>MAX_INT%10)))
		{
			n = MAX_INT;
			break;
		}
		else if (minus && ((n > (unsigned)MIN_INT / 10) || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
		{
			n = MIN_INT;
			break;
		}
		//未溢出，则继续给结果加上该位
		n = n * 10 + c;
		++str;
	}
	return (minus==true ? -1*n : n);
}
int main()
{
	string str = "-2147483697";
	cout << StrToInt(str.c_str()) << endl;
	cin >> str;
	return 0;
}
#endif