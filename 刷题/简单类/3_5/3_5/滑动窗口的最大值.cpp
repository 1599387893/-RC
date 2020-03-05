class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		if (nums.size() == 0)
			return res;
		int Max;
		for (int i = 0; i < nums.size() - k + 1; ++i)
		{
			Max = nums[i];
			for (int j = i + 1; j < k + i; ++j)
				Max = max(Max, nums[j]);
			res.push_back(Max);
		}
		return res;
	}
};