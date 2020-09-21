class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.empty()) return res;
		for (int i = 0; i < nums.size(); ++i)
		{
			int size = res.size();
			for (int j = 0; j < size; ++j)
			{
				auto arr = res[j];
				arr.push_back(nums[i]);
				res.push_back(arr);
			}
			res.push_back(vector<int>{nums[i]});
		}
		res.push_back(vector<int>());
		return res;
	}
};