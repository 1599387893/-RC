class Solution {
public:
	bool isStraight(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int maxNum = 0;
		int minNum = 15;
		int same = 0;
		for (int i = 0; i<nums.size(); ++i)
		{
			if (nums[i] == 0)
				continue;
			maxNum = max(maxNum, nums[i]);
			minNum = min(minNum, nums[i]);
			if (i >= 1 && nums[i] == nums[i - 1])
				return false;
		}
		if (maxNum - minNum + 1 > 5)
			return false;
		return true;
	}
};