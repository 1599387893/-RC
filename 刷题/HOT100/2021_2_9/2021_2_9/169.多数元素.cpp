class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int num = nums[nums.size() / 2];
		int count = 0;
		for (auto n : nums)
			if (n == num)
				count++;
		return count > nums.size() / 2 ? num : -1;
	}
};