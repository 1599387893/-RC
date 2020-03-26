//数组中有一个数出现了一次，其他数都出现了三次

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> m;
		int res;
		for (auto c : nums)
			m[c]++;
		for (auto it = m.begin(); it != m.end(); ++it)
			if ((*it).second == 1)
			{
			res = (*it).first;
			break;
			}
		return res;
	}
};