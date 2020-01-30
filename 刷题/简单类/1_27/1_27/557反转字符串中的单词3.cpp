#if 0
class Solution {
public:
	string reverseWords(string s) {
		int left = 0;
		for (int right = 1; right < s.size(); ++right)
		{
			if (s[right] == ' ')
			{
				reverse(s.begin() + left, s.begin() + right);
				left = 1 + right;
			}
		}
		reverse(s.begin() + left, s.end());
		return s;
	}
};
#endif
//利用栈结构
#if 0
class Solution {
public:
	string reverseWords(string s) {
		string ret;
		stack<char> sta;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				while (!sta.empty())
				{
					ret += sta.top();
					sta.pop();
				}
				ret += ' ';
			}
			else
			{
				sta.push(s[i]);
			}
		}
		while (!sta.empty())
		{
			ret += sta.top();
			sta.pop();
		}
		return ret;
	}
};
#endif
