class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> dp(nums);
		int res = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			dp[i] = max(nums[i], dp[i - 1] + nums[i]);
			res = max(res, dp[i]);
		}
		return res;
	}
};