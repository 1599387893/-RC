#include <iostream>
#include <stack>
#include <string>
using namespace std;

//1.先将中缀表达式转换为后缀表达式(逆波兰表达式)
//2.运用栈计算后缀表达式
//本题只考虑+和*

int GetNum(const string& str, int& pos)
{
	int res = 0;
	bool nega = false;
	if (str[pos] == '-')
	{
		nega = true;
		pos++;
	}
	while (pos < str.size() && isdigit(str[pos]))
	{
		res = res * 10 + str[pos] - '0';
		pos++;
	}
	return nega ? 0 - res : res;
}

//操作符优先级
string op_level{"+*"};
int Level(char& c)
{
	for (int i = 0; i < op_level.size(); ++i)
		if (op_level[i] == c)
			return i;
	return -1;
}
//将中缀表达式转换成后缀表达式（不含括号）
string InfixToSuffix(string& str)
{
	string res;
	stack<char> sop; //操作符栈
	stack<int> val; //操作数栈(使用bool确定该元素是否为负数)
	int pos = 0;
	int size = (int)str.size();
	while (pos < size)
	{
		if (isdigit(str[pos]) || str[pos] == '-')
		{
			res += str[pos++];
		}
		if (pos < size && (str[pos] == '+' || str[pos] == '*' || str[pos] == '('))
		{
			//对于操作符栈的插入规则： 
			//    1.如果sop栈栈顶的操作符的优先级 > 将要插入的操作符的优先级  -----> 直接入栈
			//    2.如果sop栈栈顶的操作符的优先级 <=  将要插入的操作符的优先级  ----> 一直弹出栈顶元素并加入到后缀表达式中，直到满足条件1
			if (sop.empty() || (Level(sop.top()) > Level(str[pos])) || str[pos] == '(')
			{
				sop.push(str[pos]);
			}
			else  //当前sop栈栈顶的元素的优先级 > 将要插入的元素的优先级
			{
				while (!sop.empty() && (Level(sop.top()) < Level(str[pos])))
				{
					res += sop.top();
					sop.pop();
				}
				sop.push(str[pos]);
			}
			pos++;
		}
		if (pos < size && str[pos] == ')')  //处理掉括号
		{
			while (!sop.empty() && sop.top() != '(')
			{
				res += sop.top();
				sop.pop();
			}
			sop.pop(); //弹出匹配的左括号
		}
	}
	//处理栈中的元素
	while (!sop.empty())
	{
		res += sop.top();
		sop.pop();
	}
	return res;
}
int Calc(string& str)
{
	//将中缀表达式转换成后缀表达式
	string suf = InfixToSuffix(str);
	//计算出后缀表达式的结果
}
int main()
{
	string str;
	getline(cin, str);
	cout << str << " = " << Calc(str) << endl;
	return 0;
}