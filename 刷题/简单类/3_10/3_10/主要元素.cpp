#if 0
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int mid = nums[nums.size() / 2];
		int count = 0;
		for (int i = 0; i < nums.size(); ++i)
			if (nums[i] == mid)
				count++;
		if (count>nums.size() / 2)
			return mid;
		return -1;
	}
};
#endif