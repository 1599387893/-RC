class Solution {
public:
	string sortString(string s) {
		vector<int> temp(26, 0);
		for (const auto c : s)
			temp[c - 'a']++;
		string res;
		while (res.size() < s.size())
		{
			for (int i = 0; i < 26; ++i)
				if (temp[i])
					res += i + 'a', temp[i]--;
			for (int i = 25; i >= 0; --i)
				if (temp[i])
					res += i + 'a', temp[i]--;
		}
		return res;
	}
};