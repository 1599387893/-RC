class Solution {
public:
	bool isValid(string s)
	{
		if (s.empty()) return true;
		if (s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
		stack<char> sta;
		int pos = 0;
		while (pos < s.size())
		{
			if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{')
				sta.push(s[pos]);
			else
			{
				if (s[pos] == ')')
				{
					if (!sta.empty() && sta.top() == '(')
						sta.pop();
					else
						return false;
				}
				else if (!sta.empty() && s[pos] == ']')
				{
					if (sta.top() == '[')
						sta.pop();
					else
						return false;
				}
				else if (s[pos] == '}')
				{
					if (!sta.empty() && sta.top() == '{')
						sta.pop();
					else
						return false;
				}
			}
			pos++;
		}
		return sta.empty();
	}
};