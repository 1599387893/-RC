#include <iostream>
#include <string>
#include <stack>
using namespace std;

string op_level = "+-*/";
int Level(char c)
{
	for (int i = 0; i < op_level.size(); ++i)
		if (op_level[i] == c)
			return i;
	return -1;
}
string InfixToSuffix(string& str)
{
	string res;
	stack<char> sop; //操作符
	int pos = 0;
	int size = str.size();
	while (pos < size)
	{
		if (isdigit(str[pos]))
		{
			while (isdigit(str[pos]))
			{
				res += str[pos++];
			}
			res += ' ';
		}
		if (str[pos] == '(' || str[pos] == '+' || str[pos] == '-' || str[pos] == '*' || str[pos] == '/')
		{
			if (str[pos] == '(' || sop.empty() || (Level(str[pos]) > Level(sop.top())))
				sop.push(str[pos]);
			else
			{
				while (!sop.empty() && (Level(str[pos]) <= Level(sop.top())))
				{
					res += sop.top();
					res += ' ';
					sop.pop();
				}
				sop.push(str[pos]);
			}
			pos++;
		}
		//处理当前匹配的括号（后缀表达式中不包含括号）
		if (str[pos] == ')')
		{
			while (!sop.empty() && sop.top() != '(')
			{
				res += sop.top();
				res += ' ';
				sop.pop();
			}
			pos++;
		}
	}
	while (!sop.empty())
	{
		res += sop.top();
		res += ' ';
		sop.pop();
	}
	return res;
}
double GetNumber(string& str, int& pos)
{
	double res = 0;
	while (pos < str.size() && isdigit(str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	return res;
}
double GetResult(string& suf)
{
	int pos = 0;
	int size = suf.size();
	double res = 0, a = 0, b = 0;
	stack<double> val;
	while (pos < size)
	{
		if (suf[pos] == ' ')
		{
			pos++;
			continue;
		}
		else if (isdigit(suf[pos]))
		{
			val.push(GetNumber(suf, pos));
		}
		else
		{
			b = val.top(); val.pop();
			a = val.top(); val.pop();
			if (suf[pos] == '+')
			{
				val.push(a + b);
			}
			else if (suf[pos] == '-')
			{
				val.push(a - b);
			}
			else if (suf[pos] == '*')
			{
				val.push(a * b);
			}
			else
			{
				if (b == 0)
					val.push(0);
				else
					val.push(a / b);
			}
			pos++;
		}
	}
	return val.top();
}
double Calc(string& s)
{
	//1.将中缀表达式转换成后缀表达式
	string suf = InfixToSuffix(s);
	//2.使用后缀表达式计算结果
	return GetResult(suf);
}
int main()
{
	string s;
	cin >> s;
	cout << Calc(s) << endl;
	return 0;
}