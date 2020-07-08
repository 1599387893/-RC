class Solution {
public:
	vector<int> divingBoard(int shorter, int longer, int k) {
		vector<int> res;
		if (!k) return res;
		if (shorter == longer)
		{
			res.push_back(shorter);
			return res;
		}
		res.push_back(shorter*k);
		for (int i = 1; i <= k; ++i)
			res.push_back(res[res.size() - 1] - shorter + longer);
		return res;
	}
};