//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> strs;
		string res;
		for (auto num : nums)
			strs.push_back(to_string(num));
		sort(strs.begin(), strs.end(), compare);
		for (auto str : strs)
			res += str;
		return res;
	}
	static bool compare(const string& s1, const string& s2)
	{
		return s1 + s2 < s2 + s1;
	}
};