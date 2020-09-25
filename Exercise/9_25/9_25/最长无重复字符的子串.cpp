#if 0
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1) return s.size();
		unordered_map<char, int> um;
		vector<int> dp(s.size(), 1);
		um[s[0]] = 0;
		int res = 0;
		for (int i = 1; i < s.size(); ++i)
		{
			if (um.find(s[i]) == um.end())
			{
				dp[i] = dp[i - 1] + 1;
				um[s[i]] = i;
			}
			else
			{
				dp[i] = i - um[s[i]] > dp[i - 1] ? dp[i - 1] + 1 : i - um[s[i]];
				um[s[i]] = i;
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};
#endif