#if 0
class Solution {
public:
	int balancedStringSplit(string s) {
		int count = 0;
		stack<char> sta;
		for (auto i = 0; i< s.size(); ++i)
		{
			if (sta.empty() || (sta.top() == s[i]))
				sta.push(s[i]);
			else
				sta.pop();
			if (sta.empty())
				count++;
		}
		return count;
	}
};

class Solution {
public:
	int balancedStringSplit(string s) {
		int count = 0;
		int left = 0, right = 0;
		for (auto i = 0; i < s.size(); ++i)
		{
			if (s[i] == 'L')
				left++;
			else
				right++;
			if (left == right)
				count++;
		}
		return count;
	}
};
#endif
