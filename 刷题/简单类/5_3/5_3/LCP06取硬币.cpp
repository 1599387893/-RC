class Solution {
public:
	int minCount(vector<int>& coins) {
		int res = 0;
		for (const auto n : coins)
			res += ceil(n / 2.0);
		return res;
	}
};