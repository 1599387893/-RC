class Solution {
public:
	int maxDepth(string s) {
		if (s.empty() || s.size() == 1) return 0;
		int res = 0, cur = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				cur++;
				res = max(res, cur);
			}
			else if (s[i] == ')')
				cur--;
		}
		return res;
	}
};