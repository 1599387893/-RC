class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0) return res;
		sort(nums.begin(), nums.end());
		do
		{
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};


class Solution {
public:
	vector<vector<int>> res;
	void TraceBack(vector<int>& nums, int pos)
	{
		if (pos == nums.size())
			res.push_back(nums);
		else
		{
			for (int i = pos; i < nums.size(); ++i)
			{
				swap(nums[i], nums[pos]);
				TraceBack(nums, pos + 1);
				swap(nums[i], nums[pos]);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0) return res;
		TraceBack(nums, 0);
		return res;
	}
};