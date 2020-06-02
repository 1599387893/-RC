class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int count = 1;
		int n = nums[nums.size() / 2];
		for (int i = 0; i <nums.size(); ++i)
			if (nums[i] == n)
				count++;
		return count >= nums.size() / 2 ? n : -1;
	}
};