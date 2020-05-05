class Solution {
public:
	bool Isget(const string& str, const vector<int>& temp)
	{
		vector<int> s(26, 0);
		for (auto c : str)
			s[c - 'a']++;
		for (int i = 0; i< temp.size(); ++i)
			if (temp[i]<s[i])
				return false;
		return true;
	}
	int countCharacters(vector<string>& words, string chars) {
		vector<int> temp(26, 0);
		for (auto c : chars)
			temp[c - 'a']++;
		int res = 0;
		for (auto str : words)
		{
			if (str.size()>chars.size())
				continue;
			if (Isget(str, temp))
				res += str.size();
		}
		return res;
	}
};