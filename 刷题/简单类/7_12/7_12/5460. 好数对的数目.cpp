class Solution {
public:
	int Count(int n)
	{
		if (n == 0) return 0;
		return n + Count(n - 1);
	}
	int numIdenticalPairs(vector<int>& nums) {
		int res = 0;
		map<int, int> temp;
		for (const auto& n : nums)
			temp[n]++;
		for (const auto& p : temp)
			if (p.second>1)
				res += Count(p.second - 1);
		return res;
	}
};