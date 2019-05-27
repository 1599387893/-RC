//2
//字符串转成整数
//输入示例：
//			+2147483647
//			1a33
//输出示例：
//			2147483647
//			0

#include<iostream>
#include<string>
using namespace std;

class Solution1 
{
public:
	int StrToInt(string str) 
	{
		int retValue = 0;
		int flag = 0;
		if (str[0] == '-')
			flag = 1;
		else if (str[0] == '+')
			flag = 2;
		for (int i = 0; i < str.size(); ++i)
		{
			if (flag!= 0 && i == 0)
				continue;
			if (str[i] >= '0'&& str[i] <= '9')
				retValue = retValue * 10 + str[i] - '0';
			else
				return 0;
		}
		if (flag == 1)
			retValue = 0 - retValue;

		return retValue;
	}
};
class Solution2
{
public:
	int StrToInt(string str)
	{
		if (str.empty())
			return 0;
		int symbol = 1;
		if (str[0] == '-') //处理负号
		{
			symbol = -1;
			str[0] = '0'; //这里是字符'0',不是0
		}
		else if (str[0] == '+') //处理正号
		{
			symbol = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i<str.size(); ++i)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return symbol * sum;
	}
};
int main()
{
	Solution1 s;
	cout<<s.StrToInt("1a33")<<endl;
	system("pause");
	return 0;
}