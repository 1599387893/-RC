class Solution {
public:
	int climbStairs(int n) {
		vector<int> temp{ 0, 1, 2 };
		if (n<temp.size()) return temp[n];
		for (int i  = 3; i  <= n; ++i)
			temp.push_back(temp[temp.size() - 1] + temp[temp.size() - 2]);
		return temp[n];
	}
};