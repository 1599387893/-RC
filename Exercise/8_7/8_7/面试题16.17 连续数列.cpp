class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		for (int i = 1; i < nums.size(); ++i)
			nums[i] = max(nums[i - 1] + nums[i], nums[i]);
		return *max_element(nums.begin(), nums.end());
	}
};


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int res = nums[0], sum = 0;
		for (const auto& n : nums)
		{
			sum += n;
			res = max(res, sum);
			if (sum < 0) sum = 0;
		}
		return res;
	}
};