class Solution {
public:
	vector<vector<int>> res;
	void BackTrace(const vector<int>& candidates, vector<int>& arr, int target, int pos)
	{
		if (pos == candidates.size())
			return;
		if (target == 0)
		{
			res.push_back(arr);
			return;
		}
		BackTrace(candidates, arr, target, pos + 1);
		if (target - candidates[pos] >= 0)
		{
			arr.push_back(candidates[pos]);
			BackTrace(candidates, arr, target - candidates[pos], pos);
			arr.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> arr;
		BackTrace(candidates, arr, target, 0);
		return res;
	}
};

