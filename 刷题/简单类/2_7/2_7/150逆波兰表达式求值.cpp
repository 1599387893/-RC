#if 0
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int res = 0;
		stack<int> sta;
		for (auto& str : tokens)
		{
			if (str == "+" || str == "-" || str == "*" || str == "/")
				Resolve(sta, str);
			else
				sta.push(atoi(str.c_str()));
		}
		return sta.top();
	}
	void Resolve(stack<int>& sta, string str)
	{
		int b = sta.top();
		sta.pop();
		int a = sta.top();
		sta.pop();
		if (str[0] == '+')
			sta.push(a + b);
		else if (str[0] == '-')
			sta.push(a - b);
		else if (str[0] == '*')
			sta.push(a*b);
		else
			sta.push(a / b);
	}
};
#endif