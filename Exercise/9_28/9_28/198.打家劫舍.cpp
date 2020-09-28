class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		if (nums.size() == 2) return max(nums[0], nums[1]);
		int a = nums[0], b = max(nums[0], nums[1]);
		int res = 0;
		for (int i = 2; i < (int)nums.size(); ++i)
		{
			res = max(b, nums[i] + a);
			a = b;
			b = res;
		}
		return res;
	}
};