#if 0
class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> count(256, 0);
		for (int i = 0; i < s.size(); ++i)
			count[s[i]] += 1;
		for (int i = 0; i < s.size(); ++i)
			if (count[s[i]] == 1)
				return i;
		return -1;
	}
};
#endif