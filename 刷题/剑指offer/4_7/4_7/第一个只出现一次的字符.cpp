#if 0
class Solution {
public:
	char firstUniqChar(string s) {
		char ret = ' ';
		unordered_map<char, int> um;
		for (auto c : s)
			um[c]++;
		for (auto c : s)
			if (um[c] == 1)
			{
			ret = c;
			break;
			}
		return ret;
	}
};
#endif