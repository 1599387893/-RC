#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

//最小栈
class MinStack
{
public:
	MinStack(){}
	void Push(int x)
	{
		_elem.push(x);
		if (_min.empty() || x <= _min.top())
			_min.push(x);
	}
	void Pop()
	{
		if (_elem.top() == _min.top())
			_min.pop();
		_elem.pop();
	}
	int Top()
	{
		return _elem.top();
	}
	int GetMin()
	{
		return _min.top();
	}
private:
	stack<int> _elem;
	stack<int> _min;
};

//逆波兰表达式求值
class solution
{
public :
	int evalRPN(vector<string>& tokens)
	{
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			string& str = tokens[i];

			if (!("+" == str || "-" == str || "*" == str || "/" == str))
				s.push(atoi(str.c_str()));
			else
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();

				switch (str[0])
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
					break;
				case '*':
					s.push(left*right);
					break;
				case '/':
					s.push(left / right);
					break;
				default:
					break;
				}
			}
		}
		return s.top();
	}
};

//判断栈的压入和弹出序列
class solution1
{
public:
	bool IsPopOrder(vector<int>& push, vector<int>& pop)
	{
		if (push.size() != pop.size())
			return false;
		
		size_t outIndex = 0;
		size_t inIndex = 0;
		stack<int> s;

		while (outIndex < pop.size())
		{
			while (s.empty() || s.top()!= pop[outIndex])
			{
				if (inIndex < push.size())
					s.push(push[inIndex++]);
				else
					return false;
			}
			s.pop();
			outIndex++;
		}
		return true;	
	}
};