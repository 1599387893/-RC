class Solution {
public:
	int findLucky(vector<int>& arr) {
		unordered_map<int, int> um;
		for (auto n : arr)
			um[n]++;
		int res = -1;
		for (auto p : um)
			if (p.first == p.second)
				res = max(p.first, res);
		return res;
	}
};