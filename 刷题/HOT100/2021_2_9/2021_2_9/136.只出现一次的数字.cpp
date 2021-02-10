class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (auto n : nums)
			ret ^= n;
		return ret;
	}
};
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> m;
		for (auto n : nums)
			m[n]++;
		for (auto p : m)
			if (p.second == 1)
				return p.first;
		return -1;
	}
};