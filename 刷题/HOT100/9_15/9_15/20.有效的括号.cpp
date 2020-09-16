class Solution {
public:
	bool isValid(string s) {
		stack<char> sta;
		unordered_map<char, char> um;
		um['('] = ')';
		um['['] = ']';
		um['{'] = '}';
		for (auto c : s)
		{
			if (sta.empty() || c == '(' || c == '[' || c == '{')
				sta.push(c);
			else
			{
				if ((c == ')' && sta.top() == '(') || (c == ']' && sta.top() == '[') || (c == '}' && sta.top() == '{'))
					sta.pop();
				else
					return false;
			}
		}
		return sta.empty();
	}
};