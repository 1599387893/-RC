class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() == t.size() && s.size() == 0) return true;
		if (s.size() != t.size()) return false;
		map<char, char> temp1;
		map<char, char> temp2;
		for (int i = 0; i < s.size(); ++i)
		{
			if (temp1.find(s[i]) == temp1.end() && temp2.find(t[i]) == temp2.end())
			{
				temp1[s[i]] = t[i];
				temp2[t[i]] = s[i];
			}
			else
			{
				if (temp1[s[i]] != t[i] && temp2[t[i]] != s[i])
					return false;
			}
		}
		return true;
	}
};
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		for (int i = 0; i < s.size(); ++i)
			if (s.find(s[i]) != t.find(t[i]))
				return false;
		return true;
	}
};